//
//  TuSDKPFEditPaintView.h
//  TuSDKGeeV1
//
//  Created by tutu on 2018/11/29.
//  Copyright © 2018 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFPaintBarView.h"
#import "TuSDKPFEditPaintBottomBar.h"
#import "TuSDKCPPaintDrawView.h"
#import "TuSDKGeeV1Import.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuSDKPFEditPaintView : UIView

/**
 *  涂鸭视图
 *  @since v3.1.0
 */
@property (nonatomic, readonly) TuSDKCPPaintDrawView *paintDrawView;

/**
 *  笔刷栏视图
 *  @since v3.1.0
 */
@property (nonatomic, readonly) TuSDKPFPaintBarView *brushBar;

/**
 *  底部动作栏
 *  @since v3.1.0
 */
@property (nonatomic, readonly) TuSDKPFEditPaintBottomBar *bottomBar;

/**
 *  需要显示的笔刷名称列表 (如果为空将显示所有自定义笔刷)
 *  @since v3.1.0
 */
@property (nonatomic, retain) NSArray<NSString *> * brushGroup;

/**
 *  默认的笔刷大小 (默认: lsqMediumBrush，中等粗细)
 *  @since v3.1.0
 */
@property (nonatomic, assign) lsqBrushSize defaultBrushSize;

/**
 *  笔刷的缩放尺寸, 默认1.5pt，范围(1-3)
 *  笔刷的真正大小是 defaultBrushSize * brushScaleSize
 *  @since v3.1.0
 */
@property (nonatomic, assign) CGFloat brushScaleSize;

/**
 *  笔刷绘制时，上一点与下一点的距离最小满足多大时，才进行绘制
 *  默认 10，范围（0-20）过小时绘制慢时会有锯齿，过大时，绘制就会出现断层
 *  @since v3.1.0
 */
@property (nonatomic, assign) CGFloat minDistance;

/**
 *  是否保存上一次使用的笔刷 (默认: YES)
 *  @since v3.1.0
 */
@property (nonatomic) BOOL saveLastBrush;

/**
 *  默认撤销的最大次数 (默认: 5)
 *  @since v3.1.0
 */
@property (nonatomic, assign) NSUInteger maxUndoCount;

/**
 *  单元格宽度 60
 *  @since v3.1.0
 */
@property (nonatomic) NSUInteger brushBarCellWidth;

/**
 *  单元格高度: 默认80
 *  @since v3.1.0
 */
@property (nonatomic) NSUInteger brushBarHeight;

/**
 *  更新布局
 *  @since v3.1.0
 *
 */
- (void)needUpdateLayout;

/**
 *  设置图片
 *  @since v3.1.0
 *
 *  @param image 图片
 */
- (void)setImage:(UIImage *)image;


/**
 *  是否显示原图
 *  @since v3.1.0
 *  @param isShow yes ---展示原图，no---展示涂鸦后的图片
 */
- (void)showOriginImage:(BOOL)isShow;

/**
 *  切换笔刷粗细
 *  @since v3.1.0
 */
- (void)switchPaintSize;

/**
 *  选中笔刷颜色
 *  @since v3.1.0
 *
 *  @param colorCode  颜色代号
 *
 *  @return 是否成功切换
 */
- (BOOL)selectColor:(NSString *)colorCode;

@end

NS_ASSUME_NONNULL_END
