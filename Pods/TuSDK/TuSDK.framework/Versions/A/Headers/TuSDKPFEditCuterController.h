//
//  TuSDKPFEditCuterController.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "TuSDKCPImageResultController.h"
#import "TuSDKRatioType.h"
#import "TuSDKPFEditCuterView.h"

#pragma mark - TuSDKPFEditCuterControllerDelegate
@class TuSDKPFEditCuterController;
/**
 *  图片编辑裁切旋转控制器委托
 */
@protocol TuSDKPFEditCuterControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑裁切旋转控制器
 *  @param result 处理结果
 */
- (void)onTuSDKPFEditCuter:(TuSDKPFEditCuterController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑裁切旋转控制器
 *  @param result 处理结果
 *  @return 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditCuter:(TuSDKPFEditCuterController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - TuSDKPFEditCuterController
/**
 *  图片编辑裁切旋转控制器
 */
@interface TuSDKPFEditCuterController : TuSDKCPImageResultController{
@protected
    // 默认样式视图
    TuSDKPFEditCuterView *_defaultStyleView;
    // 缩放选择区域
    CGRect _zoomRect;
    // 缩放比例
    CGFloat _zoomScale;
    // 图片方向
    UIImageOrientation _imageOrientation;
    // 当前裁剪比例类型
    lsqRatioType _currentRatioType;
    // 当前裁剪比例
    CGFloat _currentRatio;
}
#pragma mark - config
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditCuterView *defaultStyleView;

/**
 *  图片编辑裁切旋转控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFEditCuterControllerDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFEditCuterView, 需要继承 TuSDKPFEditCuterView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  是否开启图片旋转 (默认: false)
 */
@property (nonatomic) BOOL enableTrun;

/**
 *  是否开启图片镜像(默认: false)
 */
@property (nonatomic) BOOL enableMirror;
/**
 *  视图显示比例类型 (默认:lsqRatioAll, 如果设置cameraViewRatio > 0, 将忽略ratioType)
 */
@property (nonatomic) lsqRatioType ratioType;

/**
 *  是否仅返回裁切参数，不返回处理图片
 */
@property (nonatomic) BOOL onlyReturnCuter;

#pragma mark - inner config
/**
 *  裁剪结果
 */
@property (nonatomic, setter=setCuterResult:) TuSDKResult *cuterResult;

/**
 *  缩放选择区域
 */
@property (nonatomic) CGRect zoomRect;
/**
 *  缩放比例
 */
@property (nonatomic) CGFloat zoomScale;
/**
 *  当前裁剪比例类型
 */
@property (nonatomic) lsqRatioType currentRatioType;
/**
 *  当前裁剪比例
 */
@property (nonatomic) CGFloat currentRatio;

/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion;
@end
