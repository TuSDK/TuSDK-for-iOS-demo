//
//  TuCamera.h
//  TuSDK
//
//  Created by Clear Hu on 2020/4/22.
//  Copyright © 2020 tusdk.com. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
@class TuResult;


// 相机状态
typedef NS_ENUM(NSInteger, TuCameraState)
{
    TuCameraState_START,        /** 相机启动 */
    TuCameraState_START_PREVIEW,/** 启动预览 */
    TuCameraState_PAUSE_PREVIEW,/** 暂停预览 */
    TuCameraState_PREPARE_SHOT, /** 准备捕捉相片 */
    TuCameraState_SHOTED,       /** 捕捉完成 */
    TuCameraState_STOP          /** 停止 */
};

@class TuCamera;

@protocol TuCameraDelegate<NSObject>
- (void)onTuCameraStatusChanged:(TuCameraState)status camera:(TuCamera *)camera;
@end

@protocol TuCameraMetadataOutputFaceDelegate<NSObject>
- (void)onTuCameraFaceOutput:(NSMutableArray<AVMetadataFaceObject*> *)faces
                 orientation:(AVCaptureVideoOrientation)orientation
                  isMirrored:(BOOL)isMirrored
                  resolution:(CGSize)resolution;
@end


// 相机视频帧输出委托
@protocol TuCameraVideoDataOutputDelegate<NSObject>

- (void)onTuCameraDidOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer;

///** 处理图片 */
- (UIImage *)processImage:(CMSampleBufferRef)sampleBuffer devicePosition:(AVCaptureDevicePosition)devicePosition;
@end

@protocol TuCameraAudioDataOutputDelegate<NSObject>

- (void)onTuCameraDidOutputAudioSampleBuffer:(CMSampleBufferRef)sampleBuffer;

- (void)onTuCameraDidOutputBufferList:(AudioBufferList)bufferList basicDescription:(AudioStreamBasicDescription)basicDescription timeStamp:(NSInteger)timeStamp;

- (void)onTuCameraDidOutputPlayBufferList:(AudioBufferList)bufferList;

@end


// 相机拍摄监听接口
@protocol TuCameraShotDelegate<NSObject>
@required
- (void)onTuCameraShotFailed:(NSError *)error; /** 拍摄照片失败 */
@optional
- (void)onTuCameraWillShot:(TuResult *)data; /** 相机即将开始拍摄 */
- (void)onTuCameraShotData:(TuResult *)data buffer:(CMSampleBufferRef)buffer;    /** 直接输出照片原始数据 TuSdkResult.imageData */
- (void)onTuCameraShotBitmap:(TuResult *)data; /** 直接UIImage TuSdkResult.image */
@end


// 相机接口
@interface TuCamera:NSObject
@property(nonatomic, readonly) TuCameraState status; /** 相机状态 */

@property(nonatomic) AVCaptureDevicePosition devicePosition; /** 相机前后位置 */

// 摄像头输出方向和镜像设置
@property(nonatomic, assign) AVCaptureVideoOrientation frontCameraOrientation;
@property(nonatomic, assign) BOOL frontCameraMirrored;
@property(nonatomic, assign) AVCaptureVideoOrientation backCameraOrientation;
@property(nonatomic, assign) BOOL backCameraMirrored;

@property(nonatomic) AVCaptureSessionPreset sessionPreset; /** 分辨率 */
@property(nonatomic) BOOL captureAsYUV; // 是否输出yuv数据
@property(nonatomic) NSInteger fps; /** 帧率 */

@property(nonatomic, readonly) CGSize outputResolution; /** 分辨率 */


// 焦距拉伸
@property(nonatomic) BOOL enableZoom;
@property(nonatomic) float maxZoomVal;
@property(nonatomic) float zoom;

// 闪光灯
@property(nonatomic, readonly) BOOL hasFlash;
@property(nonatomic) AVCaptureFlashMode flashMode;
- (BOOL)isFlashModeSupport:(AVCaptureFlashMode)mode;

@property(nonatomic, readonly) BOOL hasTorch;
@property(nonatomic) AVCaptureTorchMode torchMode;
- (BOOL)isTorchModeSupport:(AVCaptureTorchMode)mode;


// 白平衡
@property(nonatomic) AVCaptureWhiteBalanceMode whiteBalanceMode;
- (BOOL)isWhiteBalanceModeSupport:(AVCaptureWhiteBalanceMode)mode;

// 低光增强
@property(nonatomic) BOOL enableLowLightBoost;
- (BOOL)islowLightBoostSupported;

// 聚焦模式
@property(nonatomic, assign) BOOL allowFocusToShot; /** 是否允许使用聚焦拍摄 */
@property(nonatomic) BOOL enableAutoFocus; // 是否开启自动聚焦
@property(nonatomic) AVCaptureFocusMode focusMode;
- (BOOL)isFocusModeSupport:(AVCaptureFocusMode)mode;

// 曝光模式
@property(nonatomic) AVCaptureExposureMode exposureMode;
- (BOOL)isExposureModeSupport:(AVCaptureExposureMode)mode;
- (BOOL)setExposureBias:(float)percent;

// 拍摄
@property(nonatomic) BOOL outputImageData; /** 直接输出图像原始数据 */
@property(nonatomic) BOOL autoReleaseAfterCaptured; /** 自动释放相机在拍摄后 (节省手机内存, 需要手动再次启动) */
@property(nonatomic) BOOL disableCaptureSound; /** 禁用系统拍照声音 (默认:false) */


@property(nonatomic, weak) id<TuCameraDelegate> delegate;
@property(nonatomic, weak) id<TuCameraShotDelegate> shotDelegate; /** 相机拍摄监听接口 */
@property(nonatomic, weak) id<TuCameraVideoDataOutputDelegate> videoDataOutputDelegate;
@property(nonatomic, weak) id<TuCameraAudioDataOutputDelegate> audioDataOutputDelegate;
@property(nonatomic, weak) id<TuCameraMetadataOutputFaceDelegate> faceDetectDelegate; /** 系统人脸检测接口 */

@property(nonatomic, assign) float shotRegionRatio; /** 设置拍照的输出比例 **/
@property(nonatomic, assign) BOOL disableFocusBeep; /** 禁用聚焦声音 (默认：false) */

- (void)setFocusPoint:(CGPoint)point isTouched:(BOOL)isTouched; /** 设置聚焦区域 */

- (BOOL)prepare; /** 准备初始化相机 [是否初始化成功] */
- (BOOL)startPreview; /** 开始预览  [是否启动摄像头成功] */
- (BOOL)pausePreview; /** Pause camera preview [是否成功暂定预览] */
- (BOOL)resumePreview; /** Resume camera preview  [是否成功恢复预览] */
- (void)stopPreview; /** 停止预览 */
- (BOOL)shotPhoto; /** 拍摄照片 [是否开始拍摄] */

- (BOOL)rotateCamera; /** 切换前后摄像头 [是否启动摄像头成功] */

- (void)audioUnitRecord:(BOOL)isAudioUnit;
- (void)startAudioUnit;
- (void)stopAudioUnit;
- (void)resetAudioUnit;
//#################### new ####################
//@property (nonatomic, strong)TuCameraShot*      cameraShot;     /** 相机拍摄接口 */

@end
