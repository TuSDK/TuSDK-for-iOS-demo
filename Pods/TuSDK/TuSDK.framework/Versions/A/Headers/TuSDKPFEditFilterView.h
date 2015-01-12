//
//  TuSDKPFEditFilterView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKFilterWrap.h"
#import "TuSDKPFCameraFilterView.h"
#import "TuSDKPFFilterConfigView.h"

#pragma mark - TuSDKPFEditFilterImageView
/**
 *  图片视图
 */
@interface TuSDKPFEditFilterImageView : UIView<TuSDKPFFilterConfigViewDelegate>
/**
 *  滤镜配置视图
 */
@property (nonatomic, retain) TuSDKPFFilterConfigView *filterConfigView;

/**
 *  顶部边距
 */
@property (nonatomic) NSInteger topSpace;

/**
 *  设置图片
 *
 *  @param image 图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  设置滤镜对象
 *
 *  @param filterWrap 滤镜对象
 */
- (void)setFilterWrap:(TuSDKFilterWrap *)filterWrap;
@end

#pragma mark - TuSDKPFEditFilterBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFEditFilterBottomBar : UIView
/**
 *  取消按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *completeButton;
@end

#pragma mark - TuSDKPFEditFilterView
/**
 *  图片编辑滤镜控制器视图
 */
@interface TuSDKPFEditFilterView : UIView
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
@property (nonatomic, readonly) TuSDKPFCameraFilterView *filterBar;
@end
