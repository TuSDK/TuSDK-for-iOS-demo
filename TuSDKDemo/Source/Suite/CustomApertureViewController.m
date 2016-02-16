//
//  CustomApertureViewController.m
//  TuSDKDemo
//
//  Created by Yanlin on 1/26/16.
//  Copyright © 2016 Lasque. All rights reserved.
//

#import "CustomApertureViewController.h"

@interface CustomApertureViewController ()
{
    // 当前选中的tab
    NSUInteger _selectedIndex;
    
    BOOL _selectionFinished;
}

@end

@implementation CustomApertureViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
}

/**
 *  配置默认样式视图
 *
 *  @param view 默认样式视图 (如需创建自定义视图，请覆盖该方法，并配置自己的视图类)
 */
- (void)configDefaultStyleView:(TuSDKPFEditApertureView *)view;
{
    
    [super configDefaultStyleView:view];
    
    view.optionBar.hidden = YES;
    
    // 默认选中第一个tab
    [self selectTab:0];
}

- (void)selectTab:(NSUInteger)tabIndex;
{
    _selectionFinished = NO;
    
    _selectedIndex = tabIndex;
    
    TuSDKPFEditApertureView *view = (TuSDKPFEditApertureView *)_defaultStyleView;
    
    if (_selectedIndex == 0)
    {
        [self onSelectiveAction:view.optionBar.radialButton];
    }
    else
    {
        [self onSelectiveAction:view.optionBar.linearButton];
    }
    
    _selectionFinished = YES;
    
    [self.defaultStyleView.configView setParams:@[@"radial", @"linear"] selectedIndex:_selectedIndex];
}

/**
 *  绑定滤镜配置选项
 *
 *  @param params 配置选项列表
 *  @param index  选中索引
 */
- (void)bindWithConfigParams:(NSArray *)params selectedIndex:(NSUInteger)index;
{
}

/**
 *  点击配置完成按钮动作
 */
- (void)onConfigCompleteAction;
{
    [self onImageCompleteAtion];
}

/**
 *  点击配置取消按钮动作
 */
- (void)onConfigCancalAction;
{
    [self backActionHadAnimated];
}

/**
 *  读取参数值
 *
 *  @param view  参数配置视图
 *  @param index 参数索引
 *
 *  @return 参数值
 */
- (CGFloat)onTuSDKCPParameterConfig:(UIView<TuSDKCPParameterConfigViewInterface> *)view
                     valueWithIndex:(NSUInteger)index;
{
    if (_selectedIndex != index && _selectionFinished)
    {
        if (index == 1)
        {
            [self selectTab:1];
        }
        else
        {
            [self selectTab:0];
        }
        
    }
    return [super onTuSDKCPParameterConfig:view valueWithIndex:0];;
}

@end
