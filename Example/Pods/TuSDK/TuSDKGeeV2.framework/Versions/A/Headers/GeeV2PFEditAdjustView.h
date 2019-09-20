//
//  GeeV2PFEditAdjustView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeeV2CPFilterResultView.h"

#pragma mark - GeeV2PFEditAdjustOptionBar
/**
 *  选项栏目
 */
@interface GeeV2PFEditAdjustOptionBar : UIView
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
 *  模块按钮列表
 */
@property (nonatomic, readonly) NSMutableArray *buttons;
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
 *  @return button 动作按钮
 */
- (UIButton *)buildButtonWithActionType:(NSString *)module moduleCount:(NSUInteger)count;

/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - GeeV2PFEditAdjustView
/**
 *  调整控制器视图
 */
@interface GeeV2PFEditAdjustView : GeeV2CPFilterResultView
{
@protected
    // 选项栏目
    GeeV2PFEditAdjustOptionBar *_optionBar;
}
/**
 *  选项栏目
 */
@property (nonatomic, readonly) GeeV2PFEditAdjustOptionBar *optionBar;


@end
