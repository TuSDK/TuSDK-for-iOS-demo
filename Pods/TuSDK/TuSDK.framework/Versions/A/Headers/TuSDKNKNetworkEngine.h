//
//  TuSDKNKNetworkEngine.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/4.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKNetworkEngine.h"
#import "TuSDKNKNetworkArg.h"

/**
 *  是否为调试模式
 */
extern BOOL const lsqTuSDKNKNetworkEngineDebug;

/**
 *  sdk应用层网络引擎
 */
@interface TuSDKNKNetworkEngine : TuSDKNetworkEngine
/**
 *  sdk应用层网络引擎
 *
 *  @return sdk应用层网络引擎
 */
+ (instancetype) sharedEngine;

/**
 *  开发者ID
 */
@property (nonatomic, copy) NSString *developerId;

/**
 *  用户标识
 */
@property (nonatomic, copy) NSString *userIdentify;

/**
 * 获取在线链接
 *
 * @param url
 * @param needAuth
 *            是否需要验证
 * @return
 */
- (NSString *)webUrlWithUrl:(NSString *)url needAuth:(BOOL)needAuth;
#pragma mark - Http
// Get方式提交
- (TuSDKNetworkOperation *)get:(NSString*)url needAuth:(BOOL)needAuth arg:(TuSDKNKNetworkArg *)arg;
// Get方式提交 需要手动执行操作，为了方便文件下载
- (TuSDKNetworkOperation *)get:(NSString*)url needAuth:(BOOL)needAuth;
// Post方式提交
- (TuSDKNetworkOperation *)post:(NSString*)url params:(NSDictionary *)params needAuth:(BOOL)needAuth arg:(TuSDKNKNetworkArg *)arg;
// 分步请求，需要手动执行操作，为了方便图片上传
- (TuSDKNetworkOperation *)post:(NSString *)url params:(NSDictionary *)params needAuth:(BOOL)needAuth;
// 处理请求 步骤二: 执行操作
- (void)executeOperation:(TuSDKNetworkOperation *)op arg:(TuSDKNKNetworkArg *)arg;
@end
