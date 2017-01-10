//
//  TuSDKGPUSkinAndLiveStickerFilter.h
//  TuSDKVideo
//
//  Created by Yanlin Qiu on 24/11/2016.
//  Copyright © 2016 TuSDK. All rights reserved.
//


#import "TuSDKFilterParameter.h"
#import "TuSDKFilterAdapter.h"

/**
 *  肤色 + 动态贴纸，提升性能
 */
@interface TuSDKGPUSkinAndLiveStickerFilter : TuSDKThreeInputFilter <TuSDKFilterFacePositionProtocol, TuSDKFilterStickerProtocol>

/** The strength of the sharpening, from 0.0 on up, with a default of 1.0 */
@property(readwrite, nonatomic) CGFloat intensity;

/** 混合 (设值范围0.0-1.0，原图默认值为0.0，越大越亮白) */
@property(readwrite, nonatomic) CGFloat mix;

- (void)setEnableSkinColorDetectionUniform:(CGFloat)newValue;

@end
