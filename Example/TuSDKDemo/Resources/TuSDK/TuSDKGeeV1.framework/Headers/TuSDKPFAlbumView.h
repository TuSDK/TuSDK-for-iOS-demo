//
//  TuSDKPFAlbumView.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKPFAlbumCell.h"
/**
 *  列表样式视图委托
 */
@protocol TuSDKPFAlbumViewProtocol <NSObject>
/**
 *  列表中选中一个相册组
 *
 *  @param group 相册组
 */
- (void) onTuSDKPFAlbumViewSelectedGroup:(id<TuTSAssetsGroupInterface>)group;
@end

/**
 *  默认相册列表样式视图
 */
@interface TuSDKPFAlbumView : TuTableView <UITableViewDataSource, UITableViewDelegate>

/**
 *  表格行视图类 (默认:TuSDKPFAlbumCell, 需要继承 TuSDKPFAlbumCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  空数据视图类 (默认:TuEmptyView, 需要继承 TuEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;

/**
 *  系统相册列表
 */
@property (nonatomic, retain) NSArray<TuTSAssetsGroupInterface> *groups;

/**
 *  列表样式视图委托
 */
@property (nonatomic, assign) id<TuSDKPFAlbumViewProtocol> selectedProtocol;

/**
 *  初始化视图
 */
- (void)lsqInitView;
@end
