//
//  TuSDKGPUGaussianBlurSmoothFilter.h
//  TuSDK
//
//  Created by tutu on 2019/8/20.
//  Copyright © 2019 tusdk.com. All rights reserved.
//

#import "SLGPUImageFilterGroup.h"
#import "TuSDKFilterParameter.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuSDKGPUSkinGaussianBlurSmoothFilter : SLGPUImageFilterGroup<TuSDKFilterParameterProtocol>

/** 高斯模糊程度（默认0.8f， 0 - 1, 越大越模糊） */
@property (nonatomic) CGFloat blurSize;

/**
 *  饱和度 (设值范围0.0-2.0，原图默认值为1.0，越大效果越强)
 */
@property(readwrite, nonatomic) CGFloat saturation;

@end

NS_ASSUME_NONNULL_END
