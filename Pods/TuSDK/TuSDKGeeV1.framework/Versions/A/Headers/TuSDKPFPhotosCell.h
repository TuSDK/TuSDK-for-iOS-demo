//
//  TuSDKPFPhotosCell.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/11/2.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKPFPhotosCellSectionHeader
/**
 *  相册照片列表行标题视图
 */
@interface TuSDKPFPhotosCellSectionHeader : UIView
/**
 *  时间标签
 */
@property (nonatomic, readonly) UILabel *dateLabel;
/**
 *  星期标签
 */
@property (nonatomic, readonly) UILabel *weekLabel;
/**
 *  分组时间
 */
@property (nonatomic, retain) NSDate *date;
@end

#pragma mark - TuSDKPFPhotosGrid
/**
 *  相册照片列表单元格视图
 */
@interface TuSDKPFPhotosGrid : UIButton
/**
 *  图片视图
 */
@property(nonatomic,readonly) UIImageView *thumbView;
/**
 *  照片数据
 */
@property (nonatomic, retain) id<TuSDKTSAssetInterface> data;
@end

#pragma mark - TuSDKPFPhotosCell
/**
 *  相册照片列表行视图委托
 */
@protocol TuSDKPFPhotosCellProtocol <NSObject>
/**
 *  选中一张照片
 *
 *  @param asset 照片对象
 */
- (void)onTuSDKPFPhotosCellSelectedWithAsset:(id<TuSDKTSAssetInterface>)asset;
@end

/**
 *  相册照片列表行视图
 */
@interface TuSDKPFPhotosCell : TuSDKICTableViewCell
/**
 *  表格单元格视图类 (默认:TuSDKPFPhotosGrid, 需要继承 TuSDKPFPhotosGrid)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 *  网格视图算法
 */
@property (nonatomic, retain) TuSDKAOCellGridViewAlgorithmic *algorithmic;

/**
 *  单元格视图
 */
@property (nonatomic, readonly) NSArray *gridViews;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<TuSDKPFPhotosCellProtocol> gridProtocol;

/**
 *  设置数据
 *
 *  @param data 数据
 */
- (void)setData:(NSArray<TuSDKTSAssetInterface> *)data;
@end
