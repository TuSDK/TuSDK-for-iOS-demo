//
//  TuSDKStickerText.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulseCore/TuDataJson.h>

/**
 *  贴纸文字类型
 */
typedef NS_ENUM(NSInteger, TuStickerTextType)
{
    TuStickerTextEmpty = 0,
    /**
     * 默认文字类型
     */
    TuStickerTextDefault = 1,
    /**
     * 时间信息 09:38
     */
    TuStickerTextTime = 2,
    /**
     * 日期信息 29/05/2014
     */
    TuStickerTextDate = 3,
    /**
     * 日期时间信息 29/05/2014 09:38
     */
    TuStickerTextDateTime = 4,
    /**
     * 地理信息
     */
    TuStickerTextLocal = 5,
    /**
     * 天气信息
     */
    TuStickerTextWeather = 6,
};

/**
 *  贴纸文字
 */
@interface TuStickerText : TuDataJson
/**
 * 贴纸ID
 */
@property (nonatomic) uint64_t idt;

/**
 * 贴纸ID
 */
@property (nonatomic) uint64_t stickerId;

/**
 * 贴纸包ID
 */
@property (nonatomic) uint64_t groupId;

/**
 * 贴纸分类ID
 */
@property (nonatomic) uint64_t categoryId;

/**
 *  贴纸文字类型
 */
@property (nonatomic, readonly) TuStickerTextType type;

/**
 * 文字信息
 */
@property (nonatomic, copy) NSString *text;

/**
 * 文字样式
 */
@property (nonatomic, copy) NSDictionary *textStyleDic;

/**
 * 文字颜色
 */
@property (nonatomic, retain) UIColor *color;

/**
 * 文字阴影颜色
 */
@property (nonatomic, retain) UIColor *shadowColor;

/**
 *  背景颜色
 */
@property (nonatomic, retain) UIColor *bgColor;

/**
 *  下划线
 */
@property (nonatomic) BOOL underline;

/**
 * 文字大小 (单位:SP)
 */
@property (nonatomic) CGFloat size;

/**
 * 文字区域位置长宽百分比信息
 */
@property (nonatomic) CGRect rect;

/**
 * 文字区域长宽信息
 */
@property (nonatomic) CGSize rectSize;

/**文字视图的 paddings */
@property (nonatomic) NSInteger paddings;

/**
 * 文字对齐方式 (0:左对齐, 1:居中对齐, 2:右对齐)
 */
@property (nonatomic) NSTextAlignment alignment;

/**
 * 文字区域生成的图片，优先使用图片，为nil 时，使用参数进行绘制
 */
@property (nonatomic) UIImage *textImage;

/**
 *  贴纸文字对象
 *
 *  @return 贴纸文字对象
 */
+ (instancetype)textWithType:(TuStickerTextType)type;

/**
 *  复制数据
 *
 *  @return 贴纸文字
 */
- (instancetype) copy;
@end
