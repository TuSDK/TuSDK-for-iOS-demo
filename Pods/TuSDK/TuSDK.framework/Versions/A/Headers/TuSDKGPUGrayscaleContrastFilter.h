//
//  TuSDKGPUGrayscaleContrastBlendFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/14.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
/**
 *  灰度对比度混合
 */
@interface TuSDKGPUGrayscaleContrastFilter : GPUImageFilter
/**
 *  混合 (设值范围0.0-1.0，原图默认值为0.0，越大越亮白)
 */
@property(readwrite, nonatomic) CGFloat mix;

/**
 *  对比度 （由于此种亮白原理是全图亮白，通过对比度控制画面色调整体变浅 0-4）
 */
@property (nonatomic) CGFloat contrast;
@end
