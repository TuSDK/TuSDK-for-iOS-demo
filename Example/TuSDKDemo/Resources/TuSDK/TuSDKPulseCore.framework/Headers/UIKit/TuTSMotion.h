//
//  TuTSMotion.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/12.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@class TuTSMotion;

/**物理感应器方向委托*/
@protocol TuTSMotionDelegate <NSObject>
@optional
/**
 *  物理感应器旋转
 *  @param motion            物理感应器
 *  @param orientation       设备旋转方向
 */
- (void)onTuTSMotion:(TuTSMotion *)motion changedOrientation:(UIDeviceOrientation)orientation;
@end

/**物理感应器方向*/
@interface TuTSMotion : NSObject
/** 物理感应器方向*/
@property (nonatomic, readonly) UIDeviceOrientation deviceOrientation;
// 界面方向
@property (nonatomic, readonly) UIInterfaceOrientation  interfaceOrientation;
/** 物理感应器方向所对应的视频方向 */
@property (nonatomic, readonly) AVCaptureVideoOrientation videoOrientation;
/** 物理感应器方向所对应的视频transform （主要针对录制时的 AVAssetWriterInput 的 transform）*/
@property (nonatomic, readonly) CGAffineTransform videoInputTransform;
/** 物理感应器弧度 */
@property (nonatomic, readonly) float deviceRadian;
/** 物理感应器角度 */
@property (nonatomic, readonly) float deviceAngle;
/**根据物理方向转变为图片方向*/
@property (nonatomic, readonly) UIImageOrientation imageOrientation;
/**视图旋转方向*/
@property (nonatomic, readonly) CGAffineTransform affineTransform;
/**物理感应器方向委托*/
@property (nonatomic, weak) id<TuTSMotionDelegate> delegate;
/**物理感应器方向*/
+ (instancetype) motion;
/**开始监听物理感应器*/
- (void)start;
/**停止监听物理感应器*/
- (void)stop;
@end
