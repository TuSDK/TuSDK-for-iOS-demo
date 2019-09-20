//
//  GeeV2PFEditTabBarController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/10/9.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditTabBarView.h"
#import "GeeV2PFEditCuterOptions.h"
#import "GeeV2PFEditTurnAndMirrorOptions.h"
#import "GeeV2PFEditWipeAndFilterOptions.h"
#import "GeeV2PFEditApertureController.h"

#pragma mark - GeeV2PFEditCuterControllerDelegate
@class GeeV2PFEditTabBarController;
/**
 *  图片编辑控制器委托
 */
@protocol GeeV2PFEditTabBarControllerDelegate<NSObject>

/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 */
- (void)onGeeV2PFEditFragment:(GeeV2PFEditTabBarController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncGeeV2PFEditFragment:(GeeV2PFEditTabBarController *)controller result:(TuSDKResult *)result;
@end

@interface GeeV2PFEditTabBarController : TuSDKPFEditTabBarControllerBase<GeeV2PFEditCuterControllerDelegate, GeeV2PFEditTurnAndMirrorDelegate, GeeV2PFEditWipeAndFilterControllerDelegate, TuSDKCPFilterResultControllerDelegate>
{
@protected
    // 默认样式视图
    GeeV2PFEditTabBarView *_defaultStyleView;
}
#pragma mark - config
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFEditTabBarView *defaultStyleView;
/**
 *  视图类 (默认:GeeV2PFEditTabBarView, 需要继承 GeeV2PFEditTabBarView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  图片编辑裁切旋转控制器配置选项
 */
@property (nonatomic, retain) GeeV2PFEditCuterOptions *editCuterOptions;
/**
 *  图片编辑裁切旋转控制器配置选项
 */
@property (nonatomic, retain) GeeV2PFEditTurnAndMirrorOptions *editTurnOptions;
/**
 *  大光圈控制器配置选项
 */
@property (nonatomic, retain) GeeV2PFEditApertureOptions *editApertureOptions;
/**
 *  滤镜涂抹控制器功能控制器配置选项
 */
@property (nonatomic, retain) GeeV2PFEditWipeAndFilterOptions *editWipeAndFilterOptions;

/**
 *  图片编辑裁切旋转控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFEditTabBarControllerDelegate> fragmentDelegate;
@end
