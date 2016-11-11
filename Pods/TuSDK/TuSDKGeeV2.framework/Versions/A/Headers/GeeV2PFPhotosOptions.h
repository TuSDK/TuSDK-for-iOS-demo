//
//  GeeV2PFPhotosOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFPhotosViewController.h"

/**
 *  相册照片列表控制器配置选项
 */
@interface GeeV2PFPhotosOptions : TuSDKCPOptions
/**
 *  视图类 (默认:GeeV2PFPhotosView, 需要继承 GeeV2PFPhotosView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  表格行视图类 (默认:GeeV2PFPhotosCell, 需要继承 GeeV2PFPhotosCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  表格单元格视图类 (默认:GeeV2PFPhotosGrid, 需要继承 GeeV2PFPhotosGrid)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 *  表格行头部视图类 (默认:GeeV2PFPhotosCellSectionHeader, 需要继承 GeeV2PFPhotosCellSectionHeader)
 */
@property (nonatomic, strong) Class cellHeaderViewClazz;

/**
 *  空数据视图类 (默认:TuSDKICEmptyView, 需要继承 TuSDKICEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;

/**
 *  创建系统相册照片列表控制器对象
 *
 *  @return 相册照片列表控制器对象
 */
- (GeeV2PFPhotosViewController *)viewController;
@end
