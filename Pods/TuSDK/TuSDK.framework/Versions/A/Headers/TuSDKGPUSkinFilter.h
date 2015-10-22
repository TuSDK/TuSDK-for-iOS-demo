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
@property(nonatomic, readwrite) CGFloat grinding;
@end
