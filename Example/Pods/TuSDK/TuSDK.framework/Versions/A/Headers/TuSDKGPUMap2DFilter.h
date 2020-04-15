//
//  TuSDKGPUMap2DFilter.h
//  TuSDK
//
//  Created by Clear Hu on 2017/11/19.
//  Copyright © 2017年 tusdk.com. All rights reserved.
//

#import "TuSDKFilterAdapter.h"
#import "TuSDKFilterParameter.h"

/** 2D贴图滤镜*/
@interface TuSDKGPUMap2DFilter : TuSDKFilter<TuSDKFilterStickerProtocol>

@property (nonatomic, assign) BOOL stickersEnable;


@end
