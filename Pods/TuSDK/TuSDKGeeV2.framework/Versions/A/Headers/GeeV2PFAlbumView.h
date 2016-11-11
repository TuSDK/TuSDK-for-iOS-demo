//
//  GeeV2PFAlbumView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV2Import.h"
#import "GeeV2PFAlbumCell.h"
/**
 *  列表样式视图委托
 */
@protocol GeeV2PFAlbumViewProtocol <NSObject>
/**
 *  列表中选中一个相册组
 *
 *  @param group 相册组
 */
- (void) onTuSDKPFAlbumViewSelectedGroup:(id<TuSDKTSAssetsGroupInterface>)group;
@end

/**
 *  默认相册列表样式视图
 */
@interface GeeV2PFAlbumView : TuSDKICTableView <UITableViewDataSource, UITableViewDelegate>

/**
 *  表格行视图类 (默认:GeeV2PFAlbumCell, 需要继承 GeeV2PFAlbumCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  空数据视图类 (默认:TuSDKICEmptyView, 需要继承 TuSDKICEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;

/**
 *  系统相册列表
 */
@property (nonatomic, retain) NSArray<TuSDKTSAssetsGroupInterface> *groups;

/**
 *  列表样式视图委托
 */
@property (nonatomic, assign) id<GeeV2PFAlbumViewProtocol> selectedProtocol;

/**
 *  初始化视图
 */
- (void)lsqInitView;
@end
