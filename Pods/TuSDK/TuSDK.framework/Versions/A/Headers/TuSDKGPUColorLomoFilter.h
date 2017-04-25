//
//  TuSDKGPUColorLomoFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/19.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKFilterAdapter.h"
#import "TuSDKFilterParameter.h"
#import "TuSDKGPUImageTwoInputFilter.h"

/**
 *  LOMO滤镜
 */
@interface TuSDKGPUColorLomoFilter : TuSDKGPUImageTwoInputFilter<TuSDKFilterParameterProtocol, TuSDKFilterStickerProtocol>

@end
