//
//  TuSDK.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/25.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TuSDKTSALAssets+Extend.h"
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
 *  设置日志输出级别
 *
 *  @param level 日志输出级别 (默认：lsqLogLevelFATAL 不输出)
 */
+ (void)setLogLevel:(lsqLogLevel)level;

/**
 *  滤镜名称列表
 *
 *  @return 滤镜名称列表
 */
+ (NSArray *)filterNames;

/**
 *  滤镜管理器
 *
 *  @return 滤镜管理器
 */
+ (TuSDKFilterManager *)filterManager;

/**
 *  材质资源库文件路径
 *
 *  @param name 文件名
 *
 *  @return 材质资源库文件路径
 */
+ (NSString *)uiBundlePathWithName:(NSString *)name;

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
