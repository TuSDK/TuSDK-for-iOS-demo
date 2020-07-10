//
//  FaceDetectionVideoSample.m
//  TuSDKDemo
//
//  Created by Clear Hu on 16/3/11.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "FaceDetectionVideoSample.h"
#import "TuFaceDetectionFocusTouchView.h"

/**
 *  人脸检测 视频
 */
@interface FaceDetectionVideoSample()<TuSDKPFCameraDelegate>

@end

@implementation FaceDetectionVideoSample
- (instancetype)init;
{
    self = [super initWithGroupId:APISample title:NSLocalizedString(@"sample_api_face_detection_camera", @"人脸检测 (视频)")];
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
    // @see-https://tutucloud.com/docs/ios/image/image/api-geev1/Classes/TuSDKPFCameraOptions.html
    TuSDKPFCameraOptions *opt = [TuSDKPFCameraOptions build];
    
    // 聚焦触摸视图类 (默认:TuSDKCPFocusTouchView, 需要继承 TuSDKCPFocusTouchView)
    opt.focusTouchViewClazz = [TuFaceDetectionFocusTouchView class];
    // 摄像头前后方向 (默认为后置优先)
    opt.cameraPostion = [AVCaptureDevice lsqFirstFrontCameraPosition];
    
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
    
    // 是否保存最后一次使用的滤镜
    opt.saveLastFilter = YES;
    
    // 自动选择分组滤镜指定的默认滤镜
    opt.autoSelectGroupDefaultFilter = YES;
    
    // 开启滤镜配置选项
    opt.enableFilterConfig = NO;
    
    // 视频视图显示比例类型 (默认:lsqRatioDefault, 如果设置cameraViewRatio > 0, 将忽略ratioType)
    opt.ratioType = lsqRatioDefault;
    
    // 是否开启长按拍摄 (默认: NO)
    opt.enableLongTouchCapture = YES;
    
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuSDKResult.asset)
    opt.saveToAlbum = YES;
    
    // 视频覆盖区域颜色 (默认：[UIColor clearColor])
    opt.regionViewColor = [UIColor lsqClorWithHex:@"#403e43"];
    
    // 是否显示辅助线 (默认: false)
    opt.displayGuideLine = false;
    
    // 是否开启脸部追踪
    opt.enableFaceDetection = NO;
    
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
- (void)onTuSDKPFCamera:(TuSDKPFCameraViewController *)controller captureResult:(TuSDKResult *)result;
{
    [controller dismissViewControllerAnimated:YES completion:nil];
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
