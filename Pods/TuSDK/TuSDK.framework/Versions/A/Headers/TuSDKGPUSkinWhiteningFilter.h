//
//  TuSDKSkinWhiteningFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/14.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterParameter.h"

/**
 *  基础美白滤镜
 */
@interface TuSDKGPUSkinWhiteningFilter : GPUImageFilterGroup<TuSDKFilterParameterProtocol, TuSDKFilterTexturesProtocol>

@end
