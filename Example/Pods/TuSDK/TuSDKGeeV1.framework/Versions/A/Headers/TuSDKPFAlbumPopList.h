//
//  TuSDKPFAlbumPopList.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 8/11/15.
//  Copyright (c) 2015 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKPFAlbumPopListCell.h"

/**
 *  列表样式视图委托
 */
@protocol TuSDKPFAlbumPopListProtocol <NSObject>
/**
 *  列表中选中一个相册组
 *
 *  @param group 相册组
 */
- (void)onTuSDKPFAlbumSelectedWithGroup:(id<TuSDKTSAssetsGroupInterface>)group;
@end

@interface TuSDKPFAlbumPopList : TuSDKICTableView<UITableViewDataSource, UITableViewDelegate>

/**
 *  列表行视图类 (默认:TuSDKPFAlbumPopListCell, 需要继承 TuSDKPFAlbumPopListCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  系统相册列表
 */
@property (nonatomic, strong) NSArray<id<TuSDKTSAssetsGroupInterface>> *groups;

/**
 *  是否为隐藏状态
 */
@property (nonatomic) BOOL stateHidden;

@property (nonatomic, assign) id<TuSDKPFAlbumPopListProtocol> groupProtocol;

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
