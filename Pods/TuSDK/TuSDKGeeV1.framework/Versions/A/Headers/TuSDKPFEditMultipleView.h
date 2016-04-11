//
//  TuSDKPFEditMultipleView.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKPFEditEntryStepView
/**
 *  操作步骤视图
 */
@interface TuSDKPFEditEntryStepView : UIView
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
/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - TuSDKPFEditMultipleOptionBar
/**
 *  选项栏目
 */
@interface TuSDKPFEditMultipleOptionBar : UIView
{
    // 横向滚动视图
    UIScrollView *_wrapView;
    // 模块按钮列表
    NSMutableArray *_buttons;
}

/**
 *  横向滚动视图
 */
@property (nonatomic, readonly) UIScrollView *wrapView;
/**
 *  绑定功能模块
 *
 *  @param modules 功能模块列表
 *  @param target  绑定事件对象
 *  @param action  绑定事件
 */
- (void)bindModules:(NSArray *)modules target:(id)target action:(SEL)action;

/**
 *  创建动作按钮
 *
 *  @param module 图片编辑动作类型
 *  @param count  按钮总数
 *
 *  @return 动作按钮
 */
- (UIButton *)buildButtonWithActionType:(lsqTuSDKCPEditActionType)type moduleCount:(NSUInteger)count;

/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - TuSDKPFEditMultipleView
/**
 *  多功能图像编辑控制器视图
 */
@interface TuSDKPFEditMultipleView : UIView
{
    // 操作步骤视图
    TuSDKPFEditEntryStepView *_stepView;
    // 自动校色按钮
    UIButton *_autoAdjustButton;
    // 返回按钮
    UIButton *_cancelButton;
    // 完成按钮
    UIButton *_doneButton;
    // 选项栏目
    TuSDKPFEditMultipleOptionBar *_optionBar;
    // 图片视图
    UIImageView *_imageView;
}

/**
 *  操作步骤视图
 */
@property (nonatomic, readonly) TuSDKPFEditEntryStepView *stepView;

/**
 *  自动校色按钮
 */
@property (nonatomic, readonly) UIButton *autoAdjustButton;

/**
 *  返回按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *doneButton;

/**
 *  选项栏目
 */
@property (nonatomic, readonly) TuSDKPFEditMultipleOptionBar *optionBar;
/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *imageView;
/**
 *  更新布局
 */
- (void)needUpdateLayout;
@end