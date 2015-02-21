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
     *  正在启动
     */
    lsqCameraStateStarting = 1,
    /**
     *  启动完成
     */
    lsqCameraStateStarted = 2,
    /**
     * 正在拍摄
     */
    lsqCameraStateCapturing = 3,
    /**
     * 拍摄完成
     */
    lsqCameraStateCaptured = 4
};

/**
 *  相机聚焦触摸视图
 */
@class TuSDKCPFocusTouchView;

/**
 *  相机对象
 */
@class TuSDKStillCamera;

/**
 *  相机事件委托
 */
@protocol TuSDKStillCameraDelegate <NSObject>
/**
 *  相机状态改变 (如需操作UI线程， 请检查当前线程是否为主线程)
 *
 *  @param camera 相机对象
 *  @param state  相机运行状态
 */
- (void)onCamera:(TuSDKStillCamera *)camera stateChanged:(lsqCameraState)state;

/**
 *  获取拍摄图片 (如需操作UI线程， 请检查当前线程是否为主线程)
 *
 *  @param camera 相机对象
 *  @param result 获取的结果
 *  @param error  错误信息
 */
- (void)onCamera:(TuSDKStillCamera *)camera takedResult:(TuSDKResult *)result error:(NSError *)error;
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
 *  是否已注册聚焦事件
 */
@property (nonatomic) BOOL isResgisterFocusEvent;

/**
 *  是否正在切换滤镜
 */
@property (nonatomic, readonly) BOOL isFilterChanging;

/**
 *  开启滤镜配置选项
 */
@property (nonatomic) BOOL enableFilterConfig;

/**
 *  是否开启长按拍摄 (默认: NO)
 */
@property (nonatomic) BOOL enableLongTouchCapture;

/**
 *  开启持续自动对焦 (默认: NO)
 */
@property (nonatomic) BOOL enableContinueFoucs;

/**
 *  自动聚焦延时 (默认: 5秒)
 */
@property (nonatomic) NSTimeInterval autoFoucsDelay;

/**
 *  长按延时 (默认: 1.2秒)
 */
@property (nonatomic) NSTimeInterval longTouchDelay;

/**
 *  视频视图显示比例 (默认：0， 0 <= mRegionRatio, 当设置为0时全屏显示)
 */
@property (nonatomic) CGFloat cameraViewRatio;

/**
 *  视频覆盖区域颜色 (默认：[UIColor blackColor])
 */
@property (nonatomic, retain) UIColor *regionViewColor;

/**
 *  照片输出分辨率
 */
@property (nonatomic) CGSize outputSize;

/**
 *  禁用前置摄像头自动水平镜像 (默认: NO，前置摄像头拍摄结果自动进行水平镜像)
 */
@property (nonatomic) BOOL disableMirrorFrontFacing;

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
 *  @param code 滤镜代号
 *
 *  @return 是否成功切换滤镜
 */
- (BOOL)switchFilterWithCode:(NSString *)code;

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
- (void)bindFocusTouchView:(TuSDKCPFocusTouchView *)view;

/**
 *  改变视频视图显示比例 (使用动画)
 *
 *  @param regionRatio 范围比例
 */
- (void)changeCameraViewRatio:(CGFloat)cameraViewRatio;

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
 *  当前聚焦状态
 *
 *  @param isFocusing 是否正在聚焦
 */
- (void)onAdjustingFocus:(BOOL)isFocusing;

/**
 *  销毁
 */
- (void)destory;
@end
