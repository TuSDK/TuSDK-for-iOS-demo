//
//  GeeV2PFEditTabBarOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/10/22.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditTabBarController.h"

#pragma mark - GeeV2PFEditTabBarOptions
/**
 *  图像编辑选项
 */
@interface GeeV2PFEditTabBarOptions : TuSDKCPResultOptions

/**
 *  视图类 (默认:GeeV2PFEditCuterView, 需要继承 GeeV2PFEditCuterView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  图片编辑裁切旋转控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditCuterOptions *editCuterOptions;
/**
 *  图片编辑裁切旋转控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditTurnAndMirrorOptions *editTurnOptions;
/**
 *  大光圈控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditApertureOptions *editApertureOptions;
/**
 *  滤镜涂抹控制器功能控制器配置选项
 */
@property (nonatomic, readonly) GeeV2PFEditWipeAndFilterOptions *editWipeAndFilterOptions;
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
- (GeeV2PFEditTabBarController *)viewController;

@end
