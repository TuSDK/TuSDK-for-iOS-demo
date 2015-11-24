//
//  TuSDKPFEditSmudgeOptions.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 10/28/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditSmudgeController.h"

@interface TuSDKPFEditSmudgeOptions : TuSDKCPImageResultOptions

/**
 *  视图类 (默认:TuSDKPFEditSmudgeView, 需要继承 TuSDKPFEditSmudgeView)
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
 *  单元格视图类 (默认:TuSDKPFBrushTableItemCell, 需要继承 TuSDKPFBrushTableItemCell)
 */
@property (nonatomic, strong) Class brushBarCellClazz;

/**
 *  需要显示的笔刷名称列表 (如果为空将显示所有自定义笔刷)
 */
@property (nonatomic, retain) NSArray * brushGroup;

/**
 *  默认的笔刷大小 (默认: lsqMediumBrush，中等粗细)
 */
@property (nonatomic, assign) lsqBrushSize defaultBrushSize;

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
 *  @return 笔刷编辑控制器对象
 */
- (TuSDKPFEditSmudgeController *)viewController;

@end
