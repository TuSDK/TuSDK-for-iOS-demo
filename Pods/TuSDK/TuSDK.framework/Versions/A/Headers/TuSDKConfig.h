//
//  TuSDKConfig.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/31.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TuSDKDataJson.h"
#import "TuSDKFilterGroup.h"

#pragma mark - TuSDKConfigSticker
/**
 *  贴纸配置
 */
@interface TuSDKConfigSticker : TuSDKDataJson
/**
 *  文件路径
 */
@property (nonatomic, retain) NSString *file;

/**
 *  贴纸分类ID
 */
@property (nonatomic)uint64_t categoryId;
@end

#pragma mark - TuSDKConfig
/**
 *  Sdk配置
 */
@interface TuSDKConfig : TuSDKDataJson

/**
 *  滤镜版本
 */
@property (nonatomic) CGFloat filterVersion;

/**
 *  滤镜分组列表
 */
@property (nonatomic, retain) NSArray *filterGroups;

/**
 * 贴纸配置列表
 */
@property (nonatomic, retain) NSArray *stickers;
@end


