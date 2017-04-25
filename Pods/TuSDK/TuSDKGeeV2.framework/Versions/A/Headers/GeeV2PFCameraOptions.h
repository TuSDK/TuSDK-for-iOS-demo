//
//  GeeV2PFCameraOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import "GeeV2PFCameraViewController.h"

/**
 *  默认相机视图控制器选项
 */
@interface GeeV2PFCameraOptions : TuSDKCPResultOptions
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
 *  滤镜视图类 (默认:TuSDKPFCameraFilterGroupView, 需要继承 TuSDKPFCameraFilterGroupView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  聚焦触摸视图类 (默认:GeeV2CPFocusTouchView, 需要继承 GeeV2CPFocusTouchView)
 */
@property (nonatomic, strong) Class focusTouchViewClazz;

/**
 *  摄像头前后方向 (默认为后置优先)
 */
@property (nonatomic) AVCaptureDevicePosition cameraPostion;

/**
 *  闪光灯模式 (默认:AVCaptureFlashModeOff)
 */
@property (nonatomic) AVCaptureFlashMode cameraDefaultFlashMode;

/**
 *  摄像头分辨率模式 (默认：AVCaptureSessionPresetHigh)
 *  @see AVCaptureSession for acceptable values
 */
@property (nonatomic, copy) NSString *sessionPreset;

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
 *  滤镜列表区头视图宽度
 */
@property (nonatomic)CGFloat filterBarStackViewWidth;

/**
 *  滤镜列表选择栏高度
 */
@property (nonatomic)CGFloat filterBarHeight;

/**
 *  滤镜列表区头视图类 (默认:TuSDKCPGroupFilterGroupCellBase, 需要继承 UITableViewCell<TuSDKCPGroupFilterItemCellInterface>)
 */
@property (nonatomic, strong) Class stackViewClazz;

/**
 *  滤镜列表行视图类 (默认:TuSDKCPGroupFilterItem, 需要继承 TuSDKCPGroupFilterItem)
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
 *  是否显示辅助线 (默认: false)
 */
@property (nonatomic) BOOL displayGuideLine;

/**
 *  是否开启脸部追踪
 */
@property (nonatomic) BOOL enableFaceDetection;

/**
 *  是否开启拍照预览
 */
@property (nonatomic) BOOL enableCameraPreview;

/**
 *  设置水印选项 (默认为空，如果设置不为空，则输出的图片上将带有水印)
 */
@property (nonatomic) TuSDKWaterMarkOption *waterMarkOption;

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
 *  创建系统相机控制器对象
 *
 *  @return controller 系统相机控制器对象
 */
- (GeeV2PFCameraViewController *)viewController;
@end
