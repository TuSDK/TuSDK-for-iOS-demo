//
//  SimpleCameraAndEditCutComponent.m
//  TuSDKDemo
//
//  Created by Lasque on 15/8/5.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "SimpleCameraAndEditCutComponent.h"

/**
 *  相机连接图片编辑组件
 */
@interface SimpleCameraAndEditCutComponent()<TuSDKPFCameraDelegate,TuSDKPFEditTurnAndCutDelegate>
{
}
@end

@implementation SimpleCameraAndEditCutComponent



- (instancetype)init;
{
    self = [super initWithGroupId:2 title:NSLocalizedString(@"simple_CameraAndEditCutComponent", @"相机连接图片编辑组件")];
    return self;
}


/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSimpleWithController:(UIViewController *)controller;
{
    if (!controller) return;
    self.controller = controller;
    
    // 开启访问相机权限
    [TuSDKTSDeviceSettings checkAllowWithType:lsqDeviceSettingsCamera
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
    // opt.avPostion = [AVCaptureDevice firstBackCameraPosition];
    
    // 设置分辨率模式
    // opt.sessionPreset = AVCaptureSessionPresetHigh;
    
    // 闪光灯模式 (默认:AVCaptureFlashModeOff)
    // opt.defaultFlashMode = AVCaptureFlashModeOff;
    
    // 是否开启滤镜支持 (默认: 关闭)
    // opt.enableFilters = NO;
    
    // 默认是否显示滤镜视图 (默认: 不显示, 如果enableFilters = NO, showFilterDefault将失效)
    // opt.showFilterDefault = NO;
    
    // 滤镜列表行视图宽度
    // opt.filterBarCellWidth = 75;
    
    // 滤镜列表选择栏高度
    // opt.filterBarHeight = 100;
    
    // 滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
    // opt.filterBarGroupCellClazz = [TuSDKCPGroupFilterGroupCell class];
    
    // 滤镜列表行视图类 (默认:TuSDKCPGroupFilterItemCell, 需要继承 TuSDKCPGroupFilterItemCell)
    // opt.filterBarTableCellClazz = [TuSDKCPGroupFilterItemCell class];
    
    // 需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
    // 滤镜名称参考 TuSDK.bundle/others/lsq_tusdk_configs.json
    // filterGroups[]->filters[]->name lsq_filter_%{Brilliant}
    // opt.filterGroup = @[@"SkinNature", @"SkinPink", @"SkinJelly", @"SkinNoir", @"SkinRuddy", @"SkinPowder", @"SkinSugar"];
    
    // 是否保存最后一次使用的滤镜
    // opt.saveLastFilter = YES;
    
    // 自动选择分组滤镜指定的默认滤镜
    // opt.autoSelectGroupDefaultFilter = YES;
    
    // 开启滤镜配置选项
    // opt.enableFilterConfig = YES;
    
    // 视频视图显示比例 (默认：0， 0 <= mRegionRatio, 当设置为0时全屏显示)
    // opt.cameraViewRatio = 0.75f;
    
    // 视频视图显示比例类型 (默认:lsqRatioAll, 如果设置cameraViewRatio > 0, 将忽略ratioType)
    // opt.ratioType = lsqRatioAll;
    
    // 是否开启长按拍摄 (默认: NO)
    opt.enableLongTouchCapture = YES;
    
    // 开启持续自动对焦 (默认: NO)
    opt.enableContinueFoucs = YES;
    
    // 自动聚焦延时 (默认: 5秒)
    // opt.autoFoucsDelay = 5;
    
    // 长按延时 (默认: 1.2秒)
    // opt.longTouchDelay = 1.2;
    
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuSDKResult.asset)
    // opt.saveToAlbum = NO;
    
    // 保存到临时文件 (默认不保存, 当设置为YES时, TuSDKResult.tmpFile)
    // opt.saveToTemp = NO;
    
    // 保存到系统相册的相册名称
    // opt.saveToAlbumName = @"TuSdk";
    
    // 照片输出压缩率 0-1 如果设置为0 将保存为PNG格式 (默认: 0.95)
    // opt.outputCompress = 0.95f;
    
    // 视频覆盖区域颜色 (默认：[UIColor clearColor])
    // opt.regionViewColor = lsqRGB(51, 51, 51);
    
    // 照片输出分辨率
    // opt.outputSize = CGSizeMake(1440, 1920);
    
    // 禁用前置摄像头自动水平镜像 (默认: NO，前置摄像头拍摄结果自动进行水平镜像)
    // opt.disableMirrorFrontFacing = YES;
    
    TuSDKPFCameraViewController *controller = opt.viewController;
    // 添加委托
    controller.delegate = self;
    [self.controller presentModalNavigationController:controller animated:YES];
}

/**
 *  获取一个拍摄结果
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onTuSDKPFCamera:(TuSDKPFCameraViewController *)controller captureResult:(TuSDKResult *)result;
{
    //    [controller dismissModalViewControllerAnimated:YES];
    lsqLDebug(@"onTuSDKPFCamera: %@", result);
    
    [self openEditAndCutWithController:(UIViewController *)controller
                                result:(TuSDKResult *)result];
}


/**
 *  开启图片编辑组件 (裁剪)
 *
 *  @param controller 来源控制器
 *  @param result     处理结果
 */
- (void)openEditAndCutWithController:(UIViewController *)controller
                              result:(TuSDKResult *)result;
{
    if (!controller || !result) return;
    
    // 组件选项配置
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKPFEditTurnAndCutOptions.html
    TuSDKPFEditTurnAndCutOptions *opt = [TuSDKPFEditTurnAndCutOptions build];
    
    // 是否开启滤镜支持 (默认: 关闭)
    opt.enableFilters = YES;
    
    // 开启用户滤镜历史记录
    opt.enableFilterHistory = YES;
    
    // 需要裁剪的长宽
    opt.cutSize = CGSizeMake(640, 640);
    
    // 是否显示处理结果预览图 (默认：关闭，调试时可以开启)
    opt.showResultPreview = NO;
    
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuSDKResult.asset)
    opt.saveToAlbum = YES;
    
    // 保存到系统相册的相册名称
    // opt.saveToAlbumName = @"TuSdk";
    
    TuSDKPFEditTurnAndCutViewController *tcController = opt.viewController;
    // 添加委托
    tcController.delegate = self;
    
    // 处理图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    tcController.inputImage = result.image;
    tcController.inputTempFilePath = result.imagePath;
    tcController.inputAsset = result.imageAsset;
    
    [controller.navigationController pushViewController:tcController animated:YES];
}

/**
 *  图片编辑完成
 *
 *  @param controller 旋转和裁剪视图控制器
 *  @param result 旋转和裁剪视图控制器处理结果
 */
- (void)onTuSDKPFEditTurnAndCut:(TuSDKPFEditTurnAndCutViewController *)controller result:(TuSDKResult *)result;
{
    // 清除所有控件
    [controller dismissModalViewControllerAnimated];
    lsqLDebug(@"onTuSDKPFEditTurnAndCut: %@", result);
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

