//
//  TuSDKStickerAdapter.h
//  TuSDK
//
//  Created by Clear Hu on 15/5/21.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKNKDownloadAdapter.h"
#import "TuSDKConfig.h"

/**
 *  贴纸适配器
 */
@interface TuSDKStickerAdapter : TuSDKNKDownloadAdapter
/**
 *  分类列表
 */
@property (nonatomic, readonly) NSArray *categories;

/**
 *  是否已初始化
 */
@property (nonatomic, readonly) BOOL isInited;

/**
 *  本地贴纸包
 *
 *  @param config Sdk配置
 *
 *  @return 本地贴纸包
 */
+ (instancetype)initWithConfig:(TuSDKConfig *)config;

/**
 *  加载贴纸预览图片
 *
 *  @param sticker   贴纸数据
 *  @param imageView 图片视图
 */
- (void)loadThumbWithSticker:(TuSDKPFSticker *)sticker imageView:(UIImageView *)imageView;

/**
 *  加载贴纸数据
 *
 *  @param sticker  贴纸数据对象
 *
 *  @return  是否加载贴纸数据对象
 */
- (BOOL)loadStickerData:(TuSDKPFSticker *)sticker;

/**
 *  获取分类数据
 *
 *  @param idt 分类ID
 *
 *  @return 分类数据
 */
- (TuSDKPFStickerCategory *)categorieWithIdt:(uint64_t)idt;

/**
 *  获取贴纸数据对象
 *
 *  @param idt 贴纸数据对象ID
 *
 *  @return 贴纸数据对象
 */
- (TuSDKPFSticker *)stickerWithIdt:(uint64_t)idt;

/**
 *  分类列表
 *
 *  @param categories 已选中分类列表 (如果为空返回所有分类)
 *
 *  @return 分类列表
 */
- (NSArray *)categoriesWithCategories:(NSArray *)categories;
@end
