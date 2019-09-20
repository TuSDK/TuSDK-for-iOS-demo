//
//  GeeV2PFEditCuterController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeeV2PFEditCuterView.h"
#import "GeeV2PFEditTabBarSubControllerInterface.h"

#pragma mark - GeeV2PFEditCuterControllerDelegate
@class GeeV2PFEditCuterController;
/**
 *  图片编辑裁切旋转控制器委托
 */
@protocol GeeV2PFEditCuterControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑裁切旋转控制器
 *  @param result 处理结果
 */
- (void)onGeeV2PFEditCuter:(GeeV2PFEditCuterController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑裁切旋转控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncGeeV2PFEditCuter:(GeeV2PFEditCuterController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - GeeV2PFEditCuterController
/**
 *  图片编辑裁切旋转控制器
 */
@interface GeeV2PFEditCuterController : TuSDKPFEditCuterControllerBase<GeeV2PFEditTabBarSubControllerInterface>{
@protected
    // 默认样式视图
    GeeV2PFEditCuterView *_defaultStyleView;
}
#pragma mark - config
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFEditCuterView *defaultStyleView;

/**
 *  图片编辑裁切旋转控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFEditCuterControllerDelegate> delegate;

/**
 *  视图类 (默认:GeeV2PFEditCuterView, 需要继承 GeeV2PFEditCuterView)
 */
@property (nonatomic, strong) Class viewClazz;
@end
