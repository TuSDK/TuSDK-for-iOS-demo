//
//  TuSDK.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/25.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//  http://tusdk.com/docs/ios/api/
//

#import <Foundation/Foundation.h>

#import "TuSDKTKThread.h"
#import "TuSDKTKStatistics.h"

#import "TuSDKTSALAssets+Extend.h"
#import "TuSDKTSAnimation.h"
#import "TuSDKTSAVAudioPlayer+Extend.h"
#import "TuSDKTSAVCaptureDevice+Extend.h"
#import "TuSDKTSBundle.h"
#import "TuSDKTSDate+Extend.h"
#import "TuSDKTSDevice+Extend.h"
#import "TuSDKTSDeviceSettings.h"
#import "TuSDKTSFileManager.h"
#import "TuSDKTSImage+Extend.h"
#import "TuSDKTSLog.h"
#import "TuSDKTSMath.h"
#import "TuSDKTSMotion.h"
#import "TuSDKTSNSArray+Extend.h"
#import "TuSDKTSNSData+Extend.h"
#import "TuSDKTSNSDictionary+Extend.h"
#import "TuSDKTSNSUserDefaults+Extend.h"
#import "TuSDKTSScreen+Extend.h"
#import "TuSDKTSString+Extend.h"
#import "TuSDKTSUIColor+Extend.h"

#import "TuSDKICView+Extend.h"
#import "TuSDKICNavigationController.h"
#import "TuSDKICTableView.h"
#import "TuSDKICTableViewCell.h"
#import "TuSDKCPFocusTouchView.h"
#import "TuSDKProgressHUD.h"

#import "TuSDKFilterLocalPackage.h"
#import "TuSDKFilterManager.h"
#import "TuSDKStillCamera.h"
#import "TuSDKPFStickerLocalPackage.h"

#import "TuSDKRatioType.h"
#import "TuSDKResult.h"
#import "TuSDKCPAvatarComponent.h"
#import "TuSDKCPPhotoEditComponent.h"
#import "TuSDKCPPhotoEditMultipleComponent.h"

/**
 *  SDK版本
 */
extern NSString * const lsqSDKVersion;

/**
 *  SDK版本代号
 */
extern NSUInteger const lsqSDKCode;

/**
 * SDK配置文件 (lsq_tusdk_configs.json)
 */
extern NSString * const lsqSdkConfigs;

/**
 *  临时文件目录 (APP/Cache/%lsqTemp%)
 */
extern NSString * const lsqTempDir;

/**
 *  资源文件下载目录 (APP/Document/%lsqDownload%)
 */
extern NSString * const lsqDownloadDir;

/**
 *  滤镜预览效果图文件名 (APP/Document/%lsqFilterSamples%)
 */
extern NSString * const lsqFilterSampleDir;

/**
 *  滤镜预览效果图文件后缀 (lfs)
 */
extern NSString * const lsqFilterSampleExtension;

/**
 *  TuSDK 核心
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDK.html
 *
 *  内部集成滤镜列表(17):
 *  Normal, Artistic, Brilliant, Cheerful, Clear, Fade, Forest, Gloss,
 *  Harmony, Instant, Lightup, Morning, Newborn, Noir, Relaxed, Rough, Thick, Vintage
 *
 *  需要将 TuSDKFilterTextures.bundle 放入应用项目内
 */

@interface TuSDK : NSObject

/**
 *  SDK界面样式 (默认:lsqSdkUIDefault)
 */
@property (nonatomic, copy) NSString *style;

/**
 *  用户标识
 */
@property (nonatomic, copy) NSString *userIdentify;

/**
 *  TuSDK 核心
 *
 *  @return TuSDK 核心
 */
+ (TuSDK *)shared;

/**
 *  初始化SDK
 *
 *  @param appkey 应用秘钥 (请前往 http://tusdk.com 申请秘钥)
 */
+ (void)initSdkWithAppKey:(NSString *)appkey;

/**
 *  设置日志输出级别
 *
 *  @param level 日志输出级别 (默认：lsqLogLevelFATAL 不输出)
 */
+ (void)setLogLevel:(lsqLogLevel)level;

/**
 *  应用临时目录
 *
 *  @return 应用临时目录
 */
+ (NSString *)appTempPath;

/**
 *  应用下载目录
 *
 *  @return 应用下载目录
 */
+ (NSString *)appDownloadPath;

/**
 *  滤镜代号列表
 *
 *  @return 滤镜代号列表
 */
+ (NSArray *)filterCodes;

/**
 *  滤镜管理器
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKFilterManager.html
 *
 *  @return 滤镜管理器
 */
+ (TuSDKFilterManager *)filterManager;

/**
 *  贴纸管理器
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKPFStickerLocalPackage.html
 *
 *  @return 贴纸管理器
 */
+ (TuSDKPFStickerLocalPackage *)stickerManager;

/**
 *  检查滤镜管理器是否初始化
 *
 *  @param delegate   滤镜控管理器委托
 */
+ (void)checkManagerWithDelegate:(id<TuSDKFilterManagerDelegate>)delegate;

/**
 *  获取滤镜任务
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKTKFiltersTempTask.html
 *
 *  @param image 滤镜预览源图 (如果为空使用SDK自带源图进行渲染)
 *  @param filterNames 需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
 *
 *  @return 滤镜任务
 */
+ (TuSDKTKFiltersTaskBase *)samplesTaskWithImage:(UIImage *)image filterNames:(NSArray *)filterNames;

/**
 *  相机对象
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKStillCamera.html
 *
 *  @param sessionPreset  相机分辨率类型 
 *  @see AVCaptureSessionPresetPhoto
 *  @param cameraPosition 相机设备标识 （前置或后置）
 *  @param cameraView     相机显示容器视图
 *
 *  @return 相机对象
 */
+ (TuSDKStillCamera *)cameraWithSessionPreset:(NSString *)sessionPreset
                               cameraPosition:(AVCaptureDevicePosition)cameraPosition
                                   cameraView:(UIView *)view;

/**
 *  自定义系统相册组件
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPAlbumComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return 自定义系统相册组件
 */
+ (TuSDKCPAlbumComponent *)albumCommponentWithController:(UIViewController *)controller
                                           callbackBlock:(TuSDKCPComponentBlock)block;

/**
 *  获取头像设置组件
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPAvatarComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return 头像设置组件
 */
+ (TuSDKCPAvatarComponent *)avatarCommponentWithController:(UIViewController *)controller
                                             callbackBlock:(TuSDKCPComponentBlock)block;

/**
 *  获取图片编辑组件
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPPhotoEditComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return 图片编辑组件
 */
+ (TuSDKCPPhotoEditComponent *)photoEditCommponentWithController:(UIViewController *)controller
                                                   callbackBlock:(TuSDKCPComponentBlock)block;

/**
 *  获取多功能图像编辑组件
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPPhotoEditMultipleComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return 多功能图像编辑组件
 */
+ (TuSDKCPPhotoEditMultipleComponent *)photoEditMultipleWithController:(UIViewController *)controller
                                                         callbackBlock:(TuSDKCPComponentBlock)block;
@end
