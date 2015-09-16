//
//  TuSDKPFEditEntryView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKPFEditEntryOptionBar
/**
 *  选项栏目
 */
@interface TuSDKPFEditEntryOptionBar : UIView
{
    // 裁切按钮
    UIButton *_cutButton;
    // 滤镜按钮
    UIButton *_filterButton;
    // 贴纸按钮
    UIButton *_stickerButton;
}
/**
 *  裁切按钮
 */
@property (nonatomic, readonly) UIButton *cutButton;

/**
 *  滤镜按钮
 */
@property (nonatomic, readonly) UIButton *filterButton;

/**
 *  贴纸按钮
 */
@property (nonatomic, readonly) UIButton *stickerButton;

/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - TuSDKPFEditEntryBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFEditEntryBottomBar : UIView
{
    // 后退按钮
    UIButton *_backButton;
    // 完成按钮
    UIButton *_completeButton;
    // 标题视图
    UILabel *_titleView;
}
/**
 *  后退按钮
 */
@property (nonatomic, readonly) UIButton *backButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *completeButton;

/**
 *  标题视图
 */
@property (nonatomic, readonly) UILabel *titleView;
@end

#pragma mark - TuSDKPFEditEntryView
/**
 *  图片编辑入口控制器视图
 */
@interface TuSDKPFEditEntryView : UIView
{
    // 图片视图
    UIView<TuSDKCPFilterStickerViewInterface> *_imageView;
    // 底部动作栏
    TuSDKPFEditEntryBottomBar *_bottomBar;
    // 选项栏目
    TuSDKPFEditEntryOptionBar *_optionBar;
}

/**
 *  图片视图
 */
@property (nonatomic, readonly) UIView<TuSDKCPFilterStickerViewInterface> *imageView;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditEntryBottomBar *bottomBar;

/**
 *  选项栏目
 */
@property (nonatomic, readonly) TuSDKPFEditEntryOptionBar *optionBar;

/**
 *  更新布局
 */
- (void)needUpdateLayout;
@end
