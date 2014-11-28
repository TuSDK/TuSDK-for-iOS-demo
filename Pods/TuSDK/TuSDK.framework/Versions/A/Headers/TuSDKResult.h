//
//  TuSDKResult.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/11.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKTSNSMutableDictionary+ImageMetadata.h"

/**
 *  SDK处理结果
 */
@interface TuSDKResult : NSObject
/**
 *  图片EXIF信息
 */
@property (nonatomic, retain) NSMutableDictionary *metadata;

/**
 *  临时文件路径
 */
@property (nonatomic, copy) NSString *tempFilePath;

/**
 *  图片方向
 */
@property (nonatomic) UIImageOrientation imageOrientation;

/**
 *  滤镜名称
 */
@property (nonatomic, copy) NSString *filterName;

/**
 *  相册图片对象
 */
@property (nonatomic, retain) ALAsset *asset;

/**
 *  获取的图片对象 (为保证内存使用空间, 当保存图片到系统相册或临时文件时，image对象会被清理)
 */
@property (nonatomic, retain) UIImage *image;

/**
 *  裁剪区域
 */
@property (nonatomic) CGRect cutRect;

/**
 *  裁剪长宽
 */
@property (nonatomic) CGSize cutSize;

/**
 *  SDK处理结果
 *
 *  @return SDK处理结果
 */
+ (instancetype)result;

/**
 *  修正图片EXIF信息
 */
- (void)fixedMetadata;

/**
 *  加载结果图片
 *
 *  @return 结果图片 (如果image不存在，会尝试加载tempFilePath，或者asset)
 */
- (UIImage *)loadResultImage;

/**
 *  打印出日志信息
 */
- (void)logInfo;
@end
