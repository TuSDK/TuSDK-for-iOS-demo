//
//  GeeV2PFEditTextView.h
//  TuSDKGeeV2
//
//  Created by 刘鹏程 on 2022/5/30.
//  Copyright © 2022 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"
#import "GeeV2PFEditAdjustView.h"
#import "GeeV2PFEditTextViewOptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface GeeV2PFEditTextBottomBar : UIView
{
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

@interface GeeV2PFEditTextView : UIView
{
    @protected
    //图片视图
    UIImageView *_imageView;
    //顶部动作栏
    GeeV2PFEditTextBottomBar *_bottomBar;
    // 文字视图
    TuTextStickerView *_textView;
    // 旋转和裁剪 裁剪区域视图
    TuMaskRegionView *_cutRegionView;
    //选项栏目
    GeeV2PFEditAdjustOptionBar *_optionBar;
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
@property (nonatomic, readonly) TuMaskRegionView *cutRegionView;
/**
 *  图片视图
 */
@property (nonatomic, readonly) TuTextStickerView *textView;
/**
 *  底部动作栏
 */
@property (nonatomic, readonly) GeeV2PFEditTextBottomBar *bottomBar;
/**
 *  选项栏视图
 */
@property (nonatomic, readonly) GeeV2PFEditAdjustOptionBar *optionBar;
/**
 *  选项操作返回按钮
 */
@property (nonatomic, readonly) UIButton *optionBackButton;
/**
 *  初始化文字创建样式
 */
@property (nonatomic, strong) GeeV2PFEditTextViewOptions *textOptions;

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

NS_ASSUME_NONNULL_END
