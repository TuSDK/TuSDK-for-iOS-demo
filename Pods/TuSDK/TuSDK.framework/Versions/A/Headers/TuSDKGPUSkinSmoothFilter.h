//
//  TuSDKGPUSkinSmoothFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/6.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterParameter.h"

/**
 *  皮肤平滑滤镜
 */
@interface TuSDKGPUSkinSmoothFilter : GPUImageFilterGroup<TuSDKFilterParameterProtocol>
/**
 *  皮肤平滑度（默认0.5， 0 - 1, 越大越平滑）
 */
@property (nonatomic) CGFloat smoothing;
@end
