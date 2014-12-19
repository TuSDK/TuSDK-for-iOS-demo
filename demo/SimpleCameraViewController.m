//
//  SimpleCameraViewController.m
//  TuSDKDemo
//
//  Created by Clear Hu on 14/10/28.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "SimpleCameraViewController.h"

#import "TuSDK/TuSDK.h"

#pragma mark - SimpleCameraViewController

@interface SimpleCameraViewController ()<TuSDKStillCameraDelegate>
{
    // 相机对象
    TuSDKStillCamera *_camera;
    // 相机视图
    UIView *_cameraView;
    // 相机配置栏目
    UIView *_configBar;
    // 取消按钮
    UIButton *_cancelButton;
    // 前后摄像头切换按钮
    UIButton *_switchCameraButton;
    // 闪光灯设置视图
    UIView *_flashBar;
    // 闪光灯按钮集合
    NSMutableArray *_flashButtons;
    // 闪光灯模式
    AVCaptureFlashMode _flashMode;
    // 下边栏
    UIView *_bottomBar;
    // 拍摄按钮
    UIButton *_captureButton;
    // 滤镜名称列表
    UIScrollView *_filterWindow;
    // 滤镜列表名称
    NSArray *_filterNames;
    
    // 照片预览视图
    UIButton *_preview;
}

@end

@implementation SimpleCameraViewController
#pragma mark - camera action
// 隐藏状态栏 for IOS7
- (BOOL)prefersStatusBarHidden;
{
    return YES;
}

-(void)loadView
{
    [super loadView];
    // 设置全屏 隐藏状态栏 for IOS6
    self.wantsFullScreenLayout = YES;
    [self.navigationController setNavigationBarHidden:YES];
    [[UIApplication sharedApplication] setStatusBarHidden:YES withAnimation:UIStatusBarAnimationFade];
}

/**
 *  视图即将显示
 *
 *  @param animated 是否显示动画
 */
-(void)viewWillAppear:(BOOL)animated;
{
    [super viewWillAppear:animated];
    
    // 如果从编辑图片回来，需要隐藏状态栏和导航栏  隐藏状态栏 for IOS6
    [self.navigationController setNavigationBarHidden:YES];
    [[UIApplication sharedApplication] setStatusBarHidden:YES];
    
    
    [self startCamera];
}

// 开始启动相机
-(void)startCamera;
{
    [self destoryCamera];
    
    _camera = [TuSDKStillCamera initWithSessionPreset:AVCaptureSessionPresetHigh
                                       cameraPosition:[AVCaptureDevice firstBackCameraPosition] // AVCaptureDevicePositionBack
                                           cameraView:_cameraView];
    // 设置拍摄委托
    _camera.captureDelegate = self;
    
    // 配置闪光灯视图
    [self configFlashView];
    
    // 可选: 绑定手动聚焦视图, 自动设置视图大小为显示大小
    TuSDKICFocusTouchView *focusView = [TuSDKICFocusTouchView initWithFrame:CGRectZero];
    [_camera bindFocusTouchView:focusView];
    // 开启持续自动对焦 (默认: NO)
    _camera.enableContinueFoucs = YES;
    // 是否开启长按拍摄 (默认: NO)
    _camera.enableLongTouchCapture = YES;
    
    // 启动相机
    [_camera tryStartCameraCapture];
}

// 配置闪光灯视图
- (void)configFlashView;
{
    if (!_camera) return;
    
    if (_camera.hasFlash) {
        _flashBar.hidden = NO;
        // 设置闪光灯模式
        [_camera flashWithMode: _flashMode];
    }else{
        _flashBar.hidden = YES;
    }
}

/**
 *  视图即将关闭
 *
 *  @param animated 是否显示动画
 */
- (void)viewDidDisappear:(BOOL)animated;
{
    [super viewDidDisappear:animated];
    
    [self destoryCamera];
}

/**
 *  切换滤镜
 *
 *  @param sender
 */
- (void)onFilterSelected:(UIButton *)sender;
{
    if (!_camera) return;
    
    [_camera switchFilterWithName:_filterNames[sender.tag]];
}

/**
 *  切换前后摄像头
 *
 *  @param sender
 */
- (void)onSwitchCamera:(UIButton *)sender;
{
    if (!_camera) return;
    
    [_camera rotateCamera];
    
    // 配置闪光灯视图
    [self configFlashView];
}

/**
 *  选择闪光灯模式
 *
 *  @param sender
 */
- (void)onSwitchFlash:(UIButton *)sender;
{
    if (!_camera) return;
    
    [_camera flashWithMode: (AVCaptureFlashMode)sender.tag];
    
    for (UIButton * btn in _flashButtons) {
        if ([btn isEqual:sender]) {
            [btn setStateNormalTitleColor:RGB(255, 85, 52)];
        }else{
            [btn setStateNormalTitleColor:[UIColor whiteColor]];
        }
    }
}

/**
 *  点击拍摄按钮
 *
 *  @param sender
 */
- (void)onCapturePhoto:(UIButton *)sender;
{
    if (!_camera) return;
    
    // 点击拍摄后，访问 - (void)onCamera:(TuSDKStillCamera *)camera takedResult:(TuSDKResult *)result error:(NSError *)error;
    // 方法获取拍摄结果
    [_camera captureImage];
}

/**
 *  销毁相机
 */
- (void)destoryCamera;
{
    if (_camera) {
        [_camera destory];
        _camera = nil;
    }
}
#pragma mark - TuSDKStillCameraDelegate
/**
 *  相机状态改变 (如需操作UI线程， 请检查当前线程是否为主线程)
 *
 *  @param camera 相机对象
 *  @param state  相机运行状态
 */
- (void)onCamera:(TuSDKStillCamera *)camera stateChanged:(lsqCameraState)state;
{
    
}

/**
 *  获取拍摄图片 (如需操作UI线程， 请检查当前线程是否为主线程)
 *
 *  @param camera 相机对象
 *  @param result 获取的结果
 *  @param error  错误信息
 */
- (void)onCamera:(TuSDKStillCamera *)camera takedResult:(TuSDKResult *)result error:(NSError *)error;
{
    if (error) return;
    
    lsqLDebug(@"Result(%ld): %@",result.image.imageOrientation, NSStringFromCGSize(result.image.size));
    // [_camera resumeCameraCapture];
    
    [self performSelectorOnMainThread:@selector(onPreviewShow:) withObject:result waitUntilDone:YES];
}


// 显示预览视图
- (void)onPreviewShow:(TuSDKResult *)result;
{
    [_preview removeAllSubviews];
    
    UIImageView *imgView = [UIImageView initWithFrame:_preview.bounds];
    imgView.backgroundColor = RGB(60, 60, 60);
    imgView.contentMode = UIViewContentModeScaleAspectFit;
    
    UIImage *image = [result.image imageCorpWithRatio:0.75];
    lsqLDebug(@"image: %@", NSStringFromCGSize(image.size));
    
    imgView.image = image;
    [_preview addSubview:imgView];
    
    _preview.alpha = 0;
    _preview.hidden = NO;
    [UIView animateWithDuration:0.32 animations:^{
        _preview.alpha = 1;
    }];
}

// 关闭预览视图
- (void)onClosePreview:(id)sender;
{
    [UIView animateWithDuration:0.32 animations:^{
        _preview.alpha = 0;
    } completion:^(BOOL finished) {
        [_preview removeAllSubviews];
        _preview.hidden = YES;
        
        [_camera resumeCameraCapture];
    }];
}
#pragma mark - init
/**
 *  初始化视图
 */
-(void)viewDidLoad;
{
    [super viewDidLoad];
    
    self.view = [UIView initWithFrame:CGRectMake(0, 0, lsqScreenWidth, lsqScreenHeight)];
    self.view.backgroundColor = RGB(122, 122, 122);
    
    // 相机视图
    _cameraView = [UIView initWithFrame:self.view.bounds];
    [self.view addSubview:_cameraView];
    
    // 相机配置栏目
    _configBar = [UIView initWithFrame:CGRectMake(0, 0, self.view.getSizeWidth, 44)];
    [self.view addSubview:_configBar];
    
    // 下边栏
    _bottomBar = [UIView initWithFrame:CGRectMake(0, self.view.getSizeHeight - 80, self.view.getSizeWidth, 80)];
    [self.view addSubview:_bottomBar];
    
    // 取消按钮
    _cancelButton = [UIButton buttonWithFrame:CGRectMake(0, 0, 60, _configBar.getSizeHeight)
                                        title:LSQString(@"lsq_button_close", @"Close") font:FONT(12) color:[UIColor whiteColor]];
    
    [_cancelButton addTouchUpInsideTarget:self action:@selector(onWindowExit:)];
    [_configBar addSubview:_cancelButton];
    
    // 前后摄像头切换按钮
    _switchCameraButton = [UIButton buttonWithFrame:CGRectMake(_configBar.getSizeWidth - 60, 0, 60, _configBar.getSizeHeight)
                                              title:LSQString(@"lsq_button_switch_camera", @"Switch") font:FONT(12) color:[UIColor whiteColor]];
    
    [_switchCameraButton addTouchUpInsideTarget:self action:@selector(onSwitchCamera:)];
    [_configBar addSubview:_switchCameraButton];
    
    // 如果仅有一个摄像头
    _switchCameraButton.hidden = ([AVCaptureDevice cameraCounts] == 0);
    
    // 闪光灯设置视图
    _flashBar = [UIView initWithFrame:CGRectMake(_cancelButton.getRightX, 0, _switchCameraButton.getOriginX - _cancelButton.getRightX, _configBar.getSizeHeight)];
    [_configBar addSubview:_flashBar];
    
    // 闪光灯标题
    UIButton *_flashTitle = [UIButton buttonWithFrame:CGRectMake(0, 0, 40, _configBar.getSizeHeight)
                                                title:LSQString(@"lsq_button_flash", @"Flash") font:FONT(12) color:[UIColor whiteColor]];
    [_flashBar addSubview:_flashTitle];
    
    // 闪光灯按钮集合
    _flashButtons = [NSMutableArray arrayWithCapacity:3];
    // 闪光灯模式
    _flashMode = AVCaptureFlashModeOff;
    CGFloat left = _flashTitle.getRightX;
    CGFloat btnWidth = floor((_flashBar.getSizeWidth - left)/3.f);
    for (int i = 0; i < 3; i++) {
        UIButton *btn = [UIButton buttonWithFrame:CGRectMake(left, 0, btnWidth, _configBar.getSizeHeight)
                                            title:@"" font:FONT(12) color:[UIColor whiteColor]];
        left = btn.getRightX;
        
        switch (i) {
            case 0:
                [btn setStateNormalTitle:LSQString(@"lsq_button_flash_model_off", @"off")];
                btn.tag = AVCaptureFlashModeOff;
                break;
            case 1:
                [btn setStateNormalTitle:LSQString(@"lsq_button_flash_model_open", @"open")];
                btn.tag = AVCaptureFlashModeOn;
                break;
            case 2:
                [btn setStateNormalTitle:LSQString(@"lsq_button_flash_model_auto", @"auto")];
                btn.tag = AVCaptureFlashModeAuto;
                break;
            default:
                break;
        }
        [btn addTouchUpInsideTarget:self action:@selector(onSwitchFlash:)];
        
        if (btn.tag == _flashMode) {
            [btn setStateNormalTitleColor:RGB(255, 85, 52)];
        }
        
        [_flashButtons addObject:btn];
        [_flashBar addSubview:btn];
    }
    
    // 拍摄按钮
    CGFloat capBtnSize = _bottomBar.getSizeHeight - 20;
    _captureButton = [UIButton initWithFrame:CGRectMake([_bottomBar getCenterX:capBtnSize], [_bottomBar getCenterY:capBtnSize], capBtnSize, capBtnSize)];
    [_captureButton setStateNormalBackgroundImageColor:RGB(255, 85, 52)];
    _captureButton.layer.cornerRadius = capBtnSize * 0.5f;
    _captureButton.layer.masksToBounds = YES;
    [_captureButton addTouchUpInsideTarget:self action:@selector(onCapturePhoto:)];
    [_bottomBar addSubview:_captureButton];
    
    [self buildFilterWindow];
    
    // 照片预览视图
    _preview = [UIButton initWithFrame:self.view.bounds];
    _preview.hidden = YES;
    [_preview addTouchUpInsideTarget:self action:@selector(onClosePreview:)];
    [self.view addSubview:_preview];
}

/**
 *  创建滤镜列表窗口
 */
- (void)buildFilterWindow;
{
    // 滤镜名称列表
    _filterWindow = [UIScrollView initWithFrame:CGRectMake(0, _bottomBar.getOriginY - 44, self.view.getSizeWidth, 44)];
    _filterWindow.backgroundColor = RGBA(0, 0, 0, 0.5);
    [self.view addSubview:_filterWindow];
    
    _filterNames = [TuSDK internalFilterNames];
    
    CGFloat left = 0;
    int index = 0;
    
    for (NSString *title in _filterNames) {
        UIButton *btn = [UIButton buttonWithFrame:CGRectMake(left, 0, 60, _filterWindow.getSizeHeight)
                                            title:title font:FONT(12) color:[UIColor whiteColor]];
        left = btn.getRightX + 10;
        btn.tag = index;
        [btn addTouchUpInsideTarget:self action:@selector(onFilterSelected:)];
        [_filterWindow addSubview:btn];
        index++;
    }
    _filterWindow.contentSize = CGSizeMake(left, _filterWindow.getSizeHeight);
}

/**
 *  退出相机
 *
 *  @param sender
 */
- (void)onWindowExit: (id)sender;
{
    // [_camera rotateCamera];
    //  隐藏状态栏 for IOS6
    [[UIApplication sharedApplication] setStatusBarHidden:NO withAnimation:UIStatusBarAnimationFade];
    [self dismissModalViewControllerAnimated:YES];
}
#pragma mark - Autorotate
// 是否允许旋转 IOS5
-(BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return NO;
}

// 是否允许旋转 IOS6
-(BOOL)shouldAutorotate
{
    return NO;
}

// 支持的旋转模式 IOS6
- (NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortrait;
}
@end
