//
//  TuSDKStickerCategory.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuStickerGroup.h"

/**
 *  贴纸分类扩展类型
 */
typedef NS_ENUM(NSInteger, TuStickerCategoryExtendType)
{
    /**
     *  未知扩展
     */
    TuStickerCategoryExtendUnknow,
    /**
     * 全部
     */
    TuStickerCategoryExtendAll = 1,
    /**
     * 常用
     */
    TuStickerCategoryExtendHistory = 2,
};

/**
 *  贴纸分类类型
 */
typedef NS_ENUM(NSInteger, TuStickerCategoryType)
{
    /**
     * 智能贴纸
     */
    TuStickerCategorySmart = 0,
    /**
     * 普通贴纸
     */
    TuStickerCategoryOther = 1,
};

/**
 *  贴纸分类
 */
@interface TuStickerCategory : TuDataJson
/**
 * 贴纸分类ID
 */
@property (nonatomic) uint64_t idt;

/**
 * 贴纸分类名称
 */
@property (nonatomic, copy) NSString *name;

/**
 * 贴纸数据列表
 */
@property (nonatomic, retain) NSArray *datas;

/**
 *  贴纸分类扩展类型
 */
@property (nonatomic) TuStickerCategoryExtendType extendType;

/**
 *  贴纸分类
 *
 *  @return 贴纸分类
 */
+ (instancetype)category;

/**
 *  贴纸分类
 *
 *  @return 贴纸分类
 */
+ (instancetype)categoryWithIdt:(uint64_t)idt title:(NSString *)title;

/**
 * 添加分类数据
 *
 * @param group 贴纸包
 */
- (void)appendGroup:(TuStickerGroup *) group;

/**
 *  插入分类数据到第一个
 *
 *  @param group 贴纸包
 */
- (void)insertFirstWithGroup:(TuStickerGroup *) group;

/**
 *  删除一个贴纸包
 *
 *  @param idt 贴纸包ID
 *
 *  @return 被删除的贴纸包
 */
- (TuStickerGroup *)removeGroupWithID:(uint64_t)idt;

/**
 *  复制数据
 *
 *  @return 贴纸分类
 */
- (instancetype) copy;
@end
