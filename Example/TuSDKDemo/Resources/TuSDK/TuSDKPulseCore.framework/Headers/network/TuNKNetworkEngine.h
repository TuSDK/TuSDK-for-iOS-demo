//
//  TuNKNetworkEngine.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/4.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <TuSDKPulseCore/TuNetworkEngine.h>
@class TuNKNetworkArg;
/**
 *  是否为调试模式
 */
extern BOOL const lsqTuSDKNKNetworkEngineDebug;

extern NSString* const lsqTuSDKNKNetworkEngineHeadrSDKTypeImage;
extern NSString* const lsqTuSDKNKNetworkEngineHeadrSDKTypeVideo;
extern NSString* const lsqTuSDKNKNetworkEngineHeadrSDKTypeEva;
extern NSString* const lsqTuSDKNKNetworkEngineHeadrSDKTypeFaceFuse;


/**
 *  sdk应用层网络引擎
 */
@interface TuNKNetworkEngine : TuNetworkEngine
/**
 *  sdk应用层网络引擎
 *
 *  @return sdk 应用层网络引擎
 */
+ (instancetype) sharedEngine;

/**
 *  sdk业务网络引擎
 *
 *  @return sdk 业务网络引擎
 */
+ (instancetype) serviceEngine;

/**
 *  sdk下载资源业务网络引擎
 *
 *  @return sdk 下载资源业务网络引擎
 */
+ (instancetype) webEngine;

/**
 *  sdk在线权限验证引擎
 *
 *  @return sdk在线权限验证引擎
 */
+ (instancetype) authEngine;

/**
 * 唯一设备ID
 *
 *  @return 唯一设备ID
 */
+ (NSString *)uniqueDeviceID;

// 全局唯一id
+ (NSString *)globalDeviceID;

/**
 *  开发者ID
 */
@property (nonatomic, copy) NSString *developerId;

/**
 *  用户标识
 */
@property (nonatomic, copy) NSString *userIdentify;

/**
 设置 SDK
 类型 1. 图像
 */
+ (void)setSDKType:(NSString *)sdkType;

/**
 *  获取服务器地址
 *
 *  @return NSString
 */
- (NSString *) serviceDomain;

/**
 * 获取在线链接
 *
 * @param url
 * @param needAuth 是否需要验证
 * @return url
 */
- (NSString *)webUrlWithUrl:(NSString *)url needAuth:(BOOL)needAuth;
#pragma mark - Http
// Get方式提交
- (TuNetworkOperation *)get:(NSString*)url needAuth:(BOOL)needAuth arg:(TuNKNetworkArg *)arg;
// Get方式提交 需要手动执行操作，为了方便文件下载
- (TuNetworkOperation *)get:(NSString*)url needAuth:(BOOL)needAuth;
// Post方式提交
- (TuNetworkOperation *)post:(NSString*)url params:(NSDictionary *)params needAuth:(BOOL)needAuth arg:(TuNKNetworkArg *)arg;
// 分步请求，需要手动执行操作，为了方便图片上传
- (TuNetworkOperation *)post:(NSString *)url params:(NSDictionary *)params needAuth:(BOOL)needAuth;
// Service 请求，需要手动执行操作，为了方便图片上传
-(TuNetworkOperation *)postService:(NSString *)url params:(NSDictionary *)params;
// 处理请求 步骤二: 执行操作
- (void)executeOperation:(TuNetworkOperation *)op arg:(TuNKNetworkArg *)arg;
@end
