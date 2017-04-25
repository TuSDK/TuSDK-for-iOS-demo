//
//  GeeV2PFEditWipeAndFilterView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV2Import.h"
#pragma mark - GeeV2PFBrushStepView
/**
 *  操作步骤视图
 */
@interface GeeV2PFBrushStepView : UIView
{
    // 后退按钮
    UIButton *_prevButton;
    // 前进按钮
    UIButton *_nextButton;
}
/**
 *  后退按钮
 */
@property (nonatomic, readonly) UIButton *prevButton;

/**
 *  前进按钮
 */
@property (nonatomic, readonly) UIButton *nextButton;
@end

#pragma mark - GeeV2PFBrushBarViewDelegate

@class GeeV2PFBrushBarView;
/**
 *  笔刷尺寸配置栏视图委托
 */
@protocol GeeV2PFEditWipeAndFilterConfigBarDelegate <NSObject>
/**
 *  选择笔刷尺寸按钮
 */
- (void)onBrushSizeSelected:(lsqBrushSize)brushSize;
@end

#pragma mark - GeeV2PFEditWipeAndFilterConfigBar

/**
 *  笔刷尺寸配置栏视图
 */
@interface GeeV2PFEditWipeAndFilterConfigBar : UIView
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
@property (nonatomic, weak) id<GeeV2PFEditWipeAndFilterConfigBarDelegate> delegate;

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

#pragma mark - GeeV2PFEditWipeAndFilterView

/**
 *  滤镜涂抹控制器视图
 */
@interface GeeV2PFEditWipeAndFilterView : TuSDKPFSmudgeViewBase

/**
 *  涂抹视图
 */
@property (nonatomic, readonly) UIView<TuSDKICSmudgeImageViewInterface> *imageView;

/**
 *  笔刷栏视图
 */
@property (nonatomic, readonly) GeeV2PFEditWipeAndFilterConfigBar *brushConfigBar;

/**
 *  操作步骤视图
 */
@property (nonatomic, retain) GeeV2PFBrushStepView *stepView;

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
