//
//  GeeV2CPPhotoEditMultipleComponent.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV2Import.h"

#import "GeeV2PFEditMultipleOptions.h"
#import "GeeV2PFEditTabBarOptions.h"
#import "GeeV2PFEditFilterOptions.h"
#import "GeeV2PFEditSkinController.h"
#import "GeeV2PFEditStickerOptions.h"
#import "GeeV2PFEditSmudgeOptions.h"
#import "GeeV2PFEditAdjustController.h"

/**
 *  组件回调结果
 *
 *  @param outputResults  处理结果
 *  @param error          错误信息
 *  @param controller     最后执行的控制器
 */
typedef void (^GeeV2CPComponentBlock)(NSArray<TuSDKResult *>*outputResults, NSError *error, UIViewController *controller);

#pragma mark - GeeV2CPPhotoEditMultipleOptions
/**
 *  多功能图像编辑组件选项
 */
@interface GeeV2CPPhotoEditMultipleOptions : TuSDKCPOptions
/**
 *  多功能图像编辑控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditMultipleOptions *editMultipleOptions;

/**
 *  多功能图像编辑控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditTabBarOptions *editTabBarOptions;

/**
 *  图片编辑滤镜控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditFilterOptions *editFilterOptions;

/**
 *  美颜控制器视图配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditSkinOptions *editSkinOptions;

/**
 *  图片编辑贴纸选择控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditStickerOptions *editStickerOptions;

/**
 *  颜色调整控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditAdjustOptions *editAdjustOptions;

/**
 *  涂抹控制器功能控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditSmudgeOptions *editSmudgeOptions;

@end


#pragma mark - GeeV2CPPhotoEditMultipleComponent
/**
 *  多功能图像编辑组件
 */
@interface GeeV2CPPhotoEditMultipleComponent : TuSDKCPPhotoEditMultipleComponentBase<GeeV2PFEditMultipleControllerDelegate, GeeV2PFEditFilterControllerDelegate, TuSDKCPFilterResultControllerDelegate,
GeeV2PFEditStickerControllerDelegate, GeeV2PFEditSmudgeControllerDelegate,GeeV2PFEditTabBarControllerDelegate>
/**
 *  多功能图像编辑组件选项
 */
@property (nonatomic, retain) GeeV2CPPhotoEditMultipleOptions *options;

/**
 *  输入资源对象列表
 */
@property (nonatomic, retain)  NSArray<TuSDKResult *> *inputResources;

/**
 *  组件回调
 */
@property (nonatomic, copy) GeeV2CPComponentBlock callbackBlockGeeV2;

/**
 *  初始化组件
 *
 *  @param controller    来源控制器
 *  @param callbackBlock 组件回调结果
 *
 *  @return controller 组件
 */
+ (instancetype)initWithSourceController:(UIViewController *)controller callbackBlock:(GeeV2CPComponentBlock)callbackBlock;
/**
 *  通知处理结果
 *
 *  @param result 返回结果
 *  @param error  异常信息
 *  @param controller  最后执行的控制器
 */
- (void)notifyResult:(NSArray<TuSDKResult *> *)resultArray
               error:(NSError *)error
          controller:(UIViewController *)controller;
@end
