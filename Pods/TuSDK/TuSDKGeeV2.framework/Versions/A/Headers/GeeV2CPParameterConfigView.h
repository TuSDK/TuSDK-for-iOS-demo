//
//  GeeV2CPParameterConfigView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"

/**
 *  参数配置视图
 */
@interface GeeV2CPParameterConfigView : UIView<TuSDKICSeekBarDelegate, TuSDKCPParameterConfigViewInterface>
{
    // 参数选项视图
    UIView *_paramsView;
    // 数字显示视图
    UILabel *_numberView;
    // 百分比控制条
    TuSDKICSeekBar *_seekBar;
}

/**
 *  参数配置视图委托
 */
@property (nonatomic, weak) id<TuSDKCPParameterConfigDelegate> delegate;

/**
 *  参数选项视图
 */
@property (nonatomic, readonly) UIView *paramsView;

/**
 *  数字显示视图
 */
@property (nonatomic, readonly) UILabel *numberView;

/**
 *  百分比控制条
 */
@property (nonatomic, readonly) TuSDKICSeekBar *seekBar;

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
