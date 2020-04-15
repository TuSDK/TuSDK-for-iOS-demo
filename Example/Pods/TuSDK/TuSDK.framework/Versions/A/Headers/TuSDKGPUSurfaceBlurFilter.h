//
//  TuSDKGPUSurfaceBlurFilter.h
//  TuSDK
//
//  Created by Clear Hu on 2017/5/25.
//  Copyright © 2017年 tusdk.com. All rights reserved.
//
#import "TuSDKGaussianBlurFiveRadiusFilter.h"

/** 表面模糊滤镜 */
@interface TuSDKGPUSurfaceBlurFilter:TuSDKGaussianBlurFiveRadiusFilter
@property(nonatomic, readwrite) CGFloat thresholdLevel;
@end
