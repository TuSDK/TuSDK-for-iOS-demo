//
//  TuSDKCPPhotoEditMultipleComponent.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPComponent.h"
#import "TuSDKCPPhotoEditMultipleOptions.h"

/**
 *  多功能图像编辑组件
 */
@interface TuSDKCPPhotoEditMultipleComponent : TuSDKCPInputComponent<TuSDKPFEditMultipleControllerDelegate,
TuSDKPFEditCuterControllerDelegate, TuSDKPFEditFilterControllerDelegate, TuSDKCPFilterResultControllerDelegate,
TuSDKPFEditStickerControllerDelegate>
/**
 *  多功能图像编辑组件选项
 */
@property (nonatomic, retain) TuSDKCPPhotoEditMultipleOptions *options;
@end
