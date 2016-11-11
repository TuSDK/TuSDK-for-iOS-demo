//
//  GeeV2PFEditStickerView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"
#import "GeeV2PFStickerBarView.h"

#pragma mark - GeeV2PFEditFiltertopBar
/**
 *  底部动作栏
 */
@interface GeeV2PFEditStickerTopBar : UIView
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


#pragma mark - GeeV2PFEditStickerView
/**
 *  图片编辑贴纸选择控制器视图
 */
@interface GeeV2PFEditStickerView : UIView{
@protected
    // 图片视图
    UIImageView *_imageView;
    // 旋转和裁剪 裁剪区域视图
    TuSDKICMaskRegionView *_cutRegionView;
    // 贴纸视图
    TuSDKPFStickerView *_stickerView;
    // 贴纸栏视图
    GeeV2PFStickerBarView *_stickerBar;
    // 底部动作栏
    GeeV2PFEditStickerTopBar *_topBar;
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
 *  贴纸视图
 */
@property (nonatomic, readonly) TuSDKPFStickerView *stickerView;

/**
 *  贴纸栏视图
 */
@property (nonatomic, readonly) GeeV2PFStickerBarView *stickerBar;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) GeeV2PFEditStickerTopBar *topBar;

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
@end
