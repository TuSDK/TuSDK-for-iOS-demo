//
//  TuSDKCPAvararComponent.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCPAlbumComponent.h"
#import "TuSDKPFCameraOptions.h"
#import "TuSDKPFEditTurnAndCutOptions.h"

#pragma mark - TuSDKCPAvatarOptions
/**
 *  头像设置组件选项
 */
@interface TuSDKCPAvatarOptions : TuSDKCPAlbumOptions

/**
 *  默认相机视图控制器选项
 */
@property (nonatomic, readonly) TuSDKPFCameraOptions *cameraOptions;

/**
 *  旋转和裁剪视图控制器配置选项
 */
@property (nonatomic, readonly) TuSDKPFEditTurnAndCutOptions *editTurnAndCutOptions;
@end

#pragma mark - TuSDKCPAvatarComponent
/**
 *  头像设置组件
 */
@interface TuSDKCPAvatarComponent : TuSDKCPAlbumComponent<TuSDKPFCameraDelegate, TuSDKPFEditTurnAndCutDelegate>

/**
 *  头像设置组件选项
 */
@property (nonatomic, retain) TuSDKCPAvatarOptions *options;
@end
