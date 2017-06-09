//
//  TuSDKGPUSkin3rdFilter.h
//  TuSDK
//
//  Created by Clear Hu on 2017/5/26.
//  Copyright © 2017年 tusdk.com. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterParameter.h"


/** 涂图第三代皮肤滤镜 */
@interface TuSDKGPUSkin3rdFilter : GPUImageFilterGroup<TuSDKFilterParameterProtocol>
/** 模糊权重 从0.0开始，数值越大模糊强度越弱 默认2.4 */
@property (nonatomic) CGFloat blurSize;

/** 模糊阈值 取值范围 [0-0.2] 值越大越模糊 默认0.14 */
@property(nonatomic, readwrite) CGFloat thresholdLevel;

/** 亮部细节 取值范围 [0-1] 值越大细节越少 默认0.5 */
@property (nonatomic) CGFloat lightLevel;

/** 细节保留 取值范围 [0-1] 值越大细节越多 默认0.5 */
@property (nonatomic) CGFloat detailLevel;

/** intensity */
@property(nonatomic, readwrite) CGFloat intensity;
@end
