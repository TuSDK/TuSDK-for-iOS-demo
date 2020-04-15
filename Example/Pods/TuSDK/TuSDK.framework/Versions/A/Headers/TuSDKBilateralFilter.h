//
//  TuSDKBilateralFilter.h
//  TuSDK
//
//  Created by Clear Hu on 15/8/27.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGaussianBlurFiveRadiusFilter.h"

@interface TuSDKBilateralFilter:TuSDKGaussianBlurFiveRadiusFilter

@property(nonatomic, readwrite) CGFloat sigmaI;
@property(nonatomic, readwrite) CGFloat sigmaS;

@end
