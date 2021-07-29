//
//  TuNKNetworkArg.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/4.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TuNetworkOperation;
@class TuNKNetworkArg;
// 返回数据处理
typedef BOOL (^TuNKNetworkArgReceivedBlock)(TuNKNetworkArg* arg);
// 返回数据处理发生错误
typedef void (^TuNKNetworkArgErrorBlock)(TuNKNetworkArg* arg);
// 返回数据处理完成最后步骤
typedef void (^TuNKNetworkArgFinishBlock)(TuNKNetworkArg* arg);

/**
 *  网络连接参数
 */
@interface TuNKNetworkArg : NSObject
/**
 *  错误对象
 */
@property (nonatomic, retain) NSError* error;

/**
 *  返回操作代码
 */
@property (nonatomic) NSInteger returnCode;

/**
 *  返回数据
 */
@property (nonatomic, retain) NSObject *data;

/**
 *  是否为下载动作
 */
@property (nonatomic) BOOL downFile;

/**
 *  初始化
 *
 *  @param target 委托对象
 *  @param action 对象方法
 *
 *  @return target 网络连接参数
 */
+ (instancetype)initWithTarget:(id)target action:(SEL)action;

/**
 *  获取字典数据
 *
 *  @return getDictionaryData 字典数据
 */
- (NSDictionary *)getDictionaryData;

/**
 *  获取子数据
 *
 *  @param key 子数据键名
 *
 *  @return key 子数据
 */
- (NSDictionary *)getSubDataWithKey:(NSString *)key;

/**
 *  网络请求结束
 *
 *  @param operation 网络操作对象
 */
- (void)onNetworkRequestFinishedWithOperation:(TuNetworkOperation *)operation;

// 处理返回数据
- (void)dataParseWithBlock:(TuNKNetworkArgReceivedBlock)block;
// 处理返回数据
- (void)dataParseWithBlock:(TuNKNetworkArgReceivedBlock)block finish:(TuNKNetworkArgFinishBlock)finish;
// 处理返回数据
- (void)dataParseWithBlock:(TuNKNetworkArgReceivedBlock)block error:(TuNKNetworkArgErrorBlock)error;
// 处理返回数据
- (void)dataParseWithBlock:(TuNKNetworkArgReceivedBlock)block finish:(TuNKNetworkArgFinishBlock)finish
                       error:(TuNKNetworkArgErrorBlock)error;
@end
