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
+ (float)ratio:(TTRatioType)ratioType;

/**
 * 通过比例获取相近比例类型
 *
 * @param ratio
 * @return ratio
 */
+ (TTRatioType)radioType:(float)ratio;

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
+ (TTRatioType)firstRatioType:(TTRatioType)ratioType;

/**
 * 获取第一个比例
 *
 * @param ratioType
 * @return ratioType
 */
+ (float) firstRatio:(TTRatioType) ratioType;

/**
 * 获取比例总数
 *
 * @param ratioType
 * @return ratioType
 */
+ (NSInteger) ratioCount:(TTRatioType)ratioType;

/**
 *  获取比例类型列表
 *
 *  @param ratioType 比例类型
 *
 *  @return ratioTypes 比例类型列表
 */
+ (NSArray *)ratioTypes:(TTRatioType)ratioType;

/**
 * 下一个比例类型
 *
 * @param ratioType 比例类型集合
 *
 * @param currentType 当前比例类型
 *
 * @return currentType
 */
+ (TTRatioType) nextRatioType:(TTRatioType)ratioType
                   currentType:(TTRatioType) currentType;

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
+ (TTRatioType) nextRatioType:(TTRatioType)ratioType
                   currentType:(TTRatioType) currentType
                    ignoreType:(TTRatioType)ignoreType;

/**
 *  获取比例动作类型
 *
 *  @param ratioType 比例类型
 *
 *  @return ratioType 比例动作类型
 */
+ (NSInteger) componentTypeWithRatioType:(TTRatioType)ratioType;

+ (NSString *)format:(TTRatioType)ratioType;
@end
