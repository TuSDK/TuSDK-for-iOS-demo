//
//  TuFilterAdapter.h
//  TuSDK
//
//  Created by Clear Hu on 15/5/21.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "network/TuNKDownloadAdapter.h"
#import "core/TuFilterOption.h"
#import "core/TuFilterGroup.h"


/**滤镜适配器*/
@interface TuFilterAdapter : TuNKDownloadAdapter
/**原生滤镜代号列表*/
@property (nonatomic, readonly) NSArray *codes;
/**滤镜分组列表*/
@property (nonatomic, readonly) NSArray *groups;
/**直播滤镜分组列表*/
@property (nonatomic, readonly) NSArray *liveGroups;


#pragma mark - datas
// 加载配置信息
- (void)loadConfig;

/**
 *  默认滤镜选项
 *
 *  @return normalOption 默认滤镜选项
 */
- (TuFilterOption *)normalOption;

/**
 *  获取滤镜选项配置
 *
 *  @param code 滤镜代号
 *
 *  @return filterOption 滤镜选项配置 (如果未找到对应选项，返回默认滤镜)
 */
- (TuFilterOption *)optionWithCode:(NSString *)code;

/**
 *  验证滤镜代号
 *
 *  @param codes 滤镜代号列表
 *
 *  @return  codes 滤镜名称
 */
- (NSArray *)verifyCodes:(NSArray *)codes;

/**
 *  获取指定名称的滤镜列表
 *
 *  @param codes 滤镜代号列表
 *
 *  @return codes 滤镜列表
 */
- (NSArray *)optionsWithCodes:(NSArray *)codes;

/**
 *  获取滤镜组
 *
 *  @param group 滤镜分组
 *
 *  @return group 滤镜列表
 */
- (NSArray *)optionsWithGroup:(TuFilterGroup *)group;

/**
 *  滤镜组名称键
 *
 *  @param groupID 滤镜组ID
 *
 *  @return groupNameKey 滤镜组名称键
 */
- (NSString *)groupNameKeyWithGroupID:(uint64_t)groupID;

/**
 *  滤镜组类型
 *
 *  @param groupID 滤镜组ID
 *
 *  @return groupType 滤镜组类型
 */
- (NSUInteger)groupTypeWithGroupID:(uint64_t)groupID;

/**
 *  分组中的滤镜类型
 *
 *  @param groupID 滤镜组ID
 *
 *  @return 滤镜类型
 */
- (NSUInteger)groupFilterTypeWithGroupID:(uint64_t)groupID;


/**
 根据滤镜组id获取滤镜分组

 @param groupID 滤镜组id
 @return TuFilterGroup
 */
- (TuFilterGroup *)groupWithGroupID:(uint64_t)groupID;

/**
 根据 SDK 类型获取滤镜分组

 @param ationScen SDK 类型获取滤镜分组
 @return 分组列表
 */
- (NSArray<TuFilterGroup *> *)groupsByAtionScen:(lsqAtionScenSDKType)ationScen;

/**
 *  获取滤镜组默认滤镜代号
 *
 *  @param group 滤镜分组
 *
 *  @return defaultFilterCode 滤镜组默认滤镜代号
 */
- (NSString *)defaultFilterCodeWithGroup:(TuFilterGroup *)group;

#pragma mark - imageLoad
/**
 *  加载滤镜组预览图
 *
 *  @param view 图片视图
 *  @param group 滤镜分组
 */
- (void)loadGroupThumbWithImageView:(UIImageView *)view group:(TuFilterGroup *)group;

/**
 *  加载滤镜组默认滤镜预览图
 *
 *  @param view 图片视图
 *  @param group 滤镜分组
 */
- (void)loadGroupDefaultFilterThumbWithImageView:(UIImageView *)view group:(TuFilterGroup *)group;

/**
 *  加载滤镜组默认滤镜预览图
 *
 *  @param view 图片视图
 *  @param option 滤镜配置选项
 */
- (void)loadFilterThumbWithImageView:(UIImageView *)view option:(TuFilterOption *)option;


/**
 添加本地滤镜组

 @param filePath 本地滤镜组文件路径
 @param groupFiltersType 滤镜类型, see TuFilterGroup.h 0: 普通滤镜, 1: 特效滤镜, 2: 粒子特效滤镜, 3: 漫画特效滤镜
 @return 是否加载成功
 @since v3.4.5
 */
- (BOOL)appendFilterGroupWithFilePath:(NSString *)filePath groupFiltersType:(NSUInteger)groupFiltersType;

/** 编译Shader*/
+ (NSString *)compileShader:(NSString *)shaderString type:(uint32_t)type shaders:(int *)shaders;
@end

