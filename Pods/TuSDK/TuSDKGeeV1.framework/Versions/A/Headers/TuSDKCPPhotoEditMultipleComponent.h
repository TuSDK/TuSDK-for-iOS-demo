//
//  TuSDKCPPhotoEditMultipleComponent.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"

#import "TuSDKPFEditMultipleOptions.h"
#import "TuSDKPFEditFilterOptions.h"
#import "TuSDKPFEditCuterOptions.h"
#import "TuSDKPFEditSkinController.h"
#import "TuSDKPFEditStickerOptions.h"
#import "TuSDKPFEditTextOptions.h"
#import "TuSDKPFEditSmudgeOptions.h"
#import "TuSDKPFEditAdjustController.h"
#import "TuSDKPFEditSharpnessController.h"
#import "TuSDKPFEditApertureController.h"
#import "TuSDKPFEditVignetteController.h"
#import "TuSDKPFEditSmudgeController.h"
#import "TuSDKPFEditWipeAndFilterOptions.h"
#import "TuSDKPFEditHolyLightController.h"
#import "TuSDKPFEditHDRController.h"
#import "TuSDKPFEditTextController.h"

#pragma mark - TuSDKCPPhotoEditMultipleOptions
/**
 *  多功能图像编辑组件选项
 */
@interface TuSDKCPPhotoEditMultipleOptions : TuSDKCPOptions
/**
 *  多功能图像编辑控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditMultipleOptions *editMultipleOptions;

/**
 *  图片编辑滤镜控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditFilterOptions *editFilterOptions;

/**
 *  图片编辑裁切旋转控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditCuterOptions *editCuterOptions;

/**
 *  美颜控制器视图配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditSkinOptions *editSkinOptions;

/**
 *  图片编辑贴纸选择控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditStickerOptions *editStickerOptions;

/**
 *  图片编辑文字控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditTextOptions *editTextOptions;

/**
 *  颜色调整控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditAdjustOptions *editAdjustOptions;

/**
 *  锐化功能控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditSharpnessOptions *editSharpnessOptions;

/**
 *  大光圈控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditApertureOptions *editApertureOptions;

/**
 *  暗角控制器功能控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditVignetteOptions *editVignetteOptions;

/**
 *  涂抹控制器功能控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditSmudgeOptions *editSmudgeOptions;

/**
 *  滤镜涂抹控制器功能控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditWipeAndFilterOptions *editWipeAndFilterOptions;

/**
 *  圣光控制器功能控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditHolyLightOptions *editHolyLightOptions;

/**
 *  HDR 控制器功能控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditHDROptions *editHDROptions;
@end


#pragma mark - TuSDKCPPhotoEditMultipleComponent
/**
 *  多功能图像编辑组件
 */
@interface TuSDKCPPhotoEditMultipleComponent : TuSDKCPPhotoEditMultipleComponentBase<TuSDKPFEditMultipleControllerDelegate,
TuSDKPFEditCuterControllerDelegate, TuSDKPFEditFilterControllerDelegate, TuSDKCPFilterResultControllerDelegate,
TuSDKPFEditStickerControllerDelegate, TuSDKPFEditSmudgeControllerDelegate, TuSDKPFEditWipeAndFilterControllerDelegate, TuSDKPFEditTextControllerDelegate>
/**
 *  多功能图像编辑组件选项
 */
@property (nonatomic, retain) TuSDKCPPhotoEditMultipleOptions *options;
@end
