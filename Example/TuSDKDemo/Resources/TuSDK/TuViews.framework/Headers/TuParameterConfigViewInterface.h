//
//  TuParameterConfigViewInterface.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/7.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TuParameterConfigViewInterface;

/**
 *  参数配置视图委托
 */
@protocol TuParameterConfigDelegate <NSObject>
/**
 *  参数数据改变
 *
 *  @param view     参数配置视图
 *  @param index    参数索引
 *  @param progress 百分比进度
 */
- (void)onTuSDKCPParameterConfig:(UIView<TuParameterConfigViewInterface> *)view
                 changeWithIndex:(NSUInteger)index
                        progress:(CGFloat)progress;

/**
 *  读取参数值
 *
 *  @param view  参数配置视图
 *  @param index 参数索引
 *
 *  @return parameterConfig 参数值
 */
- (CGFloat)onTuSDKCPParameterConfig:(UIView<TuParameterConfigViewInterface> *)view
                     valueWithIndex:(NSUInteger)index;

/**
 *  读取参数值
 *
 *  @param view  参数配置视图
 *  @param key 参数名
 *
 *  @return parameterConfig 参数值
 */
- (CGFloat)onTuSDKCPParameterConfig:(UIView<TuParameterConfigViewInterface> *)view
                     valueWithKey:(NSString *)key;

/**
 *  重置参数
 *
 *  @param view  参数配置视图
 *  @param index 参数索引
 */
- (void)onTuSDKCPParameterConfig:(UIView<TuParameterConfigViewInterface> *)view
                  resetWithIndex:(NSUInteger)index;
@end

/**
 *  参数配置视图接口
 */
@protocol TuParameterConfigViewInterface <NSObject>
/**
 *  参数配置视图委托
 */
@property (nonatomic, weak) id<TuParameterConfigDelegate> delegate;
/**
 *  跳到指定百分比
 *
 *  @param progress 百分比进度
 */
- (void)seekWithProgress:(CGFloat)progress;

/**
 *   设置参数列表
 *
 *  @param params 参数列表
 *  @param index  选中索引
 */
- (void)setParams:(NSArray *)params selectedIndex:(NSUInteger)index;
@end
