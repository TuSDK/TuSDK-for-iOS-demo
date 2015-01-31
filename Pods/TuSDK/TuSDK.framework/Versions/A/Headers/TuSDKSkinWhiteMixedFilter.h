//
//  TuSDKSkinWhiteMixedFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/14.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterParameter.h"
/**
 *  图层混合亮白 + 对比度 + 混合肤色识别 + 增强双边滤波 + 锐化
 */
@interface TuSDKSkinWhiteMixedFilter : GPUImageFilterGroup<TuSDKFilterParameterProtocol>
/**
 *  模糊范围 (从0.0开始，数值越大越模糊)
 */
@property (nonatomic) CGFloat blurSize;

/**
 *  模糊权重 (从0.0开始，数值越大模糊强度越弱)
 */
@property (nonatomic) CGFloat blurWeight;

/**
 *  肤色检测阈值 (从0.0开始，数值越小检测面越大)
 */
@property (nonatomic) CGFloat skinColorThreshold;

/**
 *  边缘检测阈值 (从0.0开始，数值越大边缘越清晰)
 */
@property (nonatomic) CGFloat distanceNormalizationFactor;

/**
 *  混合 (设值范围0.0-1.0，原图默认值为0.0，越大越亮白)
 */
@property(readwrite, nonatomic) CGFloat mix;

/**
 *  对比度 （由于此种亮白原理是全图亮白，通过对比度控制画面色调整体变浅）
 */
@property (nonatomic) CGFloat contrast;

/**
 *  锐化 (设值范围0.0-1.0，原图默认值为0.0，越大越强)
 */
@property (nonatomic) CGFloat sharpness;
@end
