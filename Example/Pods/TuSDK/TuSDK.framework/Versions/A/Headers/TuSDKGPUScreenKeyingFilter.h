//
//  TuSDKGPUSkinBlueFilter.h
//  TuSDK
//
//  Created by KK on 2019/12/5.
//  Copyright © 2019 tusdk.com. All rights reserved.
//

#import "TuSDKFilterAdapter.h"
#import "TuSDKFilterParameter.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuSDKGPUScreenKeyingFilter : SLGPUImageFilterGroup<TuSDKFilterParameterProtocol>

/** 缺少注释） */
@property (nonatomic) CGFloat strength;
/** 缺少注释  */
@property (nonatomic) CGFloat rangeOffset;

@end

NS_ASSUME_NONNULL_END
