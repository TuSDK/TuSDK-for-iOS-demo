//
//  VerticalMenuView.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/18.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunguarded-availability"

// 选项组栈视图配置 Block
typedef void(^VerticalMenuItemOptionsViewConfig)(UIStackView *optionsStackView);

#pragma clang diagnostic pop

/**
 纵向菜单视图
 */
@interface VerticalMenuView : UIView

/**
 标题
 */
@property (nonatomic, copy) NSString *title;

/**
 配置方法，子类需继承调用
 */
- (void)commonInit;

/**
 添加 cell

 @param title cell 辩题
 @param configHandler 配置处理块
 */
- (void)addCellWithTitle:(NSString *)title optionsConfig:(VerticalMenuItemOptionsViewConfig)configHandler;

/**
 设置对应行隐藏

 @param hiddenRow 行索引
 */
- (void)addHiddenRow:(NSInteger)hiddenRow;

/**
 设置隐藏行显示

 @param hiddenRow 行索引
 */
- (void)removeHiddenRow:(NSInteger)hiddenRow;

/**
 给定行是否隐藏

 @param row 行索引
 @return 是否隐藏
 */
- (BOOL)isRowHidden:(NSInteger)row;

@end
