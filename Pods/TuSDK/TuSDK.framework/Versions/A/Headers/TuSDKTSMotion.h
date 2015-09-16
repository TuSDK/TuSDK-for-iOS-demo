//
//  TuSDKTSMotion.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/12.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class TuSDKTSMotion;

/**
 *  物理感应器方向委托
 */
@protocol TuSDKTSMotionDelegate <NSObject>
@optional
/**
 *  物理感应器旋转
 *
 *  @param motion            物理感应器
 *  @param orientation       设备旋转方向
 */
- (void)onTuSDKTSMotion:(TuSDKTSMotion *)motion changedOrientation:(UIDeviceOrientation)orientation;
@end

/**
 *  物理感应器方向
 */
@interface TuSDKTSMotion : NSObject
/**
 *  物理感应器方向
 */
@property (nonatomic, readonly) UIDeviceOrientation deviceOrientation;

/**
 *  根据物理方向转变为图片方向
 */
@property (nonatomic, readonly) UIImageOrientation imageOrientation;

/**
 *  视图旋转方向
 */
@property (nonatomic, readonly) CGAffineTransform affineTransform;

/**
 *  物理感应器方向委托
 */
@property (nonatomic, assign) id<TuSDKTSMotionDelegate> delegate;

/**
 *  物理感应器方向
 *
 *  @return 物理感应器方向
 */
+ (instancetype) motion;

/**
 *  开始监听物理感应器
 */
- (void)start;

/**
 *  停止监听物理感应器
 */
- (void)stop;
@end
