//
//  TuSDKCPFocusTouchView.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/29.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKGeeV1Import.h"

/**
 *  相机聚焦触摸视图
 */
@interface TuSDKCPFocusTouchView : TuSDKCPFocusTouchViewBase<TuSDKVideoCameraExtendViewInterface>
{
    @protected
    // 聚焦视图 (如果不设定，将使用 TuSDKICFocusRangeView)
    UIView<TuSDKICFocusRangeViewProtocol> *_rangeView;
    // 裁剪区域视图 (如果不设定，将使用 TuSDKICCutRegionView)
    TuSDKICMaskRegionView *_cutRegionView;
    // 滤镜配置视图
    TuSDKPFFilterConfigView *_filterConfigView;
}

/**
 *  聚焦视图 (如果不设定，将使用 TuSDKICFocusRangeView)
 */
@property (nonatomic, readonly) UIView<TuSDKICFocusRangeViewProtocol> *rangeView;

/**
 *  裁剪区域视图 (如果不设定，将使用 TuSDKICCutRegionView)
 */
@property (nonatomic, readonly) TuSDKICMaskRegionView *cutRegionView;

/**
 *  滤镜配置视图
 */
@property (nonatomic, readonly) TuSDKPFFilterConfigView *filterConfigView;

/**
 *  区域长宽比例
 */
@property (nonatomic) CGFloat regionRatio;

/**
 *  视频覆盖区域颜色 (默认：[UIColor blackColor])
 */
@property (nonatomic, retain) UIColor *regionViewColor;

/**
 *  顶部边距
 */
@property (nonatomic) NSInteger topSpace;

/**
 *  通知选取范围视图
 *
 *  @param point 聚焦点
 */
- (void)notifyRangeViewWithPoint:(CGPoint)point;
@end
