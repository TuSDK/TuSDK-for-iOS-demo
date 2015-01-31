//
//  TuSDKFilterConfig.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/26.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKFilterOption.h"
#import "TuSDKConfig.h"

/**
 *  原生滤镜配置委托
 */
@protocol TuSDKFilterConfigDelegate <NSObject>
/**
 *  滤镜初始化完成
 */
- (void)onTuSDKFilterConfigInited;
@end

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
 *  是否已初始化
 */
@property (nonatomic, readonly) BOOL isInited;

/**
 *  原生滤镜配置委托
 */
@property (nonatomic, assign) id<TuSDKFilterConfigDelegate> delegate;

/**
 *  原生滤镜配置
 *
 *  @param config Sdk配置
 *
 *  @return 原生滤镜配置
 */
+ (instancetype)initWithConfig:(TuSDKConfig *)config;

/**
 *  原生滤镜配置
 *
 *  @return 原生滤镜配置
 */
+ (instancetype)config;

/**
 *  获取滤镜内部配置选项
 *
 *  @param name 配置名称
 *
 *  @return 配置选项
 */
+ (NSString *)internalConfigWithName:(NSString *)name;

/**
 *  加载材质列表
 *
 *  @param name 滤镜名称
 *
 *  @return 材质列表
 */
- (NSArray *)loadTexturesWithName:(NSString *)name;

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
