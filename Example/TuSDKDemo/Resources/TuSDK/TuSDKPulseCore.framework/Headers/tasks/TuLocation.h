//
//  TuLocation.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/9.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

@class TuLocation;

/**
 *  地理位置委托
 */
@protocol TuLocationDelegate <NSObject>
/**
 *  地理位置更新
 *
 *  @param location     地理位置对象
 *  @param lastLocation 最后获取的地理信息
 */
- (void)onTuSDKTKLocation:(TuLocation *)location update:(CLLocation *)lastLocation;
@end

/**
 *  地理位置
 */
@interface TuLocation : NSObject

/**
 *  最后获取的地理信息
 */
@property (nonatomic, readonly) CLLocation *lastLocation;

/**
 *  地理位置委托
 */
@property (nonatomic, weak) id<TuLocationDelegate> delegate;

/**
 *  请求请求GPS权限
 *
 *  @param controller UIViewController
 */
- (void)requireAuthorWithController:(UIViewController *)controller;

/**
 *  地理位置
 */
+ (instancetype)shared;
@end
