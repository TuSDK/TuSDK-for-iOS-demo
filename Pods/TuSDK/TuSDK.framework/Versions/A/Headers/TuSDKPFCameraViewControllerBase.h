//
//  TuSDKPFCameraViewControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/7.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCPResultViewController.h"
#import "TuSDKVideoCameraInterface.h"

/**
 *  默认相机视图控制器基础类
 */
@interface TuSDKPFCameraViewControllerBase : TuSDKCPResultViewController<TuSDKStillCameraDelegate>
/**
 *  视频视图显示比例类型 (默认:lsqRatioDefault, 如果设置cameraViewRatio > 0, 将忽略ratioType)
 */
@property (nonatomic) lsqRatioType ratioType;
/**
 *  视频视图显示比例 (默认：0， 0 <= mRegionRatio, 当设置为0时全屏显示)
 */
@property (nonatomic) CGFloat cameraViewRatio;
/**
 *  相机对象
 */
@property (nonatomic, readonly) id<TuSDKStillCameraInterface> camera;

/** 相机视图 */
@property (nonatomic, readonly) UIView *cameraView;

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
 *  开始启动相机
 */
- (void)startCamera;

/**
 *  销毁相机
 */
- (void)destoryCamera;

/**
 *  获取当前比例
 *
 *  @return 当前比例
 */
- (CGFloat)getCurrentRatio;

/**
 *  设置当前比例类型
 *
 *  @param ratioType 比例类型
 */
- (void)setCurrentRatioType:(lsqRatioType)ratioType;

/**
 *  闪光灯模式
 *
 *  @param flashMode 闪光灯模式
 */
-(void)setFlashMode:(AVCaptureFlashMode)flashMode;

/**
 *  手动设置相机比例
 *
 *  @param sender
 */
- (void)onCameraRatioChange:(id)sender;

/**
 *  设置辅助线显示状态
 *
 *  @param isShow 是否显示辅助线
 */
- (void)setGuideLineViewState:(BOOL)isShow;

/**
 *  是音量键拍摄
 *
 *  @param isEnableCaptureWithVolumeKeys 是否开启音量键拍摄
 */
- (void)setEnableCaptureWithVolumeKeys:(BOOL)isEnableCaptureWithVolumeKeys;

/**
 *  获取辅助线显示状态
 */
- (BOOL)getGuideLineViewState;

/**
 *  按音量键拍摄
 */
- (void)onCapturePhotoWithVolume;
@end