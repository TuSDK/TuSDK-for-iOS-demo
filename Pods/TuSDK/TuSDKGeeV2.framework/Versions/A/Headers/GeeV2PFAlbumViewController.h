//
//  GeeV2PFAlbumViewController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "GeeV2PFAlbumView.h"

@class GeeV2PFAlbumViewController;

/**
 *  系统相册委托
 */
@protocol GeeV2PFAlbumDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  选中相册组
 *
 *  @param controller 系统相册控制器
 *  @param group 相册组
 */
- (void)onTuSDKPFAlbum:(GeeV2PFAlbumViewController *)controller selectedGroup:(id<TuSDKTSAssetsGroupInterface>)group;
@end

/**
 *  系统相册控制器
 */
@interface GeeV2PFAlbumViewController : TuSDKPFAlbumViewControllerBase<GeeV2PFAlbumViewProtocol>{
@protected
    /**
     *  默认样式视图
     */
    GeeV2PFAlbumView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFAlbumView *defaultStyleView;

/**
 *  系统相册委托
 */
@property (nonatomic, assign) id<GeeV2PFAlbumDelegate> delegate;

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
@end
