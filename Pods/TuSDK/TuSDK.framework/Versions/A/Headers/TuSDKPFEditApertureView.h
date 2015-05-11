//
//  TuSDKPFEditApertureView.h
//  TuSDK
//
//  Created by Clear Hu on 15/5/7.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPFilterResultController.h"

@class TuSDKPFEditApertureTouchView;

/**
 *  贴纸元素类型
 */
typedef NS_ENUM(NSInteger, lsqApertureTouchType)
{
    /**
     * 触摸开始
     */
    lsqApertureTouchEnd,
    /**
     * 触摸结束
     */
    lsqApertureTouchBegin,
    /**
     * 平移动作
     */
    lsqApertureTouchTrans,
    /**
     * 旋转动作
     */
    lsqApertureTouchRotation,
    /**
     * 缩放动作
     */
    lsqApertureTouchScale,
};

/**
 *  触摸视图委托
 */
@protocol TuSDKPFEditApertureTouchDelegate <NSObject>
/**
 *  触摸视图状态改变
 *
 *  @param touchView 触摸视图
 *  @param change    改变状态 0:完成 1:开始 2:动作
 */
- (void)apertureTouchView:(TuSDKPFEditApertureTouchView *)touchView
              stateChange:(lsqApertureTouchType)change;
@end

#pragma mark - TuSDKPFEditApertureTouchView


/**
 *  触摸视图
 */
@interface TuSDKPFEditApertureTouchView : UIView<UIGestureRecognizerDelegate>
/**
 *  旋转角度相对百分比
 */
@property (nonatomic, readonly) CGPoint pointPrecent;
/**
 *  旋转角度相对百分比
 */
@property (nonatomic, readonly) CGFloat degreePrecent;
/**
 *  缩放相对百分比
 */
@property (nonatomic, readonly) CGFloat scalePrecent;

/**
 *  触摸视图委托
 */
@property (nonatomic, assign) id<TuSDKPFEditApertureTouchDelegate> delegate;

/**
 *  重置参数
 */
- (void)reset;
@end
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
    // 触摸视图
    TuSDKPFEditApertureTouchView *_touchView;
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
 *  触摸视图
 */
@property (nonatomic, readonly) TuSDKPFEditApertureTouchView *touchView;


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
