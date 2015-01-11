//
//  TuSDKPFStickerLocalPackage.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/7.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKPFStickerCategory.h"

/**
 *  默认贴纸文件夹名称
 */
extern NSString * const lsq_STICKER_LOCAL_IMAGE;
/**
 *  心情贴纸文件夹名称
 */
extern NSString * const lsq_STICKER_LOCAL_MOOD;
/**
 *  水印贴纸文件夹名称
 */
extern NSString * const lsq_STICKER_LOCAL_WATERMARK;

/**
 *  本地贴纸包
 */
@interface TuSDKPFStickerLocalPackage : NSObject

/**
 *  分类列表
 */
@property (nonatomic, readonly) NSArray *categories;
/**
 *  本地贴纸包
 *
 *  @return 本地贴纸包
 */
+ (instancetype)package;

/**
 *  加载贴纸预览图片
 *
 *  @param sticker   贴纸数据
 *  @param imageView 图片视图
 */
- (void)loadThumbWtihSticker:(TuSDKPFSticker *)sticker imageView:(UIImageView *)imageView;

/**
 *  加载贴纸数据
 *
 *  @param sticker  贴纸数据对象
 *
 *  @return  新的贴纸数据对象
 */
- (TuSDKPFSticker *)loadStickerData:(TuSDKPFSticker *)sticker;
@end
