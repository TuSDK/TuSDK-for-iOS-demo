//
//  TuSDKPFEditEntryController.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditEntryView.h"

#pragma mark - TuSDKPFEditEntryControllerDelegate
@class TuSDKPFEditEntryController;

/**
 *  图片编辑入口控制器委托
 */
@protocol TuSDKPFEditEntryControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑入口控制器
 *  @param result 图片编辑入口控制器处理结果
 */
- (void)onTuSDKPFEditEntry:(TuSDKPFEditEntryController *)controller result:(TuSDKResult *)result;

/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑入口控制器
 *  @param action 图片编辑动作类型
 */
- (void)onTuSDKPFEditEntry:(TuSDKPFEditEntryController *)controller action:(lsqTuSDKCPEditActionType)action;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑入口控制器
 *  @param result 图片编辑入口控制器处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: false, 设置为True时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditEntry:(TuSDKPFEditEntryController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - TuSDKPFEditEntryController
/**
 *  图片编辑入口控制器
 */
@interface TuSDKPFEditEntryController : TuSDKPFEditEntryControllerBase{
@protected
    // 默认样式视图
    TuSDKPFEditEntryView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditEntryView *defaultStyleView;

/**
 *  图片编辑入口控制器委托
 */
@property (nonatomic, weak) id<TuSDKPFEditEntryControllerDelegate> delegate;

/**
 *  贴纸视图委托
 */
@property (nonatomic, weak) id<TuSDKPFStickerViewDelegate> stickerViewDelegate;

#pragma mark - config
/**
 *  视图类 (默认:TuSDKPFEditEntryView, 需要继承 TuSDKPFEditEntryView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  开启裁剪旋转功能
 */
@property (nonatomic) BOOL enableCuter;

/**
 *  开启滤镜功能
 */
@property (nonatomic) BOOL enableFilter;

/**
 *  开启贴纸功能
 */
@property (nonatomic) BOOL enableSticker;
@end
