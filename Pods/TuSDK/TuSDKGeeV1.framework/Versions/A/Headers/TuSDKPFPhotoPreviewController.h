//
//  TuSDKPhotoPreviewController.h
//  TuSDKGeeV1
//
//  Created by Jimmy Zhao on 16/8/22.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"
#import "TuSDKPFPhotosGridVPreview.h"
#import "TuSDKPFPhotoPreviewBarViewWrap.h"

@class TuSDKPFPhotoPreviewController;

@protocol TuSDKPFPhotoPreviewControllerDelegate <NSObject>

@required
/**
 *  选中的相片列表
 *
 *  @param controller 系统相册控制器
 *  @param assets     相片数组
 */
- (void)onTuSDKPFPhotos:(TuSDKPFPhotoPreviewController *)controller selectedAssets:(NSArray<TuSDKTSAssetInterface> *)assets;

@end

/**
 *  相册预览控制器
 */
@interface TuSDKPFPhotoPreviewController : TuSDKPFPhotoPreviewControllerBase

/**
 *  默认预览视图
 */
@property (nonatomic, readonly) TuSDKPFPhotosGridVPreview *defaultPreview;

/**
 *  视图类 (默认:TuSDKPhotosGridVPreview, 需要继承 TuSDKPhotosGridVPreview)
 */
@property (nonatomic, strong) Class previewClazz;

/**
 *  照片列表单元格视图类 (默认:TuSDKPFPhotosGridCell, 需要继承 TuSDKPFPhotosGridCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  预览视图工具视图
 */
@property (nonatomic, strong) TuSDKPFPhotoPreviewBarViewWrap *barViewWrap;

/**
 *  视图类 (默认:TuSDKPFPhotoPreviewBarViewWrap, 需要继承 TuSDKPFPhotoPreviewBarViewWrap 重写LSQInitView，可以改变工具栏样式)
 */
@property (nonatomic, strong) Class previewBarViewClazz;

/**
 * 一次选择的最大照片数量 (默认: 3, 0 < n <= 10)
 */
@property (nonatomic, assign) NSUInteger maxSelectionNumber;

/**
 *  用户点击的图片的索引
 */
@property (nonatomic, assign) NSUInteger currentIndex;

/**
 *  选中的单元列表
 */
@property (nonatomic, strong) NSMutableArray<TuSDKTSPhotosGridCellData *> *selectedItems;

/**
 *  当前选中相册组
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;

/**
 *  预览视图控制器代理
 */
@property (nonatomic, assign) id<TuSDKPFPhotoPreviewControllerDelegate> delegate;

@end

