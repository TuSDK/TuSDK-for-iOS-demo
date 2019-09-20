//
//  TuSDKCPPhotoEditComponent.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"
#import "TuSDKPFEditEntryOptions.h"
#import "TuSDKPFEditFilterOptions.h"
#import "TuSDKPFEditCuterOptions.h"
#import "TuSDKPFStickerLocalOptions.h"

#pragma mark - TuSDKCPPhotoEditOptions
/**
 *  图片编辑组件配置
 */
@interface TuSDKCPPhotoEditOptions : TuSDKCPOptions
/**
 *  图片编辑入口控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditEntryOptions *editEntryOptions;

/**
 *  图片编辑滤镜控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditFilterOptions *editFilterOptions;

/**
 *  图片编辑裁切旋转控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditCuterOptions *editCuterOptions;

/**
 *  本地贴纸选择控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFStickerLocalOptions *stickerLocalOptions;
@end

#pragma mark - TuSDKCPPhotoEditComponent
/**
 *  图片编辑组件
 */
@interface TuSDKCPPhotoEditComponent : TuSDKCPPhotoEditComponentBase<TuSDKPFEditEntryControllerDelegate, TuSDKPFEditCuterControllerDelegate, TuSDKPFEditFilterControllerDelegate, TuSDKPFStickerLocalControllerDelegate>
/**
 *  图片编辑组件配置选项
 */
@property (nonatomic, retain) TuSDKCPPhotoEditOptions *options;
@end
