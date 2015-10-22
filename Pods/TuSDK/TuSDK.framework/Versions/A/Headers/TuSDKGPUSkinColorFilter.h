//
//  TuSDKGPUSkinColorFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/1.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKFilterAdapter.h"
#import "TuSDKFilterParameter.h"

/**
 *  美白颜色滤镜
 */
@interface TuSDKGPUSkinColorFilter : GPUImageFilterGroup<TuSDKFilterParameterProtocol, TuSDKFilterTexturesProtocol>

@end
