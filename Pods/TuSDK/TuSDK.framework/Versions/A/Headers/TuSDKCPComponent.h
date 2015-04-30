//
//  TuSDKCPComponent.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKCPViewController.h"

/**
 *  组件回调结果
 *
 *  @param result     处理结果
 *  @param error      错误信息
 *  @param controller 最后执行的控制器
 */
typedef void (^TuSDKCPComponentBlock)(TuSDKResult *result, NSError *error, UIViewController *controller);

#pragma mark - TuSDKCPComponent
/**
 *  组件基础类
 */
@interface TuSDKCPComponent : NSObject<TuSDKCPComponentErrorDelegate>

/**
 *  来源控制器
 */
@property (nonatomic, assign) UIViewController *sourceController;

/**
 *  组件回调
 */
@property (nonatomic, strong) TuSDKCPComponentBlock callbackBlock;

/**
 *  是否在组件执行完成后自动关闭组件 (默认:NO)
 */
@property (nonatomic) BOOL autoDismissWhenCompelted;

/**
 *  初始化组件
 *
 *  @param controller    来源控制器
 *  @param callbackBlock 组件回调结果
 *
 *  @return 组件
 */
+ (instancetype)initWithSourceController:(UIViewController *)controller callbackBlock:(TuSDKCPComponentBlock)callbackBlock;

/**
 *  显示组件
 */
- (void)showComponent;

/**
 *  通知处理结果
 *
 *  @param result 返回结果
 *  @param error  异常信息
 *  @param controller  最后执行的控制器
 */
- (void)notifyResult:(TuSDKResult *)result
               error:(NSError *)error
          controller:(UIViewController *)controller;
@end

#pragma mark - TuSDKCPInputComponent
/**
 *  组件基础类(输入内容)
 */
@interface TuSDKCPInputComponent : TuSDKCPComponent
/**
 *  输入的临时文件目录 (处理优先级: inputImage > inputTempFilePath > inputAsset)
 */
@property (nonatomic, copy) NSString *inputTempFilePath;

/**
 *  输入的相册图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
 */
@property (nonatomic, retain) ALAsset *inputAsset;

/**
 *  输入的图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
 */
@property (nonatomic, retain) UIImage *inputImage;
@end