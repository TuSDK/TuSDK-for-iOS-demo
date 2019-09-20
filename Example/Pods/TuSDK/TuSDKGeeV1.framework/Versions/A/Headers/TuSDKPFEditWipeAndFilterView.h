//
//  TuSDKPFEditWipeAndFilterView.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 12/3/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"
#import "TuSDKPFEditSmudgeBottomBar.h"

#pragma mark - TuSDKPFEditWipeAndFilterConfigBar

#pragma mark - TuSDKPFBrushBarViewDelegate

@class TuSDKPFBrushBarView;
/**
 *  笔刷尺寸配置栏视图委托
 */
@protocol TuSDKPFEditWipeAndFilterConfigBarDelegate <NSObject>
/**
 *  选择笔刷尺寸按钮
 */
- (void)onBrushSizeSelected:(lsqBrushSize)brushSize;
@end

/**
 *  笔刷尺寸配置栏视图
 */
@interface TuSDKPFEditWipeAndFilterConfigBar : UIView
{
    // 小尺寸按钮
    UIButton *_smallSizeButton;
    // 中等尺寸按钮
    UIButton *_mediumSizeButton;
    // 大尺寸按钮
    UIButton *_largeSizeButton;
}

/**
 *  笔刷尺寸配置栏视图委托
 */
@property (nonatomic, weak) id<TuSDKPFEditWipeAndFilterConfigBarDelegate> delegate;

/**
 *  小尺寸按钮
 */
@property (nonatomic, readonly) UIButton *smallSizeButton;

/**
 *  中等尺寸按钮
 */
@property (nonatomic, readonly) UIButton *mediumSizeButton;

/**
 *  大尺寸按钮
 */
@property (nonatomic, readonly) UIButton *largeSizeButton;

/**
 *  设置当前笔刷粗细
 *
 *  @param mBrushSize 笔刷粗细
 */
- (void)setBrushSize:(lsqBrushSize)mBrushSize;

@end

#pragma mark - TuSDKPFEditWipeAndFilterView

/**
 *  滤镜涂抹控制器视图
 */
@interface TuSDKPFEditWipeAndFilterView : TuSDKPFSmudgeViewBase

/**
 *  涂抹视图
 */
@property (nonatomic, readonly) UIView<TuSDKICSmudgeImageViewInterface> *imageView;

/**
 *  笔刷栏视图
 */
@property (nonatomic, readonly) TuSDKPFEditWipeAndFilterConfigBar *brushConfigBar;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditSmudgeBottomBar *bottomBar;

/**
 *  笔刷大小演示容器
 */
@property (nonatomic, readonly) UIView *brushSizeAnimView;

/**
 *  放大区域图片
 */
@property (nonatomic, readonly) UIImageView *zoomInImage;

/**
 *  默认的笔刷大小 (默认: lsqMediumBrush，中等粗细)
 */
@property (nonatomic, assign) lsqBrushSize defaultBrushSize;

/**
 *  默认撤销的最大次数 (默认: 5)
 */
@property (nonatomic, assign) NSUInteger maxUndoCount;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  设置图片
 *
 *  @param image 图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  设置当前笔刷粗细
 *
 *  @param mBrushSize 笔刷粗细
 */
- (void)setBrushSize:(lsqBrushSize)mBrushSize;

/**
 *  获取笔刷像素尺寸
 *
 *  @return size 尺寸
 */
- (NSUInteger)getBrushSizeInPoint;

@end
