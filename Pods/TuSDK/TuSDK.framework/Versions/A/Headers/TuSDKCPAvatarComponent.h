//
//  TuSDKCPAvararComponent.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TuSDKCPAlbumComponent.h"
#import "TuSDKCPAvatarOptions.h"

/**
 *  头像设置组件
 */
@interface TuSDKCPAvatarComponent : TuSDKCPAlbumComponent<TuSDKPFCameraDelegate, TuSDKPFEditTurnAndCutDelegate>

/**
 *  头像设置组件选项
 */
@property (nonatomic, retain) TuSDKCPAvatarOptions *options;
@end
