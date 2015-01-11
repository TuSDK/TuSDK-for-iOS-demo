//
//  TuSDKPFSticker.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/2.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#import "TuSDKPFStickerText.h"

/**
 *  贴纸元素类型
 */
typedef NS_ENUM(NSInteger, lsqStickerType)
{
    /**
     * 图片贴纸
     */
    lsqStickerImage,
    /**
     * 文字水印贴纸
     */
    lsqStickerText,
};

/**
 *  贴纸数据对象
 */
@interface TuSDKPFSticker : NSObject
/**
 * 贴纸ID
 */
@property (nonatomic) uint64_t idt;

/**
 * 贴纸分类ID
 */
@property (nonatomic) uint64_t categoryIdt;

/**
 * 贴纸名称
 */
@property (nonatomic, copy) NSString *name;

/**
 * 预览视图文件名
 */
@property (nonatomic, copy) NSString *preivewName;

/**
 * 贴纸文件名
 */
@property (nonatomic, copy) NSString *stickerImageName;

/**
 * 贴纸文件MD5
 */
@property (nonatomic, copy) NSString *md5;

/**
 * 贴纸长宽 (单位DP: 需要与原始图片比例保持一致，否则会造成成图片变形)
 */
@property (nonatomic) CGSize size;

/**
 *  贴纸元素类型
 */
@property (nonatomic, readonly) lsqStickerType type;

/**
 *  贴纸图片
 */
@property (nonatomic, retain) UIImage *image;

/**
 *  贴纸文字列表
 */
@property (nonatomic, readonly) NSArray *texts;

/**
 *  贴纸数据对象
 *
 *  @return 贴纸数据对象
 */
+ (instancetype)sticker;

/**
 *  贴纸数据对象
 *
 *  @return 贴纸数据对象
 */
+ (instancetype)stickerWithType:(lsqStickerType)type;

/**
 *  复制数据
 *
 *  @return 贴纸数据对象
 */
- (instancetype) copy;

/**
 *  添加贴纸文字
 *
 *  @param sText 贴纸文字对象
 */
- (void)appendText:(TuSDKPFStickerText *)sText;
@end
