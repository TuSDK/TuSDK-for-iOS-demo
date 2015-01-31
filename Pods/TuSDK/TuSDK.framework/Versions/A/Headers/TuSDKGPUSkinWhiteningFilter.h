//
//  TuSDKSkinWhiteningFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/14.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterParameter.h"

/**
 *  基础美白滤镜
 */
@interface TuSDKGPUSkinWhiteningFilter : GPUImageFilterGroup<TuSDKFilterParameterProtocol>
/**
 *  皮肤平滑度（默认0.5， 0 - 1, 越大越平滑）
 */
@property (nonatomic) CGFloat smoothing;

/**
 *  皮肤加白（默认0.25， 0 - 1, 越大越白）
 */
@property (nonatomic) CGFloat whitening;
@end
