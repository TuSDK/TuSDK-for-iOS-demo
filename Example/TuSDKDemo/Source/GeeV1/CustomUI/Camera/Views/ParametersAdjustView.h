//
//  ParametersAdjustView.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/6/28.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 参数面板项
 */
@interface ParameterAdjustItemView : UIView

/**
 参数名称标签
 */
@property (nonatomic, strong, readonly) UILabel *nameLabel;

/**
 值变更 slider
 */
@property (nonatomic, strong, readonly) UISlider *slider;

/**
 值标签
 */
@property (nonatomic, strong, readonly) UILabel *valueLabel;

/**
 显示值偏移
 */
@property (nonatomic, assign) double displayValueOffset;

/**
 替换参数项控件

 @param targetView 原控件
 @param replacementView 替换后的控件
 */
- (void)replaceSubView:(UIView *)targetView withView:(__kindof UIView *)replacementView;

/**
 同步值标签
 */
- (void)updateValueText;

@end

// 参数配置 Block
typedef void(^ParametersAdjustViewConfigBlock)(NSUInteger index, ParameterAdjustItemView *itemView, void (^parameterItemConfig)(NSString *name, double percent));
// 参数变更回调 Block
typedef void(^ParametersValueChangeBlock)(NSUInteger index, double percent);

/**
 参数面板视图
 */
@interface ParametersAdjustView : UIView

/**
 参数项
 */
@property (nonatomic, strong, readonly) NSArray<ParameterAdjustItemView *> *itemViews;

/**
 面板的自适应高度
 */
@property (nonatomic, assign, readonly) CGFloat contentHeight;

/**
 配置参数
 注意本对象持有 valueChangeHandler，因此在 valueChangeHandler 中需要弱引用全局、成员变量

 @param parameterCount 参数个数
 @param configHandler 参数配置处理块
 @param valueChangeHandler 值变更处理块
 */
- (void)setupWithParameterCount:(NSInteger)parameterCount config:(ParametersAdjustViewConfigBlock)configHandler valueChange:(ParametersValueChangeBlock)valueChangeHandler;

@end
