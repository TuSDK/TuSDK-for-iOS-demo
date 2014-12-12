//
//  TuSDKPFPhotosView.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/1.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKICTableView.h"
#import "TuSDKPFPhotosCell.h"

/**
 *  相册照片列表视图
 */
@interface TuSDKPFPhotosView : TuSDKICTableView<UITableViewDataSource, UITableViewDelegate>

/**
 *  表格行视图类 (默认:TuSDKPFPhotosCell, 需要继承 TuSDKPFPhotosCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  表格单元格视图类 (默认:TuSDKPFPhotosGrid, 需要继承 TuSDKPFPhotosGrid)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 *  表格行头部视图类 (默认:TuSDKPFPhotosCellSectionHeader, 需要继承 TuSDKPFPhotosCellSectionHeader)
 */
@property (nonatomic, strong) Class cellHeaderViewClazz;

/**
 *  空数据视图类 (默认:TuSDKPFEmptyView, 需要继承 TuSDKPFEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;

/**
 *  系统相册组
 */
@property (nonatomic, retain) ALAssetsGroup *group;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<TuSDKPFPhotosCellProtocol> gridProtocol;
@end
