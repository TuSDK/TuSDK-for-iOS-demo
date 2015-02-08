//
//  TuSDKGPUSoftColorFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/5.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <GPUImage/GPUImage.h>

@interface TuSDKGPUSoftColorFilter : GPUImageFilterGroup
/**
 *  模糊范围 (从0.0开始，数值越大越模糊)
 */
@property (nonatomic) CGFloat blurSize;

/**
 *  The strength of the sharpening, from 0.0 on up, with a default of 1.0
 */
@property(readwrite, nonatomic) CGFloat intensity;
@end
