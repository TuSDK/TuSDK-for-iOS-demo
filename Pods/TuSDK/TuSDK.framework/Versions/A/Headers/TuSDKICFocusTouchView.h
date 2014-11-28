//
//  TuSDKICFocusTouchView.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/29.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKStillCamera.h"
#import "TuSDKICFocusRangeView.h"

/**
 *  相机聚焦触摸视图
 */
@interface TuSDKICFocusTouchView : UIView

/**
 *  相机对象
 */
@property (nonatomic, assign) TuSDKStillCamera *camera;

/**
 *  聚焦视图 (如果不设定，将使用 TuSDKICFocusRangeView)
 */
@property (nonatomic, retain) UIView<TuSDKICFocusRangeViewProtocol> *rangeView;

/**
 *  聚焦点
 *
 *  @param point 聚焦点
 */
- (void)onFocusWithPoint:(CGPoint)point;

/**
 *  重置聚焦到中心
 */
- (void)resetFoucsCenter;

/**
 *  通知选取范围视图
 *
 *  @param point 聚焦点
 */
- (void)notifyRangeViewWithPoint:(CGPoint)point;

/**
 *  通知相机聚焦点
 *
 *  @param point 聚焦点
 */
- (void)notifyCameraWithFocusPoint:(CGPoint)point;

/**
 *  转换触摸点为百分比点
 *
 *  @param point 触摸点
 *
 *  @return 百分比坐标
 */
- (CGPoint)convertPercentPointFromTouchPoint:(CGPoint)point;

/**
 *  转换百分比触摸点为相机聚焦点
 *
 *  @param point 视图百分比坐标点
 *
 *  @return 相机坐标点
 */
- (CGPoint)convertFocusPointFromPercentPoint:(CGPoint)point;

/**
 *  转换触摸点为相机聚焦点
 *
 *  @param point 触摸点
 *
 *  @return 相机聚焦点
 */
- (CGPoint)convertFocusPointFromTouchPoint:(CGPoint)point;
@end
