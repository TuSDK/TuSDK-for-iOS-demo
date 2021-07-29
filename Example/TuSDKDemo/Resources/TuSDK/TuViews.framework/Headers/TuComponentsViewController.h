//
//  TuComponentsViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/12/11.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import "TuViewController.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>
//#import "TuSDKPulseCore/core/TuResult.h"

@class TuComponentsViewController;
/**
 *  组件控制器错误信息委托
 */
@protocol TuComponentErrorDelegate <NSObject>
/**
 *  获取组件返回错误信息
 *
 *  @param controller 控制器
 *  @param result     返回结果
 *  @param error      异常信息
 */
- (void)onComponent:(TuComponentsViewController *)controller result:(TuResult *)result error:(NSError *)error;
@end

/**
 *  组件控制器
 */
@interface TuComponentsViewController : TuViewController
/**
 *  组件控制器错误信息委托
 */
@property (nonatomic, weak) id<TuComponentErrorDelegate> errorDelegate;

/**
 *  通知错误信息
 *
 *  @param error  错误信息
 *  @param result 处理结果
 */
- (void)notifyError:(NSError *)error result:(TuResult *)result;

/**
 *  创建默认样式视图 (如需创建自定义视图，请覆盖该方法，并创建自己的视图类)
 */
- (void)buildDefaultStyleView;

/**
 *  配置默认样式视图
 *
 *  @param view 默认样式视图 (如需创建自定义视图，请覆盖该方法，并配置自己的视图类)
 */
- (void)configDefaultStyleView:(UIView *)view;
@end
