//
//  TuSDKCPFilterResultView.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 15/9/7.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKPFEditFilterBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFEditFilterBottomBar : UIView
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

#pragma mark - TuSDKCPFilterResultView
/**
 *  滤镜处理结果控制器视图
 */
@interface TuSDKCPFilterResultView : UIView<TuSDKCPFilterResultViewInterface>
{
    // 图片视图
    UIView<TuSDKICFilterImageViewInterface> *_imageView;
    // 参数配置视图
    UIView<TuSDKCPParameterConfigViewInterface> *_configView;
    // 底部动作栏
    TuSDKPFEditFilterBottomBar *_bottomBar;
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
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditFilterBottomBar *bottomBar;
@end

