//
//  TuSDKPFAlbumViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKICViewController.h"
#import "TuSDKPFAlbumView.h"

@class TuSDKPFAlbumViewController;

/**
 *  系统相册委托
 */
@protocol TuSDKPFAlbumDelegate <NSObject>
/**
 *  选中相册组
 *
 *  @param controller 系统相册控制器
 *  @param group 相册组
 */
- (void)onTuSDKPFAlbum:(TuSDKPFAlbumViewController *)controller selectedGroup:(ALAssetsGroup *)group;
@end

/**
 *  系统相册控制器
 */
@interface TuSDKPFAlbumViewController : TuSDKICViewController<TuSDKPFAlbumViewProtocol>{
    @protected
    /**
     *  默认样式视图
     */
    TuSDKPFAlbumView *_defaultStyleView;
}
/**
 *  系统相册委托
 */
@property (nonatomic, assign) id<TuSDKPFAlbumDelegate> delegate;

/**
 *  系统相册列表
 */
@property (nonatomic, retain) NSArray *groups;

/**
 *  是否自动选择相册组 (默认: YES, 如果没有设定相册组名称，自动跳转到系统相册组)
 */
@property (nonatomic) BOOL autoSelectedAblumGroup;

/**
 *  需要自动跳转到相册组名称 (需要设定 autoSkipToPhotoList = YES)
 */
@property (nonatomic, copy) NSString *skipAlbumName;

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFAlbumView *defaultStyleView;

/**
 *  创建默认样式视图 (如需创建自定义视图，请覆盖该方法，并创建自己的视图类)
 */
- (void)buildDefaultStyleView;

/**
 *  通知获取一个相册组
 *
 *  @param group 相册组
 */
- (void)notifySelectedGroup:(ALAssetsGroup *)group;
@end
