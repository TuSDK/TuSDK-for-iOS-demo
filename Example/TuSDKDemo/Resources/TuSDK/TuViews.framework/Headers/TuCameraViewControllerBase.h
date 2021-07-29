//
//  TuCameraViewControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/7.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuResultViewController.h"
#import "TuFocusTouchViewBase.h"
//#import "TuSDKPulseCore/components/widgets/TuRegionHandler.h"
//#import "TuSDKPulseCore/cx/seles/extend/SelesParameters.h"
#import "TuCAEAGLView.h"
#import "TuCamera/TuCamera.h"
#import "TuCameraShower.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>



/**
 *  默认相机视图控制器基础类
 */
@interface TuCameraViewControllerBase : TuResultViewController<TuCameraDelegate, TuCameraShotDelegate>
{
    @protected
    BOOL _isShowAllSetRatio; // 是否显示所有设置的比例(默认剔除和屏幕相同比例)
}
/**
 *  视图显示比例类型列表 ( 优先级 ratioTypeList > ratioType, 默认：lsqTuSDKRatioDefaultTypes)
 *
 *  设置 NSNumber 型数组来控制显示的按钮顺序， 例如:
 *    @[@(lsqRatioOrgin), @(lsqRatio_1_1), @(lsqRatio_2_3), @(lsqRatio_3_4)]
 *
 */
@property (nonatomic) NSArray<NSNumber *> *ratioTypeList;
// 支持的显示比例列表
@property (nonatomic) NSArray<NSNumber *> *ratioTypes;
// 摄像头分辨率模式 (默认：AVCaptureSessionPresetHigh)
@property (nonatomic, copy) NSString *sessionPreset;
// 摄像头前后方向 (默认为后置优先)
@property (nonatomic) AVCaptureDevicePosition avPostion;
// 设置闪光灯模式
@property (nonatomic) AVCaptureFlashMode flashMode;
// 视频视图显示比例类型 (默认:lsqRatioDefault, 如果设置cameraViewRatio > 0, 将忽略ratioType)
@property (nonatomic) lsqRatioType ratioType;
// 当前比例类型
@property (nonatomic) lsqRatioType currentRatioType;
// 获取当前比例
@property (nonatomic, readonly) CGFloat currentRatio;
// 是否开启音量键拍摄
@property (nonatomic) BOOL enableCaptureWithVolumeKeys;
// 视频视图显示比例 (默认：0， 0 <= mRegionRatio, 当设置为0时全屏显示)
@property (nonatomic) CGFloat cameraViewRatio;
// 相机对象
@property (nonatomic, readonly) TuCamera * camera;
// 相机视图
@property (nonatomic, readonly) UIView* cameraView;
// GL视图
//@property (nonatomic, readonly) UIView<TuCAEAGLViewInterface>* surfaceView;
// 聚焦触摸视图
@property (nonatomic, readonly) TuFocusTouchViewBase* focusTouchView;
// 选区范围算法
@property (nonatomic, strong) id<TuRegionHandler> regionHandler;
// 处理相机焦距变化
@property (nonatomic) float focalDistance;
// 视频覆盖区域颜色 (默认：[UIColor blackColor])
@property (nonatomic, strong) UIColor *displayBackgroundColor;
// 开始启动相机
- (void)startCamera;
// 停止相机
- (void)stopCamera;
// 暂停相机
- (void)pauseCamera;
// 恢复相机
- (void)resumePreview;
// 销毁相机
- (void)destoryCamera;
// 配置相机参数
- (void)configCamera:(TuCamera *)camera;
// 切换滤镜
- (SelesParameters *)handleSwitchFilter:(NSString *)code;
// 按音量键拍摄
- (void)onCapturePhotoWithVolume;
// 切换相机显示比例
- (void)handleNextCameraRatio;
// 切换相机显示比例
- (void)handleCameraRatio;
// 添加缩放手势，用于调整焦距
- (void)addPinchGesture;
@end
