//
//  TuSDKPFAlbumOptions.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/6.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKCPOptions.h"
#import "TuSDKPFAlbumViewController.h"

/**
 *  系统相册控制器配置选项
 */
@interface TuSDKPFAlbumOptions : TuSDKCPOptions

/**
 *  视图类 (默认:TuSDKPFAlbumView, 需要继承 TuSDKPFAlbumView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  表格行视图类 (默认:TuSDKPFAlbumCell, 需要继承 TuSDKPFAlbumCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  空数据视图类 (默认:TuSDKPFEmptyView, 需要继承 TuSDKPFEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;

/**
 *  是否自动选择相册组 (默认: YES, 如果没有设定相册组名称，自动跳转到系统相册组)
 */
@property (nonatomic) BOOL autoSkipToPhotoList;

/**
 *  需要自动跳转到相册组名称 (需要设定 autoSkipToPhotoList = YES)
 */
@property (nonatomic, copy) NSString *skipAlbumName;

/**
 *  创建系统相册列表控制器对象
 *
 *  @return 系统相册列表控制器对象
 */
- (TuSDKPFAlbumViewController *)viewController;
@end
