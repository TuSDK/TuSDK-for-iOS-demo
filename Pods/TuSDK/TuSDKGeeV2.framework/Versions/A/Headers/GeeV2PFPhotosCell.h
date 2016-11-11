//
//  GeeV2PFPhotosCell.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"

#pragma mark - GeeV2PFPhotosCellSectionHeader
/**
 *  相册照片列表行标题视图
 */
@interface GeeV2PFPhotosCellSectionHeader : UIView
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

#pragma mark - GeeV2PFPhotosGrid
/**
 *  相册照片列表单元格视图
 */
@interface GeeV2PFPhotosGrid : UIButton
/**
 *  图片视图
 */
@property(nonatomic,readonly) UIImageView *thumbView;
/**
 *  照片数据
 */
@property (nonatomic, retain) id<TuSDKTSAssetInterface> data;
@end

#pragma mark - GeeV2PFPhotosCell
/**
 *  相册照片列表行视图委托
 */
@protocol GeeV2PFPhotosCellProtocol <NSObject>
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
@interface GeeV2PFPhotosCell : TuSDKICTableViewCell
/**
 *  表格单元格视图类 (默认:GeeV2PFPhotosGrid, 需要继承 GeeV2PFPhotosGrid)
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
@property (nonatomic, assign) id<GeeV2PFPhotosCellProtocol> gridProtocol;

/**
 *  设置数据
 *
 *  @param data 数据
 */
- (void)setData:(NSArray<TuSDKTSAssetInterface> *)data;
@end
