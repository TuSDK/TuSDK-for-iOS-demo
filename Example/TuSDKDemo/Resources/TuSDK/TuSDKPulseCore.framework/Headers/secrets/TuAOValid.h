//
//  TuAOValid.h
//  TuSDK
//
//  Created by Clear Hu on 14/12/15.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/** SDK用户验证 */
@interface TuAOValid : NSObject

/** SDK用户验证 */
+ (instancetype) shared;

/** 是否通过开发者账号验证 */
@property (nonatomic, readonly, getter=isValid) BOOL isValid;
/** 开发者ID [ewdjn1] */
@property (nonatomic, readonly) NSString *developerId;
/** appkey [1724c60dc2fd4a86-04-ewdjn1]*/
@property (nonatomic, readonly) NSString *appKey;
/** appType */
@property (nonatomic, readonly) NSUInteger appType;
/** 权限加密信息MD5 */
@property (nonatomic, readonly) NSString *masterMd5;
/** 资源是否已加载完成 */
@property (nonatomic, readonly) BOOL isLoaded;

/**
 *  验证开发者ID
 *
 *  @param key 开发者ID
 *  @param devType 开发模式(需要与lsq_tusdk_configs.json中masters.key匹配， 如果找不到devType将默认读取master字段)
 *
 *  @return BOOL 是否通过验证
 */
- (BOOL)sdkValidWithKey:(NSString *)key devType:(NSString *)devType specialKey:(NSString *)specialKey;
/** 是否通过验证开发者ID */
- (BOOL)sdkValid;
/** 是否过期 allTypes:是否所有过期*/
- (BOOL)isExpired:(BOOL)allTypes;
/** 最近的超时时间*/
- (NSTimeInterval)expiredSeconds;
/** 检查权限信息 */
- (NSUInteger)checkAuthor:(NSUInteger)author;
/** 下次 auth 信息请求时间 [秒] */
- (NSTimeInterval) nextUpdate:(NSTimeInterval)expire succeed:(BOOL)succeed;
/** 请求配置信息 */
- (void)checkAppAuth;
/**
 * 检查权限是否到期
 * @return 返回权限是否到期值
 */
- (BOOL)checkServiceExpire;
/** 打印权限列表 */
- (void)logAuthors;

#pragma mark-  decode
/** 加密文本 返回索引以及数据[(NSNumber *)index, (NSData *)data] */
- (NSDictionary *)sdkAESEncodeWithString:(NSString *)str;
#pragma mark-  Image
/** 图片最大允许处理的边长 */
- (CGFloat)maxImageSide;
/** 允许最多使用贴纸数量 */
- (NSUInteger)maxStickers;
/** 本地滤镜总数 */
- (NSUInteger)localFilterCount;
/** 本地贴纸总数 */
- (NSUInteger)localStickerCount;
/** 是否去水印 */
- (BOOL)noPower;
/** 去除视频版权声明 */
- (BOOL)noVideoPower;
/** 是否允许实时渲染滤镜预览图 */
- (BOOL)renderFilterThumb;
/** 涂抹功能是否开启 */
- (BOOL)smudgeEnabled;
/** 画笔涂鸦功能是否开启 */
- (BOOL)paintEnabled;
/** 滤镜涂抹功能是否开启 */
- (BOOL)wipeFilterEnabled;
/** HDR 功能是否开启 */
- (BOOL)hdrFilterEnabled;
/** 美颜级别 */
- (NSUInteger)beautyLevel;

#pragma mark-  Video
/** 视频录制权限是否开启 */
- (BOOL)videoRecordEnabled;
/** 视频录制时长控制是否开启 */
- (BOOL)videoDurationEnabled;
/** 视频编辑功能是否开启 */
- (BOOL)videoEditEnabled;
/** video record continuous support 断点续拍 */
- (BOOL)videoRecordContinuousSupport;
/** video camera shot support 拍照*/
- (BOOL)videoCameraShotSupport;
/** video camera sticker support 相机贴纸*/
- (BOOL)videoCameraStickerSupport;
/** video camera bitrate support 相机 自定义码率*/
- (BOOL)videoCameraBitrateSupport;
/** video camera monster face support 录制相机 是否支持哈哈镜特效*/
- (BOOL)videoCameraMonsterFaceSupport;
/** video editor music support 编辑视频 添加音乐*/
- (BOOL)videoEditorMusicSupport;
/** video editor sticker support 编辑视频 添加贴纸*/
- (BOOL)videoEditorStickerSupport;
/** video editor filter support 编辑视频 使用滤镜*/
- (BOOL)videoEditorFilterSupport;
/** video editor bitrate support 编辑视频 自定义码率*/
- (BOOL)videoEditorBitrateSupport;
/** video editor resolution support 编辑视频 自定义分辨率*/
- (BOOL)videoEditorResolutionSupport;
/** video editor scene effects filter support 编辑视频 是否支持场景特效滤镜*/
- (BOOL)videoEditorSceneEffectsFilterSupport;
/** video editor particle effects filter support 编辑视频 是否支持粒子特效滤镜*/
- (BOOL)videoEditorParticleEffectsFilterSupport;
/** video editor text effects support 编辑视频 是否支持文字特效 */
- (BOOL)videoEditorTextEffectsSupport;
/** video editor text effects support 编辑视频 是否漫画特效 */
- (BOOL)videoEditorComicEffectsSupport;
/** video editor monster face support 编辑视频 是否支持哈哈特效*/
- (BOOL)videoEditorMonsterFaceSupport;
/** video editor transition support 编辑视频 是否支持转场特效 */
- (BOOL)videoEditorTransitionSupport;
/** video composition support 合成视频 是否视频合成 */
- (BOOL)videoCompositionSupport;
/** 视频直播功能是否开启 */
- (BOOL)videoStreamEnabled;
/** video editor image sticker effects support 编辑视频 是否支持自定义图片贴纸 */
- (BOOL)videoEditorImageStickerSupport;
/** audioPitchEffectsSupport 音频变声权限 */
- (BOOL)audioPitchEffectsSupport;
/** audioResampleEffectsSupport 音频重采样权限 */
- (BOOL)audioResampleEffectsSupport;
#pragma mark- Eva

/** EVA 支持替换文字 */
- (BOOL)evaEditorReplaceTxtSupport;
/** EVA 支持替换图像 */
- (BOOL)evaEditorReplaceImgSupport;
/** EVA 支持替换视频 */
- (BOOL)evaEditorReplaceVideoSupport;
/** EVA 支持替换音频 */
- (BOOL)evaEditorReplaceAudioSupport;
/** EVA 去除版权声明 */
- (BOOL)evaEditorWipeCopyRightSupport;
/** EVA 自定义码率 */
- (BOOL)evaEditorBitrateSupport;
/** EVA 自定义分辨率 */
- (BOOL)evaEditorResolutionSupport;
/** EVA 导出时添加水印 */
- (BOOL)evaEditorAddMarkImageSupport;
/** 当前支持的功能模块 */
- (NSUInteger)evaEnableFunctions;
#pragma mark- face

/** 本地人脸检测标点数 */
- (NSUInteger)faceLocalMarks;
/** 本地人脸检测图片 */
- (BOOL)faceLocalImageSupport;
/** 本地人脸检测视频 */
- (BOOL)faceLocalVideoSupport;
/** 基于本地人脸检测的美颜 */
- (BOOL)faceLocalBeautySupport;
@end
