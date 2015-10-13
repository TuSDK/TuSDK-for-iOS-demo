//
//  TuSDKTSAVCaptureDevice+Extend.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/2.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

/**
 *  硬件设备扩展
 */
@interface AVCaptureDevice(TuSDKTSAVCaptureDeviceExtend)
#pragma mark - Camera
/**
 *  测试系统摄像头授权状态
 *
 *  @return 系统摄像头是否授权
 */
+ (BOOL)hasVideoAuthor;

/**
 *  相机设备总数
 *
 *  @return 相机设备总数
 */
+ (int)cameraCounts;

/**
 *  如果不支持摄像头显示警告信息
 *
 *  @param controller UIViewController
 *
 *  @return 是否显示警告
 */
+ (BOOL)showAlertIfNotSupportCameraWithController:(UIViewController *)controller;

/**
 *  获取相机设备标识（前置或后置） 后置优先
 *
 *  @return 相机设备标识
 */
+ (AVCaptureDevicePosition)firstBackCameraPosition;

/**
 *  获取相机设备标识（前置或后置） 前置优先
 *
 *  @return 相机设备标识
 */
+ (AVCaptureDevicePosition)firstFrontCameraPosition;

/**
 *  获取相机设备（前置或后置） 后置优先
 *
 *  @return 相机设备
 */
+ (AVCaptureDevice *)getBackOrFrontCamera;

/**
 *  获取相机设备
 *
 *  @param type 获取相机设备标识
 *
 *  @return 相机设备
 */
+ (AVCaptureDevice *)getCameraWithType:(AVCaptureDevicePosition)type;

/**
 *  转换触摸点为相机聚焦点坐标
 *
 *  @param point    触摸点百分比坐标
 *  @param position 相机前后置
 *  @param orient   相机方向
 *
 *  @return 相机聚焦点坐标
 */
+ (CGPoint)convertPoint:(CGPoint)point
           withPosition:(AVCaptureDevicePosition)position
 outputImageOrientation:(UIInterfaceOrientation)orient;
@end
