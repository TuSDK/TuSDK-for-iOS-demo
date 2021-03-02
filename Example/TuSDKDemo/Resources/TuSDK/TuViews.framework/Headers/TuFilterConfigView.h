//
//  TuFilterConfigView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/11.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSeekBar.h"
#import "TuSDKPulseCore/cx/seles/extend/SelesParameters.h"

#pragma mark - TuFilterSeekbar
// 滤镜配置拖动栏
@interface TuFilterSeekbar : UIView<TuSeekBarDelegate>
// 百分比控制条
@property (nonatomic, readonly) TuSeekBar *seekBar;
// 标题视图
@property (nonatomic, readonly) UILabel *titleView;
// 计数视图
@property (nonatomic, readonly) UILabel *numberView;
// 滤镜配置参数
@property (nonatomic, strong) SelesParameterArg *filterArg;
// 重置参数
- (void)reset;
@end

#pragma mark - TuFilterConfigView
/**
 *  滤镜配置视图
 */
@interface TuFilterConfigView : UIView
// 重置按钮
@property (nonatomic, readonly) UIButton *resetButton;
// 显示状态按钮
@property (nonatomic, readonly) UIButton *stateButton;
// 状态背景
@property (nonatomic, readonly) UIView *stateBg;
// 配置包装
@property (nonatomic, readonly) UIView *configWrap;
// 滤镜参数对象
@property (nonatomic, strong) SelesParameters *filterParams;
// 设置隐藏为默认状态
- (void)hiddenDefault;
/**
 *  创建滤镜配置拖动栏
 *  @param top 顶部距离
 *  @return 滤镜配置拖动栏
 */
- (TuFilterSeekbar *)buildSeekbarWithTop:(CGFloat)top;
@end
