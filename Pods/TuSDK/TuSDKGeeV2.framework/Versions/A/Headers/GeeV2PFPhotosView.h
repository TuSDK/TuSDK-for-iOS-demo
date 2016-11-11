//
//  GeeV2PFPhotosView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV2Import.h"
#import "GeeV2PFPhotosCell.h"

/**
 *  相册照片列表视图
 */
@interface GeeV2PFPhotosView : TuSDKICTableView<UITableViewDataSource, UITableViewDelegate>

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
 *  系统相册组
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<GeeV2PFPhotosCellProtocol> gridProtocol;
@end
