//
//  TuSDKFilterConfig.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/26.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKFilterOption.h"

/**
 *  原生滤镜配置
 */
@interface TuSDKFilterConfig : NSObject

/**
 *  原生滤镜配置选项列表
 */
@property (nonatomic, readonly) NSDictionary *maps;

/**
 *  原生滤镜名称列表
 */
@property (nonatomic, readonly) NSArray *names;

/**
 *  原生滤镜配置
 *
 *  @return 原生滤镜配置
 */
+ (instancetype)config;

/**
 *  默认滤镜选项
 *
 *  @return 默认滤镜选项
 */
- (TuSDKFilterOption *)normalOption;

/**
 *  获取滤镜选项配置
 *
 *  @param name 滤镜名称
 *
 *  @return 滤镜选项配置 (如果未找到对应选项，返回默认滤镜)
 */
- (TuSDKFilterOption *)optionWithName:(NSString *)name;

/**
 *  验证滤镜名称
 *
 *  @param filterNames 滤镜名称
 *
 *  @return 滤镜名称
 */
- (NSArray *)verifyNames:(NSArray *)filterNames;
@end
