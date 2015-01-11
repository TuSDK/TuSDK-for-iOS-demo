//
//  TuSDKStickerCategory.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKPFSticker.h"

/**
 *  贴纸分类
 */
@interface TuSDKPFStickerCategory : NSObject
/**
 * 贴纸分类ID
 */
@property (nonatomic) uint64_t idt;

/**
 * 贴纸分类名称
 */
@property (nonatomic, copy) NSString *title;

/**
 * 贴纸数据列表
 */
@property (nonatomic, retain) NSArray *datas;

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
 * @param sticker 贴纸数据对象
 */
- (void)appendSticker:(TuSDKPFSticker*) sticker;

/**
 *  复制数据
 *
 *  @return 贴纸分类
 */
- (instancetype) copy;
@end
