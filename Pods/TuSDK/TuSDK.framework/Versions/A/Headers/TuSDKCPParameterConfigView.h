//
//  TuSDKCPParameterConfigView.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/20.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKICSeekBar.h"

@class TuSDKCPParameterConfigView;

/**
 *  参数配置视图委托
 */
@protocol TuSDKCPParameterConfigDelegate <NSObject>
/**
 *  参数数据改变
 *
 *  @param view     参数配置视图
 *  @param index    参数索引
 *  @param progress 百分比进度
 */
- (void)onTuSDKCPParameterConfig:(TuSDKCPParameterConfigView *)view
                 changeWithIndex:(NSUInteger)index
                        progress:(CGFloat)progress;

/**
 *  读取参数值
 *
 *  @param view  参数配置视图
 *  @param index 参数索引
 *
 *  @return 参数值
 */
- (CGFloat)onTuSDKCPParameterConfig:(TuSDKCPParameterConfigView *)view
                     valueWithIndex:(NSUInteger)index;

/**
 *  重置参数
 *
 *  @param view  参数配置视图
 *  @param index 参数索引
 */
- (void)onTuSDKCPParameterConfig:(TuSDKCPParameterConfigView *)view
                  resetWithIndex:(NSUInteger)index;
@end
/**
 *  参数配置视图
 */
@interface TuSDKCPParameterConfigView : UIView<TuSDKICSeekBarDelegate>
{
    // 参数选项视图
    UIView *_paramsView;
    // 重置按钮
    UIButton *_restButton;
    // 数字显示视图
    UILabel *_numberView;
    // 百分比控制条
    TuSDKICSeekBar *_seekBar;
    // 分割线1
    UIView *_splitOne;
    // 分割线2
    UIView *_splitTwo;
}
/**
 *  参数配置视图委托
 */
@property (nonatomic, assign) id<TuSDKCPParameterConfigDelegate> delegate;

/**
 *  参数选项视图
 */
@property (nonatomic, readonly) UIView *paramsView;

/**
 *  重置按钮
 */
@property (nonatomic, readonly) UIButton *restButton;

/**
 *  数字显示视图
 */
@property (nonatomic, readonly) UILabel *numberView;

/**
 *  百分比控制条
 */
@property (nonatomic, readonly) TuSDKICSeekBar *seekBar;

/**
 *  分割线1
 */
@property (nonatomic, readonly) UIView *splitOne;

/**
 *  分割线2
 */
@property (nonatomic, readonly) UIView *splitTwo;

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
