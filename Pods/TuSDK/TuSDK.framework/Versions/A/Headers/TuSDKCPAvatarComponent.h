//
//  TuSDKCPAvararComponent.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TuSDKResult.h"
#import "TuSDKCPAvatarOptions.h"

/**
 *  获取头像图片回调
 *
 *  @param image 头像图片
 *  @param error 错误信息
 */
typedef void (^TuSDKCPAvatarReadedBlock)(TuSDKResult *result, NSError *error);

/**
 *  头像设置组件
 */
@interface TuSDKCPAvatarComponent : NSObject<TuSDKPFAlbumDelegate, TuSDKPFPhotosDelegate, TuSDKPFCameraDelegate, TuSDKPFEditTurnAndCutDelegate>
/**
 *  来源控制器
 */
@property (nonatomic, assign) UIViewController *sourceController;

/**
 *  获取头像图片回调
 */
@property (nonatomic, strong) TuSDKCPAvatarReadedBlock callbackBlock;

/**
 *  头像设置组件选项
 */
@property (nonatomic, retain) TuSDKCPAvatarOptions *options;

/**
 *  初始化头像设置组件
 *
 *  @param controller    来源控制器
 *  @param callbackBlock 获取头像图片回调
 *
 *  @return 头像设置组件
 */
+ (instancetype)initWithSourceController:(UIViewController *)controller callbackBlock:(TuSDKCPAvatarReadedBlock)callbackBlock;

/**
 *  显示组件
 */
- (void)showComponent;
@end
