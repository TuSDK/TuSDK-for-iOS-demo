//
//  TuBrushTableItemCellBase.h
//  TuSDK
//
//  Created by Yanlin on 11/8/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "TuSDKPulseCore/components/widgets/smudge/TuBrush.h"
#import "TuTableViewCell.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>

#pragma mark - TuBrushTableItemCellInterface

/**
 *  笔刷元素视图接口
 */
@protocol TuBrushTableItemCellInterface <NSObject>

/**
 *  数据对象
 */
@property (nonatomic, retain) TuBrush *mode;

@end

#pragma mark - TuBrushTableItemCellDelegate

@class TuBrushTableItemCellBase;

/**
 *  笔刷视图基础类委托
 */
@protocol TuBrushTableItemCellDelegate <NSObject>

/**
 *  删除笔刷
 *
 *  @param cell 笔刷视图
 */
- (void)onBrushCellRemove:(TuBrushTableItemCellBase *)cell;
@end


#pragma mark - TuBrushTableItemCellBase
/**
 *  笔刷元素视图基础类
 */
@interface TuBrushTableItemCellBase : TuTableViewCell<TuBrushTableItemCellInterface>

/**
 *  数据对象
 */
@property (nonatomic, retain) TuBrush *mode;

/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *thumbView;

/**
 *  滤镜分组视图委托
 */
@property (nonatomic, weak) id<TuBrushTableItemCellDelegate> delegate;

/**
 *  初始化视图 (空方法, 默认当使用+(id)initWithFrame:(CGRect)frame;初始化视图时调用)
 */
- (void)lsqInitView;

/**
 *  是否隐藏删除标识
 *
 *  @return 是否隐藏删除标识
 */
- (BOOL)canHiddenRemoveFlag;

/**
 *  笔刷
 *
 *  @param mode 笔刷元素
 */
- (void)handleTypeBrush:(TuBrush *)mode;

/**
 *  在线笔刷
 *
 *  @param mode 笔刷元素
 */
- (void)handleTypeOnlie:(TuBrush *)mode;

/**
 *  橡皮擦
 *
 *  @param mode 笔刷元素
 */
- (void)handleTypeEraser:(TuBrush *)mode;

/**
 *  设置功能块视图
 *
 *  @param color 颜色
 *  @param icon  图标
 */
- (void)handleBlockView:(UIColor *)color icon:(NSString *)icon;
@end
