//
//  GeeV2PFEditSmudgeOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditSmudgeController.h"

@interface GeeV2PFEditSmudgeOptions : TuSDKCPImageResultOptions

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
@property (nonatomic, retain) NSArray * brushGroup;

/**
 *  默认的笔刷大小 (默认: lsqMediumBrush，中等粗细)
 */
@property (nonatomic, assign) lsqGeeV2BrushSize defaultBrushSize;

/**
 *  是否保存上一次使用的笔刷
 */
@property (nonatomic) BOOL saveLastBrush;

/**
 *  默认撤销的最大次数 (默认: 5)
 */
@property (nonatomic, assign) NSUInteger maxUndoCount;

/**
 *  创建笔刷编辑控制器对象
 *
 *  @return controller 笔刷编辑控制器对象
 */
- (GeeV2PFEditSmudgeController *)viewController;

@end
