//
//  TuSDKICSmudgeImageViewWrap.h
//  TuSDK
//
//  Created by Yanlin on 10/28/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKTSScreen+Extend.h"
#import "TuSDKPFBrush.h"
#import "TuSDKPFBrushManager.h"
#import "TuSDKPFBrushLocalPackage.h"
#import "TuSDKPFSmudgeProcessor.h"

#ifndef SmudgeView_Define
#define SmudgeView_Define

#define lsq_PIXEL_PER_POINT     [UIScreen scale]

#define lsq_BYTES_PER_PIXEL     4
#define lsq_BITS_PER_COMPONENT 8

#define lsq_TILE_SIZE 10

#define lsq_rgbaDataIndex(width, x, y)    ((width) * (y) + (x)) * lsq_BYTES_PER_PIXEL

#endif

#pragma mark - TuSDKICSmudgeImageViewDelegate

@protocol TuSDKICSmudgeImageViewDelegate <NSObject>

/**
 *  用户操作导致撤销/重做数据发生变化
 *
 *  @param undoCount 可以撤销的次数
 *  @param redoCount 可以重做的次数
 */
- (void)onRefreshStepStatesWithHistories:(NSUInteger)undoCount redoCount:(NSUInteger)redoCount;

@end

#pragma mark - TuSDKICSmudgeImageViewInterface
/**
 *  Smudge Image View Interface
 */
@protocol TuSDKICSmudgeImageViewInterface <NSObject>

/**
 *  画布操作事件委托
 */
@property (nonatomic, assign) id<TuSDKICSmudgeImageViewDelegate> delegate;

/**
 *  显示的图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  笔刷对象
 */
- (void)setBrush:(TuSDKPFBrush *)brush;

/**
 *  笔刷粗细， 0 < brushSize <= 1
 */
- (void)setBrushSize:(lsqBrushSize)brushSize;

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
 *  获取最终效果图
 *
 *  @param source 原图
 */
- (UIImage*)getCanvasImage:(UIImage *)source;

/**
 *  清理内存
 */
- (void)destroy;
@end


#pragma mark - TuSDKICSmudgeImageViewWrap

@interface TuSDKICSmudgeImageViewWrap : UIView<TuSDKICSmudgeImageViewInterface>
{
    // 笔刷粗细
    lsqBrushSize _mBrushSize;
    
    // 笔刷透明度度
    CGFloat _mBrushAlpha;
    
    // 当前笔刷
    TuSDKPFBrush *_mBrush;
    
    //  默认撤销的最大次数 (默认: 5)
    NSUInteger _mMaxUndoCount;
}

/**
 *  画布操作事件委托
 */
@property (nonatomic, assign) id<TuSDKICSmudgeImageViewDelegate> delegate;

/**
 *  显示的图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  笔刷对象
 */
- (void)setBrush:(TuSDKPFBrush *)mBrush;

/**
 *  笔刷粗细， 0 < brushSize <= 1
 */
- (void)setBrushSize:(lsqBrushSize)mBrushSize;

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
 *  获取最终效果图
 *
 *  @param source 原图
 */
- (UIImage*)getCanvasImage:(UIImage *)source;

/**
 *  清理内存
 */
- (void)destroy;
@end
