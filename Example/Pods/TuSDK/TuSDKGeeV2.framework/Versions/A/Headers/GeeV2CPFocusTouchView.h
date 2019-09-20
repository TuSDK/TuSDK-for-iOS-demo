//
//  GeeV2CPFocusTouchView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKGeeV2Import.h"

/**
 *  相机聚焦触摸视图
 */
@interface GeeV2CPFocusTouchView : TuSDKCPFocusTouchViewBase<TuSDKVideoCameraExtendViewInterface>
{
@protected
    // 聚焦视图 (如果不设定，将使用 TuSDKICFocusRangeView)
    UIView<TuSDKICFocusRangeViewProtocol> *_rangeView;
    // 滤镜配置视图
    TuSDKPFFilterConfigView *_filterConfigView;
}

/**
 *  聚焦视图 (如果不设定，将使用 TuSDKICFocusRangeView)
 */
@property (nonatomic, readonly) UIView<TuSDKICFocusRangeViewProtocol> *rangeView;

/**
 *  滤镜配置视图
 */
@property (nonatomic, readonly) TuSDKPFFilterConfigView *filterConfigView;

/**
 *  顶部边距
 */
@property (nonatomic) NSInteger topSpace;

/**
 *  是否显示辅助线
 */
@property (nonatomic) BOOL displayGuideLine;

/**
 *  通知选取范围视图
 *
 *  @param point 聚焦点
 */
- (void)notifyRangeViewWithPoint:(CGPoint)point;

/** 创建脸部定位视图 */
- (UIView *)buildFaceDetectionView;

@end
