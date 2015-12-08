//
//  TuSDKPFEditSmudgeView.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 10/27/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFBrushBarView.h"
#import "TuSDKPFEditSmudgeBottomBar.h"
#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKPFEditSmudgeView
/**
 *  图片编辑笔刷选择控制器视图
 */
@interface TuSDKPFEditSmudgeView : TuSDKPFSmudgeViewBase

/**
 *  涂抹视图
 */
@property (nonatomic, readonly) UIView<TuSDKICSmudgeImageViewInterface> *imageView;

/**
 *  笔刷栏视图
 */
@property (nonatomic, readonly) TuSDKPFBrushBarView *brushBar;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditSmudgeBottomBar *bottomBar;

/**
 *  笔刷大小演示动画容器
 */
@property (nonatomic, readonly) UIView *brushSizeAnimView;

/**
 *  需要显示的笔刷名称列表 (如果为空将显示所有自定义笔刷)
 */
@property (nonatomic, retain) NSArray * brushGroup;

/**
 *  默认的笔刷大小 (默认: lsqMediumBrush，中等粗细)
 */
@property (nonatomic, assign) lsqBrushSize defaultBrushSize;

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
 *  切换笔刷粗细
 */
- (void)switchBrushSize;

@end
