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
#import "TuSDKAOFile.h"

/**
 *  滤镜配置选项
 */
@interface TuSDKFilterOption : TuSDKDataJson

/**
 * 滤镜ID
 */
@property (nonatomic)uint64_t filterId;

/**
 *  滤镜名称
 */
@property (nonatomic, retain) NSString *name;

/**
 * 滤镜类型
 */
@property (nonatomic) NSUInteger filterType;

/**
 * 滤镜配置参数
 */
@property (nonatomic, retain) NSArray *configs;

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
 * 是否为内置滤镜
 */
@property (nonatomic) BOOL isInternal;

/**
 *  SDK文件
 */
@property (nonatomic, retain) TuSDKAOFile *sdkFile;

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
 *  获取材质图片
 *
 *  @param name 材质图片名称
 *
 *  @return 材质图片
 */
- (UIImage *)textureImageWithName:(NSString *)name;
@end
