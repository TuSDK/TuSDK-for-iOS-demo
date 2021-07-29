//
//  TuSDKPFAlbumViewController.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKPFAlbumMultipleView.h"
#import "TuSDKPFCameraViewController.h"
#import "TuSDKGeeV1Import.h"

@class TuSDKPFAlbumMultipleViewController;
@class TuSDKPFPhotoPreviewBarViewWrap;
/**
 *  系统相册委托
 */
@protocol TuSDKPFAlbumMultipleDelegate <TuComponentErrorDelegate>

@optional
/**
 *  选中相册组
 *
 *  @param controller 系统相册控制器
 *  @param group      相册组
 */
- (void)onTuSDKPFAlbum:(TuSDKPFAlbumMultipleViewController *)controller selectedGroup:(id<TuTSAssetsGroupInterface>)group;

/**
 *  请求从相册界面跳转至相机
 *
 *  @param controller 系统相册控制器
 */
- (void)onTuSDKCameraDemand:(TuSDKPFAlbumMultipleViewController *)controller;

/**
 *  相册读取错误信息
 *
 *  @param controller 系统相册控制器
 *  @param error      相册读取错误信息
 */
- (void)onTuSDKPFPhotos:(TuSDKPFAlbumMultipleViewController *)controller error:(NSError *)error;

@required
/**
 *  选中的相片列表
 *
 *  @param controller 系统相册控制器
 *  @param assets     相片数组
 */
- (void)onTuSDKPFPhotos:(TuSDKPFAlbumMultipleViewController *)controller selectedAssets:(NSArray<TuTSAssetInterface> *)assets;

@end

/**
 *  包含相机的系统相册控制器
 */ 
@interface TuSDKPFAlbumMultipleViewController : TuAlbumMultipleViewControllerBase<TuSDKPFAlbumMultipleViewProtocol>{
    @protected
    /**
     *  默认样式视图
     */
    TuSDKPFAlbumMultipleView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFAlbumMultipleView *defaultStyleView;

/**
 *  系统相册委托
 */
@property (nonatomic, weak) id<TuSDKPFAlbumMultipleDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFAlbumMultipleView, 需要继承 TuSDKPFAlbumMultipleView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  相册列表视图类 (默认:TuSDKPFAlbumPopList, 需要继承 TuSDKPFAlbumPopList)
 */
@property (nonatomic, strong) Class albumPopListClazz;

/**
 *  相册列表行高度 (默认: 64)
 */
@property (nonatomic, assign) CGFloat popListRowHeight;

/**
 *  相册列表行视图类 (默认:TuSDKPFAlbumPopListCell, 需要继承 TuSDKPFAlbumPopListCell)
 */
@property (nonatomic, strong) Class albumPopListCellClazz;

/**
 *  相册照片列表视图类 (默认:TuSDKPFPhotosGridView, 需要继承 TuSDKPFPhotosGridView)
 */
@property (nonatomic, strong) Class photosViewClazz;

/**
 *  照片列表单元格视图类 (默认:TuSDKPFPhotosGridCell, 需要继承 TuSDKPFPhotosGridCell)
 */
@property (nonatomic, strong) Class gridCellViewClazz;

/**
 *  预览视图控制器默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, strong) Class previewClazz;

/**
 *  预览视图控制器相册照片列表视图类 (默认:TuSDKPFPhotosGridPreview, 需要继承 TuSDKPFPhotosGridPreview)
 */
@property (nonatomic, strong) Class previewPhotosViewClazz;

/**
 *  预览视图控制器照片列表单元格视图类 (默认:TuSDKPFPhotosGridCell, 需要继承 TuSDKPFPhotosGridCell)
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
@property (nonatomic,assign) TuAssetSortKeyType photosSortKeyType;

/**
 *  显示相机单元格，点击后请求打开相机 (默认: true)
 */
@property (nonatomic) BOOL displayCameraCell;

/**
 *  初始化视图控制器，已选择的资源数据
 */
@property (nonatomic, retain) NSMutableArray<TuTSAssetInterface> *selectedAssets;

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
 *  是否从相机界面进入 (默认: NO)
 */
@property (nonatomic) BOOL openedByCameraController;

/**
 *  配置相册列表视图
 *
 *  @param view 相册列表视图
 */
- (void)configPhotoView:(TuSDKPFPhotosGridView *)view;

@end
