//
//  TuSDKGPUSkinNaturalFilter.h
//  TuSDK
//
//  Created by Clear Hu on 2018/12/14.
//  Copyright © 2018 tusdk.com. All rights reserved.
//

#import "TuSDKFilterAdapter.h"
#import "TuSDKFilterParameter.h"

/** 自然磨皮 */
@interface TuSDKGPUSkinNaturalFilter:SLGPUImageFilterGroup<TuSDKFilterParameterProtocol>
@property (nonatomic) CGFloat smoothing; // 磨皮
@property (nonatomic) CGFloat fair; // 美白
@property (nonatomic) CGFloat ruddy; // 红润

@end
