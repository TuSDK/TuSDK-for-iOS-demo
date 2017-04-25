//
//  TuSDKPFAlbumViewController.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKPFAlbumView.h"

@class TuSDKPFAlbumViewController;

/**
 *  系统相册委托
 */
@protocol TuSDKPFAlbumDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  选中相册组
 *
 *  @param controller 系统相册控制器
 *  @param group 相册组
 */
- (void)onTuSDKPFAlbum:(TuSDKPFAlbumViewController *)controller selectedGroup:(id<TuSDKTSAssetsGroupInterface>)group;

/**
 *  相册读取错误信息
 *
 *  @param controller 系统相册控制器
 *  @param error      相册读取错误信息
 */
- (void)onTuSDKPFPhotos:(TuSDKPFAlbumViewController *)controller error:(NSError *)error;

@end

/**
 *  系统相册控制器
 */
@interface TuSDKPFAlbumViewController : TuSDKPFAlbumViewControllerBase<TuSDKPFAlbumViewProtocol>{
    @protected
    /**
     *  默认样式视图
     */
    TuSDKPFAlbumView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFAlbumView *defaultStyleView;

/**
 *  系统相册委托
 */
@property (nonatomic, weak) id<TuSDKPFAlbumDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFAlbumView, 需要继承 TuSDKPFAlbumView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  表格行视图类 (默认:TuSDKPFAlbumCell, 需要继承 TuSDKPFAlbumCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  空数据视图类 (默认:TuSDKICEmptyView, 需要继承 TuSDKICEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;
@end
