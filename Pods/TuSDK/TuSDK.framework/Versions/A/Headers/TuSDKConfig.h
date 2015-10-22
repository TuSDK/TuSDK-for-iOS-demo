//
//  TuSDKConfig.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/31.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TuSDKFilterGroup.h"
#import "TuSDKPFStickerCategory.h"

#pragma mark - TuSDKPermission
/**
 *  SDK Permission
 */
@interface TuSDKPermission : TuSDKDataJson
/**
 *  level
 */
@property (nonatomic) NSInteger level;
/**
 *  no Power
 */
@property (nonatomic) BOOL noPower;
/**
 *  service Expire
 */
@property (nonatomic, retain) NSDate *serviceExpire;
/**
 *  resolution
 */
@property (nonatomic) NSInteger resolution;

/**
 * sticker Use Count
 */
@property (nonatomic) NSInteger stickerUseCount;

/**
 * local filter Count
 */
@property (nonatomic) NSInteger localFilterCount;

/**
 *  local sticker Count
 */
@property (nonatomic) NSInteger localStickerCount;
@end

#pragma mark - TuSDKConfig
/**
 *  Sdk配置
 */
@interface TuSDKConfig : TuSDKDataJson
/**
 *  滤镜分组列表
 */
@property (nonatomic, retain) NSArray *filterGroups;

/**
 * 贴纸分类
 */
@property (nonatomic, retain) NSArray *stickerCategories;

/**
 * 贴纸配置列表
 */
@property (nonatomic, retain) NSArray *stickerGroups;

/**
 *  配置信息
 */
@property (nonatomic, copy) NSString * master;

/**
 *  配置信息列表
 */
@property (nonatomic, copy) NSDictionary * masters;

/**
 *  SDK Permission
 */
@property (nonatomic, retain) TuSDKPermission *permission;
@end