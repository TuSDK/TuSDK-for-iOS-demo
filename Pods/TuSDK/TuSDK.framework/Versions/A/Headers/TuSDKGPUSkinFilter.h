//
//  TuSDKGPUSkinFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/8/27.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKFilterAdapter.h"
/** SkinFilter */
@interface TuSDKGPUSkinFilter : GPUImageFilterGroup
/** blur Size */
@property (nonatomic) CGFloat blurSize;

/** intensity */
@property(readwrite, nonatomic) CGFloat intensity;

/** grinding */
@property(nonatomic, readwrite) CGFloat thresholdLevel;

/** 亮部细节 取值范围 [0-1] 值越大细节越少 默认0.5 */
@property (nonatomic) CGFloat lightLevel;

/** 细节保留 取值范围 [0-1] 值越大细节越多 默认0.5 */
@property (nonatomic) CGFloat detailLevel;

/** 最大模糊半径 */
@property(nonatomic, readonly) CGFloat maxBlursize;

/** 最大模糊阈值 */
@property(nonatomic, readonly) CGFloat maxThresholdLevel;
@end
