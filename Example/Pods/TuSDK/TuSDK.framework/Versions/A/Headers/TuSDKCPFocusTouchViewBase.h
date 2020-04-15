//
//  TuSDKCPFocusTouchViewBase.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/29.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKVideoCameraInterface.h"

@interface TuSDKCPFocusTouchViewBase:UIView

@property (nonatomic, assign) id<TuSDKVideoCameraInterface> camera;

@property (nonatomic, assign) AVCaptureFocusMode focusMode;
@property (nonatomic, assign) BOOL disableContinueFoucs; // 禁用持续自动对焦 (默认: NO)

@property (nonatomic, assign) AVCaptureExposureMode exposureMode;
@property (nonatomic, assign) BOOL disableTapExposure; // 禁用手动曝光(默认: NO)

@property (nonatomic, assign) BOOL enableLongTouchCapture; // 是否开启长按拍摄 (默认: NO)

@property (nonatomic, assign) NSTimeInterval autoFoucsDelay; // 自动聚焦延时 (默认: 5秒)
@property (nonatomic, assign) NSTimeInterval longTouchDelay; // 长按延时 (默认: 1.2秒)
@property (nonatomic, assign) NSTimeInterval faceDetectionRate; // 脸部定位采样频率 (默认: 0.2秒)

@property (nonatomic, assign) CGRect regionPercent; // 显示区域百分比


- (void)cameraStateChanged:(lsqCameraState)state;
- (BOOL)onFocusWithPoint:(CGPoint)point isTouches:(BOOL)isTouches;

- (void)hiddenFaceViews;

- (void)notifyFaceDetection:(NSArray<TuSDKTSFaceFeature *> *)faces;
- (UIView *)buildFaceDetectionView;

@end
