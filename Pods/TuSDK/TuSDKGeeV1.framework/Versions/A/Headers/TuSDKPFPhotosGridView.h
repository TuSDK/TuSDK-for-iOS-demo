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
 *  获取单元格
 *
 *  @param asset 单元格数据
 *
 *  @return 选择索引
 */
- (NSInteger)getAssetSelectionIndex:(id)asset;
@end

/**
 *  相册照片列表视图
 */
@interface TuSDKPFPhotosGridView : TuSDKICGridView<UICollectionViewDataSource, UICollectionViewDelegate>

/**
 *  表格行视图类 (默认:TuSDKPFPhotosGridCell, 需要继承 TuSDKPFPhotosGridCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  表格单元格视图类 (默认:TuSDKPFPhotosGrid, 需要继承 TuSDKPFPhotosGrid)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 *  相册列表每行显示的照片数量 (默认:0, 程序自动适配设备)
 */
@property (nonatomic, assign) NSUInteger photoColumnNumber;

/**
 *  是否为多选模式
 */
@property (nonatomic, assign) BOOL enableMultiSelection;

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
