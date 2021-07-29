//
//  TuFilterResultController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/29.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuImageResultController.h"
//#import "TuSDKICFilterImageViewWrap.h"
#import "TuParameterConfigViewInterface.h"
#import "TuCAEAGLView.h"
//#import "TuSDKPulseCore/cx/seles/extend/SelesParameters.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>
#pragma mark - TuFilterResultViewInterface
// 滤镜处理结果控制器视图接口
@protocol TuFilterResultViewInterface <NSObject>
// Filter Image View
@property (nonatomic, readonly) UIView<TuCAEAGLViewInterface> *imageView;
// 参数配置视图
@property (nonatomic, readonly) UIView<TuParameterConfigViewInterface> *configView;
@end


@class TuFilterResultController;
// 滤镜处理结果控制器委托
@protocol TuFilterResultControllerDelegate <TuComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 */
- (void)onTuSDKFilterResult:(TuFilterResultController *)controller result:(TuResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKFilterResult:(TuFilterResultController *)controller result:(TuResult *)result;
@end

#pragma mark - TuFilterResultController
// 滤镜处理结果控制器
@interface TuFilterResultController : TuImageResultController<TuParameterConfigDelegate>
{
    @protected
    // 默认样式视图
    UIView<TuFilterResultViewInterface> *_defaultStyleView;
}
// 默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
@property (nonatomic, readonly) UIView<TuFilterResultViewInterface> *defaultStyleView;
// 控制器委托
@property (nonatomic, weak) id<TuFilterResultControllerDelegate> delegate;
// 视图类 (需要实现 TuFilterResultViewInterface 接口)
@property (nonatomic, strong) Class viewClazz;
// 滤镜参数
@property (nonatomic, strong) SelesParameters *filterParams;
// 显示背景区域颜色
@property (nonatomic, strong) UIColor* displayBackgroundColor;
// 显示图片
@property (nonatomic, strong) UIImage* displayImage;
// 编辑图片完成按钮动作
- (void)onImageCompleteAtion;
// 异步处理图片
- (void)asyncEditWithResult:(TuResult *)result;
// 刷新滤镜参数视图
- (void)refreshConfigView;

- (void)setSkinFilterParams:(SelesParameters *)filterParams;
- (void)enableSkinFilter;


@end
