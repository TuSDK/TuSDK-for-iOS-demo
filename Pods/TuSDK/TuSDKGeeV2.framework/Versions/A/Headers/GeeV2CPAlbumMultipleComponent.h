//
//  GeeV2CPAlbumMultipleComponent.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFAlbumMultipleOptions.h"
#import "GeeV2PFCameraOptions.h"
/**
 *  组件打开相机回调
 *
 *  @param controller 执行的控制器
 */
typedef void (^GeeV2CPAlbumMultipleOpenCameraBlock)(GeeV2PFAlbumMultipleViewController *controller);

/**
 *  多功能相册组件配置选项
 */
@interface GeeV2CPAlbumMultipleOptions : TuSDKCPOptions
/**
 *  系统相册控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFAlbumMultipleOptions *albumOptions;

/**
 *  相册中相机控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFCameraOptions *cameraOptions;
@end

/**
 *  多功能相册组件
 */
@interface GeeV2CPAlbumMultipleComponent : TuSDKCPAlbumMultipleComponentBase<GeeV2PFAlbumMultipleDelegate>
/**
 *  自定义系统相册组件配置选项
 */
@property (nonatomic, retain) GeeV2CPAlbumMultipleOptions *options;

/**
 *  组件回调
 */
@property (nonatomic, strong) GeeV2CPAlbumMultipleOpenCameraBlock openCameraCallback;

/**
 *  显示相册界面
 */
- (void)handleShowAlbum;
/**
 *  初始化组件
 *
 *  @param controller         来源控制器
 *  @param callbackBlock      组件回调结果
 *  @param openCameraCallback 打开相机回调结果
 *
 *  @return  controller 组件
 */
+ (instancetype)initWithSourceController:(UIViewController *)controller callbackBlock:(TuSDKCPComponentBlock)callbackBlock openCameraCallback:(GeeV2CPAlbumMultipleOpenCameraBlock)openCameraCallback;

@end
