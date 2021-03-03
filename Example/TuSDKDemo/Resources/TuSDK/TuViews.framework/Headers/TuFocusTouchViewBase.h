//
//  TuFocusTouchViewBase.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/29.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPulseCore/tools/TuTSScreen+Extend.h"
#import "TuGuideRegionView.h"
#import "TuFocusRangeView.h"
//#import "TuFilterConfigView.h"

#import "TuCamera/TuCamera.h"

/**
 *  相机聚焦触摸视图
 */
@interface TuFocusTouchViewBase : UIView<TuCameraMetadataOutputFaceDelegate>
{
@protected
    TuGuideRegionView *_guideView; // 辅助线视图
    UIView<TuFocusRangeViewProtocol> *_rangeView;
//    TuFilterConfigView *_filterConfigView;
}

@property (nonatomic, readonly) TuGuideRegionView *guideView; // 辅助线视图
@property (nonatomic, readonly) UIView<TuFocusRangeViewProtocol> *rangeView;  // 聚焦视图 (如果不设定，将使用 TuFocusRangeView)
//@property (nonatomic, readonly) TuFilterConfigView *filterConfigView; // 滤镜配置视图

@property (nonatomic, strong) TuCamera *camera;              // 相机对象

@property (nonatomic) NSTimeInterval    autoFoucsDelay;         // 自动聚焦延时 (默认: 5秒)
@property (nonatomic) NSTimeInterval    longTouchDelay;         // 长按延时 (默认: 1.2秒)
@property (nonatomic) NSTimeInterval    faceDetectionRate;      // 脸部定位采样频率 (默认: 0.2秒)
@property (nonatomic) BOOL              enableFilterConfig;     // 开启滤镜配置选项
@property (nonatomic) NSInteger         topSpace;               // 顶部边距
@property (nonatomic) BOOL              enableLongTouchCapture; // 是否开启长按拍摄 (默认: NO)
@property (nonatomic) BOOL              enableFaceDetection;    // 是否开启脸部追踪
@property (nonatomic) CGRect            regionPercent;          // 显示区域百分比
@property (nonatomic) BOOL              displayGuideLine;       // 是否显示辅助线

/**
 * 相机状态改变
 * @param status 相机状态
 * @param camera 相机接口
 */
- (void)cameraStatusChanged:(TuCameraState)status camera:(TuCamera *)camera;

- (BOOL)onFocusWithPoint:(CGPoint)point isTouches:(BOOL)isTouches;

- (void)hiddenFaceViews;
///**
// *  通知脸部追踪信息
// *
// *  @param faces 脸部追踪信息
// *  @param size  显示区域长宽
// */
//- (void)notifyFaceDetection:(NSMutableArray<AVMetadataFaceObject*> *)faces size:(CGSize)size;

/** 按照宽高计算相对于图片的范围 */
- (CGRect)makeRectRelativeImage:(CGSize)size;
/** 创建脸部定位视图 */
- (UIView *)buildFaceDetectionView;

- (void)setRangeViewPosition:(CGPoint)point; // 通知选取范围视图
//- (void)notifyFilterConfigView:(SelesParameters *)filter; // 通知滤镜配置视图通知滤镜配置视图
@end
