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
#import "TuSDKPulseCore/components/widgets/sticker/TuStickerText.h"
#import "TuSDKPulseCore/tools/TuDataJson.h"

#pragma mark - TuStickerPositionInfo

/** 智能贴纸类型 */
typedef NS_ENUM(NSUInteger, lsqStickerPositionType)
{
    lsqStickerPosEmpty              = 0,
    lsqStickerPosEyeBrow            = 1, // 眉毛
    lsqStickerPosEye                = 2, // 眼睛
    lsqStickerPosNose               = 3, // 鼻子
    lsqStickerPosMouth              = 4, // 嘴巴
    lsqStickerPosCheek              = 5, // 脸颊
    lsqStickerPosHead               = 6, // 头饰
    lsqStickerPosJaw                = 7, // 下巴

    lsqStickerCosEyeShadow          = 31,   // 眼影 (v4.0)
    lsqStickerCosEyeLine            = 32,   // 眼线 (v4.0)
    lsqStickerCosEyeLash            = 33,   // 睫毛 (v4.0)
    lsqStickerCosBrows              = 34,   // 画眉 (v4.0)
    lsqStickerCosBlush              = 35,   // 腮红 (v4.0)
    lsqStickerCosLipGloss           = 36,   // 唇彩 (v4.0)
    lsqStickerCosIris               = 37,   // 彩瞳 (v4.0)
    
    lsqStickerPosFullScreen         = 100, // 全屏显示
    lsqStickerPosScreenLeftTop      = 101, // 左上角
    lsqStickerPosScreenRightTop     = 102, // 右上角
    lsqStickerPosScreenLeftBottom   = 103, // 左下角
    lsqStickerPosScreenRightBottom  = 104, // 右下角
    lsqStickerPosScreenCenter       = 105, // 中心
    lsqStickerPosScreenRightCenter  = 106, // 右对齐居中
    lsqStickerPosScreenLeftCenter   = 107, // 左对齐居中
    lsqStickerPosScreenTopCenter    = 108, // 顶部对齐居中
    lsqStickerPosScreenBottomCenter = 109, // 右下角对齐居中
};

/** 动画播放模式 */
typedef NS_ENUM(NSInteger, lsqStickerLoopMode)
{
    lsqStickerLoopEmpty = 0,
    /** 正向循环*/
    lsqStickerLoop = 1,
    /** 反向循环*/
    lsqStickerLoopReverse = 2,
    /** 随机循环*/
    lsqStickerLoopRandom = 3
};

/**
 *  渲染模式
 */
typedef NS_ENUM(NSInteger, lsqStickerRenderType)
{
    lsqStickerRenderEmpty = 0,
    /** Alpha 混合*/
    lsqStickerRenderAlphaBlend = 1,
    /** 正片叠底*/
    lsqStickerRenderBlendMultiply = 2,
    /** Light*/
    lsqStickerRenderLightGlare = 3
};


@interface TuStickerPositionInfo : NSObject

/** 贴纸模型尺寸*/
@property (nonatomic) CGSize modelSize;

/** 设计屏幕尺寸*/
@property (nonatomic) CGSize designScreenSize;

/** 贴纸模型类型*/
@property (nonatomic) NSUInteger modelType;

/** 贴纸定位类型*/
@property (nonatomic) lsqStickerPositionType posType;

/** 贴纸渲染类型*/
@property (nonatomic) lsqStickerRenderType renderType;

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
@property (nonatomic) lsqStickerLoopMode loopMode;

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
typedef NS_ENUM(NSInteger, lsqStickerType)
{
    lsqStickerEmpty     = 0,
    lsqStickerImage     = 1, // 图片贴纸
    lsqStickerText      = 2, // 文字水印贴纸
    lsqStickerDynamic   = 3, // 智能贴纸
    lsqStickerCosmetic  = 4, // 美妆贴纸 (v4.0)
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
@property (nonatomic) lsqStickerType type;

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
+ (instancetype)stickerWithType:(lsqStickerType)type;

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
