//
//  TuSDKPFEditApertureView.h
//  TuSDK
//
//  Created by Clear Hu on 15/5/7.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"
#import "TuSDKCPFilterResultView.h"

#pragma mark - TuSDKPFEditApertureOptionBar
/**
 *  选项栏目
 */
@interface TuSDKPFEditApertureOptionBar : UIView
{
    // 关闭按钮
    UIButton *_closeButton;
    // 径向按钮
    UIButton *_radialButton;
    // 线性按钮
    UIButton *_linearButton;
}

/**
 *  关闭按钮
 */
@property (nonatomic, readonly) UIButton *closeButton;

/**
 *  径向按钮
 */
@property (nonatomic, readonly) UIButton *radialButton;

/**
 *  线性按钮
 */
@property (nonatomic, readonly) UIButton *linearButton;

/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - TuSDKPFEditApertureView
/**
 *  大光圈视图
 */
@interface TuSDKPFEditApertureView : TuSDKCPFilterResultView
{
    @protected
    // 选项栏目
    TuSDKPFEditApertureOptionBar *_optionBar;
    // 参数配置视图完成按钮
    UIButton *_configCompleteButton;
    // 参数配置视图取消按钮
    UIButton *_configCancalButton;
    // 参数配置容器
    UIView *_configActionContainer;
    // 触摸视图
    UIView<TuSDKICGestureRecognizerViewInterface> *_touchView;
}
/**
 *  选项栏目
 */
@property (nonatomic, readonly) TuSDKPFEditApertureOptionBar *optionBar;

/**
 *  参数配置视图完成按钮
 */
@property (nonatomic, readonly) UIButton *configCompleteButton;

/**
 *  参数配置视图完成按钮
 */
@property (nonatomic, readonly) UIButton *configCancalButton;

/**
 *  触摸视图
 */
@property (nonatomic, readonly) UIView<TuSDKICGestureRecognizerViewInterface> *touchView;


/**
 *  点击配置完成按钮动作
 */
- (void)onConfigCompleteAction;
/**
 *  设置配置视图隐藏状态
 *
 *  @param isHidden 是否隐藏
 */
- (void)setConfigViewHiddenState:(BOOL)isHidden;
@end
