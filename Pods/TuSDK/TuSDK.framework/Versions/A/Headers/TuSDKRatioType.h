//
//  TuSDKRatioType.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  裁剪比例
 */
typedef NS_ENUM(NSInteger, lsqRatioType)
{
    /**
     *  原始比例
     */
    lsqRatioOrgin = 1,
    /**
     *  1:1比例
     */
    lsqRatio_1_1 = 1 << 1,
    
    /**
     * 2:3比例
     */
    lsqRatio_2_3 = 1 << 2,
    
    /**
     * 3:4比例
     */
    lsqRatio_3_4 = 1 << 3,
    
    /**
     * 3:4比例
     */
    lsqRatio_9_16 = 1 << 4,
    
    /**
     * 所有比例
     */
    lsqRatioAll = lsqRatioOrgin | lsqRatio_1_1 | lsqRatio_2_3 | lsqRatio_3_4 | lsqRatio_9_16,
};

/**
 *  裁剪比例
 */
@interface TuSDKRatioType : NSObject
/**
 *  比例类型列表
 */
+ (NSArray *)lsqTuSDKRatioTypes;

/**
 * 获取比例
 *
 * @param ratioType
 *            比例类型 RatioType
 * @return
 */
+ (float)ratio:(lsqRatioType)ratioType;

/**
 * 通过比例获取相近比例类型
 *
 * @param ratio
 * @return
 */
+ (lsqRatioType)radioType:(float)ratio;

/**
 * 获取第一个比例类型
 *
 * @param ratioType
 * @return
 */
+ (lsqRatioType)firstRatioType:(lsqRatioType)ratioType;

/**
 * 获取第一个比例
 *
 * @param ratioType
 * @return
 */
+ (float) firstRatio:(lsqRatioType) ratioType;

/**
 * 获取比例总数
 *
 * @param ratioType
 * @return
 */
+ (NSInteger) ratioCount:(lsqRatioType)ratioType;

/**
 *  获取比例类型列表
 *
 *  @param ratioType 比例类型
 *
 *  @return 比例类型列表
 */
+ (NSArray *)ratioTypes:(lsqRatioType)ratioType;

/**
 * 下一个比例类型
 *
 * @param ratioType
 *            比例类型集合
 * @param currentType
 *            当前比例类型
 * @return
 */
+ (lsqRatioType) nextRatioType:(lsqRatioType)ratioType
                   currentType:(lsqRatioType) currentType;

/**
 * 下一个比例类型
 *
 * @param ratioType
 *            比例类型集合
 * @param currentType
 *            当前比例类型
 * @param ignoreType
 *            需要忽略的比例类型
 * @return
 */
+ (lsqRatioType) nextRatioType:(lsqRatioType)ratioType
                   currentType:(lsqRatioType) currentType
                    ignoreType:(lsqRatioType)ignoreType;

/**
 *  获取比例动作类型
 *
 *  @param ratioType 比例类型
 *
 *  @return 比例动作类型
 */
+ (NSInteger) componentTypeWithRatioType:(lsqRatioType)ratioType;
@end
