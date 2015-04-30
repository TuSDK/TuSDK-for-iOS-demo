//
//  TuSDKPFEditMultipleController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPImageResultController.h"
#import "TuSDKPFEditMultipleView.h"
#import "TuSdkCPEditActionType.h"

#pragma mark - TuSDKPFEditMultipleControllerDelegate
@class TuSDKPFEditMultipleController;

/**
 *  多功能图像编辑控制器委托
 */
@protocol TuSDKPFEditMultipleControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑入口控制器
 *  @param result 图片编辑入口控制器处理结果
 */
- (void)onTuSDKPFEditMultiple:(TuSDKPFEditMultipleController *)controller result:(TuSDKResult *)result;

/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑入口控制器
 *  @param action 图片编辑动作类型
 */
- (void)onTuSDKPFEditMultiple:(TuSDKPFEditMultipleController *)controller action:(lsqTuSDKCPEditActionType)action;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑入口控制器
 *  @param result 图片编辑入口控制器处理结果
 *  @return 是否截断默认处理逻辑 (默认: false, 设置为True时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditMultiple:(TuSDKPFEditMultipleController *)controller result:(TuSDKResult *)result;
@end


#pragma mark - TuSDKPFEditMultipleController
/**
 *  多功能图像编辑控制器
 */
@interface TuSDKPFEditMultipleController : TuSDKCPImageResultController{
@protected
    // 默认样式视图
    TuSDKPFEditMultipleView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditMultipleView *defaultStyleView;
/**
 *  多功能图像编辑控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFEditMultipleControllerDelegate> delegate;

#pragma mark - config
/**
 *  视图类 (默认:TuSDKPFEditEntryView, 需要继承 TuSDKPFEditEntryView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  最大输出图片边长 (默认:0, 不限制图片宽高)
 */
@property (nonatomic) NSUInteger limitSideSize;

/**
 *  最大输出图片按照设备屏幕 (默认:false, 如果设置了LimitSideSize, 将忽略LimitForScreen)
 */
@property (nonatomic) BOOL limitForScreen;

/**
 *  视频视图显示比例类型 (默认:lsqRatioAll, 如果设置cameraViewRatio > 0, 将忽略ratioType)
 */
@property (nonatomic) lsqRatioType ratioType;

/**
 *  是否禁用操作步骤记录
 */
@property (nonatomic) BOOL disableStepsSave;

/**
 *  功能模块列表 lsqTuSDKCPEditActionType (默认全部加载, [TuSDKCPEditActionType multipleActionTypes])
 */
@property (nonatomic, retain) NSArray *modules;

/**
 *  显示的图片
 */
@property (nonatomic, retain) UIImage *displayImage;

/**
 *  获取最后执行的步骤
 *
 *  @return 最后执行的步骤
 */
- (NSString *)lastStepTemp;

/**
 *  添加一条操作
 *
 *  @param temp 操作文件路径
 */
- (void)appendHistory:(NSString *)temp;

/**
 *  操作记录后退
 */
- (void)onStepPreviewAction;

/**
 *  操作记录前进
 */
- (void)onStepNextAction;

/**
 *  开启响应处理控制器
 *
 *  @param btn 入口按钮
 */
- (void)onEditWithAction:(UIButton *)btn;

/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion;
@end
