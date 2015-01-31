//
//  SimpleEditTurnAndCutView.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/1/20.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "SimpleEditTurnAndCutView.h"

@implementation SimpleEditTurnAndCutView
/**
 *  每个视图都会执行initView，自定义视图在这里开始
 */
-(void)initView;
{
    [super initView];
    
    // 修改底部工具栏背景
    self.bottomBar.backgroundColor = RGB(255,123,44);
    // 改变底部镜像按钮为向右旋转按钮
    // 隐藏镜像按钮
    self.bottomBar.mirrorButton.hidden = YES;
    // 创建向右旋转按钮
    _trunRightButton = [UIButton buttonWithFrame:self.bottomBar.mirrorButton.frame
                           imageLSQBundleNamed:@"style_default_edit_button_trun_right"];
    // 绑定动作
    [_trunRightButton addTouchUpInsideTarget:self action:@selector(onImageTurnRightAction)];
    // 添加到视图
    [self.bottomBar addSubview:_trunRightButton];
}

/**
 *  向右旋转图片
 */
- (void)onImageTurnRightAction;
{
    [self.editImageView changeImage:lsqImageChangeTurnRight];
}
@end
