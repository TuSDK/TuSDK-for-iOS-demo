//
//  TuSDKPFEditEntryOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPImageResultOptions.h"
#import "TuSDKPFEditEntryController.h"

/**
 *  图片编辑入口控制器配置选项
 */
@interface TuSDKPFEditEntryOptions : TuSDKCPImageResultOptions
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
 *  图片编辑入口控制器对象
 *
 *  @return 图片编辑入口控制器对象
 */
- (TuSDKPFEditEntryController *)viewController;
@end
