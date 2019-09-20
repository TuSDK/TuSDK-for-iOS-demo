//
//  TuSDKCPAlbumMultipleComponent.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKPFAlbumMultipleOptions.h"
#import "TuSDKPFCameraOptions.h"

/**
 *  多功能相册组件配置选项
 */
@interface TuSDKCPAlbumMultipleOptions : TuSDKCPOptions
/**
 *  系统相册控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFAlbumMultipleOptions *albumOptions;

/**
 *  相册中相机控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFCameraOptions *cameraOptions;
@end

/**
 *  多功能相册组件
 */
@interface TuSDKCPAlbumMultipleComponent : TuSDKCPAlbumMultipleComponentBase<TuSDKPFAlbumMultipleDelegate, TuSDKPFCameraDelegate>
/**
 *  自定义系统相册组件配置选项
 */
@property (nonatomic, retain) TuSDKCPAlbumMultipleOptions *options;

/**
 *  显示相册界面
 */
- (void)handleShowAlbum;
@end
