//
//  GeeV2PFEditSmudgeView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeeV2PFBrushBarView.h"
#import "GeeV2PFEditSmudgeBottomBar.h"
#import "GeeV2CPParameterConfigView.h"
#import "TuSDKGeeV2Import.h"
/**
 *  操作步骤视图
 */
@interface GeeV2PFSmudgeStepView : UIView
{
    // 后退按钮
    UIButton *_prevButton;
    // 前进按钮
    UIButton *_nextButton;
}
/**
 *  后退按钮
 */
@property (nonatomic, readonly) UIButton *prevButton;

/**
 *  前进按钮
 */
@property (nonatomic, readonly) UIButton *nextButton;
@end

#pragma mark - GeeV2PFEditSmudgeView
/**
 *  图片编辑笔刷选择控制器视图
 */
@interface GeeV2PFEditSmudgeView : TuSDKPFSmudgeViewBase

/**
 *  涂抹视图
 */
@property (nonatomic, readonly) UIView<TuSDKICSmudgeImageViewInterface> *imageView;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) GeeV2PFEditSmudgeBottomBar *bottomBar;

/**
 *  笔刷大小演示动画容器
 */
@property (nonatomic, readonly) UIView *brushSizeAnimView;

/**
 *  操作步骤视图
 */
@property (nonatomic, retain) GeeV2PFSmudgeStepView *stepView;

/**
 *  需要显示的笔刷名称列表 (如果为空将显示所有自定义笔刷)
 */
@property (nonatomic, retain) NSArray * brushGroup;

/**
 *  默认的笔刷大小 (默认: lsqGeeV2MediumBrush，中等粗细)
 */
@property (nonatomic, assign) lsqGeeV2BrushSize defaultBrushSize;

// 当前笔刷尺寸
@property (nonatomic, assign) lsqGeeV2BrushSize currentBrushSize;

/**
 *  是否保存上一次使用的笔刷 (默认: YES)
 */
@property (nonatomic) BOOL saveLastBrush;

/**
 *  默认撤销的最大次数 (默认: 5)
 */
@property (nonatomic, assign) NSUInteger maxUndoCount;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  设置图片
 *
 *  @param image 图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  设置当前笔刷粗细
 *
 *  @param mBrushSize 笔刷粗细
 */
- (void)setBrushSize:(lsqGeeV2BrushSize)mBrushSize;
/**
 *  点击笔刷按钮切换笔刷粗细
 */
- (void)switchBrushSize:(lsqGeeV2BrushSize)mBrushSize;
@end
