//
//  TuSDKFilterManager.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/27.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKFilterWrap.h"
#import "TuSDKTKFiltersTempTask.h"
#import "TuSDKTKFiltersSampleTask.h"
#import "TuSDKConfig.h"

@class TuSDKFilterManager;

/**
 *  滤镜控管理器委托
 */
@protocol TuSDKFilterManagerDelegate <NSObject>
/**
 * 滤镜管理器初始化完成
 *
 * @param manager
 *            滤镜管理器
 */
- (void)onTuSDKFilterManagerInited:(TuSDKFilterManager *)manager;
@end

#pragma mark - TuSDKFilterManager
/**
 *  滤镜控管理器
 */
@interface TuSDKFilterManager : NSObject

/**
 *  滤镜控管理器
 *
 *  @return 滤镜控管理器
 */
+ (instancetype) manager;

/**
 *  滤镜控管理器
 *
 *  @param config Sdk配置
 *
 *  @return 滤镜控管理器
 */
+ (instancetype)initWithConfig:(TuSDKConfig *)config;

/**
 *  是否已初始化
 */
@property (nonatomic, readonly) BOOL isInited;

/**
 *  是否初始化默认滤镜预览图
 */
@property (nonatomic) BOOL initSample;

/**
 *  滤镜名称列表
 */
@property (nonatomic, readonly) NSArray *filterNames;

/**
 *  滤镜预览效果列表任务
 */
@property (nonatomic, readonly) TuSDKTKFiltersSampleTask *samplesTask;

/**
 *  初始化滤镜管理器
 *
 *  @param delegate   滤镜控管理器委托
 *  @param initSample 是否初始化默认滤镜预览图
 */
- (void)initFilterManagerWithDelegate:(id<TuSDKFilterManagerDelegate>)delegate
                           initSample:(BOOL)initSample;

/**
 *  获取滤镜任务
 *
 *  @param image 滤镜预览源图 (如果为空使用SDK自带源图进行渲染)
 *  @param filterNames 需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
 *
 *  @return 滤镜任务
 */
- (TuSDKTKFiltersTaskBase *)samplesTaskWithImage:(UIImage *)image filterNames:(NSArray *)filterNames;

/**
 * 创建滤镜临时预览效果列表任务
 *
 *  @param image 输入的图片
 *  @param filterNames 需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
 *
 *  @return 滤镜任务
 */
- (TuSDKTKFiltersTempTask *)tempTaskWithImage:(UIImage *)image filterNames:(NSArray *)filterNames;

/**
 *  获取滤镜包装对象
 *
 *  @param name 滤镜名称
 *
 *  @return 滤镜包装对象
 */
- (TuSDKFilterWrap *)filterWrapWithName:(NSString *)name;

/**
 *  执行滤镜 并输出图形
 *
 *  @param image image 输入图像
 *  @param name  滤镜名称
 *
 *  @return 滤镜处理过的图像 (默认使用图像自身的方向属性)
 */
- (UIImage *)processWithImage:(UIImage *)image byFilterName:(NSString *)name;

/**
 *  执行滤镜 并输出图形
 *
 *  @param image            输入图像
 *  @param imageOrientation 图像方向
 *  @param name             滤镜名称
 *
 *  @return 滤镜处理过的图像
 */
- (UIImage *)processWithImage:(UIImage *)image orientation:(UIImageOrientation)imageOrientation byFilterName:(NSString *)name;
@end
