//
//  TuAuth.h
//  TuSDK
//
//  Created by sprint on 2019/1/21.
//  Copyright © 2019 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TuAuthInfo;

/** copy 完成后回调处理 */
typedef void (^TuAuthCompletionHandler)(TuAuthInfo* _Nullable, BOOL updated);


NS_ASSUME_NONNULL_BEGIN
/**
 * 请求逻辑:
 *      当前时间 ：C 过期时间: E
 *
 *       (C - E) > 30天     成功：1月/次        失败： >=6小时/一次 （每个月内必须请求一次）
 *       (C - E) <= 30天    成功：1天/次        失败： >=6小时/一次  (每天内必须请求一次)
 *       C > E              成功：一次即可      失败：每次启动/一次
 *       特殊情况： 本地资源包更新也需要发起 auth 验证请求
 *  @since v3.0.7
 */
@interface TuAuth : NSObject

/**
 *  SDK在线验证
 *
 *  @return shared SDK在线验证
 */
+ (instancetype) shared;

/**
 * 请求远端 auth 信息
 *
 * @since v3.0.7
 */
- (void)requestRemoteAuthInfo:(TuAuthCompletionHandler)handler;

@end

/**
 在线请求的 auth info
 */
@interface TuAuthInfo : NSObject

/**
 根据 json 初始化TuAuthInfo

 @param json 在线json信息
 @return TuAuthInfo
 */
-(instancetype)initWithJSON:(NSDictionary *)json;
/** 在线更新后的 masterKey 过期日期  @since v3.0.7 */
@property (nonatomic,readonly) NSDate *service_expire;

/** 在线更新后获取到的 masterKey */
@property (nonatomic,readonly) NSString *masterKey;
/**
 记录请求在线权限时本地 bundle 中 master 的 md5.
 该 md5值 用以判断是否需要更新存储在本地的auth info。防止用户更新了权限信息 @since v3.0.7 */
@property (nonatomic,readonly) NSString *bundleMasterMD5;
/** 是否有效 */
@property (nonatomic,readonly) BOOL isValid;

/** TuAuthInfo 转为  NSDictionary */
@property (nonatomic,readonly) NSDictionary *jsonObject;

@end


/** 本地存储的auth */
@interface TuLocalAuthInfo : NSObject
/** 远端下发的验证请求 */
@property (nonatomic) TuAuthInfo *remoteAuthInfo;
/** 下次更新时间 */
@property (nonatomic,readonly) NSDate *nextRequstUpdateDate;
/** 本地存储的auth info 可能为空 */
@property (nonatomic,readonly) NSString *localKey;

/** 验证是否可以发起远端 auth 请求 */
- (BOOL)canRequestAuthUpdate;
/** 数据持久化，供下次验证 */
- (BOOL)persistence;
/** 刷新下次 auth 信息请求时间 */
- (void)nextUpdate:(BOOL)succeed;
/** 将持久化的数据恢复 */
+ (TuLocalAuthInfo *)recovery;
/** 本地缓存的key */
+ (NSString *)persistenceKey;
@end

NS_ASSUME_NONNULL_END
