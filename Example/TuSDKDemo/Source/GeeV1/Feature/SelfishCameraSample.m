//
//  SelfishCameraSample.m
//  TuSDKDemo
//
//  Created by Yanlin on 1/28/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import "SelfishCameraSample.h"

/**
 *  美颜自拍相机
 */

@interface SelfishCameraSample()<TuSDKPFCameraDelegate>

@end

@implementation SelfishCameraSample

- (instancetype)init;
{
    self = [super initWithGroupId:FeatureSample title:NSLocalizedString(@"sample_comp_SelfishCamera", @"美颜相机")];
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
    [TuTSDeviceSettings checkAllowWithController:controller
                                               type:TuDeviceSettingsCamera
                                          completed:^(TuDeviceSettingsType type, BOOL openSetting)
     {
         if (openSetting) {
             lsqLError(@"Can not open camera");
             return;
         }
         [self showCamera];
     }];
}

#pragma mark - showCamera

/**
 *  启动相机
 */
- (void)showCamera;
{
    // 组件选项配置
    // @see-https://tutucloud.com/docs/ios/image/image/api-geev1/Classes/TuSDKPFCameraOptions.html
    TuSDKPFCameraOptions *opt = [TuSDKPFCameraOptions build];
    
    // 使用前置摄像头
    opt.cameraPostion = AVCaptureDevicePositionFront;

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

    // 视频视图显示比例 (默认：0， 0 <= mRegionRatio, 当设置为0时全屏显示)
    // opt.cameraViewRatio = 0.75f;
    
    // 自定义滤镜列表，输入本地已有的滤镜编码即可
    // @see-https://tutucloud.com/docs/ios/image/self-customize-filter
    opt.filterGroup = @[@"SkinNature", @"SkinPink", @"SkinJelly", @"SkinNoir", @"SkinRuddy", @"SkinPowder", @"SkinSugar"];

    // 视频视图显示比例类型 (默认:lsqRatioDefault, 如果设置cameraViewRatio > 0, 将忽略ratioType)
    opt.ratioType = lsqRatioDefault;

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
    opt.outputCompress = 0;

    // 视频覆盖区域颜色 (默认：[UIColor clearColor])
    opt.regionViewColor = [UIColor lsqClorWithHex:@"#403e43"];

    // 照片输出分辨率
    // opt.outputSize = CGSizeMake(1440, 1920);

    // 禁用前置摄像头自动水平镜像 (默认: NO，前置摄像头拍摄结果自动进行水平镜像)
    // opt.disableMirrorFrontFacing = YES;

    // 是否显示辅助线 (默认: false)
    opt.displayGuideLine = YES;

    // 是否开启脸部追踪
    opt.enableFaceDetection = YES;

    TuSDKPFCameraViewController *controller = opt.viewController;
    // 添加委托
     controller.delegate = self;
    [self.controller lsqPresentModalNavigationController:controller animated:YES];
}

#pragma mark - TuSDKPFCameraDelegate

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
