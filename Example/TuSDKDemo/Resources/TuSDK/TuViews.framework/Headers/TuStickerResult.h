//
//  TuStickerResult.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "TuSDKPulseCore/components/widgets/sticker/TuSticker.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>
/**
 *  贴纸结果
 */
@interface TuStickerResult : NSObject
/**
 * 居中位置信息
 */
@property (nonatomic) CGRect center;

/**
 * 旋转度数
 */
@property (nonatomic) float degree;

/**
 * 贴纸元素
 */
@property (nonatomic, retain) TuSticker *sticker;

/**
 *  初始化贴纸结果
 *
 *  @param sticker 贴纸元素
 *  @param center  居中位置信息
 *  @param degree  旋转度数
 *
 *  @return 贴纸结果
 */
+ (instancetype)initWithSticker:(TuSticker *)sticker center:(CGRect)center degree:(float)degree;
@end
