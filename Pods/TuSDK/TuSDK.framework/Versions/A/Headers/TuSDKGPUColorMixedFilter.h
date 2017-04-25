//
//  TuSDKGPUColorLookupFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/31.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKFilterAdapter.h"
#import "TuSDKFilterParameter.h"
#import "TuSDKGPUImageTwoInputFilter.h"

/**
 *  颜色替换滤镜
 */
@interface TuSDKGPUColorMixedFilter : TuSDKGPUImageTwoInputFilter<TuSDKFilterParameterProtocol, TuSDKFilterStickerProtocol>
/**
 *  混合 (设值范围0.0-1.0，原图默认值为0.0，越大效果越强)
 */
@property(readwrite, nonatomic) CGFloat mixed;
@end
