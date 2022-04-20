//
//  CustomizedCameraComponent.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/5/11.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "CustomizedCameraComponent.h"

#pragma mark - CustomizedCameraComponent
/**
 *  基础相机组件范例 (对现有组件进行扩展 - 修改界面)
 */
@interface CustomizedCameraComponent()<TuSDKPFCameraDelegate>

@end

@implementation CustomizedCameraComponent
- (instancetype)init;
{
    self = [super initWithGroupId:UISample title:NSLocalizedString(@"sample_ui_CameraBase", @"相机界面自定义")];
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
    
    /**
     *  滤镜预览图修改方式：
     *
     *  编辑 TuSDK.bundle/others/lsq_tusdk_configs.json
     *  filterGroups[]->filters[]->thumb
     */
    
    // 开启访问相机权限
    [TuTSDeviceSettings checkAllowWithController:self.controller
                                               type:TuDeviceSettingsCamera
                                          completed:^(TuDeviceSettingsType type, BOOL openSetting)
     {
         if (openSetting) {
             lsqLError(@"Can not open camera");
             return;
         }
         [self showCameraController];
     }];
}

#pragma mark - cameraComponentHandler TuSDKPFCameraDelegate
- (void)showCameraController;
{
    // 组件选项配置
    // @see-https://tutucloud.com/docs/ios/image/image/api-geev1/Classes/TuSDKPFCameraOptions.html
    TuSDKPFCameraOptions *opt = [TuSDKPFCameraOptions build];
    
    // 控制器类
    opt.componentClazz = [CustomizedCameraController class];
    
    // 视图类 (默认:TuSDKPFCameraView, 需要继承 TuSDKPFCameraView)
    opt.viewClazz = [CustomizedCameraView class];
    
    // 默认相机控制栏视图类 (默认:TuSDKPFCameraConfigView, 需要继承 TuSDKPFCameraConfigView)
    // opt.configBarViewClazz = [TuSDKPFCameraConfigView class];
    
    // 默认相机底部栏视图类 (默认:TuSDKPFCameraBottomView, 需要继承 TuSDKPFCameraBottomView)
    // opt.bottomBarViewClazz = [TuSDKPFCameraBottomView class];
    
    // 设置视图类 (默认:TuSDKPFCameraSettingView, 需要继承 TuSDKPFCameraSettingView)
    // opt.settingViewClazz = [TuSDKPFCameraSettingView class];
    
    // 结果预览视图类 (默认:TuSDKPFCameraPreviewView, 需要继承 TuSDKPFCameraPreviewView)
    //opt.previewViewClazz = [TuSDKPFCameraPreviewView class];
    
    // 滤镜视图类 (默认:TuSDKPFCameraFilterGroupView, 需要继承 TuSDKPFCameraFilterGroupView)
    // opt.filterViewClazz = [TuSDKPFCameraFilterGroupView class];
    
    
    // 聚焦触摸视图类 (默认:TuSDKCPFocusTouchView, 需要继承 TuSDKCPFocusTouchView)
    // opt.focusTouchViewClazz = [TuSDKCPFocusTouchView class];
    // 摄像头前后方向 (默认为后置优先)
    // opt.cameraPostion = [AVCaptureDevice firstBackCameraPosition];
    
    // 设置分辨率模式
    // opt.sessionPreset = AVCaptureSessionPresetHigh;
    
    // 闪光灯模式 (默认:AVCaptureFlashModeOff)
    // opt.cameraDefaultFlashMode = AVCaptureFlashModeOff;
    
    // 是否开启滤镜支持 (默认: 关闭)
    opt.enableFilters = YES;
    
    // 是否预览拍照结果 (默认: NO 不预览)
    opt.enablePreview = YES;
    
    // 默认是否显示滤镜视图 (默认: 不显示, 如果enableFilters = NO, showFilterDefault将失效)
    // opt.showFilterDefault = YES;
    
    // 开启滤镜历史记录
    opt.enableFilterHistory = YES;
    
    // 开启在线滤镜
    opt.enableOnlineFilter = YES;
    
    // 显示滤镜标题视图
    opt.displayFilterSubtitles = YES;
    
    // 滤镜列表行视图宽度
    opt.filterBarCellWidth = 60;
    
    // 滤镜列表选择栏高度
    opt.filterBarHeight = 60;
    
    // 滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
    // opt.filterBarGroupCellClazz = [TuSDKCPGroupFilterGroupCell class];
    
    // 滤镜列表行视图类 (默认:TuSDKCPGroupFilterItemCell, 需要继承 TuSDKCPGroupFilterItemCell)
    opt.filterBarTableCellClazz = [CustomizedCameraFilterItemCell class];
    
    // 需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
    // 滤镜名称参考 TuSDK.bundle/others/lsq_tusdk_configs.json
    // filterGroups[]->filters[]->name lsq_filter_%{Brilliant}
    opt.filterGroup = @[@"SkinNature", @"SkinPink", @"SkinJelly", @"SkinNoir", @"SkinRuddy", @"SkinPowder", @"SkinSugar"];
    
    // 是否保存最后一次使用的滤镜
    // opt.saveLastFilter = YES;
    
    // 自动选择分组滤镜指定的默认滤镜
    opt.autoSelectGroupDefaultFilter = YES;
    
    // 开启滤镜配置选项
    // opt.enableFilterConfig = YES;
    
    // 视频视图显示比例 (默认：0， 0 <= mRegionRatio, 当设置为0时全屏显示)
    // opt.cameraViewRatio = 0.75f;
    
    // 视频视图显示比例类型 (默认:TTRatioOrgin, 如果设置cameraViewRatio > 0, 将忽略ratioType)
    opt.ratioType = TTRatioOrgin; // 不设置比例
    
    // 是否开启长按拍摄 (默认: NO)
    opt.enableLongTouchCapture = YES;
    
    // 禁用持续自动对焦 (默认: NO)
    // opt.disableContinueFoucs = YES;
    
    // 自动聚焦延时 (默认: 5秒)
    // opt.autoFoucsDelay = 5;
    
    // 长按延时 (默认: 1.2秒)
    // opt.longTouchDelay = 1.2;
    
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuResult.asset)
    opt.saveToAlbum = YES;
    
    // 保存到临时文件 (默认不保存, 当设置为YES时, TuResult.tmpFile)
    // opt.saveToTemp = NO;
    
    // 保存到系统相册的相册名称
    // opt.saveToAlbumName = @"TuSdk";
    
    // 照片输出压缩率 0-1 如果设置为0 将保存为PNG格式 (默认: 0.95)
    // opt.outputCompress = 0.95f;
    
    // 视频覆盖区域颜色 (默认：[UIColor clearColor])
    opt.regionViewColor = lsqRGB(51, 51, 51);
    
    // 照片输出分辨率
    // opt.outputSize = CGSizeMake(1440, 1920);
    
    // 禁用前置摄像头自动水平镜像 (默认: NO，前置摄像头拍摄结果自动进行水平镜像)
    // opt.disableMirrorFrontFacing = YES;
    
    // 是否开启脸部追踪
    opt.enableFaceDetection = YES;
    
    TuSDKPFCameraViewController *controller = opt.viewController;
    // 添加委托
    controller.delegate = self;
    [self.controller lsqPresentModalNavigationController:controller animated:YES];
}

/**
 *  获取一个拍摄结果
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onTuSDKPFCamera:(TuSDKPFCameraViewController *)controller captureResult:(TuResult *)result;
{
    [controller dismissViewControllerAnimated:YES completion:nil];
    lsqLDebug(@"onTuSDKPFCamera: %@", result);
}

#pragma mark - TuComponentErrorDelegate
/**
 *  获取组件返回错误信息
 *
 *  @param controller 控制器
 *  @param result     返回结果
 *  @param error      异常信息
 */
- (void)onComponent:(TuComponentsViewController *)controller result:(TuResult *)result error:(NSError *)error;
{
    lsqLDebug(@"onComponent: controller - %@, result - %@, error - %@", controller, result, error);
}
@end

#pragma mark - CustomizedCameraController
/**
 *  基础相机组件范例 - 相机视图控制器
 */
@interface CustomizedCameraController()<TuSDKPFNormalFilterGroupDelegate>
{
    // 滤镜栏视图
    TuSDKPFNormalFilterGroupView *_filterBar;
}
@end

@implementation CustomizedCameraController
- (void)configDefaultStyleView:(TuSDKPFCameraView *)view;
{
    if (!view) return;
    [super configDefaultStyleView:view];
    
    UIButton *closeButton = [UIButton buttonWithFrame:CGRectMake(20, [view.bottomBar lsqGetCenterY:60] + 8, 60, 60)
                                                title:LSQString(@"lsq_cancel", @"取消") font:lsqFontSize(16)
                                                color:[UIColor whiteColor]];
    // 关闭摄像头按钮
    [closeButton addTouchUpInsideTarget:self action:@selector(cancelAction)];
    [view.bottomBar addSubview:closeButton];
}

/**
 *  创建滤镜栏视图
 *
 *  @param view 默认样式视图 (如需创建自定义视图，请覆盖该方法，并配置自己的视图类)
 */
- (void)buildFilterBar:(TuSDKPFCameraView *)view;
{
    // 滤镜栏视图
    _filterBar = [TuSDKPFNormalFilterGroupView initWithFrame:CGRectMake(0, 0, view.lsqGetSizeWidth, view.bottomBar.lsqGetOriginY)];
    _filterBar.filterBar.backgroundColor = [UIColor clearColor];
    
    // 配置滤镜栏视图
    [self configWithGroupFilterView:_filterBar];
    _filterBar.delegate = self;
    
    [view insertSubview:_filterBar belowSubview:view.bottomBar];
    // 设置是否默认显示滤镜栏
    [_filterBar setDefaultShowState:self.showFilterDefault];
    // 加载滤镜数据
    [_filterBar loadFilters];
    
    // 创建滤镜显示状态切换按钮
    [view.bottomBar buildFilterButton];
    [view.bottomBar.filterButton addTouchUpInsideTarget:_filterBar action:@selector(toggleBarShowState)];
}
#pragma mark - TuSDKPFEditTurnAndCutFilterDelegate
/**
 *  选中一个滤镜
 *
 *  @param view 裁剪与缩放控制器滤镜视图
 *  @param item 滤镜分组元素
 *
 *  @return 是否允许继续执行
 */
- (BOOL)onTuSDKPFNormalFilterGroup:(TuSDKPFNormalFilterGroupView *)view
                         selectedItem:(TuGroupFilterItem *)item;
{
    if (item.type == TuGroupFilterItemFilter) {
        SelesParameters * param = [self onSelectedFilterCode:[item filterCode]];
        return param != nil;
    }
    return YES;
}
@end
#pragma mark - CustomizedCameraView
/**
 *  基础相机组件范例视图自定义
 */
@implementation CustomizedCameraView
// 初始化视图
- (void)lsqInitView;
{
    [super lsqInitView];
    
    // 默认相机控制栏视图
    [_configBar lsqSetSizeHeight:44];
    _configBar.closeButton.hidden = YES;
}
@end

#pragma mark - CustomizedCameraFilterItemCell
/**
 *  基础相机组件范例视图 滤镜行视图
 */
@implementation CustomizedCameraFilterItemCell
- (void)lsqInitView;
{
    [super lsqInitView];

    // 标题视图
    _titleView.hidden = YES;
}

-(id)lsqSetSize:(CGSize)size;
{
    [super lsqSetSize:size];
    
    // 图片视图
    _thumbView.frame = _wrapView.bounds;
    // 标题视图
    _titleView.hidden = YES;
    return self;
}
@end
