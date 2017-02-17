//
//  TuSDKPFAlbumMultipleView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV2Import.h"
#import "GeeV2PFAlbumPopList.h"
#import "GeeV2PFPhotosGridView.h"

/**
 *  列表样式视图委托
 */
@protocol GeeV2PFAlbumMultipleViewProtocol <NSObject>
/**
 *  列表中选中一个相册组
 *
 *  @param group 相册组
 */
- (void)onTuSDKPFAlbumViewSelectedGroup:(id<TuSDKTSAssetsGroupInterface>)group;

/**
 *  相册列表显示状态发生变化
 */
- (void)onAlbumGroupViewStateChanged;

/**
 *  选中相片
 *
 *  @param asset 相片
 */
- (void)onTuSDKPFPhotosCellSelectedWithAsset:(id)asset;

/**
 *  选中相片预览
 *
 *  @param asset 相片
 */
- (void)onTuSDKPFPhotosCellClickedWithAsset:(id)asset currentIndex:(NSInteger)currentIndex;

@end

/**
 *  默认相册列表样式视图
 */
@interface GeeV2PFAlbumMultipleView : UIView<GeeV2PFAlbumPopListProtocol, GeeV2PFPhotoGridProtocol>

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
 *  相册列表视图
 */
@property (nonatomic, strong) GeeV2PFAlbumPopList *albumPopList;

/**
 *  相册照片列表视图
 */
@property (nonatomic, strong) GeeV2PFPhotosGridView *photosView;

/**
 *  相册列表每行显示的照片数量 (默认:0, 程序自动适配设备)
 */
@property (nonatomic, assign) NSUInteger photoColumnNumber;

/**
 *  系统相册列表
 */
@property (nonatomic, retain) NSArray *groups;

/**
 *  允许在多个相册中选择 (默认: 开启)
 */
@property (nonatomic, assign) BOOL enabelShareSelection;

/**
 *  选中的单元格列表
 */
@property (nonatomic, readonly) NSMutableArray<GeeV2TSPhotosGridCellData *> *selectedItems;

/**
 * 一次选择的最大照片数量 (默认: 3, 0 < n <= 9)
 */
@property (nonatomic, assign) NSUInteger maxSelectionNumber;

/**
 *  选择图片的尺寸限制 默认：CGSize(8000,8000)
 */
@property (nonatomic,assign) CGSize maxSelectionImageSize;

/**
 *  显示相机单元格，点击后请求打开相机 (默认: true)
 */
@property (nonatomic) BOOL displayCameraCell;

/**
 *  列表样式视图委托
 */
@property (nonatomic, assign) id<GeeV2PFAlbumMultipleViewProtocol> selectedProtocol;

/**
 *  初始化视图
 */
- (void)lsqInitView;

/**
 *  显示指定相册的照片
 *
 *  @param group 相册对象
 */
- (void)selectGroup:(id<TuSDKTSAssetsGroupInterface>)group;

/**
 *  切换相册选择列表显示状态: 显示 | 隐藏
 */
- (void)toggleAlbumListViewState;

/**
 *  获取相册列表当前的显示状态
 *
 *  @return BOOL 相册列表当前的显示状态
 */
- (BOOL)getAlbumListViewState;

/**
 *  选中一张照片
 *
 *  @param asset     照片对象
 *  @param indexPath 单元格索引
 */
- (void)onTuSDKPFPhotoGridAssetSelected:(id)asset atIndexPath:(NSIndexPath*)indexPath;

@end
