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
#import "TuSDKPFBrushGroup.h"

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

/**
 *  render filter thumb
 */
@property (nonatomic) BOOL renderFilterThumb;

/**
 *  smudge
 */
@property (nonatomic) BOOL smudgeEnabled;

/**
 *  smudge and filter
 */
@property (nonatomic) BOOL wipeFilterEnabled;

/**
 *  beauty Level
 */
@property (nonatomic) NSInteger beautyLevel;

/**
 *  userType
 */
@property (nonatomic) NSInteger userType;

/**
 *  video record
 */
@property (nonatomic) BOOL videoRecordEnabled;

/**
 *  config video duration
 */
@property (nonatomic) BOOL videoDurationEnabled;

/**
 *  video streaming
 */
@property (nonatomic) BOOL videoStreamEnabled;

/**
 *  video edit
 */
@property (nonatomic) BOOL videoEditEnabled;

/**
 *  face Local Marks
 */
@property (nonatomic) NSInteger faceLocalMarks;

/**
 *  face Local Image Support
 */
@property (nonatomic) BOOL faceLocalImageSupport;

/**
 *  face Local Video Support
 */
@property (nonatomic) BOOL faceLocalVideoSupport;

/**
 *  Filter API
 */
@property (nonatomic) BOOL filterAPIEnabled;

/**
 *  Filter list which could be used by FilterAPI
 */
@property (nonatomic) NSArray *filterAPIList;

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
 * 笔刷配置列表
 */
@property (nonatomic, retain) NSArray *brushGroups;

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