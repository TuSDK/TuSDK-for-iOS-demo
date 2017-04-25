//
//  GeeV2PFCameraView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "GeeV2PFCameraFilterGroupView.h"

#pragma mark - GeeV2PFCameraFlashView
@class GeeV2PFCameraFlashView;
/**
 *  默认相机闪光灯视图委托
 */
@protocol GeeV2PFCameraFlashDelegate <NSObject>

/**
 *  选中闪光灯模式
 *
 *  @param view 默认相机闪光灯视图
 *  @param mode 闪光灯模式
 */
- (void)onTuSDKPFCameraFlashView:(GeeV2PFCameraFlashView *)view selectedMode:(AVCaptureFlashMode)mode;

@end

/**
 *  默认相机闪光灯视图
 */
@interface GeeV2PFCameraFlashView : UIButton{
@protected
    // 闪光灯包装视图
    UIImageView *_flashWrapView;
    // 闪光灯选项按钮列表
    NSMutableArray *_buttons;
}

/**
 *  默认相机闪光灯视图委托
 */
@property (nonatomic, weak) id<GeeV2PFCameraFlashDelegate> delegate;

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

#pragma mark - GeeV2FCameraConfigView
/**
 *  默认相机控制栏视图
 */
@interface GeeV2PFCameraConfigView : UIView{
@protected
    // 关闭按钮
    UIButton *_closeButton;
    // 闪光灯按钮
    UIButton *_flashButton;
    // 前后摄像头切换按钮
    UIButton *_switchButton;
    // 辅助线按钮
    UIButton *_guideLineButton;
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
 *  辅助线按钮
 */
@property (nonatomic, readonly) UIButton *guideLineButton;

/**
 *  闪光灯模式
 */
@property (nonatomic) AVCaptureFlashMode flashMode;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  设置辅助线显示状态
 *
 *  @param isShow 是否显示辅助线
 */
- (void)setGuideLineViewState:(BOOL)isShow;
@end
#pragma mark - GeeV2PFCameraCuterOptionBar
/**
 *  选项栏目
 */
@interface GeeV2PFCameraCuterOptionBar : UIView

/**
 *  横向滚动视图
 */
@property (nonatomic, readonly) UIScrollView *wrapView;

/**
 *  按钮列表
 */
@property (nonatomic, readonly) NSArray *buttons;

/**
 *  视图显示比例类型列表 (默认：lsqTuSDKRatioDefaultTypes)
 *
 *  设置 NSNumber 型数组来控制显示的按钮顺序， 例如:
 *	@[@(lsqRatioOrgin), @(lsqRatio_1_1), @(lsqRatio_2_3), @(lsqRatio_3_4)]
 *
 */
@property (nonatomic) NSArray<NSNumber *> *ratioTypeList;

/**
 *  当前视图显示比例类型
 */
@property (nonatomic) lsqRatioType currentRatioType;

/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end


#pragma mark - GeeV2PFCameraBottomView
/**
 *  默认相机底部栏视图
 */
@interface GeeV2PFCameraBottomView : UIView{
@protected
    // 拍摄按钮
    UIButton *_captureButton;
    // 滤镜开关按钮
    UIButton *_filterButton;
    // 相册链接
    UIButton *_albumPoster;
    // 相机比例工具栏
    GeeV2PFCameraCuterOptionBar *_cuterOptionBar;
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
 *  相机比例工具栏
 */
@property (nonatomic, readonly) GeeV2PFCameraCuterOptionBar *cuterOptionBar;

/**
 *  创建滤镜开关按钮
 */
- (void)buildFilterButton;

/**
 *  创建相册按钮，点击后请求跳转到相册
 */
- (void)buildAlbumButton;
@end

#pragma mark - GeeV2PFCameraView
@class GeeV2PFCameraView;
/**
 *  默认相机视图委托
 */
@protocol GeeV2PFCameraViewDelegate <NSObject>
/**
 *  选中一个闪光灯模式
 *
 *  @param mode 闪光灯模式
 */
- (void)onTuSDKPFCameraSelectedFlashMode:(AVCaptureFlashMode)mode;
@end

/**
 *  默认相机视图
 */
@interface GeeV2PFCameraView : UIView<GeeV2PFCameraFlashDelegate>{
@protected
    // 显示图像视图
    UIImageView *_displayView;
    // 默认相机控制栏视图
    GeeV2PFCameraConfigView *_configBar;
    // 默认相机底部栏视图
    GeeV2PFCameraBottomView *_bottomBar;
    // 闪光灯视图
    GeeV2PFCameraFlashView *_flashView;
    // 滤镜视图
    GeeV2PFCameraFilterGroupView *_filterView;
}
/**
 *  默认相机控制栏视图类 (默认:GeeV2PFCameraConfigView, 需要继承 GeeV2PFCameraConfigView)
 */
@property (nonatomic, strong) Class configBarViewClazz;

/**
 *  默认相机底部栏视图类 (默认:GeeV2PFCameraBottomView, 需要继承 GeeV2PFCameraBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  闪光灯视图类 (默认:GeeV2PFCameraFlashView, 需要继承 GeeV2PFCameraFlashView)
 */
@property (nonatomic, strong) Class flashViewClazz;

/**
 *  滤镜视图类 (默认:GeeV2PFCameraFilterGroupView, 需要继承 GeeV2PFCameraFilterGroupView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  显示图像视图
 */
@property (nonatomic, readonly) UIView *displayView;

/**
 *  默认相机控制栏视图
 */
@property (nonatomic, readonly) GeeV2PFCameraConfigView *configBar;

/**
 *  默认相机底部栏视图
 */
@property (nonatomic, readonly) GeeV2PFCameraBottomView *bottomBar;

/**
 *  闪光灯视图
 */
@property (nonatomic, readonly) GeeV2PFCameraFlashView *flashView;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) GeeV2PFCameraFilterGroupView *filterView;

/**
 *  滤镜视图
 */
@property (nonatomic, weak) id<GeeV2PFCameraViewDelegate> delegate;

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
@end
