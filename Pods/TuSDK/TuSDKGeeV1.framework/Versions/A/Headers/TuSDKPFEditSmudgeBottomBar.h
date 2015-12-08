//
//  TuSDKPFEditSmudgeBottomBar.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 12/3/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - TuSDKPFEditSmudgeBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFEditSmudgeBottomBar : UIView
{
    // 取消按钮
    UIButton *_cancelButton;
    // 完成按钮
    UIButton *_completeButton;
    // 撤销按钮
    UIButton *_undoButton;
    // 重做按钮
    UIButton *_redoButton;
    // 查看原图按钮
    UIButton *_originalButton;
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
 *  撤销按钮
 */
@property (nonatomic, readonly) UIButton *undoButton;

/**
 *  重做按钮
 */
@property (nonatomic, readonly) UIButton *redoButton;

/**
 *  查看原图按钮
 */
@property (nonatomic, readonly) UIButton *originalButton;

/**
 *  更新布局
 */
- (void)needUpdateLayout;
@end