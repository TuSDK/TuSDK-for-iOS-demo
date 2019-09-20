//
//  GeeV2PFPhotosGridCell.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeeV2ICCircularProgressView.h"
#import "TuSDKGeeV2Import.h"

@interface GeeV2TSPhotosGridCellData : NSObject
/**
 *  是否正在下载数据
 */
@property (nonatomic, assign) BOOL downloading;

/**
 * 下载进度，-1表示无下载状态
 */
@property (nonatomic, assign) double progress;

/**
 *  选择序列，-1表示不在选择队列中
 */
@property (nonatomic, assign) NSInteger index;

/**
 *  媒体资源图片
 */
@property (nonatomic, retain) id<TuSDKTSAssetInterface> asset;

/**
 *  初始化方法
 *
 *  @param asset 字典数据
 *
 */
+ (instancetype)dataWithAsset:(id<TuSDKTSAssetInterface>)asset;

@end


@protocol GeeV2PFPhotosGridCellDelegate;
/**
 * 相册图标在列表中的占位符
 */
extern NSString * const CAMERA_GeeV2_PLACEHOLDER;

/**
 *  相册照片单元格视图
 */
@interface GeeV2PFPhotosGridCell : UICollectionViewCell
{
    
    @protected
    UIImageView *_thumbView;
    
    @protected
    UIButton *_selectedView;
    
    @protected
    UIButton *_selectButton;
    
    @protected
    BOOL _cellSelected;
}

/**
 *  下载进度背景view
 */
@property (nonatomic, retain) UIImageView *thumbView;

/**
 *  是否为多选模式
 */
@property (nonatomic, assign) BOOL enableMultiSelection;

/**
 *  下载进度背景view
 */
@property (nonatomic, retain) UIView *progressBgView;

/**
 *  下载进度view
 */
@property (nonatomic, retain) GeeV2ICCircularProgressView *progressView;

/**
 * 相册照片表单元格协议
 */
@property (nonatomic, weak) id<GeeV2PFPhotosGridCellDelegate> photosGridCellDelegate;

/**
 *  初始化视图
 */
- (void)lsqInitView;

// 重置视图
- (void)viewNeedRest;

/**
 *  设置单元格显示数据
 *
 *  @param data 数据
 */
- (void)setData:(id)data;

/**
 *  设置cell的样式
 *
 *  @param cellData 单元格数据
 */
- (void)setSelectionCellData:(GeeV2TSPhotosGridCellData *)cellData;

@end

@protocol GeeV2PFPhotosGridCellDelegate <NSObject>

@optional
/**
 *  添加单元格数据到选择队列
 *
 *  @param photosGridCell 当前单元格
 */
- (void)didSelectCell:(GeeV2PFPhotosGridCell *)photosGridCell;
@end

