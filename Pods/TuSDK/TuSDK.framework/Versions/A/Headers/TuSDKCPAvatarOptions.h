//
//  TuSDKCPAvatarOptions.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/1.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//
//    // 系统相册控制器配置选项
//    _albumOptions = [TuSDKPFAlbumOptions build];
//
//    // 相册照片列表控制器配置选项
//    _photosOptions = [TuSDKPFPhotosOptions build];
//
//    // 默认相机视图控制器选项
//    _cameraOptions = [TuSDKPFCameraOptions build];
//    // 是否开启滤镜支持 (默认: 开启)
//    _cameraOptions.enableFilters = YES;
//    // 摄像头前后方向 (默认为前置)
//    _cameraOptions.cameraPostion = [AVCaptureDevice firstFrontCameraPosition];
//    // 保存到临时文件 (默认不保存, 当设置为YES时, TuSDKResult.tmpFile)
//    _cameraOptions.saveToTemp = YES;
//    // 是否开启长按拍摄 (默认: NO)
//    _cameraOptions.enableLongTouchCapture = YES;
//    // 开启持续自动对焦 (默认: NO)
//    _cameraOptions.enableContinueFoucs = YES;
//
//    // 旋转和裁剪视图控制器配置选项
//    _editTurnAndCutOptions = [TuSDKPFEditTurnAndCutOptions build];
//    // 是否开启滤镜支持 (默认: 开启)
//    _editTurnAndCutOptions.enableFilters = YES;
//    // 需要裁剪的长宽
//    _editTurnAndCutOptions.cutSize = CGSizeMake(640, 640);
//    // 保存头像到相册
//    _editTurnAndCutOptions.saveToAlbum = YES;

#import <Foundation/Foundation.h>
#import "TuSDKCPOptions.h"
#import "TuSDKCPAlbumOptions.h"
#import "TuSDKPFCameraOptions.h"
#import "TuSDKPFEditTurnAndCutOptions.h"

/**
 *  头像设置组件选项
 */
@interface TuSDKCPAvatarOptions : TuSDKCPAlbumOptions

/**
 *  默认相机视图控制器选项
 */
@property (nonatomic, readonly) TuSDKPFCameraOptions *cameraOptions;

/**
 *  旋转和裁剪视图控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditTurnAndCutOptions *editTurnAndCutOptions;
@end
