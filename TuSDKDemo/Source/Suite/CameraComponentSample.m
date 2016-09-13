//
//  CameraComponentSample.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "CameraComponentSample.h"

/**
 *  相机组件范例
 */
@interface CameraComponentSample()<TuSDKPFCameraDelegate>

@end

@implementation CameraComponentSample
- (instancetype)init;
{
    self = [super initWithGroupId:SuiteSample title:NSLocalizedString(@"sample_CameraComponent", @"相机组件")];
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
    
    // 开启访问相机权限
    [TuSDKTSDeviceSettings checkAllowWithController:self.controller
                                               type:lsqDeviceSettingsCamera
                                          completed:^(lsqDeviceSettingsType type, BOOL openSetting)
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
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKPFCameraOptions.html
    TuSDKPFCameraOptions *opt = [TuSDKPFCameraOptions build];
    
    // 视图类 (默认:TuSDKPFCameraView, 需要继承 TuSDKPFCameraView)
    // opt.viewClazz = [TuSDKPFCameraView class];
    
    // 默认相机控制栏视图类 (默认:TuSDKPFCameraConfigView, 需要继承 TuSDKPFCameraConfigView)
    // opt.configBarViewClazz = [TuSDKPFCameraConfigView class];
    
    // 默认相机底部栏视图类 (默认:TuSDKPFCameraBottomView, 需要继承 TuSDKPFCameraBottomView)
    // opt.bottomBarViewClazz = [TuSDKPFCameraBottomView class];
    
    // 闪光灯视图类 (默认:TuSDKPFCameraFlashView, 需要继承 TuSDKPFCameraFlashView)
    // opt.flashViewClazz = [TuSDKPFCameraFlashView class];
    
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
    
    // 默认是否显示滤镜视图 (默认: 不显示, 如果enableFilters = NO, showFilterDefault将失效)
    opt.showFilterDefault = YES;
    
    // 开启滤镜历史记录
    opt.enableFilterHistory = YES;
    
    // 开启在线滤镜
    opt.enableOnlineFilter = YES;
    
    // 显示滤镜标题视图
    opt.displayFilterSubtitles = YES;
    
    // 滤镜列表行视图宽度
    // opt.filterBarCellWidth = 60;
    
    // 滤镜列表选择栏高度
    // opt.filterBarHeight = 80;
    
    // 滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
    // opt.filterBarGroupCellClazz = [TuSDKCPGroupFilterGroupCell class];
    
    // 滤镜列表行视图类 (默认:TuSDKCPGroupFilterItemCell, 需要继承 TuSDKCPGroupFilterItemCell)
    // opt.filterBarTableCellClazz = [TuSDKCPGroupFilterItemCell class];
    
    // 需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
    // 滤镜名称参考 TuSDK.bundle/others/lsq_tusdk_configs.json
    // filterGroups[]->filters[]->name lsq_filter_%{Brilliant}
    // opt.filterGroup = @[@"SkinNature", @"SkinPink", @"SkinJelly", @"SkinNoir", @"SkinRuddy", @"SkinPowder", @"SkinSugar"];
    
    // 是否保存最后一次使用的滤镜
    opt.saveLastFilter = YES;
    
    // 自动选择分组滤镜指定的默认滤镜
    opt.autoSelectGroupDefaultFilter = YES;
    
    // 开启滤镜配置选项
    opt.enableFilterConfig = NO;
    
    // 视频视图显示比例 (默认：0， 0 <= mRegionRatio, 当设置为0时全屏显示)
    // opt.cameraViewRatio = 0.75f;
    
    // 视频视图显示比例类型 (默认:lsqRatioDefault, 如果设置cameraViewRatio > 0, 将忽略ratioType)
    // opt.ratioType = lsqRatioDefault;
    
    // 是否开启长按拍摄 (默认: NO)
    opt.enableLongTouchCapture = YES;
    
    // 禁用持续自动对焦 (默认: NO)
    // opt.disableContinueFoucs = YES;
    
    // 自动聚焦延时 (默认: 5秒)
    // opt.autoFoucsDelay = 5;
    
    // 长按延时 (默认: 1.2秒)
    // opt.longTouchDelay = 1.2;
    
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuSDKResult.asset)
    opt.saveToAlbum = YES;
    
    // 保存到临时文件 (默认不保存, 当设置为YES时, TuSDKResult.tmpFile)
    // opt.saveToTemp = NO;
    
    // 保存到系统相册的相册名称
    // opt.saveToAlbumName = @"TuSdk";
    
    // 照片输出压缩率 0-1 如果设置为0 将保存为PNG格式 (默认: 0.95)
    // opt.outputCompress = 0.95f;
    
    // 视频覆盖区域颜色 (默认：[UIColor clearColor])
    opt.regionViewColor = [UIColor lsqClorWithHex:@"#403e43"];
    
    // 照片输出分辨率
    // opt.outputSize = CGSizeMake(1440, 1920);
    
    // 禁用前置摄像头自动水平镜像 (默认: NO，前置摄像头拍摄结果自动进行水平镜像)
    // opt.disableMirrorFrontFacing = YES;
    
    // 是否显示辅助线 (默认: false)
    opt.displayGuideLine = false;
    
    // 是否开启脸部追踪
    opt.enableFaceDetection = YES;
    
    // 设置水印选项 (默认为空，如果设置不为空，则输出的图片上将带有水印)
    // opt.waterMarkOption = [self waterMarkOption];
    
    // 是否允许音量键拍照 (默认关闭)
    opt.enableCaptureWithVolumeKeys = YES;
    
    TuSDKPFCameraViewController *controller = opt.viewController;
    // 添加委托
    controller.delegate = self;
    [self.controller presentModalNavigationController:controller animated:YES];
}

/**
 *  相机水印
 *
 *  @return
 */
- (TuSDKWaterMarkOption *)waterMarkOption;
{
    TuSDKWaterMarkOption *option = [[TuSDKWaterMarkOption alloc] init];
    
    // 水印文字或者图片需要至少设置一个
    // 设置水印文字
    option.markText = @"";
    
    // 设置水印文字颜色
    option.markTextColor = [UIColor whiteColor];
    
    // 文字大小 (默认: 24 SP)
    option.markTextSize = 24;
    
    // 文字阴影颜色 (默认:[UIColor grayColor])
    option.markTextShadowColor = [UIColor grayColor];
    
    // 设置水印图片
    option.markImage = [UIImage imageNamed:@"sample_watermark.png"];
    
    // 文字和图片顺序 (仅当图片和文字都非空时生效，默认: 文字在右)
    option.markTextPosition = lsqMarkTextPositionRight;

    // 设置水印位置 (默认: lsqWaterMarkBottomRight)
    option.markPosition = lsqWaterMarkBottomRight;
    
    // 设置水印距离图片边距 (默认: 6dp)
    option.markMargin = 6;
    
    // 文字和图片间距 (默认: 2dp)
    option.markTextPadding = 5;
    
    return option;
}

/**
 *  获取一个拍摄结果
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onTuSDKPFCamera:(TuSDKPFCameraViewController *)controller captureResult:(TuSDKResult *)result;
{
    [controller dismissModalViewControllerAnimated:YES];
    lsqLDebug(@"onTuSDKPFCamera: %@", result);
}

#pragma mark - TuSDKCPComponentErrorDelegate
/**
 *  获取组件返回错误信息
 *
 *  @param controller 控制器
 *  @param result     返回结果
 *  @param error      异常信息
 */
- (void)onComponent:(TuSDKCPViewController *)controller result:(TuSDKResult *)result error:(NSError *)error;
{
    lsqLDebug(@"onComponent: controller - %@, result - %@, error - %@", controller, result, error);
}
@end
