//
//  TuSDKPFEditAdjustView.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/29.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKTSBundle.h"
#import "TuSDKCPFilterResultController.h"

#pragma mark - TuSDKPFEditAdjustOptionBar
/**
 *  选项栏目
 */
@interface TuSDKPFEditAdjustOptionBar : UIView
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
 *  @param type 图片编辑动作类型
 *
 *  @return 动作按钮
 */
- (UIButton *)buildButtonWithActionType:(NSString *)module;

/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - TuSDKPFEditAdjustView
/**
 *  颜色调整控制器视图
 */
@interface TuSDKPFEditAdjustView : TuSDKCPFilterResultView
{
    @protected
    // 选项栏目
    TuSDKPFEditAdjustOptionBar *_optionBar;
    // 参数配置视图完成按钮
    UIButton *_configCompleteButton;
}
/**
 *  选项栏目
 */
@property (nonatomic, readonly) TuSDKPFEditAdjustOptionBar *optionBar;

/**
 *  参数配置视图完成按钮
 */
@property (nonatomic, readonly) UIButton *configCompleteButton;

/**
 *  点击配置完成按钮动作
 */
- (void)onConfigCompleteAction;

/**
 *  显示配置选项
 *
 *  @param key 配置选项键
 */
- (void)showConfigWithKey:(NSString *)key;
@end
