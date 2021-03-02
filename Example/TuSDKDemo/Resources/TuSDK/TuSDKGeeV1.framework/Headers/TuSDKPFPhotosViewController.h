//
//  TuSDKPFPhotosViewController.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/11/1.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKPFPhotosView.h"

@class TuSDKPFPhotosViewController;

/**
 *  相册照片列表控制器委托
 */
@protocol TuSDKPFPhotosDelegate <TuComponentErrorDelegate>

/**
 *  选中相片
 *
 *  @param controller 相册照片列表控制器
 *  @param asset      相片
 */
- (void)onTuSDKPFPhotos:(TuSDKPFPhotosViewController *)controller selectedAsset:(id<TuTSAssetInterface>)asset;
@end

/**
 *  相册照片列表控制器
 */
@interface TuSDKPFPhotosViewController : TuPhotosViewControllerBase<TuSDKPFPhotosCellProtocol>{
@protected
    /**
     *  默认样式视图
     */
    TuSDKPFPhotosView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFPhotosView *defaultStyleView;

/**
 *  相册照片列表控制器委托
 */
@property (nonatomic, weak) id<TuSDKPFPhotosDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFPhotosView, 需要继承 TuSDKPFPhotosView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  表格行视图类 (默认:TuSDKPFPhotosGridCell, 需要继承 TuSDKPFPhotosGridCell)
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
 *  空数据视图类 (默认:TuEmptyView, 需要继承 TuEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;

/**
 *  选择图片的尺寸限制 默认：CGSize(8000,8000)
 */
@property (nonatomic,assign) CGSize maxSelectionImageSize;

/**
 *  系统相册组
 */
@property (nonatomic, retain) id<TuTSAssetsGroupInterface> group;

/**
 *  通知获取一个相片
 *
 *  @param asset 相片
 */
- (void)notifySelectedAsset:(id<TuTSAssetInterface>)asset;
@end
