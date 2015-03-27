//
//  TuSDKAOValid.h
//  TuSDK
//
//  Created by Clear Hu on 14/12/15.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

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
 *  验证开发者ID
 *
 *  @param key 开发者ID
 *
 *  @return 是否通过验证
 */
- (BOOL)sdkValidWithKey:(NSString *)key;

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

/**
 *  获取文本加密KEY
 *
 *  @param key  key
 *  @param type 加密类型
 *
 *  @return 文本加密KEY
 */
- (NSString *)sdkTextKey:(NSString *)key type:(NSUInteger)type;

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
