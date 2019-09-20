//
//  TuSDKEditStickerView.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/28.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKPFStickerBarView.h"

#pragma mark - TuSDKPFEditFilterBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFEditStickerBottomBar : UIView
{
    // 取消按钮
    UIButton *_cancelButton;
    // 完成按钮
    UIButton *_completeButton;
    // 详细列表按钮
    UIButton *_listButton;
    // 在线按钮
    UIButton *_onlineButton;
}

/**
 *  取消按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *completeButton;

/**
 *  详细列表按钮
 */
@property (nonatomic, readonly) UIButton *listButton;

/**
 *  在线按钮
 */
@property (nonatomic, readonly) UIButton *onlineButton;
@end


#pragma mark - TuSDKPFEditStickerView
/**
 *  图片编辑贴纸选择控制器视图
 */
@interface TuSDKPFEditStickerView : UIView{
    @protected
    // 图片视图
    UIImageView *_imageView;
    // 旋转和裁剪 裁剪区域视图
    TuSDKICMaskRegionView *_cutRegionView;
    // 贴纸视图
    TuSDKPFStickerView *_stickerView;
    // 贴纸栏视图
    TuSDKPFStickerBarView *_stickerBar;
    // 底部动作栏
    TuSDKPFEditStickerBottomBar *_bottomBar;
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
@property (nonatomic, readonly) TuSDKPFStickerBarView *stickerBar;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditStickerBottomBar *bottomBar;

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
