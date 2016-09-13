//
//  TuSDKPFPhotosGridView.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/11/1.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKICGridView.h"
#import "TuSDKPFPhotosGridCell.h"
#import "TuSDKGeeV1Import.h"

/**
 *  相册照片列表行视图委托
 */
@protocol TuSDKPFPhotoGridProtocol <NSObject>
/**
 *  单元格被选中
 *
 *  @param asset     单元格对象
 *  @param indexPath 单元格索引
 */
- (void)onTuSDKPFPhotoGridAssetSelected:(id)asset atIndexPath:(NSIndexPath*)indexPath;

/**
 *  单元格被点击，跳转到预览视图
 *
 *  @param asset     单元格对象
 *  @param indexPath 单元格索引
 */
- (void)onTuSDKPFPhotoGridAssetClicked:(id)asset atIndexPath:(NSIndexPath*)indexPath;

/**
 *  获取选中的单元格列表
 *
 *  @return
 */
- (NSMutableArray<TuSDKTSPhotosGridCellData *> *)getSelectedItem;
@end

/**
 *  相册照片列表视图
 */
@interface TuSDKPFPhotosGridView : TuSDKICGridView<UICollectionViewDataSource, UICollectionViewDelegate>

/**
 *  表格单元格视图类 (默认:TuSDKPFPhotosGridCell, 需要继承 TuSDKPFPhotosGridCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  相册列表每行显示的照片数量 (默认:0, 程序自动适配设备)
 */
@property (nonatomic, assign) NSUInteger photoColumnNumber;

/**
 *  是否为多选模式
 */
@property (nonatomic, assign) BOOL enableMultiSelection;

/**
 *  显示相机单元格，点击后请求打开相机 (默认: true)
 */
@property (nonatomic) BOOL displayCameraCell;

/**
 *  当前选中相册组
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<TuSDKPFPhotoGridProtocol> gridProtocol;

#pragma mark - refresh selection item
/**
 *  重置单元格视图
 *
 *  @param asset 单元格数据对象
 */
- (void)reloadItemWithData:(id<TuSDKTSAssetInterface>)asset;

@end
