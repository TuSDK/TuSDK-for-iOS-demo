//
//  TuSDKCPFocusTouchView.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/29.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKStillCamera.h"
#import "TuSDKICFocusRangeView.h"
#import "TuSDKICCutRegionView.h"
#import "TuSDKPFFilterConfigView.h"
#import "TuSDKFilterWrap.h"

/**
 *  相机聚焦触摸视图
 */
@interface TuSDKCPFocusTouchView : UIView

/**
 *  相机对象
 */
@property (nonatomic, assign) TuSDKStillCamera *camera;

/**
 *  聚焦视图 (如果不设定，将使用 TuSDKICFocusRangeView)
 */
@property (nonatomic, retain) UIView<TuSDKICFocusRangeViewProtocol> *rangeView;

/**
 *  裁剪区域视图 (如果不设定，将使用 TuSDKICCutRegionView)
 */
@property (nonatomic, retain) TuSDKICCutRegionView *cutRegionView;

/**
 *  滤镜配置视图
 */
@property (nonatomic, retain) TuSDKPFFilterConfigView *filterConfigView;

/**
 *  聚焦模式
 */
@property (nonatomic) AVCaptureFocusMode focusMode;

/**
 *  是否开启长按拍摄 (默认: NO)
 */
@property (nonatomic) BOOL enableLongTouchCapture;

/**
 *  开启持续自动对焦 (默认: NO)
 */
@property (nonatomic) BOOL enableContinueFoucs;

/**
 *  自动聚焦延时 (默认: 5秒)
 */
@property (nonatomic) NSTimeInterval autoFoucsDelay;

/**
 *  长按延时 (默认: 1.2秒)
 */
@property (nonatomic) NSTimeInterval longTouchDelay;

/**
 *  区域长宽比例
 */
@property (nonatomic) CGFloat regionRatio;

/**
 *  视频覆盖区域颜色 (默认：[UIColor blackColor])
 */
@property (nonatomic, retain) UIColor *regionViewColor;

/**
 *  顶部边距
 */
@property (nonatomic) NSInteger topSpace;

/**
 *  相机状态改变
 *
 *  @param state 改变
 */
- (void)cameraStateChanged:(lsqCameraState)state;

/**
 *  改变范围比例 (使用动画)
 *
 *  @param regionRatio 范围比例
 */
- (void)changeRegionRatio:(CGFloat)regionRatio;

/**
 *  当前聚焦状态
 *
 *  @param isFocusing 是否正在聚焦
 */
- (void)onAdjustingFocus:(BOOL)isFocusing;

/**
 *  聚焦点
 *
 *  @param point 聚焦点
 *
 *  @return 是否允许聚焦
 */
- (BOOL)onFocusWithPoint:(CGPoint)point;

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
 *  通知滤镜配置视图
 *
 *  @param filter 滤镜包装对象
 */
- (void)notifyFilterConfigView:(TuSDKFilterWrap *)filter;

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
