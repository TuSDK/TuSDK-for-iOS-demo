//
//  TuFilterSmudgeProcessor.h
//  TuSDK
//
//  Created by Yanlin on 12/2/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "TuSimpleProcessor.h"
#import "TuSDKPulseCore/cx/seles/extend/SelesParameters.h"

#pragma mark - TuFilterSmudgeProcessor
/**
 *  基于滤镜的涂抹处理
 */
@interface TuFilterSmudgeProcessor : TuSimpleProcessor
{
    // 滤镜对象
    SelesParameters *_filterParams;
}

@property (nonatomic, strong) SelesParameters *filterParams;

@end
