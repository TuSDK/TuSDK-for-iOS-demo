//
//  TuResult.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/11.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulseCore/TUCEnum.h>
#import <TuSDKPulseCore/TUCProtocol.h>

@class SelesParameters;

// SDK处理结果
@interface TuResult : NSObject
@property (nonatomic, strong)   NSMutableDictionary*            metadata;           // 图片EXIF信息
@property (nonatomic)           UIImageOrientation              imageOrientation;   // 图片方向
@property (nonatomic)           TuRotationMode                  imageRotation;      // 图片方向
@property (nonatomic, strong)   UIImage *                       image;              // 获取的图片对象 (为保证内存使用空间, 当保存图片到系统相册或临时文件时，image对象会被清理)
@property (nonatomic, copy)     NSString *                      imagePath;          // 临时文件路径
@property (nonatomic, strong)   id<TuTSAssetInterface>       imageAsset;         // 相册图片对象
@property (nonatomic, strong)   NSArray<TuTSAssetInterface>* imageAssets;        // 相册图片列表
@property (nonatomic)           CGRect                          cutRect;            // 裁剪区域
@property (nonatomic)           CGSize                          cutSize;            // 裁剪长宽
@property (nonatomic)           CGFloat                         cutScale;           // 裁切时缩放
@property (nonatomic)           TTRatioType                    cutRatioType;       // 裁剪比例类型
@property (nonatomic)           CGFloat                         imageRatio;         // 图片比例
@property (nonatomic, copy)     NSString *                      filterCode;         // 滤镜代号
@property (nonatomic, strong)   SelesParameters *               filterParams;       // 当前所使用的滤镜
@property (nonatomic, strong)   NSArray *                       stickers;           // 贴纸列表
@property (nonatomic)           NSInteger                       outIndex;           // 输出排序索引
+ (instancetype)    result;             // SDK处理结果
- (void)            fixedMetadata;      // 修正图片EXIF信息
- (UIImage *)       loadResultImage;    // 结果图片 (如果image不存在，会尝试加载tempFilePath，或者asset)
- (void)            logInfo;            // 打印出日志信息
- (NSString *)      buildTempFile;      // 创建临时文件路径
@end
