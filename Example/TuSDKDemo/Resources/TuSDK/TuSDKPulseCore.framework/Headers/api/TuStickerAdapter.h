//
//  TuStickerAdapter.h
//  TuSDK
//
//  Created by Clear Hu on 15/5/21.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "network/TuNKDownloadAdapter.h"
#import "components/widgets/sticker/TuStickerGroup.h"
#import "components/widgets/sticker/TuStickerCategory.h"

/**
 *  贴纸适配器
 */
@interface TuStickerAdapter : TuNKDownloadAdapter
/**
 *  分类列表
 */
@property (nonatomic, readonly) NSArray *categories;

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
 *  获取分类数据
 *
 *  @param idt 分类ID
 *
 *  @return 分类数据
 */
- (TuStickerCategory *)categorieWithIdt:(uint64_t)idt;


/**
 *  获取贴纸组对象
 *
 *  @param idt 贴纸组对象ID
 *
 *  @return 贴纸组对象
 */
- (TuStickerGroup*) groupWithGroupID:(uint64_t)idt;

/**
 *  获取贴纸数据对象
 *
 *  @param idt 贴纸数据对象ID
 *
 *  @return 贴纸数据对象
 */
- (TuSticker *)stickerWithIdt:(uint64_t)idt;

/**
 *  分类列表
 *
 *  @param categories 已选中分类列表 (如果为空返回所有分类)
 *
 *  @return 分类列表
 */
- (NSArray *)categoriesWithCategories:(NSArray *)categories;

/**
 *  获取分类下的贴纸组数据
 *
 *  @param idt 分类ID
 *
 *  @return 分类数据
 */
- (NSArray<TuStickerGroup*> *)getGroupListWithCategoryType:(lsqStickerCategoryType)type;

/**
 *  是否存在包ID
 *
 *  @param groupId 包ID
 *
 *  @return 是否存在包ID
 */
- (BOOL)containsWithGroupId:(uint64_t)groupId;


/**
 将本地贴纸添加到 Package
 
 @param filePath 本地贴纸组文件
 @return true/false
 @since 3.0
 */
- (BOOL)addStickerGroupFile:(NSString *)filePath;

@end
