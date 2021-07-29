//
//  TuSticker.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulseCore/TuDataJson.h>
@class TuStickerText;
#pragma mark - TuStickerPositionInfo

/** 智能贴纸类型 */
typedef NS_ENUM(NSUInteger, TuStickerPositionType)
{
    TuStickerPosEmpty              = 0,
    TuStickerPosEyeBrow            = 1, // 眉毛
    TuStickerPosEye                = 2, // 眼睛
    TuStickerPosNose               = 3, // 鼻子
    TuStickerPosMouth              = 4, // 嘴巴
    TuStickerPosCheek              = 5, // 脸颊
    TuStickerPosHead               = 6, // 头饰
    TuStickerPosJaw                = 7, // 下巴

    TuStickerCosEyeShadow          = 31,   // 眼影 (v4.0)
    TuStickerCosEyeLine            = 32,   // 眼线 (v4.0)
    TuStickerCosEyeLash            = 33,   // 睫毛 (v4.0)
    TuStickerCosBrows              = 34,   // 画眉 (v4.0)
    TuStickerCosBlush              = 35,   // 腮红 (v4.0)
    TuStickerCosLipGloss           = 36,   // 唇彩 (v4.0)
    TuStickerCosIris               = 37,   // 彩瞳 (v4.0)
    
    TuStickerPosFullScreen         = 100, // 全屏显示
    TuStickerPosScreenLeftTop      = 101, // 左上角
    TuStickerPosScreenRightTop     = 102, // 右上角
    TuStickerPosScreenLeftBottom   = 103, // 左下角
    TuStickerPosScreenRightBottom  = 104, // 右下角
    TuStickerPosScreenCenter       = 105, // 中心
    TuStickerPosScreenRightCenter  = 106, // 右对齐居中
    TuStickerPosScreenLeftCenter   = 107, // 左对齐居中
    TuStickerPosScreenTopCenter    = 108, // 顶部对齐居中
    TuStickerPosScreenBottomCenter = 109, // 右下角对齐居中
};

/** 动画播放模式 */
typedef NS_ENUM(NSInteger, TuStickerLoopMode)
{
    TuStickerLoopEmpty = 0,
    /** 正向循环*/
    TuStickerLoop = 1,
    /** 反向循环*/
    TuStickerLoopReverse = 2,
    /** 随机循环*/
    TuStickerLoopRandom = 3
};

/**
 *  渲染模式
 */
typedef NS_ENUM(NSInteger, TuStickerRenderType)
{
    TuStickerRenderEmpty = 0,
    /** Alpha 混合*/
    TuStickerRenderAlphaBlend = 1,
    /** 正片叠底*/
    TuStickerRenderBlendMultiply = 2,
    /** Light*/
    TuStickerRenderLightGlare = 3
};


@interface TuStickerPositionInfo : NSObject

/** 贴纸模型尺寸*/
@property (nonatomic) CGSize modelSize;

/** 设计屏幕尺寸*/
@property (nonatomic) CGSize designScreenSize;

/** 贴纸模型类型*/
@property (nonatomic) NSUInteger modelType;

/** 贴纸定位类型*/
@property (nonatomic) TuStickerPositionType posType;

/** 贴纸渲染类型*/
@property (nonatomic) TuStickerRenderType renderType;

/** 宽高比*/
@property (nonatomic) CGFloat ratio;

/** 贴纸缩放系数*/
@property (nonatomic) CGFloat scale;

/** 与定位参考点的X坐标位移*/
@property (nonatomic) CGFloat offsetX;

/** 与定位参考点的Y坐标位移*/
@property (nonatomic) CGFloat offsetY;

/** 旋转系数*/
@property (nonatomic) CGFloat rotation;

/** 每帧持续时间*/
@property (nonatomic) NSUInteger frameInterval;

/** 播放模式*/
@property (nonatomic) TuStickerLoopMode loopMode;

/** 动画循环起始帧索*/
@property (nonatomic) NSUInteger loopStartIndex;

/** 素材列表*/
@property (nonatomic, retain) NSArray *resourceList;

/**
 *  初始化
 *
 *  @param json Json字典
 */
- (instancetype)initWithJson:(NSDictionary *)json;

/** 是否支持动画*/
- (BOOL)hasAnimationSupported;
@end

#pragma mark - TuSticker

/** 贴纸元素类型*/
typedef NS_ENUM(NSInteger, TuSDKStickerType)
{
    TuSDKStickerEmpty     = 0,
    TuSDKStickerImage     = 1, // 图片贴纸
    TuSDKStickerText      = 2, // 文字水印贴纸
    TuSDKStickerDynamic   = 3, // 智能贴纸
    TuSDKStickerCosmetic  = 4, // 美妆贴纸 (v4.0)
};

/** 贴纸数据对象*/
@interface TuSticker : TuDataJson
/** 贴纸ID*/
@property (nonatomic) uint64_t idt;

/** 贴纸包ID*/
@property (nonatomic) uint64_t groupId;

/** 贴纸分类ID*/
@property (nonatomic) uint64_t categoryId;

/** 贴纸名称*/
@property (nonatomic, copy) NSString *name;

/** 预览视图文件名*/
@property (nonatomic, copy) NSString *previewName;

/** 贴纸文件名*/
@property (nonatomic, copy) NSString *stickerImageName;

/** 贴纸长宽 (单位DP: 需要与原始图片比例保持一致，否则会造成成图片变形)*/
@property (nonatomic) CGSize size;

/** 贴纸元素类型*/
@property (nonatomic) TuSDKStickerType type;

/** 贴纸图片*/
@property (nonatomic, retain) UIImage *image;

/** 贴纸文字列表*/
@property (nonatomic, retain) NSArray *texts;

/** 贴纸定位信息*/
@property (nonatomic, retain) TuStickerPositionInfo *positionInfo;

/**
 *  贴纸数据对象
 *
 *  @return 贴纸数据对象
 */
+ (instancetype)sticker;

/**
 *  贴纸数据对象
 *
 *  @return 贴纸数据对象
 */
+ (instancetype)stickerWithType:(TuSDKStickerType)type;

/**
 *  复制数据
 *
 *  @return 贴纸数据对象
 */
- (instancetype) copy;

/**
 *  获取贴纸文字
 *
 *  @param textId 贴纸文字ID
 *
 *  @return 贴纸文字
 */
- (TuStickerText *)stickerTextWithId:(uint64_t)textId;

/** 动态贴纸是否依赖人脸特征*/
- (BOOL)requireFaceFeature;
@end
