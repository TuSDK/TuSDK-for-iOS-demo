//
//  TuSDKPFVideoViewController.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 2/3/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import "TuSDKVideoUIImport.h"
#import "TuSDKPFVideoView.h"

#pragma mark - TuSDKPFVideoDataOutputDelegate
/**
 *  视频输出委托
 */
@protocol TuSDKPFVideoResultDelegate <NSObject>

/**
 *  拍摄结束
 */
- (void)onVideoResult;

@end

#pragma mark - TuSDKPFVideoViewController

/**
 *  视频视图控制器
 */
@interface TuSDKPFVideoViewController : TuSDKPFVideoViewControllerBase<TuSDKPFVideoViewDelegate, TuSDKPFVideoFilterGroupViewDelegate>{
@protected
    // 默认样式视图
    TuSDKPFVideoView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFVideoView *defaultStyleView;

/**
 *  视频输出委托
 */
@property (nonatomic, assign) id<TuSDKPFVideoResultDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFVideoView, 需要继承 TuSDKPFVideoView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  默认相机控制栏视图类 (默认:TuSDKPFVideoConfigView, 需要继承 TuSDKPFVideoConfigView)
 */
@property (nonatomic, strong) Class configBarViewClazz;

/**
 *  默认相机底部栏视图类 (默认:TuSDKPFVideoBottomView, 需要继承 TuSDKPFVideoBottomView)
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
 *  聚焦触摸视图类 (需要继承 TuSDKCPFocusTouchView)
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
 *  滤镜列表选择栏高度
 */
@property (nonatomic)CGFloat filterBarHeight;

/**
 *  滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
 */
@property (nonatomic, strong)Class filterBarGroupCellClazz;

/**
 *  滤镜列表行视图类 (默认:TuSDKCPGroupFilterItemCell, 需要继承 TuSDKCPGroupFilterItemCell)
 */
@property (nonatomic, strong)Class filterBarTableCellClazz;

/**
 *  需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
 */
@property (nonatomic, retain) NSArray * filterGroup;

/**
 *  是否保存最后一次使用的滤镜
 */
@property (nonatomic) BOOL saveLastFilter;

/**
 *  自动选择分组滤镜指定的默认滤镜
 */
@property (nonatomic) BOOL autoSelectGroupDefaultFilter;

/**
 *  禁用持续自动对焦 (默认: NO)
 */
@property (nonatomic) BOOL disableContinueFoucs;

/**
 *  视频覆盖区域颜色 (默认：[UIColor blackColor])
 */
@property (nonatomic, retain) UIColor *regionViewColor;

/**
 *  录制的视频时长
 */
@property (nonatomic) CGFloat videoDuration;

/**
 *  禁用前置摄像头自动水平镜像 (默认: NO，前置摄像头拍摄结果自动进行水平镜像)
 */
@property (nonatomic) BOOL disableMirrorFrontFacing;

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
 *  创建滤镜栏视图
 *
 *  @param view 默认样式视图 (如需创建自定义视图，请覆盖该方法，并配置自己的视图类)
 */
- (void)buildFilterBar:(TuSDKPFVideoView *)view;

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
 *  @return 是否成功切换滤镜
 */
- (BOOL)onSelectedFilterCode:(NSString *)code;

@end
