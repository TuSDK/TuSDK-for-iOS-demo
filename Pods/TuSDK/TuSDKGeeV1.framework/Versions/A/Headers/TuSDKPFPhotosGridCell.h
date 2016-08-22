//
//  TuSDKPFPhotosGridCell.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 8/12/15.
//  Copyright (c) 2015 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCircularProgressView.h"
#import "TuSDKGeeV1Import.h"

/**
 * 相册图标在列表中的占位符
 */
extern NSString * const CAMERA_PLACEHOLDER;

/**
 *  相册照片网格列表单元格视图
 */
@interface TuSDKPFPhotosGridCell : UICollectionViewCell{
    
    @protected
    UIImageView *_thumbView;
    
    @protected
    UIButton *_selectedView;
    
    @protected
    BOOL _cellSelected;
}

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
@property (nonatomic, retain) TuSDKCircularProgressView *progressView;

/**
 *  是否正在下载数据
 */
@property (nonatomic, assign)BOOL downloading;

/**
 *  媒体资源图片
 */
@property (nonatomic, retain) id<TuSDKTSAssetInterface> asset;



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
 *  设置选择序
 *
 *  @param index 选择序列
 */
-(void)setSelectionIndex:(NSInteger)index;

@end
