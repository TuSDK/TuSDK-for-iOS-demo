//
//  GeeV2PFEditTextController.h
//  TuSDKGeeV2
//
//  Created by 刘鹏程 on 2022/5/30.
//  Copyright © 2022 tusdk.com. All rights reserved.
//

#import <TuViews/TuViews.h>
#import "GeeV2PFEditTextView.h"
#import "GeeV2PFEditTextViewOptions.h"
#import "TuSDKGeeV2Import.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - GeeV2PFEditTextControllerDelegate

@class GeeV2PFEditTextController;
/**
 *  图片编辑贴纸选择控制器委托
 */
@protocol GeeV2PFEditTextControllerDelegate <TuComponentErrorDelegate>

/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 */
- (void)onGeeV2EditText:(GeeV2PFEditTextController *)controller result:(TuResult *)result;

@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncGeeV2EditText:(GeeV2PFEditTextController *)controller result:(TuResult *)result;


@end

#pragma mark - GeeV2PFEditTextController

@interface GeeV2PFEditTextController : TuEditTextControllerBase
{
    //默认样式视图
    GeeV2PFEditTextView *_defaultStyleView;
}

/**
 *  控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFEditTextControllerDelegate> delegate;
/**
 *  视图类 (默认:GeeV2PFEditTextView, 需要继承 GeeV2PFEditTextView)
 */
@property (nonatomic, strong) Class viewClazz;
/**
 *  文字初始化创建样式
 */
@property (nonatomic, strong) GeeV2PFEditTextViewOptions *textOptions;

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFEditTextView *defaultStyleView;

@end

NS_ASSUME_NONNULL_END
