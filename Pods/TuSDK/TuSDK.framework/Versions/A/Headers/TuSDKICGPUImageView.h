//
//  TuSDKICGPUImageView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/4.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterWrap.h"

/**
 *  GPU视图
 */
@interface TuSDKICGPUImageView : GPUImageView
/**
 *  显示的图片
 */
@property (nonatomic, setter=setImage:) UIImage *image;

/**
 *  滤镜包装
 */
@property (nonatomic, retain) TuSDKFilterWrap *filterWrap;

/**
 *  开启触摸时显示原图效果
 */
@property (nonatomic) BOOL enableTouchCleanFilter;
@end
