//
//  TuSDKGPUSobelEdgeFilter.h
//  TuSDK
//
//  Created by Clear Hu on 2017/8/29.
//  Copyright © 2017年 tusdk.com. All rights reserved.
//

#import "TuSDKGPUImageTwoInputFilter.h"
#import "TuSDKFilterParameter.h"

/** 边缘光效*/
@interface TuSDKGPUSobelEdgeFilter : TuSDKGPUImageTwoInputFilter<TuSDKFilterParameterProtocol, TuSDKFilterStickerProtocol>

@end
