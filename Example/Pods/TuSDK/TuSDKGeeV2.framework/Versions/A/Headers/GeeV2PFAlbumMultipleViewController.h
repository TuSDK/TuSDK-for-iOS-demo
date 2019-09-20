//
//  GeeV2PFAlbumMultipleViewController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFAlbumMultipleView.h"
#import "GeeV2PFCameraViewController.h"
#import "TuSDKGeeV2Import.h"

@class GeeV2PFAlbumMultipleViewController;
@class GeeV2PFPhotoPreviewBarViewWrap;
/**
 *  系统相册委托
 */
@protocol GeeV2PFAlbumMultipleDelegate <TuSDKCPComponentErrorDelegate>

@optional
/**
 *  选中相册组
 *
 *  @param controller 系统相册控制器
 *  @param group      相册组
 */
- (void)onGeeV2PFAlbum:(GeeV2PFAlbumMultipleViewController *)controller selectedGroup:(id<TuSDKTSAssetsGroupInterface>)group;

/**
 *  请求从相册界面跳转至相机
 *
 *  @param controller 系统相册控制器
 */
- (void)onGeeV2CameraDemand:(GeeV2PFAlbumMultipleViewController *)controller;

@required
/**
 *  选中的相片列表
 *
 *  @param controller 系统相册控制器
 *  @param assets     相片数组
 */
- (void)onGeeV2PFPhotos:(GeeV2PFAlbumMultipleViewController *)controller selectedAssets:(NSArray<TuSDKTSAssetInterface> *)assets;

/**
 *  相册读取错误信息
 *
 *  @param controller 系统相册控制器
 *  @param error      相册读取错误信息
 */
- (void)onTuSDKPFPhotos:(GeeV2PFAlbumMultipleViewController *)controller error:(NSError *)error;
@end

/**
 *  包含相机的系统相册控制器
 */
@interface GeeV2PFAlbumMultipleViewController : TuSDKPFAlbumMultipleViewControllerBase<GeeV2PFAlbumMultipleViewProtocol>{
@protected
    /**
     *  默认样式视图
     */
    GeeV2PFAlbumMultipleView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFAlbumMultipleView *defaultStyleView;

/**
 *  系统相册委托
 */
@property (nonatomic, weak) id<GeeV2PFAlbumMultipleDelegate> delegate;

/**
 *  视图类 (默认:GeeV2PFAlbumMultipleView, 需要继承 GeeV2PFAlbumMultipleView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  相册列表视图类 (默认:GeeV2PFAlbumPopList, 需要继承 GeeV2PFAlbumPopList)
 */
@property (nonatomic, strong) Class albumPopListClazz;

/**
 *  相册列表行高度 (默认: 80)
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
 *  显示相机单元格，点击后请求打开相机 (默认: true)
 */
@property (nonatomic) BOOL displayCameraCell;

/**
 *  是否开启大图预览 (默认: true)
 */
@property (nonatomic) BOOL enabelPreview;

/**
 *  初始化视图控制器，已选择的资源数据
 */
@property (nonatomic, retain) NSMutableArray<TuSDKTSAssetInterface> *selectedAssets;

/**
 *  允许在多个相册中选择 (默认: 开启)
 */
@property (nonatomic, assign) BOOL enabelShareSelection;

/**
 *  相册列表每行显示的照片数量 (默认:0, 程序自动适配设备)
 */
@property (nonatomic, assign) NSUInteger photoColumnNumber;

/**
 *  是否从相机界面进入 (默认: NO)
 */
@property (nonatomic) BOOL openedByCameraController;

/**
 *  配置相册列表视图
 *
 *  @param view 相册列表视图
 */
- (void)configPhotoView:(GeeV2PFPhotosGridView *)view;

@end
