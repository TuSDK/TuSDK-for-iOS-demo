//
//  TuSDKSkinTwiceMixedFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/12.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterParameter.h"

/**
 *  基于二次多项式混合模型的肤色检测 + 双边滤波
 */
@interface TuSDKSkinTwiceMixedFilter : GPUImageTwoPassTextureSamplingFilter<TuSDKFilterParameterProtocol>
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
@end
