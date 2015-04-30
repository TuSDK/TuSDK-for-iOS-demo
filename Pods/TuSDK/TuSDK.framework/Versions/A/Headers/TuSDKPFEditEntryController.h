//
//  TuSDKPFEditEntryController.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPImageResultController.h"
#import "TuSDKPFEditEntryView.h"
#import "TuSDKRatioType.h"
#import "TuSDKFilterWrap.h"
#import "TuSDKPFSticker.h"
#import "TuSdkCPEditActionType.h"

#pragma mark - TuSDKPFEditEntryControllerDelegate
@class TuSDKPFEditEntryController;

/**
 *  图片编辑入口控制器委托
 */
@protocol TuSDKPFEditEntryControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑入口控制器
 *  @param result 图片编辑入口控制器处理结果
 */
- (void)onTuSDKPFEditEntry:(TuSDKPFEditEntryController *)controller result:(TuSDKResult *)result;

/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑入口控制器
 *  @param action 图片编辑动作类型
 */
- (void)onTuSDKPFEditEntry:(TuSDKPFEditEntryController *)controller action:(lsqTuSDKCPEditActionType)action;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑入口控制器
 *  @param result 图片编辑入口控制器处理结果
 *  @return 是否截断默认处理逻辑 (默认: false, 设置为True时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditEntry:(TuSDKPFEditEntryController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - TuSDKPFEditEntryController
/**
 *  图片编辑入口控制器
 */
@interface TuSDKPFEditEntryController : TuSDKCPImageResultController{
@protected
    // 默认样式视图
    TuSDKPFEditEntryView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditEntryView *defaultStyleView;

/**
 *  图片编辑入口控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFEditEntryControllerDelegate> delegate;

#pragma mark - config
/**
 *  视图类 (默认:TuSDKPFEditEntryView, 需要继承 TuSDKPFEditEntryView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  开启裁剪旋转功能
 */
@property (nonatomic) BOOL enableCuter;

/**
 *  开启滤镜功能
 */
@property (nonatomic) BOOL enableFilter;

/**
 *  开启贴纸功能
 */
@property (nonatomic) BOOL enableSticker;

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

#pragma mark - inner config
/**
 *  滤镜处理过的原始图片
 */
@property (nonatomic, readonly) UIImage *filterImage;

/**
 *  经过裁剪的原始图片
 */
@property (nonatomic, readonly) UIImage *cuterImage;

/**
 *  裁剪结果
 */
@property (nonatomic, retain) TuSDKResult *cuterResult;

/**
 *  当前所使用的滤镜
 */
@property (nonatomic, retain) TuSDKFilterWrap *filterWrap;

/**
 *  添加贴纸数据
 *
 *  @param sticker 贴纸数据
 */
- (void)appendSticker:(TuSDKPFSticker *)sticker;

/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion;
@end
