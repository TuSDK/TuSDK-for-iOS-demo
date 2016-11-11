//
//  GeeV2CPFilterResultView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKGeeV2Import.h"

#pragma mark - GeeV2PFEditFilterBottomBar
/**
 *  底部动作栏
 */
@interface GeeV2PFEditFilterBottomBar : UIView
{
    // 取消按钮
    UIButton *_cancelButton;
    // 完成按钮
    UIButton *_completeButton;
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
 *  标题视图
 */
@property (nonatomic, readonly) UILabel *titleView;

@end

#pragma mark - GeeV2CPFilterResultView
/**
 *  滤镜处理结果控制器视图
 */
@interface GeeV2CPFilterResultView : UIView<TuSDKCPFilterResultViewInterface>
{
    // 图片视图
    UIView<TuSDKICFilterImageViewInterface> *_imageView;
    // 参数配置视图
    UIView<TuSDKCPParameterConfigViewInterface> *_configView;
    // 顶部动作栏
    GeeV2PFEditFilterBottomBar *_topBar;
}

/**
 *  图片视图
 */
@property (nonatomic, readonly) UIView<TuSDKICFilterImageViewInterface> *imageView;

/**
 *  参数配置视图
 */
@property (nonatomic, readonly) UIView<TuSDKCPParameterConfigViewInterface> *configView;

/**
 *  顶部动作栏
 */
@property (nonatomic, readonly) GeeV2PFEditFilterBottomBar *topBar;

@end
