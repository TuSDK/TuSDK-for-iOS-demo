//
//  TuSDKPFEditCuterView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKTSBundle.h"
#import "TuSDKICCutRegionView.h"
#import "TuSDKRatioType.h"
#import "TuSDKPFEditImageView.h"

#pragma mark - TuSDKPFEditCuterOptionBar
/**
 *  选项栏目
 */
@interface TuSDKPFEditCuterOptionBar : UIView
/**
 *  按钮列表
 */
@property (nonatomic, readonly) NSArray *buttons;

/**
 *  视图显示比例类型 (默认:lsqRatioAll)
 */
@property (nonatomic) lsqRatioType ratioType;

/**
 *  当前视图显示比例类型
 */
@property (nonatomic) lsqRatioType currentRatioType;

/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - TuSDKPFEditCuterBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFEditCuterBottomBar : UIView
/**
 *  取消按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  旋转按钮
 */
@property (nonatomic, readonly) UIButton *trunButton;

/**
 *  镜像按钮
 */
@property (nonatomic, readonly) UIButton *mirrorButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *completeButton;
@end

#pragma mark - TuSDKPFEditCuterView
/**
 *  图片编辑裁切旋转控制器视图
 */
@interface TuSDKPFEditCuterView : UIView
/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditCuterBottomBar *bottomBar;

/**
 *  选项栏目
 */
@property (nonatomic, readonly) TuSDKPFEditCuterOptionBar *optionBar;

/**
 *  图片编辑视图 (旋转，缩放)
 */
@property (nonatomic, readonly) TuSDKPFEditImageView *imageView;
/**
 *  更新布局
 */
- (void)needUpdateLayout;
@end
