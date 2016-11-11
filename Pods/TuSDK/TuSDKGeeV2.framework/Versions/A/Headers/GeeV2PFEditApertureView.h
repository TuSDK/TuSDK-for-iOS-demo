//
//  GeeV2PFEditApertureView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV2Import.h"
#import "GeeV2CPFilterResultView.h"

#pragma mark - GeeV2PFEditApertureOptionBar
/**
 *  选项栏目
 */
@interface GeeV2PFEditApertureOptionBar : UIView
{
    // 关闭按钮
    UIButton *_closeButton;
    // 径向按钮
    UIButton *_radialButton;
    // 线性按钮
    UIButton *_linearButton;
}

/**
 *  关闭按钮
 */
@property (nonatomic, readonly) UIButton *closeButton;

/**
 *  径向按钮
 */
@property (nonatomic, readonly) UIButton *radialButton;

/**
 *  线性按钮
 */
@property (nonatomic, readonly) UIButton *linearButton;

@end

#pragma mark - TuSDKPFEditApertureView
/**
 *  大光圈视图
 */
@interface GeeV2PFEditApertureView : GeeV2CPFilterResultView
{
@protected
    // 选项栏目
    GeeV2PFEditApertureOptionBar *_optionBar;
    // 触摸视图
    UIView<TuSDKICGestureRecognizerViewInterface> *_touchView;
}
/**
 *  选项栏目
 */
@property (nonatomic, readonly) GeeV2PFEditApertureOptionBar *optionBar;

/**
 *  触摸视图
 */
@property (nonatomic, readonly) UIView<TuSDKICGestureRecognizerViewInterface> *touchView;

@end
