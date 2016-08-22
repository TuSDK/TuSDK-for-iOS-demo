//
//  TuSDKTSDevice+Extend.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/28.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - Hardware
extern NSString * const kDevice;
// iPhone
extern NSString * const kDeviceiPhone;
// iPhone 1G
extern NSString * const kDeviceiPhone1G;
// iPhone 3G
extern NSString * const kDeviceiPhone3G;
// iPhone 3GS
extern NSString * const kDeviceiPhone3GS;
// iPhone 4
extern NSString * const kDeviceiPhone4;
// iPhone 4S
extern NSString * const kDeviceiPhone4S;
// iPhone 5
extern NSString * const kDeviceiPhone5;
// iPhone 5S
extern NSString * const kDeviceiPhone5S;

// iPod
extern NSString * const kDeviceiPod;
// iPod touch 1G, N45
extern NSString * const kDeviceiPod1G;
// iPod touch 2G, N72
extern NSString * const kDeviceiPod2G;
// iPod touch 3G, N18
extern NSString * const kDeviceiPod3G;
// iPod touch 4G, N80
extern NSString * const kDeviceiPod4G;

// iPad
extern NSString * const kDeviceiPad;
// iPad 1G
extern NSString * const kDeviceiPad1G;
// iPad 2G
extern NSString * const kDeviceiPad2G;
// iPad 3G
extern NSString * const kDeviceiPad3G;
// iPad 4G
extern NSString * const kDeviceiPad4G;

#pragma mark - TuSDKTSDeviceExtend
/**
 *  硬件设备扩展
 */
@interface UIDevice(TuSDKTSDeviceExtend)
/**
 *  设备名称
 *
 *  @return 设备名称 e.g. "My iPhone"
 */
+ (NSString *)lsqName;

/**
 *  系统名称
 *
 *  @return 系统名称 e.g. @"iOS"
 */
+ (NSString *)lsqSystemName;

/**
 *  系统版本号
 *
 *  @return 系统版本号 e.g. @"4.0"
 */
+ (CGFloat)lsqSystemFloatVersion;

/**
 *  系统版本号
 *
 *  @return 系统版本号 e.g. @"4.0.2"
 */
+ (NSString *)lsqSystemVersion;

/**
 *  硬件型号
 *
 *  @return 硬件型号 e.g. @"iPhone", @"iPod touch"
 */
+ (NSString *)lsqModel;

/**
 *  本地化硬件型号
 *
 *  @return 本地化硬件型号
 */
+ (NSString *)lsqLocalizedModel;

/**
 *  获取应用名称
 *
 *  @return 应用名称
 */
+ (NSString *)lsqAppName;

/**
 *  获取应用版本
 *
 *  @return 应用版本
 */
+ (NSString *)lsqAppVersion;

/**
 *  应用编译版本
 *
 *  @return 应用编译版本
 */
+ (NSString *)lsqAppBuild;

/**
 *  应用 Bundle Identifier
 *
 *  @return 应用 Bundle Identifier
 */
+ (NSString *)lsqAppIdentifier;

/**
 *  开启应用设置页面
 */
+ (void)lsqOpenAppSettings  NS_AVAILABLE_IOS(8_0);

/**
 *  获取WIFI IP地址
 *
 *  @return WIFI IP地址
 */
+ (NSString *)lsqGetWifiIpAddress;

/**
 *  获取文件大小 BYTE
 *
 *  @param filePath 文件路径
 *
 *  @return 文件大小 BYTE
 */
+ (long long)lsqFileSizeAtPath:(NSString *)filePath;

/**
 *  获取当前应用可用内存(单位：MB）
 *
 *  @return 当前应用可用内存(单位：MB）
 */
+ (double)lsqSpaceMemory;

/**
 *  获取当前应用所占用的内存（单位：MB）
 *
 *  @return 当前应用所占用的内存（单位：MB）
 */
+ (double)lsqUsedMemory;

/**
 *  打印内存使用情况
 *
 *  @param tag 标签
 */
+ (void)lsqLogMemory:(NSString *)tag;

/**
 *  硬件性能
 *
 *  @return 2-5
 */
+ (NSUInteger)lsqPerformance;

/**
 *  Universally Unique Identifier 通用唯一识别码
 *
 *  @return 通用唯一识别码
 */
+ (NSString*)lsqUuid;

/**
 *  硬件名称
 *
 *  @return 硬件名称
 */
- (NSString *)lsqPlatform;

/**
 *  是否为指定设备
 *
 *  @param device 设备名称
 *
 *  @return 是否为指定设备
 */
- (BOOL)lsqIsDevice:(NSString *)device;

/**
 *  硬件类型
 *
 *  @return 硬件类型
 */
- (NSString *)lsqHwmodel;

/**
 *  CPU频率
 *
 *  @return CPU频率
 */
- (NSUInteger)lsqCpuFrequency;

/**
 *  系统总线频率
 *
 *  @return 系统总线频率
 */
- (NSUInteger)lsqBusFrequency;

/**
 *  CPU核心数
 *
 *  @return CPU核心数
 */
- (NSUInteger)lsqCpuCount;

/**
 *  合计内存
 *
 *  @return 合计内存
 */
- (NSUInteger)lsqTotalMemory;

/**
 *  已使用内存
 *
 *  @return 已使用内存
 */
- (NSUInteger)lsqUserMemory;

/**
 *  空闲内存
 *
 *  @return 空闲内存
 */
- (NSUInteger)lsqSapceMemory;

/**
 *  总存储空间
 *
 *  @return 总存储空间
 */
- (NSNumber *)lsqTotalDiskSpace;

/**
 *  可使用存储空间
 *
 *  @return 可使用存储空间
 */
- (NSNumber *)lsqFreeDiskSpace;

/**
 *  网络Mac地址
 *
 *  @return 网络Mac地址
 */
- (NSString *)lsqMacaddress;

/**
 *  根据设备方向获取旋转角度
 *
 *  @param orient 设备旋转方向
 *
 *  @return 旋转角度
 */
+ (CGFloat)lsqGetRotationByOrient:(UIDeviceOrientation)orient;
@end
