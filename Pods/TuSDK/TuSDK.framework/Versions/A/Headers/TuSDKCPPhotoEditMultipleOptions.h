//
//  TuSDKCPPhotoEditMultipleOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPOptions.h"
#import "TuSDKPFEditMultipleOptions.h"
#import "TuSDKPFEditFilterOptions.h"
#import "TuSDKPFEditCuterOptions.h"
#import "TuSDKPFEditSkinOptions.h"
#import "TuSDKPFEditStickerOptions.h"
#import "TuSDKPFEditAdjustOptions.h"
#import "TuSDKEditSharpnessController.h"

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
 *  颜色调整控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditAdjustOptions *editAdjustOptions;

/**
 *  锐化功能控制器配置选项
 */
@property (nonatomic, readonly) TuSDKEditSharpnessOptions *editSharpnessOptions;
@end
