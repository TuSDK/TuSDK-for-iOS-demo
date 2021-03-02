//
//  TuStickerLocalPackage.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/7.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulseCore/components/widgets/sticker/TuStickerCategory.h>
#import <TuSDKPulseCore/network/TuNKDownloadItem.h>

@class TuStickerLocalPackage;

/**
 *  本地贴纸包委托
 */
@protocol TuStickerLocalPackageDelegate <NSObject>

/**
 *  本地贴纸包下载状态改变
 *
 *  @param manager 本地贴纸包
 *  @param item    下载对象
 *  @param status  下载状态
 */
- (void)stickerManager:(TuStickerLocalPackage *)manager
                  item:(TuNKDownloadItem *)item
         changedStatus:(lsqDownloadTaskStatus)status;
@end

/**本地贴纸包*/
@interface TuStickerLocalPackage : NSObject
/**分类列表*/
@property (nonatomic, readonly) NSArray *categories;
/** 已下载文件列表 */
@property (nonatomic, readonly) NSArray* downloadItems;

/** 本地贴纸包 */
+ (instancetype)package;

// 加载配置信息
- (void)loadConfig;

/**
 *  加载贴纸预览图片
 *
 *  @param sticker   贴纸数据
 *  @param imageView 图片视图
 */
- (void)loadThumbWithSticker:(TuSticker *)sticker imageView:(UIImageView *)imageView;

/**
 *  加载贴纸组预览图片
 *
 *  @param stickerGroup   贴纸数据
 *  @param imageView      图片视图
 */
- (void)loadThumbWithStickerGroup:(TuStickerGroup *)stickerGroup imageView:(UIImageView *)imageView;

/**
 *  取消加载图片
 *
 *  @param imageView 图片视图
 */
- (void)cancelLoadImage:(UIImageView *)imageView;

/**
 *  加载贴纸数据
 *
 *  @param sticker  贴纸数据对象
 *
 *  @return  是否加载贴纸数据对象
 */
- (BOOL)loadStickerData:(TuSticker *)sticker;

/**
 *  加载智能贴纸中包含的素材
 *
 *  @param sticker  贴纸数据对象
 *  @param resName  元素名
 *
 *  @return  是否加载贴纸数据对象
 */
- (UIImage *)loadSmartSticker:(TuSticker *)sticker withResName:(NSString *)resName;

/**
 *  添加本地贴纸包委托
 *
 *  @param delegate 本地贴纸包委托
 */
- (void)appenDelegate:(id<TuStickerLocalPackageDelegate>)delegate;

/**
 *  删除本地贴纸包委托
 *
 *  @param delegate 本地贴纸包委托
 */
- (void)removeDelegate:(id<TuStickerLocalPackageDelegate>)delegate;

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
 *  是否正在下载某个资源
 
 *  @param idt  下载对象ID
 *
 *  @return true: 下载中
 */
- (BOOL)isDownloadingWithIdt:(uint64_t)idt;

/**
 *  获取分类数据
 *
 *  @param idt 分类ID
 *
 *  @return 分类数据
 */
- (TuStickerCategory *)categorieWithIdt:(uint64_t)idt;

/**
 *  获取贴纸数据对象
 *
 *  @param idt 贴纸数据对象ID
 *
 *  @return 贴纸数据对象
 */
- (TuSticker *)stickerWithIdt:(uint64_t)idt;
- (TuStickerGroup*) groupWithGroupID:(uint64_t)idt;

/**
 *  分类列表
 *
 *  @param categories 已选中分类列表 (如果为空返回所有分类)
 *
 *  @return 分类列表
 */
- (NSArray *)categoriesWithCategories:(NSArray *)categories;

/**
 获取所有的动态贴纸组列表

 @return 贴纸组列表
 */
- (NSArray<TuStickerGroup *> *)getSmartStickerGroups;

/**
 获取动态贴纸组列表

 @param requireFaceFeature 是否包含依赖人脸特征的贴纸
 @return 贴纸组列表
 */
- (NSArray<TuStickerGroup *> *)getSmartStickerGroupsWithFaceFeature:(BOOL)requireFaceFeature;

/**
 *  是否存在包ID
 *
 *  @param groupId 包ID
 *
 *  @return 是否存在包ID
 */
- (BOOL)containsWithGroupId:(uint64_t)groupId;

/**
 *  获取所有json数据
 *
 *  @return json数据
 */
- (NSString *)jsonAllData;

@end

#pragma mark 本地贴纸组

@interface TuStickerLocalPackage (LocalSticker)

/**
 将本地贴纸添加到 Package

 @param filePath 本地贴纸组文件
 @param master master
 @return true/false
 @since 3.0
 */
- (BOOL)addStickerGroupFile:(NSString *)filePath;

@end
