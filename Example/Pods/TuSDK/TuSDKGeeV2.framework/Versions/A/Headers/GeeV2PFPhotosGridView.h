//
//  GeeV2PFPhotosGridView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "GeeV2ICGridView.h"
#import "GeeV2PFPhotosGridCell.h"
#import "TuSDKGeeV2Import.h"

/**
 *  相册照片列表行视图委托
 */
@protocol GeeV2PFPhotoGridProtocol <NSObject>
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
 *  @return gridCellData
 */
- (NSMutableArray<GeeV2TSPhotosGridCellData *> *)getSelectedItem;
@end

/**
 *  相册照片列表视图
 */
@interface GeeV2PFPhotosGridView : GeeV2ICGridView<UICollectionViewDataSource, UICollectionViewDelegate>

/**
 *  表格单元格视图类 (默认:GeeV2PFPhotosGridCell, 需要继承 GeeV2PFPhotosGridCell)
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
 *  照片排序字段 默认根据创建时间排序 ( lsqAssetSortKeyModificationDate 类型 iOS8以上可用)
 */
@property (nonatomic,assign) lsqAssetSortKeyType photosSortKeyType;

/**
 *  当前选中相册组
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<GeeV2PFPhotoGridProtocol> gridProtocol;

#pragma mark - refresh selection item
/**
 *  重置单元格视图
 *
 *  @param asset 单元格数据对象
 */
- (void)reloadItemWithData:(id<TuSDKTSAssetInterface>)asset;

@end
