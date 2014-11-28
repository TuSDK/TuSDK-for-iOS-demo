//
//  TuSDKPFCameraOptions.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/6.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import "TuSDKCPOptions.h"
#import "TuSDKPFCameraViewController.h"

/**
 *  默认相机视图控制器选项
 */
@interface TuSDKPFCameraOptions : TuSDKCPOptions
/**
 *  系统相机控制类  (默认: TuSDKPFCameraViewController，如需自定义请继承自 TuSDKPFCameraViewController)
 */
@property (nonatomic, strong) Class controllerClazz;

/**
 *  摄像头前后方向 (默认为后置优先)
 */
@property (nonatomic) AVCaptureDevicePosition cameraPostion;

/**
 *  闪光灯模式 (默认:AVCaptureFlashModeOff)
 */
@property (nonatomic) AVCaptureFlashMode cameraDefaultFlashMode;

/**
 *  摄像头分辨率模式 (默认：AVCaptureSessionPresetHigh)
 *  @see AVCaptureSession for acceptable values
 */
@property (nonatomic, copy) NSString *sessionPreset;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  保存到临时文件 (默认不保存, 当设置为YES时, TuSDKCaputorResult.tmpFile)
 */
@property (nonatomic) BOOL saveToTemp;

/**
 *  保存到系统相册 (默认不保存, 当设置为YES时, TuSDKCaputorResult.asset)
 */
@property (nonatomic) BOOL saveToAlbum;

/**
 *  保存到系统相册的相册名称
 */
@property (nonatomic, copy) NSString *saveToAlbumName;

/**
 *  创建系统相机控制器对象
 *
 *  @return 系统相机控制器对象
 */
- (TuSDKPFCameraViewController *)viewController;
@end
