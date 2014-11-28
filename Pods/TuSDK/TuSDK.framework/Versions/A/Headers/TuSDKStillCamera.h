//
//  TuSDKStillCamera.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/27.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKResult.h"

/**
 *  滤镜类型
 */
typedef NS_ENUM(NSInteger, lsqCameraState)
{
    /**
     *  未知
     */
    lsqCameraStateUnknow = 0,
    /**
     *  内部集成
     */
    lsqCameraStateStarting = 1,
    /**
     *  内部集成
     */
    lsqCameraStateStarted = 2,
};

/**
 *  相机事件委托
 */
@protocol TuSDKStillCameraDelegate <NSObject>
/**
 *  获取拍摄图片 （当执行正确时，为异步线程）
 *
 *  @param result 相机拍摄结果
 *  @param error  错误信息
 */
- (void)onTuSDKStillCameraCaputorWithResult:(TuSDKResult *)result error:(NSError *)error;

@optional
/**
 *  相机已启动
 */
- (void)onTuSDKStillCameraStarted;
@end

/**
 *  相机对象
 */
@interface TuSDKStillCamera : GPUImageStillCamera

/**
 *  相机事件委托
 */
@property (nonatomic, assign) id<TuSDKStillCameraDelegate> captureDelegate;

/**
 *  相机状态
 */
@property (nonatomic, readonly) lsqCameraState state;

/**
 *  是否正在切换滤镜
 */
@property (nonatomic, readonly) BOOL isFilterChanging;

/**
 *  初始化相机
 *
 *  @param sessionPreset  相机分辨率类型
 *  @param cameraPosition 相机设备标识 （前置或后置）
 *  @param cameraView     相机显示容器视图
 *
 *  @return 相机对象
 */
+ (instancetype)initWithSessionPreset:(NSString *)sessionPreset cameraPosition:(AVCaptureDevicePosition)cameraPosition cameraView:(UIView *)view;

/**
 *  尝试启动相机
 */
- (void)tryStartCameraCapture;
#pragma mark - filter
/**
 *  切换滤镜
 *
 *  @param name 滤镜名称
 */
- (void)switchFilterWithName:(NSString *)name;

#pragma mark - Flash
/**
 *  是否存在闪关灯
 *
 *  @return 是否存在闪关灯
 */
- (BOOL)hasFlash;

/**
 *  设置闪光灯模式
 *  @see AVCaptureFlashMode
 *
 *  @param flashMode 设置闪光灯模式
 */
- (void)flashWithMode:(AVCaptureFlashMode)flashMode;

#pragma mark - Focus
/**
 *  绑定聚焦触摸视图
 *
 *  @param view 聚焦触摸视图
 */
- (void)bindFocusTouchView:(UIView *)view;

/**
 *  设置聚焦模式
 *
 *  @param focusMode 聚焦模式
 *
 *  @return 是否支持对焦
 */
- (BOOL)focusWithMode:(AVCaptureFocusMode)focusMode;

/**
 *  设置聚焦模式
 *
 *  @param focusMode 聚焦模式
 *  @param point     聚焦坐标
 *
 *  @return 是否支持对焦
 */
- (BOOL)focusWithMode:(AVCaptureFocusMode)focusMode point:(CGPoint)point;

/**
 *  是否支持对焦
 *
 *  @param focusMode 对焦模式
 *
 *  @return 是否支持对焦
 */
- (BOOL)isSupportFocusWithMode:(AVCaptureFocusMode)focusMode;

/**
 *  设置曝光模式
 *
 *  @param exposureMode 曝光模式
 *
 *  @return 是否支持曝光模式
 */
- (BOOL)exposureWithMode:(AVCaptureExposureMode)exposureMode;

/**
 *  设置曝光模式
 *
 *  @param focusMode 曝光模式
 *  @param point     曝光坐标
 *
 *  @return 是否支持曝光模式
 */
- (BOOL)exposureWithMode:(AVCaptureExposureMode)exposureMode point:(CGPoint)point;

/**
 *  是否支持曝光模式
 *
 *  @param focusMode 曝光模式
 *
 *  @return 是否支持曝光模式
 */
- (BOOL)isSupportExposureWithMode:(AVCaptureExposureMode)exposureMode;

/**
 *  开始获取照片
 */
-(void)captureImage;

/**
 *  销毁
 */
- (void)destory;
@end
