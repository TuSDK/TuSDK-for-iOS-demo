//
//  GeeV2PFEditTurnAndMirrorViewController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "GeeV2PFEditTurnAndMirrorView.h"
#import "GeeV2PFEditTabBarSubControllerInterface.h"

@class GeeV2PFEditTurnAndMirrorViewController;

#pragma mark - GeeV2PFEditTurnAndMirrorDelegate
/**
 *  旋转视图控制器委托
 */
@protocol GeeV2PFEditTurnAndMirrorDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 旋转和镜像视图控制器
 *  @param result 旋转和镜像视图控制器处理结果
 */
- (void)onGeeV2PFEditTurnAndMirror:(GeeV2PFEditTurnAndMirrorViewController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 旋转和镜像视图控制器
 *  @param result 旋转和镜像视图控制器处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: false, 设置为True时使用自定义处理逻辑)
 */
- (BOOL)onAsyncGeeV2PFEditTurnAndMirror:(GeeV2PFEditTurnAndMirrorViewController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - GeeV2PFEditTurnAndMirrorViewController
/**
 *  旋转和镜像视图控制器
 */
@interface GeeV2PFEditTurnAndMirrorViewController : TuSDKPFEditTurnAndCutViewControllerBase<GeeV2PFEditTabBarSubControllerInterface>{
@protected
    // 默认样式视图
    GeeV2PFEditTurnAndMirrorView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFEditTurnAndMirrorView *defaultStyleView;

/**
 *  旋转视图控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFEditTurnAndMirrorDelegate> delegate;

/**
 *  视图类 (默认:GeeV2PFEditTurnAndMirrorView, 需要继承 GeeV2PFEditTurnAndMirrorView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  旋转视图控制栏类 (默认:GeeV2PFEditTurnAndMirrorBottomView, 需要继承 GeeV2PFEditTurnAndMirrorBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  图片编辑视图 (旋转，缩放)类 (默认:TuSDKICTouchImageView, 需要继承 TuSDKICTouchImageView)
 */
@property (nonatomic, strong) Class editImageViewClazz;
@end
