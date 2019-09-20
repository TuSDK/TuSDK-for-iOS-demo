//
//  GeeV2PFEditSmudgeController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeeV2PFEditSmudgeView.h"

#pragma mark - GeeV2PFEditSmudgeControllerDelegate
@class GeeV2PFEditSmudgeController;
/**
 *  涂抹编辑控制器委托
 */
@protocol GeeV2PFEditSmudgeControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 笔刷编辑控制器
 *  @param result 处理结果
 */
- (void)onGeeV2PFEditSmudge:(GeeV2PFEditSmudgeController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 笔刷编辑控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncGeeV2PFEditSmudge:(GeeV2PFEditSmudgeController *)controller result:(TuSDKResult *)result;
@end


#pragma mark - GeeV2PFEditSmudgeController
/**
 *  涂抹编辑控制器
 */
@interface GeeV2PFEditSmudgeController : TuSDKPFEditSmudgeControllerBase<GeeV2PFBrushBarViewDelegate>
{
    // 默认样式视图
    GeeV2PFEditSmudgeView *_defaultStyleView;
}

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFEditSmudgeView *defaultStyleView;

/**
 *  涂抹编辑控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFEditSmudgeControllerDelegate> delegate;

/**
 *  视图类 (默认:GeeV2PFEditSmudgeView, 需要继承 GeeV2PFEditSmudgeView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  单元格宽度
 */
@property (nonatomic) NSUInteger brushBarCellWidth;

/**
 *  单元格高度
 */
@property (nonatomic) NSUInteger brushBarHeight;

/**
 *  单元格视图类 (默认:GeeV2PFBrushTableItemCell, 需要继承 GeeV2PFBrushTableItemCell)
 */
@property (nonatomic, strong) Class brushBarCellClazz;

/**
 *  需要显示的笔刷名称列表 (如果为空将显示所有自定义笔刷)
 */
@property (nonatomic, retain) NSArray *brushGroup;

/**
 *  默认的笔刷大小 (默认: lsqGeeV2MediumBrush，中等粗细)
 */
@property (nonatomic, assign) lsqGeeV2BrushSize defaultBrushSize;

/**
 *  是否保存上一次使用的笔刷 (默认: YES)
 */
@property (nonatomic) BOOL saveLastBrush;

/**
 *  默认撤销的最大次数 (默认: 5)
 */
@property (nonatomic, assign) NSUInteger maxUndoCount;

@end
