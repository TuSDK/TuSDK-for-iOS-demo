//
//  TuSDKPFAlbumMultipleView.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKPFAlbumPopList.h"
#import "TuSDKPFPhotosGridView.h"

/**
 *  列表样式视图委托
 */
@protocol TuSDKPFAlbumMultipleViewProtocol <NSObject>
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

@end

/**
 *  默认相册列表样式视图
 */
@interface TuSDKPFAlbumMultipleView : UIView<TuSDKPFAlbumPopListProtocol, TuSDKPFPhotoGridProtocol>

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
 *  相册列表视图
 */
@property (nonatomic, strong) TuSDKPFAlbumPopList *albumPopList;

/**
 *  相册照片列表视图
 */
@property (nonatomic, strong) TuSDKPFPhotosGridView *photosView;

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
 *  选中的单元列表
 */
@property (nonatomic, readonly) NSMutableArray<TuSDKTSAssetInterface> *selectedItems;

/**
 * 一次选择的最大照片数量 (默认: 3, 0 < n <= 10)
 */
@property (nonatomic, assign) NSUInteger maxSelectionNumber;

/**
 *  列表样式视图委托
 */
@property (nonatomic, assign) id<TuSDKPFAlbumMultipleViewProtocol> selectedProtocol;

/**
 *  初始化视图
 */
- (void)initView;

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
 *  @return 相册列表当前的显示状态
 */
- (BOOL)getAlbumListViewState;

@end
