//
//  GeeV2PFAlbumMultipleOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFAlbumMultipleViewController.h"
#import "GeeV2PFPhotoPreviewController.h"

/**
 *  系统相册控制器配置选项
 */
@interface GeeV2PFAlbumMultipleOptions : TuSDKCPOptions

/**
 *  视图类 (默认:GeeV2PFAlbumMultipleView, 需要继承 GeeV2PFAlbumMultipleView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  相册列表视图类 (默认:GeeV2PFAlbumPopList, 需要继承 GeeV2PFAlbumPopList)
 */
@property (nonatomic, strong) Class albumPopListClazz;

/**
 *  相册列表行高度 (默认: 64)
 */
@property (nonatomic, assign) CGFloat popListRowHeight;

/**
 *  相册列表行视图类 (默认:GeeV2PFAlbumPopListCell, 需要继承 GeeV2PFAlbumPopListCell)
 */
@property (nonatomic, strong) Class albumPopListCellClazz;

/**
 *  相册照片列表视图类 (默认:GeeV2PFPhotosGridView, 需要继承 GeeV2PFPhotosGridView)
 */
@property (nonatomic, strong) Class photosViewClazz;

/**
 *  照片列表单元格视图类 (默认:GeeV2PFPhotosGridCell, 需要继承 GeeV2PFPhotosGridCell)
 */
@property (nonatomic, strong) Class gridCellViewClazz;

/**
 *  预览视图控制器默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, strong) Class previewClazz;
/**
 *  预览视图控制器相册照片列表视图类 (默认:GeeV2PFPhotosGridPreview, 需要继承 GeeV2PFPhotosGridPreview)
 */
@property (nonatomic, strong) Class previewPhotosViewClazz;

/**
 *  预览视图控制器照片列表单元格视图类 (默认:GeeV2PFPhotosGridCell, 需要继承 GeeV2PFPhotosGridCell)
 */
@property (nonatomic, strong) Class previewCellViewClazz;

/**
 *  一次选择的最大照片数量 (默认: 3, 0 < n <= 9)
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
 *  显示相机单元格，点击后请求打开相机 (默认: true)
 */
@property (nonatomic) BOOL displayCameraCell;

/**
 *  允许在多个相册中选择 (默认: 开启)
 */
@property (nonatomic, assign) BOOL enabelShareSelection;

/**
 *  是否开启大图预览 (默认: true)
 */
@property (nonatomic) BOOL enabelPreview;

/**
 *  相册列表每行显示的照片数量 (默认:0, 程序自动适配设备)
 */
@property (nonatomic, assign) NSUInteger photoColumnNumber;

/**
 *  需要自动跳转到相册组名称
 */
@property (nonatomic, copy) NSString *skipAlbumName;

/**
 *  选中的媒体资源对象
 */
@property (nonatomic, readonly) NSMutableArray<TuSDKTSAssetInterface> *selectedAssets;

/**
 *  创建系统相册列表控制器对象
 *
 *  @return controller 系统相册列表控制器对象
 */
- (GeeV2PFAlbumMultipleViewController *)viewController;
@end

