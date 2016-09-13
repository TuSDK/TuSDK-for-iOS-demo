//
//  TuSDKPFAlbumMultipleOptions.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/11/6.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKPFAlbumMultipleViewController.h"
#import "TuSDKPFPhotoPreviewController.h"

/**
 *  系统相册控制器配置选项
 */
@interface TuSDKPFAlbumMultipleOptions : TuSDKCPOptions

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
 *  视图类 (默认:TuSDKPFPhotoPreviewBarViewWrap, 需要继承 TuSDKPFPhotoPreviewBarViewWrap 重写LSQInitView，可以改变工具栏样式)
 */
@property (nonatomic, strong) Class previewBarViewClazz;

/**
 *  一次选择的最大照片数量 (默认: 3, 0 < n <= 10)
 */
@property (nonatomic, assign) NSUInteger maxSelectionNumber;

/**
 *  显示相机单元格，点击后请求打开相机 (默认: true)
 */
@property (nonatomic) BOOL displayCameraCell;

/**
 *  允许在多个相册中选择 (默认: 开启)
 */
@property (nonatomic, assign) BOOL enabelShareSelection;

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
 *  @return 系统相册列表控制器对象
 */
- (TuSDKPFAlbumMultipleViewController *)viewController;
@end
