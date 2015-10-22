//
//  TuSDKAOValid.h
//  TuSDK
//
//  Created by Clear Hu on 14/12/15.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TuSDKConfig.h"

/**
 *  SDK用户验证
 */
@interface TuSDKAOValid : NSObject

/**
 *  SDK用户验证
 *
 *  @return SDK用户验证
 */
+ (instancetype) shared;

/**
 *  是否通过开发者账号验证
 */
@property (nonatomic, readonly, getter=isValid) BOOL isValid;

/**
 *  开发者级别
 */
@property (nonatomic, readonly, getter=level) NSInteger level;

/**
 *  开发者ID
 */
@property (nonatomic, readonly) NSString *developerId;

/**
 *  Sdk配置
 */
@property (nonatomic, readonly) TuSDKConfig *sdkConfig;

/**
 *  验证开发者ID
 *
 *  @param key 开发者ID
 *  @param devType 开发模式(需要与lsq_tusdk_configs.json中masters.key匹配， 如果找不到devType将默认读取master字段)
 *
 *  @return 是否通过验证
 */
- (BOOL)sdkValidWithKey:(NSString *)key devType:(NSString *)devType;

/**
 *  验证开发者ID
 *
 *  @return 是否通过验证
 */
- (BOOL)sdkValid;

/**
 *  是否允许该级别
 *
 *  @return 级别
 */
- (BOOL)allowLevel:(NSUInteger)level;

/**
 *  图片最大允许处理的边长
 *
 *  @return 边长
 */
- (CGFloat)maxImageSide;

/**
 *  允许最多使用贴纸数量
 *
 *  @return 最多使用贴纸数量
 */
- (NSUInteger)maxStickers;

/** local filter Count */
- (NSUInteger)localFilterCount;

/** local sticker Count */
- (NSUInteger)localStickerCount;

/** service Expire */
- (BOOL)serviceExpire;

/** no Power */
- (BOOL)noPower;

/**
 *  解密文本
 *
 *  @param txt 加密文本
 *
 *  @return 解密文本
 */
- (NSString *)sdkDecodeWithString:(NSString *)txt;

/**
 *  解密数据
 *
 *  @param data 数据
 *  @param key  key
 *  @param type type
 *
 *  @return 解密文本
 */
- (NSString *)sdkDecodeWithData:(NSData *)data key:(NSString *)key type:(NSUInteger)type;

/**
 *  验证滤镜
 *
 *  @param filterId 滤镜ID
 *  @param type     验证方式
 *
 *  @return 是否验证成功
 */
- (BOOL)filterValidWithID:(uint64_t)filterId type:(NSUInteger)type;

/**
 *  验证滤镜密钥
 *
 *  @param key      滤镜验证码
 *  @param type     验证方式
 *  @param filterId 滤镜ID
 *
 *  @return 是否验证成功
 */
- (BOOL)filterValidWithKey:(NSString *)key type:(NSUInteger)type filterId:(uint64_t)filterId;

/**
 *  验证贴纸
 *
 *  @param stickerId 贴纸ID
 *  @param type      验证方式
 *
 *  @return 是否验证成功
 */
- (BOOL)stickerValidWithID:(uint64_t)stickerId type:(NSUInteger)type;

/**
 *  验证贴纸密钥
 *
 *  @param key       贴纸密钥
 *  @param type      验证方式
 *  @param stickerId 贴纸ID
 *
 *  @return 是否验证成功
 */
- (BOOL)stickerValidWithKey:(NSString *)key type:(NSUInteger)type stickerId:(uint64_t)stickerId;
@end
