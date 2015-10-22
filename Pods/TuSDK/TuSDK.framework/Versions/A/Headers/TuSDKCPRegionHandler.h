//
//  TuSDKCPRegionHandler.h
//  TuSDK
//
//  Created by Clear Hu on 15/10/14.
//  Copyright © 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  选区范围算法接口
 */
@protocol TuSDKCPRegionHandler <NSObject>
/**
 *  比例
 */
@property (nonatomic) CGFloat ratio;

/**
 *  容器长宽
 */
@property (nonatomic) CGSize wrapSize;

/**
 *  选区范围百分比
 */
@property (nonatomic, readonly) CGRect rectPercent;

/**
 *  切换比例动画
 *
 *  @param ratio   比例
 *  @param changer 切换动作
 *
 *  @return 确定的选区范围百分比
 */
- (CGRect)changeWithRatio:(CGFloat)ratio changer:(void (^)(CGRect rectPercent))changer;
@end

/**
 *  默认选区范围算法
 */
@interface TuSDKCPRegionDefaultHandler : NSObject<TuSDKCPRegionHandler>

@end