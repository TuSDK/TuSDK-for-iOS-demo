//
//  TuSDK.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/25.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TuSDKTSALAssets+Extend.h"
#import "TuSDKTSAnimation.h"
#import "TuSDKTSAVAudioPlayer+Extend.h"
#import "TuSDKTSAVCaptureDevice+Extend.h"
#import "TuSDKTSDate+Extend.h"
#import "TuSDKTSDevice+Extend.h"
#import "TuSDKTSFileManager.h"
#import "TuSDKTSImage+Extend.h"
#import "TuSDKTSLog.h"
#import "TuSDKTSMath.h"
#import "TuSDKTSMotion.h"
#import "TuSDKTSScreen+Extend.h"
#import "TuSDKTSString+Extend.h"

#import "TuSDKICView+Extend.h"
#import "TuSDKICNavigationController.h"
#import "TuSDKICTableView.h"
#import "TuSDKICTableViewCell.h"
#import "TuSDKICFocusTouchView.h"
#import "TuSDKProgressHUD.h"

#import "TuSDKFilterConfig.h"
#import "TuSDKFilterManager.h"
#import "TuSDKStillCamera.h"

#import "TuSDKResult.h"
#import "TuSDKCPAvatarComponent.h"

#import "TuSDKTKFiltersSampleTask.h"

/**
 *  SDK滤镜版本
 */
extern float const lasFilterVersion;

/**
 *  滤镜材质包 (TuSDKFilterTextures)
 */
extern NSString * const lasFilterTextureBundle;

/**
 *  UI材质包 (TuSDKFilterUI)
 */
extern NSString * const lasFilterUIBundle;

/**
 *  临时文件目录 (APP/Cache/%lasFilterTempDir%)
 */
extern NSString * const lasFilterTempDir;

/**
 *  滤镜预览效果图文件名 (APP/Document/%lasFilterSampleDir%)
 */
extern NSString * const lasFilterSampleDir;

/**
 *  滤镜预览效果图文件后缀 (lfs)
 */
extern NSString * const lasFilterSampleExtension;

/**
 *  滤镜预览效果图默认输入图片 (style_default_camera_filter_sample.jpg)
 */
extern NSString * const lasFilterSampleDefaultOriginImage;

/**
 *  相机聚焦音效 (camera_focus_beep.mp3)
 */
extern NSString * const lasFilterCameraFocusBeepAudio;

/**
 *  TuSDK 核心
 *
 *  内部集成滤镜列表(17):
 *  Normal, Artistic, Brilliant, Cheerful, Clear, Fade, Forest, Gloss,
 *  Harmony, Instant, Lightup, Morning, Newborn, Noir, Relaxed, Rough, Thick, Vintage
 *
 *  需要将 TuSDKFilterTextures.bundle 放入应用项目内
 */

@interface TuSDK : NSObject
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
 *  内部滤镜名称列表
 *
 *  @return 内部滤镜名称列表
 */
+ (NSArray *)internalFilterNames;

/**
 *  自定义滤镜名称列表
 *
 *  @return 内部滤镜名称列表
 */
+ (NSArray *)customFilterNames;

/**
 *  滤镜管理器
 *
 *  @return 滤镜管理器
 */
+ (TuSDKFilterManager *)filterManager;

/**
 *  获取滤镜任务
 *
 *  @param image 滤镜预览源图 (如果为空使用SDK自带源图进行渲染)
 *
 *  @return 滤镜任务
 */
+ (TuSDKTKFiltersTaskBase *)samplesTaskWithImage:(UIImage *)image;

/**
 *  材质资源库文件路径
 *
 *  @param name 文件名
 *
 *  @return 材质资源库文件路径
 */
+ (NSString *)uiBundlePathWithName:(NSString *)name;

/**
 *  相机对象
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
 *  获取头像设置组件
 *
 *  @param controller 来源控制器
 *  @param block      获取头像图片回调
 *
 *  @return 头像设置组件
 */
+ (TuSDKCPAvatarComponent *)avatarCommponentWithController:(UIViewController *)controller callbackBlock:(TuSDKCPAvatarReadedBlock)block;
@end
