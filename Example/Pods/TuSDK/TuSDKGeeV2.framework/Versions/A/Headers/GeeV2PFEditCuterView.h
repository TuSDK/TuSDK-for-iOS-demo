//
//  GeeV2PFEditCuterView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"

#pragma mark - GeeV2PFEditCuterOptionBar
/**
 *  选项栏目
 */
@interface GeeV2PFEditCuterOptionBar : UIView

/**
 *  横向滚动视图
 */
@property (nonatomic, readonly) UIScrollView *wrapView;

/**
 *  按钮列表
 */
@property (nonatomic, readonly) NSArray *buttons;

/**
 *  视图显示比例类型列表 (默认：lsqTuSDKRatioDefaultTypes)
 *
 *  设置 NSNumber 型数组来控制显示的按钮顺序， 例如:
 *	@[@(lsqRatioOrgin), @(lsqRatio_1_1), @(lsqRatio_2_3), @(lsqRatio_3_4)]
 *
 */
@property (nonatomic) NSArray<NSNumber *> *ratioTypeList;

/**
 *  当前视图显示比例类型
 */
@property (nonatomic) lsqRatioType currentRatioType;

/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - GeeV2PFEditCuterView
/**
 *  图片编辑裁切旋转控制器视图
 */
@interface GeeV2PFEditCuterView : UIView

/**
 *  选项栏目
 */
@property (nonatomic, readonly) GeeV2PFEditCuterOptionBar *optionBar;

/**
 *  图片编辑视图 (旋转，缩放)
 */
@property (nonatomic, readonly) UIView<TuSDKICTouchImageViewInterface> *imageView;
/**
 *  更新布局
 */
- (void)needUpdateLayout;
@end
