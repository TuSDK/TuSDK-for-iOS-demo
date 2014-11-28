//
//  TuSDKFilterOption.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/26.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  滤镜类型
 */
typedef NS_ENUM(NSInteger, lsqFilterType)
{
    /**
     *  未知
     */
    lsqFilterTypeUnknow = 0,
    /**
     *  内部集成
     */
    lsqFilterTypeIntegrate = 1
};

/**
 *  滤镜配置选项
 */
@interface TuSDKFilterOption : NSObject

/**
 *  滤镜名称
 */
@property (nonatomic, retain) NSString *name;

/**
 *  滤镜类名
 */
@property (nonatomic, retain) NSString *clazzName;

/**
 *  滤镜材质列表
 */
@property (nonatomic, retain) NSArray *textures;

/**
 *  滤镜类型
 */
@property (nonatomic) lsqFilterType type;

/**
 *  快速创建选项
 *
 *  @param name     滤镜名称
 *  @param clazz    滤镜类名
 *  @param textures 滤镜材质列表
 *  @param type     滤镜类型
 *
 *  @return 滤镜配置选项
 */
+ (instancetype) buildWithName:(NSString *)name clazz:(NSString *)clazz textures:(NSArray *)textures type:(lsqFilterType)type;

/**
 *  快速创建选项 - 内部集成
 *
 *  @param name     滤镜名称
 *  @param clazz    滤镜类名
 *  @param textures 滤镜材质列表
 *
 *  @return 滤镜配置选项
 */
+ (instancetype) buildIntegrateWithName:(NSString *)name clazz:(NSString *)clazz textures:(NSArray *)textures;
@end
