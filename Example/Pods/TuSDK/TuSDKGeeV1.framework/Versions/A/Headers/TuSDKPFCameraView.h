//
//  TuSDKPFCameraView.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/3.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKPFCameraFilterGroupView.h"
#import "TuSDKGeeV1Import.h"


#pragma mark - TuSDKPFCameraSettingView

/*
 * 设置View按钮类型枚举
 */
typedef enum : NSUInteger {
    lsqCameraSettingBtnTypeDefault = 201, // 默认类型
    lsqCameraSettingBtnTypeRatio,         // 相机比例按钮
    lsqCameraSettingBtnTypeGrid,          // 网格辅助线按钮
    lsqCameraSettingBtnTypeFlash,         // 闪光灯按钮
} lsqCameraSettingBtnType;


@class TuSDKPFCameraSettingView;

#pragma mark - TuSDKPFCameraSettingDelegate

/**
 设置视图View代理
 */
@protocol TuSDKPFCameraSettingDelegate <NSObject>

/**
 *  设置视图View选中回调
 *
 *  @param view 默认相机闪光灯视图
 *  @param mode 闪光灯模式
 */
- (void)onTuSDKPFCameraSettingView:(TuSDKPFCameraSettingView *)view selectedIndex:(lsqCameraSettingBtnType)type;

@end

#pragma mark - TuSDKPFCameraSettingView

/**
 设置视图View
 */
@interface TuSDKPFCameraSettingView : UIView

/**
 默认相机闪光灯视图委托
 */
@property (nonatomic, weak) id<TuSDKPFCameraSettingDelegate> delegate;

/**
 按钮类型数组
 */
@property (nonatomic, strong) NSArray<NSNumber *> *btnTypes;

/**
 绑定按钮视图
 
 @param imageNames 按钮图片名数组
 @param titles 按钮title数组
 */
- (void)bindButtonWithImages:(NSArray<NSString *> *)imageNames titles:(NSArray<NSString *> *)titles;

/**
 更新按钮显示

 @param type 按钮类型
 @param imageName 新的按钮图片
 @param title 新的按钮title
 */
- (void)updateButtonAtIndex:(lsqCameraSettingBtnType)type image:(NSString *)imageName  title:(NSString *)title;

/**
 删除按钮

 @param type 按钮类型
 */
- (void)removeButtonWithType:(lsqCameraSettingBtnType)type;

/**
 显示视图
 
 @param isShow 是否显示视图
 */
- (void)showView:(BOOL)isShow;

@end




#pragma mark - TuSDKPFCameraConfigView
/**
 *  默认相机控制栏视图
 */
@interface TuSDKPFCameraConfigView : UIView{
    @protected
    // 关闭按钮
    UIButton *_closeButton;
    // 前后摄像头切换按钮
    UIButton *_switchButton;
    // 设置按钮
    UIButton *_settingButton;
}

/**
 *  关闭按钮
 */
@property (nonatomic, readonly) UIButton *closeButton;

/**
 *  前后摄像头切换按钮
 */
@property (nonatomic, readonly) UIButton *switchButton;

/**
 *  设置按钮
 */
@property (nonatomic, readonly) UIButton *settingButton;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

@end

#pragma mark - TuSDKPFCameraConfigView
/**
 *  默认相机底部栏视图
 */
@interface TuSDKPFCameraBottomView : UIView{
    @protected
    // 拍摄按钮
    UIButton *_captureButton;
    // 滤镜开关按钮
    UIButton *_filterButton;
    // 相册链接
    UIButton *_albumPoster;
}
/**
 *  拍摄按钮
 */
@property (nonatomic, readonly) UIButton *captureButton;

/**
 *  滤镜开关按钮
 */
@property (nonatomic, readonly) UIButton *filterButton;

/**
 *  相册图片
 */
@property (nonatomic, readonly) UIButton *albumPoster;

/**
 *  创建滤镜开关按钮
 */
- (void)buildFilterButton;

/**
 *  创建相册按钮，点击后请求跳转到相册
 */
- (void)buildAlbumButton;
@end


#pragma mark - TuSDKPFCameraView

@class TuSDKPFCameraView;
/**
 *  默认相机视图委托
 */
@protocol TuSDKPFCameraViewDelegate <NSObject>
/**
 *  选中一个闪光灯模式
 *
 *  @param mode 闪光灯模式
 */
- (void)onTuSDKPFCameraSelectedFlashMode:(AVCaptureFlashMode)mode;

/**
 *  改变网格辅助线显示
 */
- (void)onTuSDKPFCameraChangeGuideLineViewState;

/**
 *  改变屏幕比例
 *
 *  @param newRatio 屏幕比例
 */
- (void)onTuSDKPFCameraChangeCameraRatioWithRatio:(lsqRatioType)newRatio;

@end

/**
 *  默认相机视图
 */
@interface TuSDKPFCameraView : UIView<TuSDKPFCameraSettingDelegate>{
    @protected
    // 显示图像视图
    UIImageView *_displayView;
    // 默认相机控制栏视图
    TuSDKPFCameraConfigView *_configBar;
    // 默认相机底部栏视图
    TuSDKPFCameraBottomView *_bottomBar;
    // 滤镜视图
    TuSDKPFCameraFilterGroupView *_filterView;
}
/**
 *  默认相机控制栏视图类 (默认:TuSDKPFCameraConfigView, 需要继承 TuSDKPFCameraConfigView)
 */
@property (nonatomic, strong) Class configBarViewClazz;

/**
 *  默认相机底部栏视图类 (默认:TuSDKPFCameraBottomView, 需要继承 TuSDKPFCameraBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  设置视图类 (默认:TuSDKPFCameraSettingView, 需要继承 TuSDKPFCameraSettingView)
 */
@property (nonatomic, strong) Class settingViewClazz;

/**
 *  滤镜视图类 (默认:TuSDKPFCameraFilterGroupView, 需要继承 TuSDKPFCameraFilterGroupView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  显示图像视图
 */
@property (nonatomic, readonly) UIView *displayView;

/**
 *  默认相机控制栏视图
 */
@property (nonatomic, readonly) TuSDKPFCameraConfigView *configBar;

/**
 *  默认相机底部栏视图
 */
@property (nonatomic, readonly) TuSDKPFCameraBottomView *bottomBar;

/**
 *  设置视图
 */
@property (nonatomic, readonly) TuSDKPFCameraSettingView *settingView;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) TuSDKPFCameraFilterGroupView *filterView;

/**
 *  滤镜视图
 */
@property (nonatomic, weak) id<TuSDKPFCameraViewDelegate> delegate;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  通知系统旋转
 *
 *  @param deviceOrientation 设备方向
 */
- (void)orientationChanged:(UIDeviceOrientation)deviceOrientation;

/**
 *  创建滤镜视图
 *
 *  @param showFilterDefault 是否默认显示滤镜列表
 */
- (void)buildFilterView:(BOOL)showFilterDefault;

/**
 *  创建相册按钮，点击后请求跳转到相册
 */
- (void)buildAlbumButton;

/**
 *  显示底部栏
 */
- (void)showBottomBar;

/**
 初始化辅助线状态

 @param isShowGuideLine 是否显示辅助线
 */
- (void)setGuideLineViewState:(BOOL)isShowGuideLine;

/**
 初始化闪光灯状态

 @param flashMode 闪光灯状态
 */
- (void)setDefaultFlashMode:(AVCaptureFlashMode)flashMode;

@end
