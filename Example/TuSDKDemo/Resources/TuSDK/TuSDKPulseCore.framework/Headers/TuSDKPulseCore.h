//
//  TuSDK.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/25.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//  https://tutucloud.com/docs/ios/image/api-core/
//

//#import "gpuimage/SLGPUImage.h"

#import "tools/TuTSALAssets+Extend.h"
#import "tools/TuTSALAssetsGrouped+CreateTimeDesc.h"
#import "tools/TuTSAVAudioPlayer+Extend.h"
#import "tools/TuTSAVCaptureDevice+Extend.h"
#import "tools/TuTSAnimation.h"
#import "tools/TuTSAsset.h"
#import "tools/TuTSBundle.h"
#import "tools/TuTSDate+Extend.h"
#import "tools/TuTSDevice+Extend.h"
#import "tools/TuTSDeviceSettings.h"
#import "tools/TuTSFileManager.h"
#import "tools/TuTSImage+Extend.h"
#import "tools/TuTSLog.h"
#import "tools/TuTSMath.h"
#import "tools/TuTSMotion.h"
#import "tools/TuTSNSArray+Extend.h"
#import "tools/TuTSNSData+Extend.h"
#import "tools/TuTSNSDictionary+Extend.h"
#import "tools/TuTSNSUserDefaults+Extend.h"
#import "tools/TuTSScreen+Extend.h"
#import "tools/TuTSString+Extend.h"
#import "tools/TuTSUIColor+Extend.h"


#import "tools/TuICView+Extend.h"
#import "components/widgets/smudge/TuBrushLocalPackage.h"
#import "components/widgets/sticker/TuStickerGroup.h"
#import "components/widgets/sticker/TuStickerLocalPackage.h"
#import "api/TuOnlineStickerDownloader.h"
//#import "api/TuSDKOnlineStickerFetcher.h"
//#import "api/TuSDKSkinFilterAPI.h"
//#import "api/TuSDKTextureCoordinateCropBuilder.h"
//#import "api/TuSDKVerticeCoordinateBuilder.h"
//#import "core/TuSDKComboFilterWrapChain.h"
#import "core/TuFaceAligment.h"
#import "core/TuFilterLocalPackage.h"
//#import "core/TuSDKFilterManager.h"
//#import "core/TuSDKFilterWrap.h"
//#import "core/TuSDKLiveStickerManager.h"
#import "core/TuRatioType.h"
#import "core/TuResult.h"
//#import "core/TuSDKVideoCameraInterface.h"
//#import "filters/gpuimage/TuSDKGPURotateShotOutput.h"
//#import "filters/livesticker/TuSDKGPU2DImageFilter.h"
#import "network/TuNKNetworkEngine.h"
#import "network/TuNKImageAnalysis.h"
#import "network/core/UIImageView+TuNetworkAdditions.h"
#import "secrets/TuAOValid.h"
#import "secrets/TuStatistics.h"
#import "tasks/TuThread.h"
#import "tools/TuAOCellGridViewAlgorithmic.h"

//#import "cx/api/TuComboSticker.h"
//#import "cx/api/TuEngine.h"
//#import "cx/api/TuEngineInput.h"
//#import "cx/api/TuEngineOutput.h"
//#import "cx/api/TuFaceDetector.h"
//#import "cx/api/TuFilterCombo.h"
//#import "cx/api/TuFilterController.h"
//#import "cx/api/TuFilterFrameListener.h"
//#import "cx/api/TuImageShower.h"
#import "cx/seles/extend/SelesParameters.h"
//#import "cx/api/impl/TuFilterEngineImpl.h"

/**
 *  SDK版本
 */
extern NSString * const lsqPulseSDKVersion;

/**
 *  SDK版本代号
 */
extern NSUInteger const lsqPulseSDKCode;

/**
 * SDK配置文件 (lsq_tusdk_configs.json)
 */
extern NSString * const lsqPulseSdkConfigs;

/**
 *  临时文件目录 (APP/Cache/%lsqTemp%)
 */
extern NSString * const lsqPulseTempDir;

/**
 *  资源文件下载目录 (APP/Document/%lsqDownload%)
 */
extern NSString * const lsqPulseDownloadDir;

/**
 *  滤镜预览效果图文件名 (APP/Document/%lsqFilterSamples%)
 */
extern NSString * const lsqPulseFilterSampleDir;

/**
 *  滤镜预览效果图文件后缀 (lfs)
 */
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
@interface TuSDKPulseCore : NSObject
/**SDK界面样式 (默认:lsqSdkUIDefault)*/
@property (nonatomic, copy) NSString *style;
/**用户标识*/
@property (nonatomic, copy) NSString *userIdentify;
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
+ (TuSDKPulseCore *)shared;

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
 *  @param devType 开发模式(需要与lsq_tusdk_configs.json中masters.key匹配， 如果找不到devType将默认读取master字段)
 */
+ (void)initSdkWithAppKey:(NSString *)appkey devType:(NSString *)devType;

/**
 *  设置日志输出级别
 *
 *  @param level 日志输出级别 (默认：lsqLogLevelFATAL 不输出)
 */
+ (void)setLogLevel:(lsqLogLevel)level;

/**
 *  设置文件日志输出级别
 *
 *  @param level 日志输出级别 (默认：lsqLogLevelFATAL 不输出)
 */
+ (void)setFileLogLevel:(lsqLogLevel)level;

/** 检查资源初始化是否完成 */
+ (BOOL)checkResourceLoaded;

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
