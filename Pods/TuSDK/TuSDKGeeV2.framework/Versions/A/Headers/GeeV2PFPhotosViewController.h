//
//  GeeV2PFPhotosViewController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV2Import.h"
#import "GeeV2PFPhotosView.h"

@class GeeV2PFPhotosViewController;

/**
 *  相册照片列表控制器委托
 */
@protocol GeeV2PFPhotosDelegate <TuSDKCPComponentErrorDelegate>

/**
 *  选中相片
 *
 *  @param controller 相册照片列表控制器
 *  @param asset      相片
 */
- (void)onGeeV2PFPhotos:(GeeV2PFPhotosViewController *)controller selectedAsset:(id<TuSDKTSAssetInterface>)asset;
@end

/**
 *  相册照片列表控制器
 */
@interface GeeV2PFPhotosViewController : TuSDKPFPhotosViewControllerBase<GeeV2PFPhotosCellProtocol>{
@protected
    /**
     *  默认样式视图
     */
    GeeV2PFPhotosView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFPhotosView *defaultStyleView;

/**
 *  相册照片列表控制器委托
 */
@property (nonatomic, assign) id<GeeV2PFPhotosDelegate> delegate;

/**
 *  视图类 (默认:GeeV2PFPhotosView, 需要继承 GeeV2PFPhotosView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  表格行视图类 (默认:GeeV2PFPhotosGridCell, 需要继承 GeeV2PFPhotosGridCell)
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
 *  通知获取一个相片
 *
 *  @param asset 相片
 */
- (void)notifySelectedAsset:(id<TuSDKTSAssetInterface>)asset;
@end

