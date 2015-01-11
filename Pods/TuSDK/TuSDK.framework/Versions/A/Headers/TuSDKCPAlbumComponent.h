//
//  TuSDKCPAlbumComponent.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPComponent.h"
#import "TuSDKCPAlbumOptions.h"

/**
 *  自定义系统相册组件
 */
@interface TuSDKCPAlbumComponent : TuSDKCPComponent<TuSDKPFAlbumDelegate, TuSDKPFPhotosDelegate>
/**
 *  自定义系统相册组件配置选项
 */
@property (nonatomic, retain) TuSDKCPAlbumOptions *options;

/**
 *  显示相册界面
 */
- (void)handleShowAlbum;
@end
