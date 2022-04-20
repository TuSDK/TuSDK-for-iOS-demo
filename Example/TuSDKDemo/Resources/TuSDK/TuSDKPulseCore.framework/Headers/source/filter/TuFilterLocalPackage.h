//
//  TuFilterLocalPackage.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/26.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import "TuFilterOption.h"
#import <TuSDKPulseCore/TUCEnum.h>
#import "TuFilterGroup.h"
@class TuNKDownloadItem;

/**
 *  默认滤镜代号
 */
extern NSString * const TTNormalFilterCode;

#pragma mark - TuFilterLocalPackageDelegate
@class TuFilterLocalPackage;

/**
 *  本地滤镜包委托
 */
@protocol TuFilterLocalPackageDelegate <NSObject>

/**
 *  本地滤镜包下载状态改变
 *
 *  @param manager 本地滤镜包
 *  @param item    下载对象
 *  @param status  下载状态
 */
- (void)filterManager:(TuFilterLocalPackage *)manager
                 item:(TuNKDownloadItem *)item
        changedStatus:(TuDownloadTaskStatus)status;
@end

#pragma mark - TuFilterLocalPackage
/** 原生滤镜配置*/
@interface TuFilterLocalPackage : NSObject
/** 原生滤镜代号列表*/
@property (nonatomic, readonly) NSArray *codes;
/** 滤镜分组列表*/
@property (nonatomic, readonly) NSArray *groups;
/**直播滤镜分组列表*/
@property (nonatomic, readonly) NSArray *liveGroups;
/** 已下载文件列表 */
@property (nonatomic, readonly) NSArray* downloadItems;

/**
 *  原生滤镜配置
 *
 *  @return package 原生滤镜配置
 */
+ (instancetype)package;

// 加载配置信息
- (void)loadConfig;

/**
 *  添加本地滤镜包委托
 *
 *  @param delegate 本地滤镜包委托
 */
- (void)appenDelegate:(id<TuFilterLocalPackageDelegate>)delegate;

/**
 *  删除本地滤镜包委托
 *
 *  @param delegate 本地滤镜包委托
 */
- (void)removeDelegate:(id<TuFilterLocalPackageDelegate>)delegate;

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
 *  @return option 滤镜选项配置 (如果未找到对应选项，返回默认滤镜)
 */
- (TuFilterOption *)optionWithCode:(NSString *)code;

/**
 *  验证滤镜代号
 *
 *  @param codes 滤镜代号列表
 *
 *  @return codes 滤镜名称
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
 *  @return groupID 滤镜组名称键
 */
- (NSString *)groupNameKeyWithGroupID:(uint64_t)groupID;

/**
 *  滤镜组类型
 *
 *  @param groupID 滤镜组ID
 *
 *  @return groupID 滤镜组类型
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
- (NSArray<TuFilterGroup *> *)groupsByAtionScen:(TuAtionScenSDKType)ationScen;

/**
 *  获取滤镜组默认滤镜代号
 *
 *  @param group 滤镜分组
 *
 *  @return group 滤镜组默认滤镜代号
 */
- (NSString *)defaultFilterCodeWithGroup:(TuFilterGroup *)group;

/**
 *  加载材质列表
 *
 *  @param code 滤镜代号
 *
 *  @return code 材质列表
 */
- (NSArray *)loadTexturesWithCode:(NSString *)code;

/**
 *  加载材质列表
 *
 *  @param codes 滤镜代号列表
 *
 *  @return codes 材质列表
 */
- (NSArray *)loadInternalTextures:(NSArray *)codes;

/**
 *  通过选项配置初始化滤镜
 *
 *  @param option 滤镜选项配置
 *
 *  @return option 获取滤镜实例
 */
//- (SLGPUImageOutput <SLGPUImageInput> *)filterWithOption:(TuFilterOption *)option;
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
 *  取消加载图片
 *
 *  @param imageView 图片视图
 */
- (void)cancelLoadImage:(UIImageView *)imageView;

/**
 *  下载贴纸
 *
 *  @param idt 贴纸ID
 *  @param key 下载SN
 *  @param fileId 文件ID
 */
- (void)downloadWithIdt:(uint64_t)idt key:(NSString *)key fileId:(NSString *)fileId;

/**
 *  取消下载贴纸
 *
 *  @param idt 贴纸ID
 */
- (void)cancelDownloadWithIdt:(uint64_t)idt;

/**
 *  删除下载贴纸
 *
 *  @param idt 贴纸ID
 */
- (void)removeDownloadWithIdt:(uint64_t)idt;

/**
 *  获取所有json数据
 *
 *  @return json 数据
 */
- (NSString *)jsonAllData;
@end


#pragma mark 本地滤镜组

@interface TuFilterLocalPackage (LocalFilter)

/**
 将本地滤镜添加到 Package
 
 @param filePath 本地滤镜组文件路径
 @param groupFiltersType 滤镜类型, see TuFilterGroup.h 0: 普通滤镜, 1: 特效滤镜, 2: 粒子特效滤镜, 3: 漫画特效滤镜
 @return true/false
 @since 3.4.5
 */
- (BOOL)addFilterGroupFile:(NSString *)filePath groupFiltersType:(NSUInteger)groupFiltersType;

@end
