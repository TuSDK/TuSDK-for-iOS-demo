//
//  TuSDKCPPhotoEditComponent.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPComponent.h"
#import "TuSDKCPPhotoEditOptions.h"

/**
 *  图片编辑组件
 */
@interface TuSDKCPPhotoEditComponent : TuSDKCPComponent<TuSDKPFEditEntryControllerDelegate, TuSDKPFEditCuterControllerDelegate, TuSDKPFEditFilterControllerDelegate, TuSDKPFStickerLocalControllerDelegate>
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

/**
 *  图片编辑组件配置选项
 */
@property (nonatomic, retain) TuSDKCPPhotoEditOptions *options;
@end
