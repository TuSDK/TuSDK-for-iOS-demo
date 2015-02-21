//
//  TuSDKICGPUImageView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/4.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterWrap.h"

@class TuSDKICGPUImageView;

/**
 *  GPU视图委托
 */
@protocol TuSDKICGPUImageViewDelegate <NSObject>
/**
 *  GPU视图滤镜对象改变
 *
 *  @param view   GPU视图
 *  @param filter 滤镜包装对象
 */
- (void)onTuSDKICGPUImageView:(TuSDKICGPUImageView *)view
                 changeFilter:(TuSDKFilterWrap *)filter;
@end

/**
 *  GPU视图
 */
@interface TuSDKICGPUImageView : GPUImageView
/**
 *  显示的图片 (当重新设置图片时，滤镜将会进行克隆)
 */
@property (nonatomic, setter=setImage:) UIImage *image;

/**
 *  滤镜包装 (设置的滤镜对象将被克隆)
 */
@property (nonatomic, retain) TuSDKFilterWrap *filterWrap;

/**
 *  开启触摸时显示原图效果
 */
@property (nonatomic) BOOL enableTouchCleanFilter;

/**
 *  GPU视图委托
 */
@property (nonatomic, assign) id<TuSDKICGPUImageViewDelegate> delegate;

/**
 *  请求渲染图片
 */
- (void)requestRender;
@end
