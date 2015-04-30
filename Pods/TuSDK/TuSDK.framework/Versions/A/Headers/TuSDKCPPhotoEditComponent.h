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
@interface TuSDKCPPhotoEditComponent : TuSDKCPInputComponent<TuSDKPFEditEntryControllerDelegate, TuSDKPFEditCuterControllerDelegate, TuSDKPFEditFilterControllerDelegate, TuSDKPFStickerLocalControllerDelegate>
/**
 *  图片编辑组件配置选项
 */
@property (nonatomic, retain) TuSDKCPPhotoEditOptions *options;
@end
