//
//  TuSDKPFAlbumView.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKICTableView.h"
#import <AssetsLibrary/AssetsLibrary.h>

/**
 *  列表样式视图委托
 */
@protocol TuSDKPFAlbumViewProtocol <NSObject>
/**
 *  列表中选中一个相册组
 *
 *  @param group 相册组
 */
- (void) onTuSDKPFAlbumViewSelectedGroup:(ALAssetsGroup *)group;
@end

/**
 *  默认相册列表样式视图
 */
@interface TuSDKPFAlbumView : TuSDKICTableView <UITableViewDataSource, UITableViewDelegate>

/**
 *  系统相册列表
 */
@property (nonatomic, retain) NSArray *groups;

/**
 *  列表样式视图委托
 */
@property (nonatomic, assign) id<TuSDKPFAlbumViewProtocol> selectedProtocol;

/**
 *  初始化视图
 */
- (void)initView;
@end
