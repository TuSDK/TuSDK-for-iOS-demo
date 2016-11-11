//
//  TuSDKPFSticker.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#import "TuSDKPFStickerText.h"
#import "TuSDKDataJson.h"

#pragma mark - TuSDKStickerPositionInfo

/**
 *  智能贴纸类型
 */
typedef NS_ENUM(NSUInteger, lsqStickerPostionType)
{
    /**
     * 眉毛
     */
    lsqStickerPosEyeBrow = 1,
    /**
     * 眼睛
     */
    lsqStickerPosEye = 2,
    /**
     * 鼻子
     */
    lsqStickerPosNose = 3,
    /**
     * 嘴巴
     */
    lsqStickerPosMouth = 4,
    /**
     * 脸颊
     */
    lsqStickerPosCheek = 5,
    /**
     * 头饰
     */
    lsqStickerPosHead = 6,
    /**
     * 下巴
     */
    lsqStickerPosJaw = 7,
    /**
     * 眼影
     */
    lsqStickerPosEyeShadow = 8,
    /**
     * 唇膏
     */
    lsqStickerPosLip = 9
    
};


@interface TuSDKStickerPositionInfo : NSObject

/**
 *  贴纸模型尺寸
 */
@property (nonatomic, readonly) CGSize modelSize;

/**
 *  贴纸模型类型
 */
@property (nonatomic, readonly) NSUInteger modelType;

/**
 *  贴纸定位类型
 */
@property (nonatomic, readonly) lsqStickerPostionType posType;

/**
 *  宽高比
 */
@property (nonatomic, readonly) CGFloat ratio;

/**
 *  贴纸缩放系数
 */
@property (nonatomic, readonly) CGFloat scale;

/**
 *  与定位参考点的X坐标位移
 */
@property (nonatomic, readonly) CGFloat offsetX;

/**
 *  与定位参考点的Y坐标位移
 */
@property (nonatomic, readonly) CGFloat offsetY;

/**
 *  旋转系数
 */
@property (nonatomic, readonly) CGFloat rotation;

/**
 *  初始化
 *
 *  @param json Json字典
 */
- (instancetype)initWithJson:(NSDictionary *)json;

@end

#pragma mark - TuSDKPFSticker

/**
 *  贴纸元素类型
 */
typedef NS_ENUM(NSInteger, lsqStickerType)
{
    /**
     * 图片贴纸
     */
    lsqStickerImage = 1,
    /**
     * 文字水印贴纸
     */
    lsqStickerText = 2,
    /**
     * 智能贴纸
     */
    lsqStickerFace = 3,
};

/**
 *  贴纸数据对象
 */
@interface TuSDKPFSticker : TuSDKDataJson
/**
 * 贴纸ID
 */
@property (nonatomic) uint64_t idt;

/**
 * 贴纸包ID
 */
@property (nonatomic) uint64_t groupId;

/**
 * 贴纸分类ID
 */
@property (nonatomic) uint64_t categoryId;

/**
 * 贴纸名称
 */
@property (nonatomic, copy) NSString *name;

/**
 * 预览视图文件名
 */
@property (nonatomic, copy) NSString *preivewName;

/**
 * 贴纸文件名
 */
@property (nonatomic, copy) NSString *stickerImageName;

/**
 * 贴纸长宽 (单位DP: 需要与原始图片比例保持一致，否则会造成成图片变形)
 */
@property (nonatomic) CGSize size;

/**
 *  贴纸元素类型
 */
@property (nonatomic, readonly) lsqStickerType type;

/**
 *  贴纸图片
 */
@property (nonatomic, retain) UIImage *image;

/**
 *  贴纸文字列表
 */
@property (nonatomic, retain) NSArray *texts;

/**
 *  贴纸定位信息
 */
@property (nonatomic, readonly) TuSDKStickerPositionInfo *positionInfo;

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
- (TuSDKPFStickerText *)stickerTextWithId:(uint64_t)textId;
@end
