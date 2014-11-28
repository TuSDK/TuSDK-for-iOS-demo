//
//  TuSDKFilterUtils.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/27.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  滤镜帮助类
 */
@interface TuSDKFilterUtils : NSObject

/**
 *  获取滤镜集成材质集合
 *
 *  @param names 材质名称集合
 *
 *  @return 滤镜集成材质集合
 */
+ (NSArray *)texturesIntegrateWithNames:(NSArray *)names;
@end
