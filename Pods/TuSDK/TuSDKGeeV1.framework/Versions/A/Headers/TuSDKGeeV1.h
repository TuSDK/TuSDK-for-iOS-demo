//
//  TuSDKGeeV1.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 15/9/6.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKGeeV1Theme.h"
#import "TuSDKCPAvatarComponent.h"
#import "TuSDKCPAlbumMultipleComponent.h"
#import "TuSDKCPPhotoEditComponent.h"
#import "TuSDKCPPhotoEditMultipleComponent.h"
#import "TuSDKCPFocusTouchView.h"

/** Gee版本号 */
extern NSString * const lsqGeeVersion;

/** Tusdk 组件 V1版本 */
@interface TuSDKGeeV1 : NSObject
/**
 *  自定义系统相册组件
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPAlbumComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return 自定义系统相册组件
 */
+ (TuSDKCPAlbumComponent *)albumCommponentWithController:(UIViewController *)controller
                                           callbackBlock:(TuSDKCPComponentBlock)block;

/**
 *  多功能相册组件，选择一张照片
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPAlbumMultipleComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return 多功能相册组件
 */
+ (TuSDKCPAlbumMultipleComponent *)albumMultipleCommponentWithController:(UIViewController *)controller
                                                           callbackBlock:(TuSDKCPComponentBlock)block;
/**
 *  多功能相册组件，选择多张照片
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPAlbumMultipleComponent.html
 *
 *  @param controller   来源控制器
 *  @param block        组件回调结果
 *  @param maxSelection 最大选择数目
 *
 *  @return 多功能相册组件
 */
+ (TuSDKCPAlbumMultipleComponent *)albumMultipleCommponentWithController:(UIViewController *)controller
                                                           callbackBlock:(TuSDKCPComponentBlock)block
                                                      maxSelectionNumber:(NSUInteger)maxSelection;

/**
 *  获取头像设置组件
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPAvatarComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return 头像设置组件
 */
+ (TuSDKCPAvatarComponent *)avatarCommponentWithController:(UIViewController *)controller
                                             callbackBlock:(TuSDKCPComponentBlock)block;

/**
 *  获取图片编辑组件
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPPhotoEditComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return 图片编辑组件
 */
+ (TuSDKCPPhotoEditComponent *)photoEditCommponentWithController:(UIViewController *)controller
                                                   callbackBlock:(TuSDKCPComponentBlock)block;

/**
 *  获取多功能图像编辑组件
 *  @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPPhotoEditMultipleComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return 多功能图像编辑组件
 */
+ (TuSDKCPPhotoEditMultipleComponent *)photoEditMultipleWithController:(UIViewController *)controller
                                                         callbackBlock:(TuSDKCPComponentBlock)block;
@end
