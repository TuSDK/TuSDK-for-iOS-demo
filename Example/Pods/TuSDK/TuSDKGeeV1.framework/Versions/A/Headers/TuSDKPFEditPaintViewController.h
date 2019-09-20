//
//  TuSDKPFEditPaintViewController.h
//  TuSDKGeeV1
//
//  Created by tutu on 2018/11/28.
//  Copyright © 2018 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFEditPaintView.h"
#import "TuSDKGeeV1Import.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - TuSDKPFEditSmudgeControllerDelegate
@class TuSDKPFEditPaintViewController;

/**
 *  涂抹编辑控制器委托
 *  @since v3.1.0
 */
@protocol TuSDKPFEditPaintViewControllerDelegate <TuSDKCPComponentErrorDelegate>

/**
 *  图片编辑完成
 *  @since v3.1.0
 *
 *  @param controller 笔刷编辑控制器
 *  @param result 处理结果
 */
- (void)onTuSDKPFEditPaint:(TuSDKPFEditPaintViewController *)controller result:(TuSDKResult *)result;
@optional

/**
 *  图片编辑完成  (异步方法)
 *  @since v3.1.0
 *
 *  @param controller 笔刷编辑控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditPaint:(TuSDKPFEditPaintViewController *)controller result:(TuSDKResult *)result;
@end


#pragma mark - TuSDKPFEditSmudgeController
/**
 *  涂抹编辑控制器
 *  @since v3.1.0
 */
@interface TuSDKPFEditPaintViewController : TuSDKCPImageResultController<TuSDKPFPaintBarViewDelegate>
{
    // 默认样式视图
    TuSDKPFEditPaintView *_paintView;
}

/**
 *  默认样式视图 (如果覆盖 paintView 方法，实现了自己的视图，paintView == nil)
 *  @since v3.1.0
 */
@property (nonatomic, readonly) TuSDKPFEditPaintView *paintView;

/**
 *  涂抹编辑控制器委托
 *  @since v3.1.0
 */
@property (nonatomic, weak) id<TuSDKPFEditPaintViewControllerDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFEditPaintView, 需要继承 TuSDKPFEditPaintView)
 *  @since v3.1.0
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  单元格宽度
 *  @since v3.1.0
 */
@property (nonatomic) NSUInteger brushBarCellWidth;

/**
 *  单元格高度
 *  @since v3.1.0
 */
@property (nonatomic) NSUInteger brushBarHeight;

/**
 *  单元格视图类 (默认:TuSDKPFBrushTableItemCell, 需要继承 TuSDKPFBrushTableItemCell)
 *  @since v3.1.0
 */
@property (nonatomic, strong) Class brushBarCellClazz;

/**
 *  需要显示的笔刷名称列表 (如果为空将显示所有自定义笔刷)
 *  默认 @[@"#f9f9f9", @"#2b2b2b", @"#ff1d12", @"#fbf606", @"#14e213", @"#199bff", @"#8c06ff"]
 *  @since v3.1.0
 */
@property (nonatomic, retain) NSArray<NSString *> *brushGroup;

/**
 *  默认的笔刷大小 (默认: lsqMediumBrush，中等粗细) 2.0pt (small - 1.0pt; large -- 4.0pt)
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
@end

NS_ASSUME_NONNULL_END
