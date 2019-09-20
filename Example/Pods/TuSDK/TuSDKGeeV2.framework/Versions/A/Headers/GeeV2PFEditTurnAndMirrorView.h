//
//  GeeV2PFEditTurnAndMirrorView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"

#pragma mark - GeeV2PFEditTurnAndMirrorBottomView
/**
 *  旋转和镜像视图控制栏
 */
@interface GeeV2PFEditTurnAndMirrorBottomView : UIView{
@protected
    // 左旋转按钮
    UIButton *_trunLeftButton;
    // 右旋转按钮
    UIButton *_trunRightButton;
    // 垂直镜像按钮
    UIButton *_mirrorVerticalButton;
    // 水平镜像按钮
    UIButton *_mirrorHorizontalButton;
}
/**
 *  左旋转按钮
 */
@property (nonatomic, readonly) UIButton *trunLeftButton;

/**
 *  右旋转按钮
 */
@property (nonatomic, readonly) UIButton *trunRightButton;

/**
 *  垂直镜像按钮
 */
@property (nonatomic, readonly) UIButton *mirrorVerticalButton;

/**
 *  水平镜像按钮
 */
@property (nonatomic, readonly) UIButton *mirrorHorizontalButton;
@end

#pragma mark - GeeV2PFEditTurnAndMirrorView
/**
 *  旋转和镜像视图
 */
@interface GeeV2PFEditTurnAndMirrorView : UIView<TuSDKICTouchImageViewDelegate>{
@protected
    // 旋转视图控制栏
    GeeV2PFEditTurnAndMirrorBottomView *_bottomBar;
    // 图片编辑视图 (旋转，缩放)
    UIView<TuSDKICTouchImageViewInterface> *_editImageView;
}

/**
 *  旋转视图控制栏类 (默认:GeeV2PFEditTurnAndMirrorBottomView, 需要继承 GeeV2PFEditTurnAndMirrorBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  图片编辑视图 (旋转，缩放)类 (默认:TuSDKICTouchImageView, 需要继承 TuSDKICTouchImageView)
 */
@property (nonatomic, strong) Class editImageViewClazz;

/**
 *  旋转视图控制栏
 */
@property (nonatomic, readonly) GeeV2PFEditTurnAndMirrorBottomView *bottomBar;

/**
 *  图片编辑视图 (旋转，缩放)
 */
@property (nonatomic, readonly) UIView<TuSDKICTouchImageViewInterface> *editImageView;

/**
 *  设置图片
 *
 *  @param image           图片
 */
- (void)setImage:(UIImage *)image;

@end
