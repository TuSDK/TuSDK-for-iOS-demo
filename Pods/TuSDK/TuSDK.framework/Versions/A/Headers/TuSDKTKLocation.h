//
//  TuSDKTKLocation.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/9.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

@class TuSDKTKLocation;

/**
 *  地理位置委托
 */
@protocol TuSDKTKLocationDelegate <NSObject>
/**
 *  地理位置更新
 *
 *  @param location     地理位置对象
 *  @param lastLocation 最后获取的地理信息
 */
- (void)onTuSDKTKLocation:(TuSDKTKLocation *)location update:(CLLocation *)lastLocation;
@end

/**
 *  地理位置
 */
@interface TuSDKTKLocation : NSObject
/**
 *  是否请求GPS权限
 */
@property (nonatomic) BOOL requireAuthor;

/**
 *  是否允许使用GPS
 */
@property (nonatomic, readonly) BOOL canGps;

/**
 *  最后获取的地理信息
 */
@property (nonatomic, readonly) CLLocation *lastLocation;

/**
 *  地理位置委托
 */
@property (nonatomic, assign) id<TuSDKTKLocationDelegate> delegate;

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
