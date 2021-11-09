//
//  TuCameraShower.h
//  TuSDK
//
//  Created by Clear Hu on 2020/4/27.
//  Copyright © 2020 tusdk.com. All rights reserved.
//
#import "TuCamera/TuCamera.h"
//#import "TuSDKPulseCore/TuSDKPulseCore.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>
@class SelesParameters;

/** 相机渲染接口 */
@protocol TuCameraShower<TuCameraVideoDataOutputDelegate>
@property(nonatomic, readonly) TuCamera *camera; // 相机接口
@property(nonatomic) CGRect displayRect; // 显示选区百分比

/**是否开启滤镜渲染效果，默认为YES*/
@property (nonatomic) BOOL enableFilter;

@property(nonatomic) lsqRatioType ratioType;
//顶部偏移百分比 0~1。默认-1
@property (nonatomic, assign) CGFloat offsetPercentTop;
@property(nonatomic, strong) UIColor *displayBackgroundColor; // 视频背景区域颜色

- (instancetype)initWithRootView:(UIView *)rootView;// 请求初始化
- (SelesParameters *)changeFilter:(NSString *)code; // 切换滤镜 [返回参数列表]
//- (void)setRatioType:(lsqRatioType)ratioType;

@end
