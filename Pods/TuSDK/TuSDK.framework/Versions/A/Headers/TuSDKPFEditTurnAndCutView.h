//
//  TuSDKPFEditTurnAndCutView.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/7.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFCameraFilterView.h"

/**
 *  图片方向改变
 */
typedef NS_ENUM(NSInteger, lsqImageChange)
{
    /**
     *  未知方向
     */
    lsqImageChangeUnknow                = 0,
    /**
     *  向左旋转
     */
    lsqImageChangeTurnLeft              = 1 << 0,
    /**
     *  向右旋转
     */
    lsqImageChangeTurnRight             = 1 << 1,
    /**
     *  水平镜像
     */
    lsqImageChangeMirrorHorizontal      = 1 << 2,
    /**
     *  垂直镜像
     */
    lsqImageChangeMirrorVertical        = 1 << 3
};

#pragma mark - TuSDKPFEditTurnAndCutRegion
/**
 *  旋转和裁剪 裁剪区域视图
 */
@interface TuSDKPFEditTurnAndCutRegion: UIView{
    // 选区信息
    CGRect _regionRect;
}
/**
 *  区域长宽
 */
@property (nonatomic) CGSize regionSize;

/**
 *  选区信息
 */
@property (nonatomic, readonly) CGRect regionRect;

/**
 *  边缘覆盖区域颜色 (默认:RGBA(0, 0, 0, 0.5))
 */
@property (nonatomic, retain) UIColor *edgeMaskColor;

/**
 *  边缘线颜色 (默认:RGBA(255, 255, 255, 0.5))
 */
@property (nonatomic, retain) UIColor *edgeSideColor;

/**
 *  边缘线宽度 (默认:2)
 */
@property (nonatomic) CGFloat edgeSideWidth;
@end

#pragma mark - TuSDKPFEditTurnAndCutBottomView
/**
 *  旋转和裁剪视图控制栏
 */
@interface TuSDKPFEditTurnAndCutBottomView : UIView{
    @protected
    // 滤镜按钮
    UIButton *_filterButton;
    // 旋转按钮
    UIButton *_trunButton;
    // 镜像按钮
    UIButton *_mirrorButton;
    // 完成按钮
    UIButton *_completeButton;
}
/**
 *  滤镜按钮
 */
@property (nonatomic, readonly) UIButton *filterButton;

/**
 *  旋转按钮
 */
@property (nonatomic, readonly) UIButton *trunButton;

/**
 *  镜像按钮
 */
@property (nonatomic, readonly) UIButton *mirrorButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *completeButton;
@end

#pragma mark - TuSDKPFEditTurnAndCutView
/**
 *  旋转和裁剪视图
 */
@interface TuSDKPFEditTurnAndCutView : UIView<UIScrollViewDelegate>{
    @protected
    // 返回按钮
    UIButton *_backButton;
    // 旋转和裁剪视图控制栏
    TuSDKPFEditTurnAndCutBottomView *_bottomBar;
    // 旋转和裁剪 裁剪区域视图
    TuSDKPFEditTurnAndCutRegion *_cutRegionView;
    // 滤镜视图
    TuSDKPFCameraFilterView *_filterView;
    // 包装视图
    UIScrollView *_wrapView;
    // 图片包装类 (处理缩放)
    UIView *_imageWrapView;
    // 图片视图  (处理旋转)
    UIImageView *_imageView;
    // 是否正在处理动画
    BOOL _isInAniming;
}

/**
 *  返回按钮
 */
@property (nonatomic, readonly) UIButton *backButton;

/**
 *  旋转和裁剪视图控制栏类 (默认:TuSDKPFEditTurnAndCutBottomView, 需要继承 TuSDKPFEditTurnAndCutBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  旋转和裁剪 裁剪区域视图类 (默认:TuSDKPFEditTurnAndCutRegion, 需要继承 TuSDKPFEditTurnAndCutRegion)
 */
@property (nonatomic, strong) Class cutRegionViewClazz;

/**
 *  滤镜列表视图类 (默认:TuSDKPFCameraFilterView, 需要继承 TuSDKPFCameraFilterView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  旋转和裁剪视图控制栏
 */
@property (nonatomic, readonly) TuSDKPFEditTurnAndCutBottomView *bottomBar;

/**
 *  旋转和裁剪 裁剪区域视图
 */
@property (nonatomic, readonly) TuSDKPFEditTurnAndCutRegion *cutRegionView;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) TuSDKPFCameraFilterView *filterView;

/**
 *  包装视图
 */
@property (nonatomic, readonly) UIScrollView *wrapView;

/**
 *  图片包装类 (处理缩放)
 */
@property (nonatomic, readonly) UIView *imageWrapView;

/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *imageView;

/**
 *  是否正在处理动画
 */
@property (nonatomic, readonly) BOOL isInAniming;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  是否开启裁剪支持 (默认: 关闭，如果设置cutSize将返回YES)
 */
@property (nonatomic, readonly) BOOL enableCut;

/**
 *  需要裁剪的长宽
 */
@property (nonatomic) CGSize cutSize;

/**
 *  设置图片
 *
 *  @param image           图片
 *  @param orginDirectionX 原图是否为横向图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  改变图片方向
 *
 *  @param changed 图片方向改变
 */
- (void)changeImage:(lsqImageChange)changed;

/**
 *  计算图片裁剪区域百分比
 *
 *  @return 图片裁剪区域百分比
 */
- (CGRect)countImageCutRect;

/**
 *  是否正在动作
 *
 *  @return 是否正在动作
 */
- (BOOL)inActioning;
@end
