//
//  TuEditTurnAndCutViewControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuImageResultController.h"
#import "TuTouchImageView.h"

/**
 *  旋转和裁剪视图控制器基础类
 */
@interface TuEditTurnAndCutViewControllerBase : TuImageResultController

@property (nonatomic, readonly) UIView<TuTouchImageViewInterface> *imageView;
@property (nonatomic) CGSize cutSize; // 需要裁剪的长宽

/**
 *  选中一个滤镜
 *
 *  @param code 滤镜名称
 *  @return BOOL 是否成功切换滤镜
 */
- (BOOL)onSelectedFilterCode:(NSString *)code;

/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion;
@end
