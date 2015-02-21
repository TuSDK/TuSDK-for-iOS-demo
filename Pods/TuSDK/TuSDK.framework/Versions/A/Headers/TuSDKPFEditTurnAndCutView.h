//
//  TuSDKPFEditTurnAndCutView.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/7.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFEditImageView.h"
#import "TuSDKPFEditTurnAndCutFilterView.h"

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
@interface TuSDKPFEditTurnAndCutView : UIView<TuSDKPFEditImageViewDelegate>{
    @protected
    // 返回按钮
    UIButton *_backButton;
    // 旋转和裁剪视图控制栏
    TuSDKPFEditTurnAndCutBottomView *_bottomBar;
    // 图片编辑视图 (旋转，缩放)
    TuSDKPFEditImageView *_editImageView;
    // 滤镜视图
    TuSDKPFEditTurnAndCutFilterView *_filterView;
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
 *  图片编辑视图 (旋转，缩放)类 (默认:TuSDKPFEditImageView, 需要继承 TuSDKPFEditImageView)
 */
@property (nonatomic, strong) Class editImageViewClazz;

/**
 *  滤镜列表视图类 (默认:TuSDKPFEditTurnAndCutFilterView, 需要继承 TuSDKPFEditTurnAndCutFilterView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  旋转和裁剪视图控制栏
 */
@property (nonatomic, readonly) TuSDKPFEditTurnAndCutBottomView *bottomBar;

/**
 *  图片编辑视图 (旋转，缩放)
 */
@property (nonatomic, readonly) TuSDKPFEditImageView *editImageView;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) TuSDKPFEditTurnAndCutFilterView *filterView;

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
@end
