//
//  TuSDKPFEditTextView.h
//  TuSDKGeeV1
//
//  Created by wen on 20/07/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKPFEditAdjustView.h"
#import "TuSDKPFEditTextViewOptions.h"

#pragma mark - TuSDKPFEditTextBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFEditTextBottomBar : UIView{
    // 取消按钮
    UIButton *_cancelButton;
    // 完成按钮
    UIButton *_completeButton;
}

/**
 *  取消按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *completeButton;

@end


#pragma mark - TuSDKPFEditTextView
/**
 *  图片编辑文字控制器视图
 */
@interface TuSDKPFEditTextView : UIView{
    @protected
    // 图片视图
    UIImageView *_imageView;
    // 底部动作栏
    TuSDKPFEditTextBottomBar *_bottomBar;
    // 文字视图
    TuSDKPFTextView *_textView;
    // 旋转和裁剪 裁剪区域视图
    TuSDKICMaskRegionView *_cutRegionView;
    
    // 选项栏目
    TuSDKPFEditAdjustOptionBar *_optionBar;
    // 选项操作返回按钮
    UIButton *_optionBackButton;
    // 选项操作容器
    UIView *_optionActionContainer;
}

/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *imageView;

/**
 *  旋转和裁剪 裁剪区域视图
 */
@property (nonatomic, readonly) TuSDKICMaskRegionView *cutRegionView;

/**
 *  图片视图
 */
@property (nonatomic, readonly) TuSDKPFTextView *textView;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditTextBottomBar *bottomBar;

/**
 *  选项栏视图
 */
@property (nonatomic, readonly) TuSDKPFEditAdjustOptionBar *optionBar;

/**
 *  选项操作返回按钮
 */
@property (nonatomic, readonly) UIButton *optionBackButton;

/**
 *  初始化文字创建样式
 */
@property (nonatomic, strong) TuSDKPFEditTextViewOptions *textOptions;

/**
 *  设置图片
 *
 *  @param image 图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  设置选项操作视图隐藏状态
 *
 *  @param isHidden 是否隐藏
 */
- (void)setOptionViewHiddenState:(BOOL)isHidden;


/**
 选中某一个选项

 @param index 选项下标
 */
- (void)selectedIndexWith:(NSInteger)index;

@end
