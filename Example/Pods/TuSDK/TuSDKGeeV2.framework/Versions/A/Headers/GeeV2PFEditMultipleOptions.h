//
//  GeeV2PFEditMultipleOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditMultipleController.h"

/**
 *  多功能图像编辑控制器配置选项
 *  建议保存到相册或者保存到临时文件二选一；如果保存相册和临时文件都为false，强制保存到相册
 */
@interface GeeV2PFEditMultipleOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:GeeV2PFEditMultipleView, 需要继承 GeeV2PFEditMultipleView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  最大输出图片边长 (默认:0, 不限制图片宽高)
 */
@property (nonatomic) NSUInteger limitSideSize;

/**
 *  是否禁用滑动切换显示图片 (默认:不禁用)
 */
@property (nonatomic) BOOL disableSlideSwitch;

/**
 *  最大输出图片按照设备屏幕 (默认:true, 如果设置了LimitSideSize, 将忽略LimitForScreen)
 */
@property (nonatomic) BOOL limitForScreen;

/**
 *  是否禁用操作步骤记录
 */
@property (nonatomic) BOOL disableStepsSave;

/**
 *  是否保存全部图片（默认：NO 结果只保留编辑过的图片）
 *
 *  当设置为Yes,结果保留所有图片（无论图片是否编辑过）
 */
@property (nonatomic) BOOL enableAlwaysSaveEditResult;

/**
 *  设置水印选项 (默认为空，如果设置不为空，则输出的图片上将带有水印)
 */
@property (nonatomic) TuSDKWaterMarkOption *waterMarkOption;

/**
 *  功能模块列表 lsqTuSDKCPEditActionType (默认全部加载, [TuSDKCPEditActionType multipleActionTypes])
 */
@property (nonatomic) NSMutableArray *modules;
/**
 *  一次编辑的最大照片数量 (默认: 9, 0 < n <= 9)
 */
@property (nonatomic, assign) NSUInteger maxSelectionNumber;
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
- (GeeV2PFEditMultipleController *)viewController;
@end
