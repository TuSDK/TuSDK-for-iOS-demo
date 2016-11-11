//
//  GeeV2PFPhotoPreviewController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV2Import.h"
#import "GeeV2PFPhotosGridVPreview.h"
#import "GeeV2PFPhotoPreviewBarViewWrap.h"

@class GeeV2PFPhotoPreviewController;

@protocol GeeV2PFPhotoPreviewControllerDelegate <NSObject>

@required
/**
 *  选中的相片列表
 *
 *  @param controller 系统相册控制器
 *  @param assets     相片数组
 */
- (void)onGeeV2PFPhotos:(GeeV2PFPhotoPreviewController *)controller selectedAssets:(NSArray<TuSDKTSAssetInterface> *)assets;

@end

/**
 *  相册预览控制器
 */
@interface GeeV2PFPhotoPreviewController : TuSDKPFPhotoPreviewControllerBase

/**
 *  默认预览视图
 */
@property (nonatomic, readonly) GeeV2PFPhotosGridVPreview *defaultPreview;

/**
 *  视图类 (默认:GeeV2PhotosGridVPreview, 需要继承 GeeV2PhotosGridVPreview)
 */
@property (nonatomic, strong) Class previewClazz;

/**
 *  照片列表单元格视图类 (默认:GeeV2PFPhotosGridCell, 需要继承 GeeV2PFPhotosGridCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  预览视图工具视图
 */
@property (nonatomic, strong) GeeV2PFPhotoPreviewBarViewWrap *barViewWrap;

/**
 *  视图类 (默认:GeeV2PFPhotoPreviewBarViewWrap, 需要继承 GeeV2PFPhotoPreviewBarViewWrap 重写LSQInitView，可以改变工具栏样式)
 */
@property (nonatomic, strong) Class previewBarViewClazz;

/**
 * 一次选择的最大照片数量 (默认: 3, 0 < n <= 9)
 */
@property (nonatomic, assign) NSUInteger maxSelectionNumber;

/**
 *  用户点击的图片的索引
 */
@property (nonatomic, assign) NSUInteger currentIndex;

/**
 *  选中的单元列表
 */
@property (nonatomic, strong) NSMutableArray<GeeV2TSPhotosGridCellData *> *selectedItems;

/**
 *  当前选中相册组
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;

/**
 *  预览视图控制器代理
 */
@property (nonatomic, assign) id<GeeV2PFPhotoPreviewControllerDelegate> delegate;

@end
