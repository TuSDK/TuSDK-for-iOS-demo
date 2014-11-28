//
//  TuSDKICViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/28.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKProgressHUD.h"

/**
 *  控制器基础类
 */
@interface TuSDKICViewController : UIViewController{
    /**
     *  页面是否已经返回 | 通过这个标记可以在viewDidDisappear里面确认销毁该控制器
     */
    BOOL _isBacked;
}

/**
 *  导航级数
 */
@property (nonatomic, readonly) NSInteger navCount;

/**
 *  返回前一页 使用动画
 */
- (void)backActionHadAnimated;

/**
 *  返回前一页
 *
 *  @param animated 是否使用动画
 */
- (void)backActionWithAnimated:(BOOL)animated;

/**
 *  Push控制器
 *
 *  @param viewController 视图控制器
 *  @param animated       是否启动动画
 */
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;

/**
 *  设置导航栏左边按钮
 *
 *  @param title  标题
 *  @param action 动作
 */
- (void)navLeftButtonWithTitle:(NSString *)title action:(SEL)action;

/**
 *  设置导航栏右边按钮
 *
 *  @param title  标题
 *  @param action 动作
 */
- (void)navRightButtonWithTitle:(NSString *)title action:(SEL)action;

/**
 *  设置导航栏左边取消按钮
 */
- (void)setNavLeftCancelButton;

/**
 *  设置导航栏右边取消按钮
 */
- (void)setNavRightCancelButton;

/**
 *  取消按钮响应事件
 */
- (void)cancelAction;

/**
 *  创建自定义返回按钮
 */
- (void)setBackButton;

/**
 *  显示进度提示信息
 *
 *  @param status 信息
 */
- (void)showHubWithStatus:(NSString *)status;

/**
 *  显示进度提示成功信息
 *
 *  @param status 信息
 */
- (void)showHubSuccessWithStatus:(NSString *)status;

/**
 *  显示进度提示失败信息
 *
 *  @param status 信息
 */
- (void)showHubErrorWithStatus:(NSString *)status;

/**
 *  关闭进度提示
 */
- (void)dismissHub;
@end


#pragma mark - TuSDKViewControllerExtend
/**
 *  扩展控制器方法
 */
@interface UIViewController(TuSDKICViewControllerExtend)
/**
 *  初始化控制器
 *
 *  @return 控制器
 */
+ (instancetype)controller;

/**
 *  取消模态控制器 使用动画
 */
- (void)dismissModalViewControllerAnimated;

/**
 *  弹出一个带导航的模态窗口
 *
 *  @param controller 控制器
 *  @param animated   是否使用动画
 */
- (void)presentModalNavigationController:(UIViewController *)controller animated:(BOOL)animated;

/**
 *  弹出一个带导航的模态窗口
 *
 *  @param controller 控制器
 *  @param animated   是否使用动画
 *  @param hiddenNav  是否隐藏导航栏
 */
- (void)presentModalNavigationController:(UIViewController *)controller animated:(BOOL)animated hiddenNav:(BOOL)hiddenNav;

/**
 *  设置全屏
 *
 *  @param wantFull 是否全屏
 */
- (void)setFullScreenLayout:(BOOL)wantFull;

/**
 *  设置导航栏是否隐藏 (不使用动画)
 *
 *  @param isHidden 是否隐藏导航栏
 */
- (void)setNavigationBarHidden:(BOOL)isHidden;

/**
 *  设置导航栏是否隐藏
 *
 *  @param isHidden 是否隐藏导航栏
 *  @param animated 是否使用动画
 */
- (void)setNavigationBarHidden:(BOOL)isHidden animated:(BOOL)animated;

/**
 *  控制器即将销毁
 */
- (void)controllerWillDestory;
@end
