//
//  TuSDKPFEditMultipleController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditMultipleView.h"

#pragma mark - TuSDKPFEditMultipleControllerDelegate
@class TuSDKPFEditMultipleController;

/**
 *  多功能图像编辑控制器委托
 */
@protocol TuSDKPFEditMultipleControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑入口控制器
 *  @param result 图片编辑入口控制器处理结果
 */
- (void)onTuSDKPFEditMultiple:(TuSDKPFEditMultipleController *)controller result:(TuSDKResult *)result;

/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑入口控制器
 *  @param action 图片编辑动作类型
 */
- (void)onTuSDKPFEditMultiple:(TuSDKPFEditMultipleController *)controller action:(lsqTuSDKCPEditActionType)action;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑入口控制器
 *  @param result 图片编辑入口控制器处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: false, 设置为True时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditMultiple:(TuSDKPFEditMultipleController *)controller result:(TuSDKResult *)result;
@end


#pragma mark - TuSDKPFEditMultipleController
/**
 *  多功能图像编辑控制器
 */
@interface TuSDKPFEditMultipleController : TuSDKPFEditMultipleControllerBase{
@protected
    // 默认样式视图
    TuSDKPFEditMultipleView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditMultipleView *defaultStyleView;
/**
 *  多功能图像编辑控制器委托
 */
@property (nonatomic, weak) id<TuSDKPFEditMultipleControllerDelegate> delegate;

#pragma mark - config
/**
 *  视图类 (默认:TuSDKPFEditMultipleView, 需要继承 TuSDKPFEditMultipleView)
 */
@property (nonatomic, strong) Class viewClazz;
@end
