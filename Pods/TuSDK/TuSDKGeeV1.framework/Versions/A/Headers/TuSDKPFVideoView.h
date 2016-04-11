//
//  TuSDKPFVideoView.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 2/3/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKPFVideoFilterGroupView.h"

#pragma mark - TuSDKPVideoFlashView
@class TuSDKPFVideoFlashView;
/**
 *  视频闪光灯视图委托
 */
@protocol TuSDKPFVideoFlashDelegate <NSObject>
/**
 *  选中闪光灯模式
 *
 *  @param view 视频闪光灯视图
 *  @param mode 闪光灯模式
 */
- (void)onTuSDKPFVideoFlashView:(TuSDKPFVideoFlashView *)view selectedMode:(AVCaptureFlashMode)mode;
@end

/**
 *  视频闪光灯视图
 */
@interface TuSDKPFVideoFlashView : UIButton{
@protected
    // 闪光灯包装视图
    UIImageView *_flashWrapView;
    // 闪光灯选项按钮列表
    NSMutableArray *_buttons;
}

/**
 *  视频闪光灯视图委托
 */
@property (nonatomic, assign) id<TuSDKPFVideoFlashDelegate> delegate;

/**
 *  设置闪光灯按钮坐标
 *
 *  @param frame 坐标
 */
- (void)setFlashFrame:(CGRect)frame;

/**
 *  显示视图
 *
 *  @param isShow 是否显示视图
 */
- (void)showView:(BOOL)isShow;
@end

#pragma mark - TuSDKPFVideoConfigView
/**
 *  视频控制栏视图
 */
@interface TuSDKPFVideoConfigView : UIView{
@protected
    // 关闭按钮
    UIButton *_closeButton;
    // 闪光灯按钮
    UIButton *_flashButton;
    // 前后摄像头切换按钮
    UIButton *_switchButton;
    // 屏幕比例按钮
    UIButton *_ratioButton;
}
/**
 *  关闭按钮
 */
@property (nonatomic, readonly) UIButton *closeButton;

/**
 *  闪光灯按钮
 */
@property (nonatomic, readonly) UIButton *flashButton;

/**
 *  前后摄像头切换按钮
 */
@property (nonatomic, readonly) UIButton *switchButton;

/**
 *  屏幕比例按钮
 */
@property (nonatomic, readonly) UIButton *ratioButton;

/**
 *  闪光灯模式
 */
@property (nonatomic) AVCaptureFlashMode flashMode;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  改变相机比例
 *
 *  @param ratioType 相机比例类型
 */
- (void)changeRatioType:(lsqRatioType)ratioType;
@end

#pragma mark - TuSDKPFVideoBottomView
/**
 *  视频底部栏视图
 */
@interface TuSDKPFVideoBottomView : UIView{
@protected
    // 拍摄按钮
    UIButton *_captureButton;
    // 滤镜开关按钮
    UIButton *_filterButton;
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
 *  创建滤镜开关按钮
 */
- (void)buildFilterButton;
@end

#pragma mark - TuSDKPFVideoView
@class TuSDKPFVideoView;
/**
 *  视频视图委托
 */
@protocol TuSDKPFVideoViewDelegate <NSObject>
/**
 *  选中一个闪光灯模式
 *
 *  @param mode 闪光灯模式
 */
- (void)onTuSDKPFVideoSelectedFlashMode:(AVCaptureFlashMode)mode;
@end

/**
 *  视频视图
 */
@interface TuSDKPFVideoView : UIView<TuSDKPFVideoFlashDelegate>{
@protected
    // 显示图像视图
    UIImageView *_displayView;
    // 视频控制栏视图
    TuSDKPFVideoConfigView *_configBar;
    // 视频底部栏视图
    TuSDKPFVideoBottomView *_bottomBar;
    // 闪光灯视图
    TuSDKPFVideoFlashView *_flashView;
    // 滤镜视图
    TuSDKPFVideoFilterGroupView *_filterView;
}
/**
 *  视频控制栏视图类 (默认:TuSDKPFVideoConfigView, 需要继承 TuSDKPFVideoConfigView)
 */
@property (nonatomic, strong) Class configBarViewClazz;

/**
 *  视频底部栏视图类 (默认:TuSDKPFVideoBottomView, 需要继承 TuSDKPFVideoBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  闪光灯视图类 (默认:TuSDKPFVideoFlashView, 需要继承 TuSDKPFVideoFlashView)
 */
@property (nonatomic, strong) Class flashViewClazz;

/**
 *  滤镜视图类 (默认:TuSDKPFVideoFilterGroupView, 需要继承 TuSDKPFVideoFilterGroupView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  显示图像视图
 */
@property (nonatomic, readonly) UIView *displayView;

/**
 *  视频控制栏视图
 */
@property (nonatomic, readonly) TuSDKPFVideoConfigView *configBar;

/**
 *  视频底部栏视图
 */
@property (nonatomic, readonly) TuSDKPFVideoBottomView *bottomBar;

/**
 *  闪光灯视图
 */
@property (nonatomic, readonly) TuSDKPFVideoFlashView *flashView;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) TuSDKPFVideoFilterGroupView *filterView;

/**
 *  滤镜视图
 */
@property (nonatomic, assign) id<TuSDKPFVideoViewDelegate> delegate;

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
 *  显示底部栏
 */
- (void)showBottomBar;
@end

