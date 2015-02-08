//
//  TuSDKGaussianBlurFiveRadiusFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/5.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
/**
 *  GaussianBlurFiveRadius
 */
@interface TuSDKGaussianBlurFiveRadiusFilter : GPUImageTwoPassTextureSamplingFilter
/**
 *  模糊范围 (从0.0开始，数值越大越模糊)
 */
@property (nonatomic) CGFloat blurSize;
@end
