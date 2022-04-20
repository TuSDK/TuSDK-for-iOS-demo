//
//  TUCCore.h
//  TuSDKPulseCore
//
//  Created by 言有理 on 2021/4/15.
//

#import <Foundation/Foundation.h>

@class TuStickerLocalPackage;
NS_ASSUME_NONNULL_BEGIN

/// SDK版本
extern NSString * const lsqPulseSDKVersion;

/// SDK版本代号
extern NSUInteger const lsqPulseSDKCode;

/// SDK配置文件 (lsq_tusdk_configs.json)
extern NSString * const lsqPulseSdkConfigs;

/// 临时文件目录 (APP/Cache/%lsqTemp%)
extern NSString * const lsqPulseTempDir;

/// 资源文件下载目录 (APP/Document/%lsqDownload%)
extern NSString * const lsqPulseDownloadDir;

/// 滤镜预览效果图文件名 (APP/Document/%lsqFilterSamples%)
extern NSString * const lsqPulseFilterSampleDir;

/// 滤镜预览效果图文件后缀 (lfs)
extern NSString * const lsqPulseFilterSampleExtension;

/**
 *  TuSDK 核心
 *  @see-https://tutucloud.com/docs/ios/image/api-core/Classes/TuSDK.html
 *
 *  内部集成滤镜列表(17):
 *  Normal, Artistic, Brilliant, Cheerful, Clear, Fade, Forest, Gloss,
 *  Harmony, Instant, Lightup, Morning, Newborn, Noir, Relaxed, Rough, Thick, Vintage
 *
 *  需要将 TuSDKFilterTextures.bundle 放入应用项目内
 */
#pragma mark - TuTSLog
/**
 *  日志输出级别
 */
typedef NS_ENUM(NSInteger, TuLogLevel)
{
    /**
     *  不输出
     */
    TuLogLevelFATAL = 0,
    /**
     *  仅输出错误信息
     */
    TuLogLevelERROR = 3,
    /**
     *  仅输出错误，警告信息
     */
    TuLogLevelWARN = 4,
    /**
     *  仅输出INFO，错误，警告信息
     */
    TuLogLevelINFO = 6,
    /**
     *  输出所有信息
     */
    TuLogLevelDEBUG = 7,
};

@interface TUCCore : NSObject
/**SDK界面样式 (默认:lsqSdkUIDefault)*/
@property (nonatomic, copy) NSString *style;
/**用户标识*/
@property (nonatomic, copy) NSString *userIdentify;

@property (nonatomic) NSBundle *bundle;

/**进度信息提示*/
//@property (nonatomic, retain) id<TuPopupMessageInterface> messageHub;
/**使用 SSL 发送网络请求 (默认: YES)*/
@property (nonatomic) BOOL useSSL;
/**
 * udid
 * @since v1.0.0
 */
@property (nonatomic, strong, readonly) NSString *openid;

/**
 *  TuSDK 核心
 *
 *  @return TuSDK 核心
 */
+ (TUCCore *)shared;


/**
 *  初始化SDK
 *
 *  @param appkey 应用秘钥 (请前往 https://tutucloud.com 申请秘钥)
 */
+ (void)initSdkWithAppKey:(NSString *)appkey;
/**
 *  初始化SDK
 *
 *  @param appkey 应用秘钥 (请前往 https://tutucloud.com 申请秘钥)
 *  @param specialKey md5加密字段
 */
+ (void)initSdkWithAppKey:(NSString *)appkey specialKey:(NSString *)specialKey;

/**
 *  初始化SDK
 *
 *  @param appkey 应用秘钥 (请前往 https://tutucloud.com 申请秘钥)
 *  @param devType 开发模式(需要与lsq_tusdk_configs.json中masters.key匹配， 如果找不到devType将默认读取master字段)
 *  @param specialKey md5加密字段
 */
+ (void)initSdkWithAppKey:(NSString *)appkey devType:(NSString *)devType specialKey:(NSString *)specialKey;

/**
 *  设置日志输出级别
 *
 *  @param level 日志输出级别 (默认：lsqLogLevelFATAL 不输出)
 */
+ (void)setLogLevel:(TuLogLevel)level;

/**
 *  设置文件日志输出级别
 *
 *  @param level 日志输出级别 (默认：lsqLogLevelFATAL 不输出)
 */
+ (void)setFileLogLevel:(TuLogLevel)level;

/** 检查资源初始化是否完成 */
+ (BOOL)checkResourceLoaded;

/**
 * 检查权限是否到期
 * @return 返回权限是否到期值
 */
+ (BOOL)checkServiceExpire;

/** 打印权限列表 */
+ (void)logAuthors;

/**
 * 获取日志文件路径
 *
 * @return 日志文件路径
 */
+ (NSString *)fileLogPath;

/**
 *  应用临时目录
 *
 *  @return appTempPath 应用临时目录
 */
+ (NSString *)appTempPath;

/**
 *  应用下载目录
 *
 *  @return appDownloadPath 应用下载目录
 */
+ (NSString *)appDownloadPath;

/**
 *  贴纸管理器
 *  @see-https://tutucloud.com/docs/ios/image/api-core/Classes/TuStickerLocalPackage.html
 *
 *  @return stickerManager 贴纸管理器
 */
+ (TuStickerLocalPackage *)stickerManager;

@end
NS_ASSUME_NONNULL_END
