//
//  GeeV2PFCameraViewController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV2Import.h"
#import "GeeV2PFCameraView.h"
#import "GeeV2PFCameraPreviewController.h"

@class GeeV2PFCameraViewController;

/**
 *  默认相机视图控制器委托
 */
@protocol GeeV2PFCameraDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  获取一个拍摄结果
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onGeeV2PFCamera:(GeeV2PFCameraViewController *)controller captureResult:(TuSDKResult *)result;
@optional
/**
 *  获取一个拍摄结果 (异步方法)
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: false, 设置为True时使用自定义处理逻辑)
 */
- (BOOL)onAsyncGeeV2PFCamera:(GeeV2PFCameraViewController *)controller captureResult:(TuSDKResult *)result;

/**
 *  请求从相机界面跳转至相册
 *
 *  @param controller 默认相机视图控制器
 */
- (void)onGeeV2AlbumDemand:(GeeV2PFCameraViewController *)controller;

@end

/**
 *  默认相机视图控制器
 */
@interface GeeV2PFCameraViewController : TuSDKPFCameraViewControllerBase<GeeV2PFCameraViewDelegate, GeeV2PFCameraFilterGroupViewDelegate, GeeV2PFCameraPreviewControllerDelegate>{
@protected
    // 默认样式视图
    GeeV2PFCameraView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFCameraView *defaultStyleView;

/**
 *  默认相机视图控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFCameraDelegate> delegate;

/**
 *  视图类 (默认:GeeV2PFCameraView, 需要继承 GeeV2PFCameraView)
 */
@property (nonatomic, strong) Class viewClazz;

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
 *  聚焦触摸视图类 (需要继承 GeeV2CPFocusTouchView)
 */
@property (nonatomic, strong) Class focusTouchViewClazz;

/**
 *  闪光灯模式 (默认:AVCaptureFlashModeOff)
 */
@property (nonatomic) AVCaptureFlashMode defaultFlashMode;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  默认是否显示滤镜视图 (默认: 不显示, 如果enableFilters = NO, showFilterDefault将失效)
 */
@property (nonatomic) BOOL showFilterDefault;

/**
 *  开启滤镜历史记录
 */
@property (nonatomic) BOOL enableFilterHistory;

/**
 *  开启无效果滤镜 (默认: 开启)
 */
@property (nonatomic) BOOL enableNormalFilter;

/**
 *  开启在线滤镜
 */
@property (nonatomic) BOOL enableOnlineFilter;

/**
 *  在线滤镜控制器类型 (需要继承 UIViewController,以及实现TuSDKCPFilterOnlineControllerInterface接口)
 */
@property (nonatomic) Class onlineControllerClazz;

/**
 *  显示滤镜标题视图
 */
@property (nonatomic) BOOL displayFilterSubtitles;

/**
 *  滤镜列表行视图宽度
 */
@property (nonatomic)CGFloat filterBarCellWidth;

/**
 *  滤镜列表折叠视图宽度
 */
@property (nonatomic)CGFloat filterBarStackViewWidth;

/**
 *  滤镜列表选择栏高度
 */
@property (nonatomic)CGFloat filterBarHeight;

/**
 *  滤镜列表折叠视图类 (默认:TuSDKCPGroupFilterGroupCellBase, 需要继承 UITableViewCell<TuSDKCPGroupFilterItemCellInterface>)
 */
@property (nonatomic, strong) Class stackViewClazz;

/**
 *  滤镜列表行视图类 (默认:GeeV2CPGroupFilterItemCell, 需要继承 GeeV2CPGroupFilterItemCell)
 */
@property (nonatomic, strong)Class filterBarTableCellClazz;

/**
 *  是否保存最后一次使用的滤镜
 */
@property (nonatomic) BOOL saveLastFilter;

/**
 *  自动选择分组滤镜指定的默认滤镜
 */
@property (nonatomic) BOOL autoSelectGroupDefaultFilter;

/**
 *  开启滤镜配置选项
 */
@property (nonatomic) BOOL enableFilterConfig;

/**
 *  是否开启长按拍摄 (默认: NO)
 */
@property (nonatomic) BOOL enableLongTouchCapture;

/**
 *  禁用持续自动对焦 (默认: NO)
 */
@property (nonatomic) BOOL disableContinueFoucs;

/**
 *  自动聚焦延时 (默认: 5秒)
 */
@property (nonatomic) NSTimeInterval autoFoucsDelay;

/**
 *  视频覆盖区域颜色 (默认：[UIColor blackColor])
 */
@property (nonatomic, retain) UIColor *regionViewColor;

/**
 *  照片输出分辨率
 */
@property (nonatomic) CGSize outputSize;

/**
 *  禁用前置摄像头自动水平镜像 (默认: NO，前置摄像头拍摄结果自动进行水平镜像)
 */
@property (nonatomic) BOOL disableMirrorFrontFacing;

/**
 *  显示相册照片，点击后请求打开相册 (默认: false，不显示相册入口)
 */
@property (nonatomic) BOOL displayAlbumPoster;

/**
 *  是否从相册界面进入 (默认: NO)
 */
@property (nonatomic) BOOL openedByAlbumController;

/**
 *  默认是否显示辅助线 (默认: false)
 */
@property (nonatomic) BOOL displayGuideLine;

/**
 *  最后选中的滤镜代号
 */
@property (nonatomic) NSString *lastFilterCode;

/**
 *  是否开启脸部追踪
 */
@property (nonatomic) BOOL enableFaceDetection;

/**
 *  是否拍照预览
 */
@property (nonatomic) BOOL enableCameraPreview;

/**
 *  是否允许音量键拍照 (默认关闭)
 */
@property (nonatomic) BOOL enableCaptureWithVolumeKeys;

/**
 *  是否开启焦距调节 (默认关闭)
 */
@property (nonatomic, assign) BOOL enableFocalDistance;

/**
 *  相机显示焦距 (默认为 1，最大不可超过硬件最大值，当小于 1 时，取 1)
 */
@property (nonatomic, assign) CGFloat focalDistanceScale;


/**
 *  创建滤镜栏视图
 *
 *  @param view 默认样式视图 (如需创建自定义视图，请覆盖该方法，并配置自己的视图类)
 */
- (void)buildFilterBar:(GeeV2PFCameraView *)view;

/**
 *  配置滤镜栏视图
 *
 *  @param view 滤镜栏视图
 */
- (void)configWithGroupFilterView:(TuSDKCPGroupFilterBaseView *)view;

/**
 *  选中一个滤镜
 *
 *  @param filterName 滤镜名称
 *  @return BOOL 是否成功切换滤镜
 */
- (BOOL)onSelectedFilterCode:(NSString *)code;

/**
 *  继续执行相机
 */
- (void)resumeCamera;
@end
