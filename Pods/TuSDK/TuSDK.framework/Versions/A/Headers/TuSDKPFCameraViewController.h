//
//  TuSDKPFCameraViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/3.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKCPResultViewController.h"
#import "TuSDKStillCamera.h"
#import "TuSDKPFCameraView.h"

@class TuSDKPFCameraViewController;

/**
 *  默认相机视图控制器委托
 */
@protocol TuSDKPFCameraDelegate <NSObject>
/**
 *  获取一个拍摄结果
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onTuSDKPFCamera:(TuSDKPFCameraViewController *)controller captureResult:(TuSDKResult *)result;
@optional
/**
 *  获取一个拍摄结果 (异步方法)
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onAsyncTuSDKPFCamera:(TuSDKPFCameraViewController *)controller captureResult:(TuSDKResult *)result;
@end

/**
 *  默认相机视图控制器
 */
@interface TuSDKPFCameraViewController : TuSDKCPResultViewController<TuSDKStillCameraDelegate, TuSDKPFCameraViewDelegate, TuSDKPFCameraFilterDelegate>{
@protected
    // 默认样式视图
    TuSDKPFCameraView *_defaultStyleView;
    // 相机对象
    TuSDKStillCamera *_camera;
}

/**
 *  默认相机视图控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFCameraDelegate> delegate;

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFCameraView *defaultStyleView;

/**
 *  相机对象
 */
@property (nonatomic, readonly) TuSDKStillCamera *camera;

/**
 *  摄像头前后方向 (默认为后置优先)
 */
@property (nonatomic) AVCaptureDevicePosition avPostion;

/**
 *  摄像头分辨率模式 (默认：AVCaptureSessionPresetHigh)
 *  @see AVCaptureSession for acceptable values
 */
@property (nonatomic, copy) NSString *sessionPreset;

/**
 *  闪光灯模式 (默认:AVCaptureFlashModeOff)
 */
@property (nonatomic) AVCaptureFlashMode defaultFlashMode;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  创建默认样式视图 (如需创建自定义视图，请覆盖该方法，并创建自己的视图类)
 */
- (void)buildDefaultStyleView;

/**
 *  开始启动相机
 */
- (void)startCamera;

/**
 *  继续执行相机
 */
- (void)resumeCamera;

/**
 *  销毁相机
 */
- (void)destoryCamera;
@end
