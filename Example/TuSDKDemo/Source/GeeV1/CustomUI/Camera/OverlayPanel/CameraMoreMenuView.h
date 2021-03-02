//
//  CameraMoreMenuView.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/18.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import "VerticalMenuView.h"
#import "OverlayViewProtocol.h"
#import "TuSDKFramework.h"

@class CameraMoreMenuView;

@protocol CameraMoreMenuViewDelegate <NSObject>
@optional

/**
 更多菜单切换预览画面比率回调
 
 @param moreMenu 更多菜单视图
 @param ratio 相机视图比例
 */
- (void)moreMenu:(CameraMoreMenuView *)moreMenu didSelectedRatio:(CGFloat)ratio;

/**
 更多菜单切换自动聚焦回调

 @param moreMenu 更多菜单视图
 @param autoFocus 自动聚焦
 */
- (void)moreMenu:(CameraMoreMenuView *)moreMenu didSwitchAutoFocus:(BOOL)autoFocus;

/**
 更多菜单切换闪光灯回调

 @param moreMenu 更多菜单视图
 @param enableFlash 闪光灯开启状态
 */
- (void)moreMenu:(CameraMoreMenuView *)moreMenu didSwitchFlashMode:(BOOL)enableFlash;

/**
 更多菜单切换变声回调

 @param moreMenu 更多菜单视图
 @param pitchType 变声类型
 */
//- (void)moreMenu:(CameraMoreMenuView *)moreMenu didSwitchPitchType:(lsqSoundPitch)pitchType;

@end

@interface CameraMoreMenuView : VerticalMenuView <OverlayViewProtocol>

/**
 触发者，外部赋值
 */
@property (nonatomic, weak) UIControl *sender;

/**
 相机折叠功能菜单代理
 */
@property (nonatomic, weak) id<CameraMoreMenuViewDelegate> delegate;

/**
 自动对焦开关
 */
@property (nonatomic, assign) BOOL autoFocus;

/**
 是否禁用闪光开关
 */
@property (nonatomic, assign) BOOL disableFlashSwitching;

/**
 闪光灯开关
 */
@property (nonatomic, assign) BOOL enableFlash;

/**
 是否禁用比例切换
 */
@property (nonatomic, assign) BOOL disableRatioSwitching;

/**
 是否隐藏变声开关
 */
@property (nonatomic, assign) BOOL pitchHidden;

@end
