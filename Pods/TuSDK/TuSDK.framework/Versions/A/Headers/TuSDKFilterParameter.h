//
//  TuSDKFilterParameter.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/11.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class TuSDKFilterParameter;

#pragma mark - TuSDKFilterParameterProtocol
/**
 *  滤镜配置选项协议
 */
@protocol TuSDKFilterParameterProtocol <NSObject>
/**
 *  滤镜配置选项
 */
@property (nonatomic, retain) TuSDKFilterParameter *parameter;

/**
 *  提交滤镜配置选项
 */
- (void)submitParameter;
@end

#pragma mark - TuSDKFilterTexturesProtocol
/**
 *  材质协议
 */
@protocol TuSDKFilterTexturesProtocol <NSObject>
/**
 *  加载材质
 *
 *  @param textures 材质列表
 */
- (void)appendTextures:(NSArray *)textures;
@end


#pragma mark - TuSDKFilterArg
/**
 *  滤镜参数
 */
@interface TuSDKFilterArg : NSObject
/**
 *  设置百分比 0 - 1
 */
@property (nonatomic) CGFloat precent;

/**
 *  获取值
 */
@property (nonatomic, readonly) CGFloat value;

/**
 *  参数键名
 */
@property (nonatomic, readonly) NSString *key;

/**
 *  默认值
 */
- (void)reset;
@end

#pragma mark - TuSDKFilterParameter
/**
 *  滤镜配置选项
 */
@interface TuSDKFilterParameter : NSObject
/**
 *  参数列表
 */
@property (nonatomic, readonly) NSArray *args;

/**
 *  参数键名列表
 */
@property (nonatomic, readonly) NSArray *argKeys;

/**
 *  配置参数总数
 */
@property (nonatomic, readonly) NSUInteger count;

/**
 *  是否已初始化
 */
@property (nonatomic, readonly) BOOL isInited;

/**
 *  滤镜配置选项
 *
 *  @return 滤镜配置选项
 */
+ (instancetype)parameter;

/**
 *  滤镜配置选项
 *
 *  @param args 自定义参数
 *
 *  @return 滤镜配置选项
 */
+ (instancetype)parameterWithArgs:(NSDictionary *)args;

/**
 *  获取已改变数值的参数列表
 */
- (NSArray *)changedArgs;

/**
 *  重置参数
 */
- (void)reset;

/**
 *  重置参数
 *
 *  @param key 参数键名
 */
- (void)resetWithKey:(NSString *)key;

/**
 *  获取滤镜参数
 *
 *  @param key 参数键名
 *
 *  @return 滤镜参数
 */
- (TuSDKFilterArg *)argWithKey:(NSString *)key;

/**
 *  设置滤镜参数百分比
 *
 *  @param key     参数键名
 *  @param precent 百分比 0 - 1
 */
- (void)setArgWithKey:(NSString *)key precent:(CGFloat)precent;

/**
 *  步进滤镜参数百分比
 *
 *  @param key     参数键名
 *  @param precent 百分比 0 - 1
 */
- (void)stepArgWithKey:(NSString *)key precent:(CGFloat)precent;

/**
 * 添加一个浮点参数
 *
 * @param key
 *            参数键名
 * @param value
 *            当前值
 * @param minValue
 *            最小值
 * @param maxValue
 *            最大值
 */
- (void)appendFloatArgWithKey:(NSString *)key
                        value:(CGFloat)value
                     minValue:(CGFloat)minValue
                     maxValue:(CGFloat)maxValue;
@end
