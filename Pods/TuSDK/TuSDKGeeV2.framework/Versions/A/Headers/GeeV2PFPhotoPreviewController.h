//
//  GeeV2PFPhotoPreviewController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFPhotoPreview.h"

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
@interface GeeV2PFPhotoPreviewController : TuSDKPFPhotoPreviewControllerBase<GeeV2PFPhotoGridPreviewProtocol>{
@protected
    /**
     *  默认样式视图
     */
    GeeV2PFPhotoPreview *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFPhotoPreview *defaultStyleView;

/**
 *  视图类 (默认:GeeV2PFPhotoPreview, 需要继承 GeeV2PFPhotoPreview)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  相册照片列表视图类 (默认:GeeV2PFPhotosGridPreview, 需要继承 GeeV2PFPhotosGridPreview)
 */
@property (nonatomic, strong) Class photosViewClazz;

/**
 *  照片列表单元格视图类 (默认:GeeV2PFPhotosGridCell, 需要继承 GeeV2PFPhotosGridCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 * 一次选择的最大照片数量 (默认: 3, 0 < n <= 9)
 */
@property (nonatomic, assign) NSUInteger maxSelectionNumber;

/**
 *  选择图片的尺寸限制 默认：CGSize(8000,8000)
 */
@property (nonatomic,assign) CGSize maxSelectionImageSize;

/**
 *  照片排序字段 默认根据创建时间排序 ( lsqAssetSortKeyModificationDate 类型 iOS8以上可用)
 */
@property (nonatomic,assign) lsqAssetSortKeyType photosSortKeyType;

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
@property (nonatomic, weak) id<GeeV2PFPhotoPreviewControllerDelegate> delegate;

@end
