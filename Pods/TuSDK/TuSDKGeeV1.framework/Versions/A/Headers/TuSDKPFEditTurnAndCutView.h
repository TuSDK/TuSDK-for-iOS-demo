//
//  TuSDKPFEditTurnAndCutView.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/7.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKPFNormalFilterGroupView.h"

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
@interface TuSDKPFEditTurnAndCutView : UIView<TuSDKICTouchImageViewDelegate>{
    @protected
    // 旋转和裁剪视图控制栏
    TuSDKPFEditTurnAndCutBottomView *_bottomBar;
    // 图片编辑视图 (旋转，缩放)
    UIView<TuSDKICTouchImageViewInterface> *_editImageView;
    // 滤镜视图
    TuSDKPFNormalFilterGroupView *_filterView;
}

/**
 *  旋转和裁剪视图控制栏类 (默认:TuSDKPFEditTurnAndCutBottomView, 需要继承 TuSDKPFEditTurnAndCutBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  图片编辑视图 (旋转，缩放)类 (默认:TuSDKICTouchImageView, 需要继承 TuSDKICTouchImageView)
 */
@property (nonatomic, strong) Class editImageViewClazz;

/**
 *  滤镜列表视图类 (默认:TuSDKPFNormalFilterGroupView, 需要继承 TuSDKPFNormalFilterGroupView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  旋转和裁剪视图控制栏
 */
@property (nonatomic, readonly) TuSDKPFEditTurnAndCutBottomView *bottomBar;

/**
 *  图片编辑视图 (旋转，缩放)
 */
@property (nonatomic, readonly) UIView<TuSDKICTouchImageViewInterface> *editImageView;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) TuSDKPFNormalFilterGroupView *filterView;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  需要裁剪的长宽
 */
@property (nonatomic, setter=setCutSize:) CGSize cutSize;

/**
 *  设置图片
 *
 *  @param image           图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  重新计算布局
 */
- (void)needUpdateLayout;
@end
