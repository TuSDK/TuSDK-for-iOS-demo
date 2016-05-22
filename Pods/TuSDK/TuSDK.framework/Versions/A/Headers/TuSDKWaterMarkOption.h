//
//  TuSDKWaterMarkOption.h
//  TuSDK
//
//  Created by Yanlin on 5/18/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  水印位置
 */
typedef NS_ENUM(NSInteger, lsqWaterMarkPosition)
{
    /**
     *  左上角
     */
    lsqWaterMarkTopLeft = 1,
    /**
     *  右上角
     */
    lsqWaterMarkTopRight = 1 << 1,
    
    /**
     * 左下角
     */
    lsqWaterMarkBottomLeft = 1 << 2,
    
    /**
     * 右下角
     */
    lsqWaterMarkBottomRight = 1 << 3,
    
    /**
     * 居中
     */
    lsqWaterMarkCenter = 1 << 4,
};

/**
 *  水印文本位置： 文本 + 图片 | 图片 + 文本
 */
typedef NS_ENUM(NSInteger, lsqMarkTextPosition)
{
    /**
     *  左边
     */
    lsqMarkTextPositionLeft = 1,
    /**
     *  右边
     */
    lsqMarkTextPositionRight = 1 << 1,
};


/**
 *  水印配置
 */
@interface TuSDKWaterMarkOption : NSObject

/**
 *  水印位置 (默认: lsqWaterMarkBottomRight)
 */
@property (nonatomic, assign) lsqWaterMarkPosition markPosition;

/**
 *  水印文字
 */
@property (nonatomic) NSString *markText;

/**
 *  水印图片
 */
@property (nonatomic, retain) UIImage *markImage;

/**
 *  水印距离图片边距 (默认: 6dp)
 */
@property (nonatomic) CGFloat markMargin;

/**
 *  文字和图片顺序 (仅当图片和文字都非空时生效，默认: 文字在右)
 */
@property (nonatomic) lsqMarkTextPosition markTextPosition;

/**
 *  文字和图片间距 (默认: 2dp)
 */
@property (nonatomic) CGFloat markTextPadding;

/**
 * 文字大小 (默认: 24 SP)
 */
@property (nonatomic) CGFloat markTextSize;

/**
 *  文字背景色 (默认:[UIColor whiteColor])
 */
@property (nonatomic, retain) UIColor *markTextColor;

/**
 *  文字阴影颜色 (默认:[UIColor grayColor])
 */
@property (nonatomic, retain) UIColor *markTextShadowColor;

/**
 *  水印是否可用
 *
 *  @return
 */
- (BOOL)isValid;

@end
