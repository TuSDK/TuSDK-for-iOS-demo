//
//  TuSDKCPAlbumComponent.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFAlbumOptions.h"
#import "TuSDKPFPhotosOptions.h"

#pragma mark - TuSDKCPAlbumOptions
/**
 *  自定义系统相册组件配置选项
 */
@interface TuSDKCPAlbumOptions : TuSDKCPOptions
/**
 *  系统相册控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFAlbumOptions *albumOptions;

/**
 *  相册照片列表控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFPhotosOptions *photosOptions;
@end

#pragma mark - TuSDKCPAlbumComponent
/**
 *  自定义系统相册组件
 */
@interface TuSDKCPAlbumComponent : TuSDKCPAlbumComponentBase<TuSDKPFAlbumDelegate, TuSDKPFPhotosDelegate>
/**
 *  自定义系统相册组件配置选项
 */
@property (nonatomic, retain) TuSDKCPAlbumOptions *options;

/**
 *  显示相册界面
 */
- (void)handleShowAlbum;
@end

