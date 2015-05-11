//
//  TuSDKGPUSoftColorFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/5.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>

/**
 *  柔光滤镜
 */
@interface TuSDKGPUSoftColorFilter : GPUImageFilterGroup
/**
 *  模糊范围 (从0.0开始，数值越大越模糊)
 */
@property (nonatomic) CGFloat blurSize;

/**
 *  The strength of the sharpening, from 0.0 on up, with a default of 1.0
 */
@property(readwrite, nonatomic) CGFloat intensity;

/**
 *  使用增强初始化
 *
 *  @param needPlus 是否需要增强 (消耗性能)
 *
 *  @return 柔光滤镜
 */
- (instancetype)initWithPlus:(BOOL)needPlus;
@end
