//
//  TuStickerView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/4.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuStickerResult.h"

@class TuStickerItemView;
@class TuStickerView;
@protocol TuStickerItemViewInterface;

/**
 *  贴纸元件视图委托
 */
@protocol TuStickerItemViewDelegate <NSObject>
/**
 *  贴纸元件关闭
 *
 *  @param view 贴纸元件视图
 */
- (void)onClosedStickerItemView:(UIView<TuStickerItemViewInterface> *)view;

/**
 *  选中贴纸元件
 *
 *  @param view 贴纸元件视图
 */
- (void)onSelectedStickerItemView:(UIView<TuStickerItemViewInterface> *)view;
@end

/**
 *  贴纸元件视图接口
 */
@protocol TuStickerItemViewInterface <NSObject>
/**
 *  贴纸元件视图委托
 */
@property (nonatomic, weak) id<TuStickerItemViewDelegate> delegate;

/**
 *  贴纸数据对象
 */
@property (nonatomic, retain) TuSticker *sticker;

/**
 *  边框宽度
 */
@property (nonatomic) CGFloat strokeWidth;

/**
 *  边框颜色
 */
@property (nonatomic, retain) UIColor *strokeColor;

/**
 *  选中状态
 */
@property (nonatomic) BOOL selected;

/**
 *  获取贴纸处理结果
 *
 *  @param regionRect 图片选区范围
 *
 *  @return 贴纸处理结果
 */
- (TuStickerResult *)resultWithRegionRect:(CGRect)regionRect;
@end

#pragma mark - TuStickerItemView
/**
 *  贴纸元件视图
 */
@interface TuStickerItemView : UIView<TuStickerItemViewInterface>{
    @protected
    // 图片视图
    UIImageView *_imageView;
    // 取消按钮
    UIButton *_cancelButton;
    // 旋转缩放按钮
    UIButton *_turnButton;
}
/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *imageView;
/**
 *  取消按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;
/**
 *  旋转缩放按钮
 */
@property (nonatomic, readonly) UIButton *turnButton;

/**
 *  贴纸元件视图委托
 */
@property (nonatomic, weak) id<TuStickerItemViewDelegate> delegate;

/**
 *  最小缩小比例(默认: 0.5f <= mMinScale <= 1)
 */
@property (nonatomic) CGFloat minScale;

/**
 *  边框宽度
 */
@property (nonatomic) CGFloat strokeWidth;

/**
 *  边框颜色
 */
@property (nonatomic, retain) UIColor *strokeColor;

/**
 *  选中状态
 */
@property (nonatomic) BOOL selected;

/**
 *  贴纸数据对象
 */
@property (nonatomic, retain) TuSticker *sticker;

/**
 *  重置图片视图边缘距离
 */
- (void)resetImageEdge;

/**
 *  获取贴纸处理结果
 *
 *  @param regionRect 图片选区范围
 *
 *  @return 贴纸处理结果
 */
- (TuStickerResult *)resultWithRegionRect:(CGRect)regionRect;
@end

#pragma mark - TuStickerView

/**
 *  贴纸视图委托
 */
@protocol TuSDKPFStickerViewDelegate <NSObject>
/**
 *  检查是否允许使用贴纸
 *
 *  @param view    贴纸视图
 *  @param sticker 贴纸数据
 *
 *  @return 是否允许使用贴纸
 */
- (BOOL)stickerView:(TuStickerView *)view canAppend:(TuSticker *)sticker;
@end

/**
 *  贴纸视图
 */
@interface TuStickerView : UIView<TuStickerItemViewDelegate>
/**
 *  贴纸视图委托
 */
@property (nonatomic, weak) id<TuSDKPFStickerViewDelegate> delegate;

/**
 *  当前已使用贴纸总数
 */
@property (nonatomic, readonly) NSUInteger stickerCount;

/**
 *  添加一个贴纸
 *
 *  @param sticker 贴纸元素
 */
- (void)appenSticker:(TuSticker *)sticker;

/**
 *  添加贴纸
 *
 *  @param stickerImage 贴纸图片 (PNG格式)
 */
- (void)appendStickerImage:(UIImage *) stickerImage;


/**
 *  获取贴纸处理结果
 *
 *  @param regionRect 图片选区范围
 *
 *  @return 贴纸处理结果
 */
- (NSArray *)resultsWithRegionRect:(CGRect)regionRect;
@end
