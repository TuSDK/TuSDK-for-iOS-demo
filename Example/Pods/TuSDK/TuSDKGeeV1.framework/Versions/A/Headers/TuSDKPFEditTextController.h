//
//  TuSDKPFEditTextController.h
//  TuSDKGeeV1
//
//  Created by wen on 20/07/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFEditTextView.h"
#import "TuSDKPFEditTextViewOptions.h"
#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKPFEditTextControllerDelegate

@class TuSDKPFEditTextController;
/**
 *  图片编辑贴纸选择控制器委托
 */
@protocol TuSDKPFEditTextControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 */
- (void)onTuSDKEditText:(TuSDKPFEditTextController *)controller result:(TuSDKResult *)result;

@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKEditText:(TuSDKPFEditTextController *)controller result:(TuSDKResult *)result;

@end


#pragma mark - TuSDKPFEditTextController

@interface TuSDKPFEditTextController : TuSDKPFEditTextControllerBase{
    // 默认样式视图
    TuSDKPFEditTextView *_defaultStyleView;
}

/**
 *  控制器委托
 */
@property (nonatomic, weak) id<TuSDKPFEditTextControllerDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFEditTextView, 需要继承 TuSDKPFEditTextView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  文字初始化创建样式
 */
@property (nonatomic, strong) TuSDKPFEditTextViewOptions *textOptions;

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditTextView *defaultStyleView;

@end
