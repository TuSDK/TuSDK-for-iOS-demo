//
//  TuBubbleView.h
//  TuSDKDemo
//
//  Created by 刘鹏程 on 2021/2/25.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <TuSDKPulseFilter/TUPFPFilter.h>
#import <TuSDKPulseFilter/TUPFPBubbleTextFilter.h>
#import "TUPFPBubbleTextFilter_Info.h"

@class TuBubbleItemView;
@class TuBubbleView;
@protocol TuBubbleItemViewInterface;

/**
 *  贴纸元件视图委托
 */
@protocol TuBubbleItemViewDelegate <NSObject>
/**
 *  贴纸元件关闭
 *
 *  @param view 贴纸元件视图
 */
- (void)onClosedBubbleItemView:(UIView<TuBubbleItemViewInterface> *)view;

/**
 *  选中贴纸元件
 *
 *  @param view 贴纸元件视图
 */
- (void)onSelectedBubbleItemView:(UIView<TuBubbleItemViewInterface> *)view;

- (void)tuBubbleItemView:(UIView<TuBubbleItemViewInterface> *)view moveBubbleSticker:(TUPFPBubbleTextFilter_Info *)filterInfo;

@end


/**
 *  贴纸元件视图接口
 */
@protocol TuBubbleItemViewInterface <NSObject>
/**
 *  贴纸元件视图委托
 */
@property (nonatomic, weak) id<TuBubbleItemViewDelegate> delegate;

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

@property (nonatomic, strong) TUPFPBubbleTextFilter_Info *posInfo;

/**加载数据*/
- (void)reloadData;

/**
 *  获取贴纸处理结果
 *
 *  @param regionRect 图片选区范围
 *
 *  @return 贴纸处理结果
 */
//- (TuStickerResult *)resultWithRegionRect:(CGRect)regionRect;
@end

#pragma mark - TuStickerItemView
/**
 *  贴纸元件视图
 */
@interface TuBubbleItemView : UIView<TuBubbleItemViewInterface>{
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
@property (nonatomic, weak) id<TuBubbleItemViewDelegate> delegate;

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


@property (nonatomic, strong) TUPFPBubbleTextFilter_Info *posInfo;

/**
 *  重置图片视图边缘距离
 */
- (void)resetImageEdge;

@end

#pragma mark - TuBubbleView

/**
 *  贴纸视图委托
 */
@protocol TuBubbleViewDelegate <NSObject>

/**
 *  贴纸元件关闭
 *
 *  @param bubbleIndex 气泡文字ID
 */
- (void)onClosedBubbleTextItemView:(int)bubbleIndex;

- (void)tuBubbleView:(TuBubbleView *)view onMoveBubbleSticker:(TUPFPBubbleTextFilter_Info *)filterInfo;

/**点击空白隐藏*/
- (void)onCancelAllSelectedView:(TuBubbleView *)view;

@end

@interface TuBubbleView : UIView<TuBubbleItemViewDelegate>

/**filter标签*/
@property (nonatomic, strong) TUPFPBubbleTextFilter_Info *posInfo;

/**
 * 添加气泡文字
 * @param stickerImage 贴纸图片
 */
- (void)appendBubbleSticker:(UIImage *)inputImage;

@property (nonatomic, weak) id<TuBubbleViewDelegate> delegate;

/**
 *  当前已使用贴纸总数
 */
@property (nonatomic, readonly) NSUInteger stickerCount;



@end

