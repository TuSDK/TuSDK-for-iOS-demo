//
//  TuSDKCPAlbumOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPOptions.h"
#import "TuSDKPFAlbumOptions.h"
#import "TuSDKPFPhotosOptions.h"

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
