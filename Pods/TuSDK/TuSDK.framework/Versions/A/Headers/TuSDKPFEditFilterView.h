//
//  TuSDKPFEditFilterView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKICGPUImageView.h"
#import "TuSDKPFEditFilterBarView.h"

#pragma mark - TuSDKPFEditFilterImageView
/**
 *  图片视图
 */
@interface TuSDKPFEditFilterImageView : UIView
/**
 *  GPU视图委托
 */
@property (nonatomic, assign) id<TuSDKICGPUImageViewDelegate> delegate;

/**
 *  滤镜对象
 */
@property (nonatomic, assign) TuSDKFilterWrap *filterWrap;

/**
 *  开启触摸时显示原图效果
 */
@property (nonatomic, readwrite) BOOL enableTouchCleanFilter;

/**
 *  设置图片
 *
 *  @param image 图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  请求渲染图片
 */
- (void)requestRender;

@end

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
    // 标题视图
    UILabel *_titleView;
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

#pragma mark - TuSDKPFEditFilterView
/**
 *  图片编辑滤镜控制器视图
 */
@interface TuSDKPFEditFilterView : UIView
{
    // 图片视图
    TuSDKPFEditFilterImageView *_imageView;
    // 底部动作栏
    TuSDKPFEditFilterBottomBar *_bottomBar;
    // 滤镜列表视图
    TuSDKPFEditFilterBarView *_filterBar;
}
/**
 *  图片视图
 */
@property (nonatomic, readonly) TuSDKPFEditFilterImageView *imageView;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditFilterBottomBar *bottomBar;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) TuSDKPFEditFilterBarView *filterBar;
@end
