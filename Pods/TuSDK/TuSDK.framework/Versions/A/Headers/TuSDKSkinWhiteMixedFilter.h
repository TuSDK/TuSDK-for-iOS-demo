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

@end
