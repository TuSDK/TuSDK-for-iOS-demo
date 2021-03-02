//
//  TuAOFile.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/26.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  SDK文件
 */
@interface TuAOFile : NSObject
/** 是否为SDK文件 */
@property (nonatomic, readonly) BOOL isSdkFile;

/**
 *  初始化SDK文件
 *
 *  @param file 文件路径
 *
 *  @return file SDK文件
 */
+ (instancetype)initWithFile:(NSString *)file;

/**
 *  初始化SDK文件
 *
 *  @param file 文件路径
 *
 *  @return file SDK文件
 */
- (instancetype)initWithFile:(NSString *)file;

/**
 * 获取文本
 *
 * @param name 名称文本
 *
 * @return name
 */
- (NSString *)getTextWithName:(NSString *)name;

/**
 * 获取图片
 *
 * @param name
 *            图片名称
 * @return name
 */
- (UIImage *)getImageWithName:(NSString *)name;


/**
 获取二进制流信息

 @param name 文件名称
 @return 文件二进制流数据
 */
- (NSData *)getBinaryDataWithName:(NSString *)name;

@end
