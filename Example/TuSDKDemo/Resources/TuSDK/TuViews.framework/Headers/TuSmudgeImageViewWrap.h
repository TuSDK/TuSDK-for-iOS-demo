//
//  TuSmudgeImageViewWrap.h
//  TuSDK
//
//  Created by Yanlin on 10/28/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "TuSDKPulseCore/tools/TuTSScreen+Extend.h"
//#import "TuSDKPulseCore/components/widgets/smudge/TuBrush.h"
//#import "TuSDKPulseCore/components/widgets/smudge/TuBrushManager.h"
//#import "TuSDKPulseCore/components/widgets/smudge/TuBrushLocalPackage.h"
#import "TuSmudgeProcessor.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>
#pragma mark - TuSmudgeImageViewDelegate

@protocol TuSmudgeImageViewDelegate <NSObject>

/**
 *  用户操作导致撤销/重做数据发生变化
 *
 *  @param undoCount 可以撤销的次数
 *  @param redoCount 可以重做的次数
 */
- (void)onRefreshStepStatesWithHistories:(NSUInteger)undoCount redoCount:(NSUInteger)redoCount;

@optional

/**
 *  涂抹动作改变
 *
 *  @param point  偏向上的涂抹位置
 *  @param viewPoint  视图上的涂抹位置
 *  @param width  画布宽度
 *  @param height 画布高度
 */
- (void)onSmudgeActionChanged:(CGPoint)point viewLocation:(CGPoint)viewPoint canvasWidth:(CGFloat)width canvasHeight:(CGFloat)height;
/**
 *  涂抹动作结束
 */
- (void)onSmudgeActionEnd;
@end


#pragma mark - TuSmudgeImageViewInterface
/**
 *  Smudge Image View Interface
 */
@protocol TuSmudgeImageViewInterface <NSObject>

/**
 *  画布操作事件委托
 */
@property (nonatomic, weak) id<TuSmudgeImageViewDelegate> delegate;

/**
 *  显示的图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  笔刷对象
 */
- (void)setBrush:(TuBrush *)brush;

/**
 *  笔刷粗细， 0 < brushSize <= 1
 */
- (void)setBrushSize:(TuSDKBrushSize)brushSize;

/**
 *  橡皮粗细  0.05 < mBrushCustomSize < 0.25
 */
- (void)setBrushCustomSize:(CGFloat)mBrushCustomSize;

/**
 *  默认撤销的最大次数 (默认: 5)
 */
- (void)setMaxUndoCount:(NSUInteger)mMaxUndoCount;

/**
 *  撤销上一步
 */
- (void)undo;

/**
 *  重做上一步
 */
- (void)redo;

/**
 *  显示原图
 *
 *  @param state 显示 | 关闭
 */
- (void)showOriginal:(BOOL)state;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  合成最终效果图
 *
 *  @param source 原图
 */
- (UIImage*)getCanvasImage:(UIImage *)source;

/**
 *  获取绘制图
 *
 *  @return image 效果图
 */
- (UIImage *)getSmudgeImage;

/**
 *  获取原始图
 *
 *  @return image 原始图
 */
- (UIImage *)getOriginalImage;

/**
 *  清理内存
 */
- (void)destroy;
/**
 *  销毁历史记录
 */
- (void)destroyHistory;
@end


#pragma mark - TuSmudgeImageViewWrap

@interface TuSmudgeImageViewWrap : UIView<TuSmudgeImageViewInterface>
{
    // 笔刷粗细
    TuSDKBrushSize _mBrushSize;
   
    // 橡皮粗细
    CGFloat _mBrushCustomSize;

    // 笔刷透明度度
    CGFloat _mBrushAlpha;
    
    // 当前笔刷
    TuBrush *_mBrush;
    
    //  默认撤销的最大次数 (默认: 5)
    NSUInteger _mMaxUndoCount;
    
    @protected
    // 涂抹处理器
    TuSimpleProcessor *_smudgeProcessor;
}

/**
 *  画布操作事件委托
 */
@property (nonatomic, weak) id<TuSmudgeImageViewDelegate> delegate;

/**
 *  显示的图片
 */
- (void)setImage:(UIImage *)image;


/**
 *  笔刷对象
 */
- (void)setBrush:(TuBrush *)mBrush;

/**
 *  笔刷粗细， 0 < brushSize <= 1
 */
- (void)setBrushSize:(TuSDKBrushSize)mBrushSize;

/**
 *  橡皮粗细  0.05 < mBrushCustomSize < 0.25
 */
- (void)setBrushCustomSize:(CGFloat)mBrushCustomSize;

/**
 *  默认撤销的最大次数 (默认: 5)
 */
- (void)setMaxUndoCount:(NSUInteger)mMaxUndoCount;

/**
 *  撤销上一步
 */
- (void)undo;

/**
 *  重做上一步
 */
- (void)redo;

/**
 *  显示原图
 *
 *  @param state 显示 | 关闭
 */
- (void)showOriginal:(BOOL)state;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  合成最终效果图
 *
 *  @param source 原图
 */
- (UIImage *)getCanvasImage:(UIImage *)source;

/**
 *  获取绘制图
 *
 *  @return image 效果图
 */
- (UIImage *)getSmudgeImage;

/**
 *  获取原始图
 *
 *  @return image 原始图
 */
- (UIImage *)getOriginalImage;

/**
 *  清理内存
 */
- (void)destroy;
@end
