//
//  TuRatioType.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulseCore/TUCEnum.h>

/**
 *  裁剪比例
 */
@interface TuRatioType : NSObject
/**
 *  比例类型默认5列表
 */
+ (NSArray *)lsqTuSDKRatioDefaultTypes;

/**
 *  比例类型列表全部
 */
+ (NSArray *)lsqTuSDKRatioAllTypes;

/**
 * 获取比例
 *
 * @param ratioType 比例类型 lsqRatioType
 *
 * @return ratioType
 */
+ (float)ratio:(lsqRatioType)ratioType;

/**
 * 通过比例获取相近比例类型
 *
 * @param ratio
 * @return ratio
 */
+ (lsqRatioType)radioType:(float)ratio;

/**
 * 检测列表中的比例数据是否合法
 *
 * @param types
 * @return types
 */
+ (NSArray<NSNumber *> *)validRatioTypes:(NSArray<NSNumber *> *)types;

/**
 * 获取第一个比例类型
 *
 * @param firstRatioType
 * @return ratioType
 */
+ (lsqRatioType)firstRatioType:(lsqRatioType)ratioType;

/**
 * 获取第一个比例
 *
 * @param ratioType
 * @return ratioType
 */
+ (float) firstRatio:(lsqRatioType) ratioType;

/**
 * 获取比例总数
 *
 * @param ratioType
 * @return ratioType
 */
+ (NSInteger) ratioCount:(lsqRatioType)ratioType;

/**
 *  获取比例类型列表
 *
 *  @param ratioType 比例类型
 *
 *  @return ratioTypes 比例类型列表
 */
+ (NSArray *)ratioTypes:(lsqRatioType)ratioType;

/**
 * 下一个比例类型
 *
 * @param ratioType 比例类型集合
 *
 * @param currentType 当前比例类型
 *
 * @return currentType
 */
+ (lsqRatioType) nextRatioType:(lsqRatioType)ratioType
                   currentType:(lsqRatioType) currentType;

/**
 * 下一个比例类型
 *
 * @param ratioType 比例类型集合
 *
 * @param currentType 当前比例类型
 *
 * @param ignoreType 需要忽略的比例类型
 *
 * @return nextType
 */
+ (lsqRatioType) nextRatioType:(lsqRatioType)ratioType
                   currentType:(lsqRatioType) currentType
                    ignoreType:(lsqRatioType)ignoreType;

/**
 *  获取比例动作类型
 *
 *  @param ratioType 比例类型
 *
 *  @return ratioType 比例动作类型
 */
+ (NSInteger) componentTypeWithRatioType:(lsqRatioType)ratioType;

+ (NSString *)format:(lsqRatioType)ratioType;
@end
