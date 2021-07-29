//
//  TuBrushSize.h
//  TuSDK
//
//  Created by Yanlin on 11/9/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulseCore/TUCEnum.h>

@interface TuBrushSize : NSObject

/**
 *  下一个可用的笔刷尺寸
 *
 *  @param currentSize 当前尺寸
 *
 *  @return 笔刷尺寸
 */
+ (TuSDKBrushSize) nextBrushSize:(TuSDKBrushSize) currentSize;

/**
 *  尺寸对应的名称
 *
 *  @param size 尺寸
 *
 *  @return 名称
 */
+ (NSString *) nameForSize:(TuSDKBrushSize)size;

@end
