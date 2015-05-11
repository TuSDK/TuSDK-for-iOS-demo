//
//  TuSDKCPFilterResultController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/29.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPImageResultController.h"
#import "TuSDKICGPUImageView.h"
#import "TuSDKPFEditFilterView.h"
#import "TuSDKCPParameterConfigView.h"

#pragma mark - TuSDKCPFilterResultView
/**
 *  滤镜处理结果控制器视图
 */
@interface TuSDKCPFilterResultView : UIView
{
    // 图片视图
    TuSDKPFEditFilterImageView *_imageView;
    // 底部动作栏
    TuSDKPFEditFilterBottomBar *_bottomBar;
    // 参数配置视图
    TuSDKCPParameterConfigView *_configView;
}
/**
 *  图片视图
 */
@property (nonatomic, readonly) TuSDKPFEditFilterImageView *imageView;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditFilterBottomBar *bottomBar;

/**
 *  参数配置视图
 */
@property (nonatomic, readonly) TuSDKCPParameterConfigView *configView;
@end

#pragma mark - TuSDKPFEditSkinControllerDelegate
@class TuSDKCPFilterResultController;
/**
 *  滤镜处理结果控制器委托
 */
@protocol TuSDKCPFilterResultControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 */
- (void)onTuSDKFilterResult:(TuSDKCPFilterResultController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 *  @return 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKFilterResult:(TuSDKCPFilterResultController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - TuSDKCPFilterResultController
/**
 *  滤镜处理结果控制器
 */
@interface TuSDKCPFilterResultController : TuSDKCPImageResultController<TuSDKICGPUImageViewDelegate, TuSDKCPParameterConfigDelegate>
{
    @protected
    // 默认样式视图
    TuSDKCPFilterResultView *_defaultStyleView;
}

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKCPFilterResultView *defaultStyleView;

/**
 *  美颜控制器委托
 */
@property (nonatomic, assign) id<TuSDKCPFilterResultControllerDelegate> delegate;

/**
 *  视图类 (默认:TuSDKCPFilterResultView, 需要继承 TuSDKCPFilterResultView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  当前所使用的滤镜
 */
@property (nonatomic, retain) TuSDKFilterWrap *filterWrap;

/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion;

/**
 *  异步处理图片
 *
 *  @param result 异步处理图片
 */
- (void)asyncEditWithResult:(TuSDKResult *)result;

/**
 *  请求渲染视图
 */
- (void)requestRender;

/**
 *  绑定滤镜配置选项
 *
 *  @param params 配置选项列表
 *  @param index  选中索引
 */
- (void)bindWithConfigParams:(NSArray *)params selectedIndex:(NSUInteger)index;
@end
