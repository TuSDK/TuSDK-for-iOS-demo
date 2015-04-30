//
//  TuSDKConfig.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/31.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TuSDKFilterGroup.h"
#import "TuSDKPFStickerCategory.h"

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
@end


