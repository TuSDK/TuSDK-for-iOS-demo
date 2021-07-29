//
//  TuTSDeviceSettings.h
//  TuSDK
//
//  Created by Clear Hu on 15/3/4.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  设备权限设置类型
 */
typedef NS_ENUM(NSInteger, TuDeviceSettingsType)
{
    /**
     *  未知类型
     */
    TuDeviceSettingsUnknow,
    /**
     *  设置照片权限
     */
    TuDeviceSettingsPhoto,
    /**
     * 设置相机权限
     */
    TuDeviceSettingsCamera,
    /**
     * 设置定位权限
     */
    TuDeviceSettingsLocation,
};

/**
 *  设备权限设置
 *
 *  @param type        设备权限设置类型
 *  @param openSetting 是否开启权限设置
 */
typedef void (^TuTSDeviceSettingsBlock)(TuDeviceSettingsType type, BOOL openSetting);

/**
 *  设备权限设置
 */
@interface TuTSDeviceSettings : NSObject
/**
 *  检查设备权限
 *
 *  @param controller UIViewController
 *  @param type       设备权限设置类型
 *  @param completed  设备权限设置
 */
+ (void)checkAllowWithController:(UIViewController *)controller type:(TuDeviceSettingsType)type completed:(TuTSDeviceSettingsBlock)completed;
@end
