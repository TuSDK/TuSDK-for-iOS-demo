//
//  TuSDKGPUColorSenseOfAutumnFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/17.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterParameter.h"

/**
 *  秋意浓
 */
@interface TuSDKGPUColorSenseOfAutumnFilter : GPUImageFilter<TuSDKFilterParameterProtocol>
/**
 *  肤色检测阈值 (从0.0开始，数值越小检测面越大)
 */
@property (nonatomic) CGFloat skinColorThreshold;

/**
 *  颜色更换 (默认:2.0, 从0.0开始，0-5)
 */
@property (nonatomic) CGFloat autumnColor;
@end
