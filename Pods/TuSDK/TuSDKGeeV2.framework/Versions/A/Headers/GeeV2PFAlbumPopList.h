//
//  GeeV2PFAlbumPopList.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV2Import.h"

/**
 *  列表样式视图委托
 */
@protocol GeeV2PFAlbumPopListProtocol <NSObject>
/**
 *  列表中选中一个相册组
 *
 *  @param group 相册组
 */
- (void)onTuSDKPFAlbumSelectedWithGroup:(id<TuSDKTSAssetsGroupInterface>)group;
@end

@interface GeeV2PFAlbumPopList : TuSDKICTableView<UITableViewDataSource, UITableViewDelegate>

/**
 *  列表行视图类 (默认:GeeV2PFAlbumPopListCell, 需要继承 GeeV2PFAlbumPopListCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  系统相册列表
 */
@property (nonatomic, retain) NSArray *groups;

/**
 *  是否为隐藏状态
 */
@property (nonatomic) BOOL stateHidden;

@property (nonatomic, assign) id<GeeV2PFAlbumPopListProtocol> groupProtocol;

/**
 *  初始化视图
 */
- (void)lsqInitView;

/**
 *  切换视图显示状态
 */
- (void)toggleGroupShowState;

/**
 *  选中某个分组
 *
 *  @param group 相册对象
 */
- (void)selectGroup:(id<TuSDKTSAssetsGroupInterface>)group;

@end
