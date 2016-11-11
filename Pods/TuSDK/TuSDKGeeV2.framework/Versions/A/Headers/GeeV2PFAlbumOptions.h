//
//  GeeV2PFAlbumOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFAlbumViewController.h"

/**
 *  系统相册控制器配置选项
 */
@interface GeeV2PFAlbumOptions : TuSDKCPOptions

/**
 *  视图类 (默认:GeeV2PFAlbumView, 需要继承 GeeV2PFAlbumView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  表格行视图类 (默认:GeeV2PFAlbumCell, 需要继承 GeeV2PFAlbumCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  空数据视图类 (默认:TuSDKICEmptyView, 需要继承 TuSDKICEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;

/**
 *  是否禁用自动选择相册组 (默认: NO, 如果没有设定相册组名称，自动跳转到系统相册组)
 */
@property (nonatomic) BOOL disableAutoSkipToPhotoList;

/**
 *  需要自动跳转到相册组名称 (需要设定 disableAutoSkipToPhotoList = NO)
 */
@property (nonatomic, copy) NSString *skipAlbumName;

/**
 *  创建系统相册列表控制器对象
 *
 *  @return 系统相册列表控制器对象
 */
- (GeeV2PFAlbumViewController *)viewController;
@end
