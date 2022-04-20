//
//  TuTSLog.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulseCore/TUCCore.h>
#pragma mark - NSObjectExceptionExtend
/**
 *  异常管理
 */
@interface NSObject(NSObjectExceptionExtend)
/**
 *  是否为相同或继承关系的类对象
 *
 *  @param clazz 类对象
 *
 *  @return 是否为相同或继承关系的类对象
 */
+ (BOOL)lsq_isKindOfClass:(Class)clazz;

/**
 *  抛出异常
 *
 *  @param reason 异常信息
 */
- (void)lsqThrowWithReason:(NSString *)reason;

/**
 *  抛出异常
 *
 *  @param reason   原因
 *  @param userInfo 详细信息
 */
- (void)lsqThrowWithReason:(NSString *)reason userInfo:(NSDictionary *)userInfo;

/**
 *  执行主线程方法
 *
 *  @param aSelector 方法签名
 *  @param arg1      参数1
 *  @param arg2      参数2
 *  @param wait      是否等待执行完毕
 */
- (void)lsqPerformSelectorOnMainThread:(SEL)aSelector withObject:(id)arg1  withObject:(id)arg2 waitUntilDone:(BOOL)wait;
@end


/**
 *  日志处理类
 */
@interface TuTSLog : NSObject
/**
 *  日志输出级别 (默认：lsqLogLevelFATAL 不输出)
 */
@property (nonatomic) TuLogLevel outputLevel;

/**
 文件日志输出级别 (默认：lsqLogLevelFATAL 不输出) 默认 ： lsqLogLevelFATAL
 */
@property (nonatomic) TuLogLevel outputFileLevel;

/**
 文件日志输出路径 可选 默认在 NSDocumentDirectory 目录下
 */
@property (nonatomic,copy) NSString* outputFilePath;


/**
 *  日志处理类
 */
+ (TuTSLog *)sharedLog;

/**
 *  输出日志
 *
 *  @param format 日志信息
 */
+ (void)log:(NSString *)format, ...;

/**
 *  仅输出错误信息
 *
 *  @param format 日志信息
 */
+ (void)error:(NSString *)format, ...;

/**
 *  仅输出错误，警告信息
 *
 *  @param format 日志信息
 */
+ (void)warn:(NSString *)format, ...;

/**
 *  仅输出INFO，错误，警告信息
 *
 *  @param format 日志信息
 */
+ (void)info:(NSString *)format, ...;

/**
 *  输出所有信息
 *
 *  @param format 日志信息
 */
+ (void)debug:(NSString *)format, ...;
@end

#ifndef TTTSLogDefine
#define TTTSLogDefine

/**
 *  输出所有日志
 */
#define lsqL(...) [TuTSLog log:__VA_ARGS__]

/**
 *  仅输出错误信息
 */
#define lsqLError(...) [TuTSLog error:__VA_ARGS__]

/**
 *  仅输出错误，警告信息
 */
#define lsqLWarn(...) [TuTSLog warn:__VA_ARGS__]

/**
 *  仅输出INFO，错误，警告信息
 */
#define lsqLInfo(...) [TuTSLog info:__VA_ARGS__]

/**
 *  仅输出INFO，错误，警告信息
 */
#define lsqLDebug(...) [TuTSLog debug:__VA_ARGS__]
#endif
