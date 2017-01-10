//
//  TuSDKPFEditMultipleOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditMultipleController.h"

/**
 *  多功能图像编辑控制器配置选项
 */
@interface TuSDKPFEditMultipleOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditMultipleView, 需要继承 TuSDKPFEditMultipleView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  最大输出图片边长 (默认:0, 不限制图片宽高)
 */
@property (nonatomic) NSUInteger limitSideSize;

/**
 *  最大输出图片按照设备屏幕 (默认:true, 如果设置了LimitSideSize, 将忽略LimitForScreen)
 */
@property (nonatomic) BOOL limitForScreen;

/**
 *  是否禁用操作步骤记录
 */
@property (nonatomic) BOOL disableStepsSave;

/**
 *  设置水印选项 (默认为空，如果设置不为空，则输出的图片上将带有水印)
 */
@property (nonatomic) TuSDKWaterMarkOption *waterMarkOption;

/**
 *  功能模块列表 lsqTuSDKCPEditActionType (默认全部加载, [TuSDKCPEditActionType multipleActionTypes])
 */
@property (nonatomic) NSMutableArray *modules;

/**
 *  禁用功能模块
 *
 *  @param actionType 图片编辑动作类型
 */
- (void)disableModule:(lsqTuSDKCPEditActionType)actionType;

/**
 *  多功能图像编辑控制器对象
 *
 *  @return controller 多功能图像编辑控制器对象
 */
- (TuSDKPFEditMultipleController *)viewController;
@end
