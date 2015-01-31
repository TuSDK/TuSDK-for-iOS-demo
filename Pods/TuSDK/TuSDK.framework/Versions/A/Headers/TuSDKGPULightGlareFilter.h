//
//  TuSDKGPULightGlareFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/17.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterParameter.h"

/**
 *  眩光混合
 */
@interface TuSDKGPULightGlareFilter : GPUImageTwoInputFilter<TuSDKFilterParameterProtocol>
/**
 *  混合 (设值范围0.0-1.0)
 */
@property(readwrite, nonatomic) CGFloat mix;
@end
