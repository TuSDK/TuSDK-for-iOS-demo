//
//  TuSDKFilterOption.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/26.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GPUImage/GPUImage.h>
#import "TuSDKDataJson.h"

/**
 *  滤镜配置选项
 */
@interface TuSDKFilterOption : TuSDKDataJson

/**
 * 滤镜ID
 */
@property (nonatomic)uint64_t filterId;

/**
 * 分组ID
 */
@property (nonatomic) uint64_t groupId;

/**
 * 滤镜代号
 */
@property (nonatomic, retain) NSString *code;

/**
 *  滤镜名称
 */
@property (nonatomic, retain) NSString *name;

/**
 * 滤镜封面
 */
@property (nonatomic, retain) NSString *thumb;

/**
 * 滤镜封面名称
 */
@property (nonatomic, retain) NSString *thumbKey;

/**
 * 滤镜类型
 */
@property (nonatomic) NSUInteger filterType;

/**
 * 滤镜颜色
 */
@property (nonatomic, retain) NSString *color;

/**
 * 滤镜渲染名称
 */
@property (nonatomic, retain) NSArray *shaders;

/**
 *  滤镜材质列表
 */
@property (nonatomic, retain) NSArray *textures;

/**
 *  材质需要保持和输入图片相同的大小与方向
 */
@property (nonatomic) BOOL texturesKeepInput;

/**
 * 是否允许调节参数
 */
@property (nonatomic) BOOL canDefinition;

/**
 * 加密级别
 */
@property (nonatomic) NSUInteger encryptType;

/**
 *  滤镜配置参数
 */
@property (nonatomic, retain) NSDictionary *args;

/**
 *  滤镜版本
 */
@property (nonatomic) NSUInteger version;

/**
 * 是否为内置滤镜
 */
@property (nonatomic) BOOL isInternal;

/**
 * 复制滤镜配置选项
 *
 * @return
 */
- (TuSDKFilterOption *)copy;

/**
 * 获取滤镜实例
 *
 * @return
 */
- (GPUImageOutput <GPUImageInput> *)getFilter;

/**
 *  获取语言资源名称
 *
 *  @return 获取语言资源名称
 */
- (NSString *)nameKey;

/**
 *  获取预览图名称
 *
 *  @return 获取预览图名称
 */
- (NSString *)thumbKey;
@end
