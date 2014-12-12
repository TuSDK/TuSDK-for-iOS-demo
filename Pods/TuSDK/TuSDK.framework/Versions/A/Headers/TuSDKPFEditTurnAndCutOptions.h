//
//  TuSDKPFEditTurnAndCutOptions.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/7.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKCPResultOptions.h"
#import "TuSDKPFEditTurnAndCutViewController.h"

/**
 *  旋转和裁剪视图控制器配置选项
 */
@interface TuSDKPFEditTurnAndCutOptions : TuSDKCPResultOptions

/**
 *  视图类 (默认:TuSDKPFEditTurnAndCutView, 需要继承 TuSDKPFEditTurnAndCutView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  旋转和裁剪视图控制栏类 (默认:TuSDKPFEditTurnAndCutBottomView, 需要继承 TuSDKPFEditTurnAndCutBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  旋转和裁剪 裁剪区域视图类 (默认:TuSDKPFEditTurnAndCutRegion, 需要继承 TuSDKPFEditTurnAndCutRegion)
 */
@property (nonatomic, strong) Class cutRegionViewClazz;

/**
 *  滤镜列表视图类 (默认:TuSDKPFCameraFilterView, 需要继承 TuSDKPFCameraFilterView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  需要裁剪的长宽
 */
@property (nonatomic) CGSize cutSize;

/**
 *  是否显示处理结果预览图 (默认：关闭，调试时可以开启)
 */
@property (nonatomic) BOOL showResultPreview;

/**
 *  创建旋转和裁剪视图控制器对象
 *
 *  @return 旋转和裁剪视图控制器对象
 */
- (TuSDKPFEditTurnAndCutViewController *)viewController;
@end
