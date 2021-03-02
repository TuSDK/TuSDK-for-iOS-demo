//
//  TuEditApertureControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuFilterResultController.h"
#import "TuGestureRecognizerView.h"
/**
 *  大光圈控制器基础类
 */
@interface TuEditApertureControllerBase : TuFilterResultController<TuGestureRecognizerViewDelegate>
/**
 *  选中一个选区模式
 *
 *  @param btn 按钮对象
 */
- (void)onSelectiveAction:(UIButton *)btn;

/**
 *  设置配置视图隐藏状态
 *
 *  @param isHidden 是否隐藏
 */
- (void)setConfigViewHiddenState:(BOOL)isHidden;
@end
