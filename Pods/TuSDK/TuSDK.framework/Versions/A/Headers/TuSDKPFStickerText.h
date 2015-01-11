//
//  TuSDKStickerText.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

/**
 *  贴纸文字类型
 */
typedef NS_ENUM(NSInteger, lsqStickerTextType)
{
    /**
     * 默认文字类型
     */
    lsqStickerTextDefault,
    /**
     * 时间信息 09:38
     */
    lsqStickerTextTime,
    /**
     * 日期信息 29/05/2014
     */
    lsqStickerTextDate,
    /**
     * 日期时间信息 29/05/2014 09:38
     */
    lsqStickerTextDateTime,
    /**
     * 地理信息
     */
    lsqStickerTextLocal,
    /**
     * 天气信息
     */
    lsqStickerTextWeather,
};

/**
 *  贴纸文字
 */
@interface TuSDKPFStickerText : NSObject
/**
 *  贴纸文字类型
 */
@property (nonatomic, readonly) lsqStickerTextType type;

/**
 * 文字信息
 */
@property (nonatomic, copy) NSString *text;

/**
 * 文字颜色
 */
@property (nonatomic, retain) UIColor *color;

/**
 * 文字大小 (单位:SP)
 */
@property (nonatomic) float size;

/**
 * 文字区域位置长宽百分比信息
 */
@property (nonatomic) CGRect rect;

/**
 * 文字对齐方式 (0:左对齐, 1:居中对齐, 2:右对齐)
 */
@property (nonatomic) NSTextAlignment alignment;

/**
 *  贴纸文字对象
 *
 *  @return 贴纸文字对象
 */
+ (instancetype)textWithType:(lsqStickerTextType)type;

/**
 *  复制数据
 *
 *  @return 贴纸文字
 */
- (instancetype) copy;
@end
