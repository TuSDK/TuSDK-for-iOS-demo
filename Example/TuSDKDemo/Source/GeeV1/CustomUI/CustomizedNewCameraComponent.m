//
//  CustomizedNewCameraComponent.m
//  TuSDKDemo
//
//  Created by 刘鹏程 on 2020/6/9.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import "CustomizedNewCameraComponent.h"
#import "PhotoCaptureConfirmView.h"
#import "RecordButton.h"
#import "CameraFilterPanelView.h"
#import "DefineCAEAGLView.h"

#import "CameraControlMaskView.h"

// 动画时长
static const NSTimeInterval kAnimationDuration = 0.25;

// 顶部工具栏高度
static const CGFloat kTopBarHeight = 64.0;

@implementation CustomizedNewCameraComponent

- (instancetype)init;
{
    self = [super initWithGroupId:UISample title:NSLocalizedString(@"sample_api_CameraFromVideo", @"短视频相机示例")];
    return self;
}

/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSampleWithController:(UIViewController *)controller;
{
    if (!controller) return;
    self.controller = controller;
    [self.controller lsqPresentModalNavigationController:[[CameraViewController alloc] init] animated:YES];
}


@end

#pragma mark - CameraViewController
/**
 *  基础相机视图控制器
 */
@interface CameraViewController()<TuSDKPFCameraFilterGroupViewDelegate,
                                    TuCameraDelegate,
                                    TuCameraShotDelegate,
                                    PhotoCaptureDelegate,
                                    CameraFilterPanelDelegate,
                                    CameraFilterPanelDataSource,
                                    CameraControlMaskViewDelegate
>
{
    // 相机接口
    id<TuCameraShower> _cameraShower;
    // 自定义 OPENGL ES视图
    DefineCAEAGLView *_preiveView;
    //曝光控制
    UISlider *_exposureSlider;
    UIImageView *_lightImageView;
    //相机顶部配置视图
    UIStackView *_cameraTopPanelView;
    // 相机滤镜视图
    TuSDKPFCameraFilterGroupView *_filterBar;
}
/**
 拍照模式中，确认照片视图
 */
@property (nonatomic, strong) PhotoCaptureConfirmView *photoCaptureconfirm;

/**
 滤镜面板叠层视图
 */
@property (nonatomic, strong, readonly) CameraFilterPanelView *filterPanelView;

/**
 当前的底部面板
 */
@property (nonatomic, weak) UIView<OverlayViewProtocol> *currentBottomPanelView;

@property (nonatomic, strong) CameraControlMaskView *cameraMaskView;

@end


@implementation CameraViewController
#pragma mark - camera action
// 隐藏状态栏 for IOS7
- (BOOL)prefersStatusBarHidden;
{
    return YES;
}

- (void)loadView
{
    [super loadView];

    [self.navigationController setNavigationBarHidden:YES];
    [[UIApplication sharedApplication] setStatusBarHidden:YES withAnimation:UIStatusBarAnimationFade];
}

- (void)dealloc;
{
    [self destoryCamera];
    [self controllerWillDestory];
    // 清空视图垃圾
    if (self.isViewLoaded && self.view) {
        [self.view viewWillDestory];
        self.view = nil;
    }
    lsqLDebug(@"dealloc controller %@: %@" , self.title, self);
}

// 销毁相机
- (void)destoryCamera;
{
    _cameraShower = nil;

}

// 视图即将关闭
- (void)viewDidDisappear:(BOOL)animated;
{
    [super viewDidDisappear:animated];
    [self stopCamera];
}

/**
 *  视图即将显示
 *
 *  @param animated 是否显示动画
 */
- (void)viewWillAppear:(BOOL)animated;
{
    [super viewWillAppear:animated];
    
    // 如果从编辑图片回来，需要隐藏状态栏和导航栏  隐藏状态栏 for IOS6
    [self.navigationController setNavigationBarHidden:YES];
    [[UIApplication sharedApplication] setStatusBarHidden:YES];
    // 开启访问相机权限
    [TuTSDeviceSettings checkAllowWithController:self
                                               type:TuDeviceSettingsCamera
                                          completed:^(TuDeviceSettingsType type, BOOL openSetting)
     {
         if (openSetting) {
             lsqLError(@"Can not open camera");
             return;
         }
         [self startCamera];
     }];
}

//开始启动相机
- (void)startCamera;
{
    if (_cameraShower != nil)
    {
        [_cameraShower.camera startPreview];
        return;
    }
    
    _cameraShower = [[TuCameraShowerImpl alloc] initWithRootView:_preiveView];
        
    // 配置相机参数
    [self configCamera:_cameraShower.camera];

    /** 设置相机状态监听 */
    _cameraShower.camera.delegate = self;
    /** 设置相机拍照监听 */
    _cameraShower.camera.shotDelegate = self;
    
    /** 启动相机*/
    [_cameraShower.camera startPreview];
    
//    // 配置闪光灯视图
////    [self configFlashView];
}

// 配置相机参数
- (void)configCamera:(TuCamera *)camera;
{
    // 设置相机前后位置
    camera.devicePosition = AVCaptureDevicePositionFront;

    // 设置相机输出画面的方向和镜像设置
    camera.frontCameraOrientation = AVCaptureVideoOrientationPortrait;
    camera.frontCameraMirrored = YES;
    camera.backCameraOrientation = AVCaptureVideoOrientationPortrait;
    camera.backCameraMirrored = NO;

    camera.sessionPreset = AVCaptureSessionPreset1920x1080; // 摄像头分辨率模式
    camera.captureAsYUV = YES;
    camera.fps = 30;

    camera.enableZoom = YES; // 是否支持双指缩放来调节焦距
    
    [camera prepare];
}

// 停止相机
- (void)stopCamera;
{
    if (!_cameraShower)
    {
        return;
    }
    
    [_cameraShower.camera stopPreview];
}

#pragma mark - TuCameraDelegate
/**
 * 相机状态改变
 * @param status 相机状态
 * @param camera 相机接口
 */
- (void)onTuCameraStatusChanged:(TuCameraState)status camera:(TuCamera *)camera;
{
    lsqLDebug(@"onStatusChanged:status: %d, isMainThread: %d", status, [NSThread isMainThread]);
}

#pragma mark - TuCameraShotDelegate
/** 拍摄照片失败 */
- (void)onTuCameraShotFailed:(NSError *)error;
{
    lsqLDebug(@"onTuCameraShotFailed [%d]: %@", error, [NSThread isMainThread]);
}

/** 相机即将开始拍摄 */
- (void)onTuCameraWillShot:(TuResult *)data;
{
    lsqLDebug(@"onTuCameraWillShot [%d]", [NSThread isMainThread]);
}

/** 直接UIImage TuResult.image */
- (void)onTuCameraShotBitmap:(TuResult *)data;
{
    [self performSelectorOnMainThread:@selector(onPreviewShow:) withObject:data waitUntilDone:YES];
}

// 配置闪光灯视图
//- (void)configFlashView;
//{
//    if (!_shower) return;
//
//    if (_shower.camera.cameraParams.hasFlash) {
//        _flashBar.hidden = NO;
//        // 设置闪光灯模式
//        _shower.camera.cameraParams.flashMode = _flashMode;
//    }else{
//        _flashBar.hidden = YES;
//    }
//}

// 选中一个滤镜
//- (BOOL)onSelectedFilterCode:(NSString *)code;
//{
//    if (!_shower) return YES;
//    SelesParameters *params = [_shower changeFilter:code];
//    return params != nil;
//}
//
// 切换前后摄像头
- (void)onSwitchCamera
{
    if (!_cameraShower)
    {
        return;
    }
    
    [_cameraShower.camera rotateCamera];

    // 配置闪光灯视图
//    [self configFlashView];
}
//
//// 选择闪光灯模式
//- (void)onSwitchFlash:(UIButton *)sender;
//{
//    if (!_shower) return;
//
//    _shower.camera.cameraParams.flashMode = (TuCameraFlash)sender.tag;
//    for (UIButton * btn in _flashButtons) {
//        if ([btn isEqual:sender]) {
//            [btn setStateNormalTitleColor:lsqRGB(255, 85, 52)];
//        }else{
//            [btn setStateNormalTitleColor:[UIColor whiteColor]];
//        }
//    }
//}

// 点击拍摄按钮
- (void)onCapturePhoto;
{
    if (!_cameraShower)
    {
        return;
    }
    
    // 点击拍摄后，访问 - (void) onTuCameraShotBitmap:(TuResult *)data; 方法获取拍摄结果
    [_cameraShower.camera shotPhoto];
}

#pragma mark - TuSDKPFCameraFilterGroupViewDelegate
/**
 *  选中一个滤镜
 *
 *  @param view    相机滤镜视图
 *  @param item    滤镜分组元素
 *  @param capture 是否允许拍摄
 *
 *  @return 是否允许继续执行
 */
//- (BOOL)onTuSDKPFCameraFilterGroup:(TuSDKPFCameraFilterGroupView *)view
//                      selectedItem:(TuGroupFilterItem *)item
//                           capture:(BOOL)capture;
//{
//    if (capture) {
//        [self onCapturePhoto:nil];
//        return YES;
//    }
//
//    switch (item.type) {
//        case lsqGroupFilterItemFilter:
//            return [self onSelectedFilterCode:[item filterCode]];
//        default:
//            break;
//    }
//    return YES;
//}

/**
 *  相机滤镜视图状态改变
 *
 *  @param view   相机滤镜视图
 *  @param isShow 是否显示
 */
- (void)onTuSDKPFCameraFilterGroup:(TuSDKPFCameraFilterGroupView *)view
                      stateChanged:(BOOL)isShow;
{

}

// 显示预览视图
- (void)onPreviewShow:(TuResult *)result;
{
    lsqLDebug(@"image: %@", NSStringFromCGSize(result.image.size));

    [_photoCaptureconfirm.photoView removeAllSubviews];


    UIImageView *imgView = [UIImageView initWithFrame:_photoCaptureconfirm.bounds];
    imgView.backgroundColor = lsqRGB(60, 60, 60);
    imgView.contentMode = UIViewContentModeScaleAspectFit;
    
    // UIImage *image = [result.image lsqImageCorpWithRatio:0.75];
    lsqLDebug(@"image: %@", NSStringFromCGSize(result.image.size));
    
    imgView.image = result.image;
    [_photoCaptureconfirm.photoView addSubview:imgView];
    
    _photoCaptureconfirm.alpha = 0;
    _photoCaptureconfirm.hidden = NO;
    [UIView animateWithDuration:0.32 animations:^{
        _photoCaptureconfirm.alpha = 1;
        [_photoCaptureconfirm show];
    }];
}

//关闭预览视图
//- (void)onClosePreview:(id)sender;
//{
//    [UIView animateWithDuration:0.32 animations:^{
//        _preview.alpha = 0;
//    } completion:^(BOOL finished) {
//        [_preview removeAllSubviews];
//        _preview.hidden = YES;
//        if (_shower) [_shower.camera startPreview];
//
//    }];
//}

- (void)viewDidLayoutSubviews {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        // 获取相机的权限并启动相机
//        if(self->_isOpenSetting) [self requestCameraPermission];
//
//        [self->_camera updateCameraViewBounds:self->_cameraView.bounds];
        
        self->_exposureSlider.frame = CGRectMake(self.view.bounds.size.width - 45, (self.view.bounds.size.height-220)*0.5, 40, 220);
        self->_lightImageView.frame = CGRectMake(self.view.bounds.size.width - 40, (self.view.bounds.size.height-220)*0.5 - 35, 30, 30);

//        // 更新其他 UI
//        [self setupUIAfterCameraSetup];
    });
}

#pragma mark - init
/**
 *  初始化视图
 */
-(void)viewDidLoad
{
    [super viewDidLoad];
    
    // sdk统计代码，请不要加入您的应用
    [TuStatistics appendWithComponentIdt:tu_sdkSimpleCamera];
    
    self.view = [UIView initWithFrame:CGRectMake(0, 0, lsqScreenWidth, lsqScreenHeight)];
    self.view.backgroundColor = lsqRGB(122, 122, 122);
    
    _preiveView = [DefineCAEAGLView initWithFrame:self.view.bounds];
    _preiveView.opaque = YES;
    _preiveView.hidden = NO;
    [self.view addSubview:_preiveView];

    //相机配置UI
    self.cameraMaskView = [[CameraControlMaskView alloc]initWithFrame:self.view.bounds];
    [self.view addSubview:self.cameraMaskView];
    [self.cameraMaskView addDelegate:self];
    
    //配置曝光视图
    [self configSlider];
    //照片预览视图
    [self configPhotoCaptureView];
    
    [self buildFilterWindow];
}

//配置预览视图
- (void)configPhotoCaptureView
{
    self.photoCaptureconfirm = [PhotoCaptureConfirmView initWithFrame:self.view.bounds];
    self.photoCaptureconfirm.hidden = YES;
    [self.photoCaptureconfirm addDelegate:self];
    [self.view addSubview:self.photoCaptureconfirm];
}

//配置效果
- (void)buildFilterWindow
{
    // 滤镜视图
//    _filterPanelView = [[CameraFilterPanelView alloc] initWithFrame:CGRectZero];
//    _filterPanelView.alpha = 0;
//    _filterPanelView.sender = _filterButton;
//    _filterPanelView.delegate = self;
//    _filterPanelView.dataSource = self;
//    [_cameraBottomPanelView addSubview:_filterPanelView];
    
    // 相机滤镜视图
    _filterBar = [TuSDKPFCameraFilterGroupView initWithFrame:self.view.bounds];
    [self.view addSubview:_filterBar];
    [_filterBar setDefaultShowState: NO];
    _filterBar.autoSelectGroupDefaultFilter = YES;
    _filterBar.delegate = self;
    [_filterBar loadFilters];
}

#pragma mark - 曝光控制
// 曝光
- (void)configSlider {
    
    _lightImageView = [[UIImageView alloc] initWithFrame:CGRectZero];
    _lightImageView.image = [UIImage imageNamed:@"ic_light"];
    [self.cameraMaskView addSubview:_lightImageView];
    
    _exposureSlider = [[UISlider alloc] initWithFrame:CGRectZero];
    [self.cameraMaskView addSubview:_exposureSlider];
    _exposureSlider.transform = CGAffineTransformMakeRotation(-M_PI/2);
    _exposureSlider.maximumValue = 1.0;
    _exposureSlider.minimumValue = 0.0;
    _exposureSlider.value = 0.5;
    _exposureSlider.minimumTrackTintColor = [UIColor whiteColor];
    _exposureSlider.maximumTrackTintColor = [UIColor colorWithRed:150/255.0 green:150/255.0 blue:150/255.0 alpha:0.3];
    [_exposureSlider setThumbImage:[UIImage imageNamed:@"slider_thum_icon"] forState:UIControlStateNormal];
    [_exposureSlider addTarget:self action:@selector(updateValue:) forControlEvents:UIControlEventValueChanged];
}

- (void)updateValue:(UISlider *)slider {
    float value = slider.value;
    float bias = (value - 0.5) * 8;
    
    NSLog(@"曝光数值变动 ==== %.2f",bias);
}

/**
 *  退出相机
 *
 *  @param sender
 */
- (void)onWindowExit
{
    //  隐藏状态栏 for IOS6
    [[UIApplication sharedApplication] setStatusBarHidden:YES withAnimation:UIStatusBarAnimationFade];
    [self dismissViewControllerAnimated:YES completion:nil];
}

/**
 底部显示按钮状态

 @param sender 按钮
 */
- (void)filterButtonAction:(UIButton *)sender
{
    NSLog(@"点击滤镜");
    [_filterBar showGroupView];
}

#pragma mark - PhotoCaptureDelegate
/**
 照片保存实现
*/
- (void)onConfirmPhotoCaptionAction
{
    [UIView animateWithDuration:kAnimationDuration animations:^{
        _photoCaptureconfirm.alpha = 0;
    } completion:^(BOOL finished) {
        [_photoCaptureconfirm.photoView removeAllSubviews];
        _photoCaptureconfirm.hidden = YES;
        if (_cameraShower) [_cameraShower.camera startPreview];
        
        NSLog(@"保存成功提示");
    }];
}

/**
 取消照片保存实现
 */
- (void)onCancelPhotoCaptionAction
{
    [UIView animateWithDuration:kAnimationDuration animations:^{
        _photoCaptureconfirm.alpha = 0;
    } completion:^(BOOL finished) {
        [_photoCaptureconfirm.photoView removeAllSubviews];
        _photoCaptureconfirm.hidden = YES;
        if (_cameraShower) [_cameraShower.camera startPreview];
    }];

}


#pragma mark - CameraControlMaskViewDelegate
/**
 相机UI操作按钮回调
 */
- (void)onClickButtonCompletion:(lsqCameraHandleType)handleType
{
    switch (handleType) {
            //退出相机
        case lsqCameraHandleTypeBack:
            [self onWindowExit];
            break;
            //切换前后摄像头
        case lsqCameraHandleTypeSwitchCamera:
            [self onSwitchCamera];
            break;
            //拍照
        case lsqCameraHandleTypeTakePhoto:
            [self onCapturePhoto];
            break;
        default:
            break;
    }
}

#pragma mark - CameraMoreMenuViewDelegate
- (void)moreMenu:(CameraMoreMenuView *)moreMenu didSelectedRatio:(CGFloat)ratio
{
    // 相机预览画面区域显示算法
    NSLog(@"-------%f",ratio);
    
    CGFloat percentOffset = 0;
    if (ratio == 1.0 || ratio == 3.0/4) {
        if (ratio == 1.0) percentOffset = kTopBarHeight / self.view.lsqGetSizeHeight;
        if (@available(iOS 11.0, *)) {
            CGFloat topOffset = self.view.safeAreaInsets.top;
            if (topOffset > 0) percentOffset = (kTopBarHeight + topOffset) / self.view.lsqGetSizeHeight;
        }
    }
}

/**
 更多菜单切换自动聚焦回调
 
 @param moreMenu 更多菜单视图
 @param autoFocus 自动聚焦
 */
- (void)moreMenu:(CameraMoreMenuView *)moreMenu didSwitchAutoFocus:(BOOL)autoFocus
{
    _cameraShower.camera.enableAutoFocus = autoFocus;
}

/**
 更多菜单切换闪光灯回调
 
 @param moreMenu 更多菜单视图
 @param enableFlash 闪光灯开启状态
 */
- (void)moreMenu:(CameraMoreMenuView *)moreMenu didSwitchFlashMode:(BOOL)enableFlash
{
    
}


@end
