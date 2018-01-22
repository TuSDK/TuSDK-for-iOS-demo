//
//  TuSDKGeeV2.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKGeeV2Import.h"
#import "TuSDKGeeV2Theme.h"
#import "GeeV2PFCameraOptions.h"
#import "GeeV2CPAlbumMultipleComponent.h"
#import "GeeV2CPPhotoEditMultipleComponent.h"
#import "GeeV2CPFocusTouchView.h"

/** Gee版本号 */
extern NSString * const lsqGeeV2Version;

/** Tusdk 组件 V2版本 */
@interface TuSDKGeeV2 : NSObject


/**
 *  多功能相册组件，选择多张照片
 *  @see-https://tutucloud.com/docs/ios/api-geev2/Classes/GeeV2CPAlbumMultipleComponent.html
 *
 *  @param controller   来源控制器
 *  @param block        组件回调结果
 *  @param openCameraCallback 打开相机回调结果
 *  @param maxSelection 最大选择数目
 *
 *  @return component 多功能相册组件
 */
+ (GeeV2CPAlbumMultipleComponent *)albumMultipleCommponentWithController:(UIViewController *)controller
                                                           callbackBlock:(TuSDKCPComponentBlock)block
                                                           openCameraCallback:(GeeV2CPAlbumMultipleOpenCameraBlock)openCameraCallback
                                                      maxSelectionNumber:(NSUInteger)maxSelection;

/**
 *  获取多功能图像编辑组件
 *  @see-https://tutucloud.com/docs/ios/api-geev2/Classes/GeeV2CPPhotoEditMultipleComponent.html
 *
 *  @param controller 来源控制器
 *  @param block      组件回调结果
 *
 *  @return component 多功能图像编辑组件
 */
+ (GeeV2CPPhotoEditMultipleComponent *)photoEditMultipleWithController:(UIViewController *)controller
                                                         callbackBlock:(GeeV2CPComponentBlock)block;
@end
