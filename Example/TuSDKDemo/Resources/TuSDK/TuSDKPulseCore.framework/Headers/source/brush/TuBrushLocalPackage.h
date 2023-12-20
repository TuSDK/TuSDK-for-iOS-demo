//
//  TuBrushLocalPackage.h
//  TuSDK
//
//  Created by Yanlin on 10/27/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TuSDKPulseCore/TUCEnum.h>
#import "TuBrush.h"
@class TuNKDownloadItem;

/**
 *  橡皮擦笔刷代号
 */
extern NSString * const TTEraserBrushCode;


@class TuBrushLocalPackage;

/**
 *  原生笔刷配置委托
 */
@protocol TuBrushLocalPackageDelegate <NSObject>
/**
 *  本地笔刷包下载状态改变
 *
 *  @param manager 本地笔刷包
 *  @param item    下载对象
 *  @param status  下载状态
 */
- (void)brushManager:(TuBrushLocalPackage *)manager
                item:(TuNKDownloadItem *)item
       changedStatus:(TuDownloadTaskStatus)status;
@end

#pragma mark - TuBrushLocalPackage
/**
 *  本地笔刷配置
 */
@interface TuBrushLocalPackage : NSObject
/** 原生笔刷代号列表*/
@property (nonatomic, readonly) NSArray *codes;
/** 已下载文件列表 */
@property (nonatomic, readonly) NSArray* downloadItems;

/**
 *  本地笔刷包
 *
 *  @return package 本地笔刷包
 */
+ (instancetype)shared;
+ (instancetype)package;

// 加载配置信息
- (void)loadConfig;

#pragma mark - delegate

/**
 *  添加本地笔刷包委托
 *
 *  @param delegate 本地笔刷包委托
 */
- (void)appenDelegate:(id<TuBrushLocalPackageDelegate>)delegate;

/**
 *  删除本地笔刷包委托
 *
 *  @param delegate 本地笔刷包委托
 */
- (void)removeDelegate:(id<TuBrushLocalPackageDelegate>)delegate;

/**
 *  获取橡皮擦笔刷对象
 *
 *  @return 笔刷对象 (如果未找到对应选项，返回默认配置)
 */
- (TuBrush *)eraserBrush;

/**
 *  获取笔刷对象
 *
 *  @param code 笔刷代号
 *
 *  @return 笔刷对象 (如果未找到对应选项，返回默认配置)
 */
- (TuBrush *)brushWithCode:(NSString *)code;

/**
 *  验证笔刷代号
 *
 *  @param codes 笔刷代号列表
 *
 *  @return 笔刷名称
 */
- (NSArray *)verifyCodes:(NSArray *)codes;

/**
 *  获取指定名称的笔刷列表
 *
 *  @param codes 笔刷代号列表
 *
 *  @return 笔刷列表
 */
- (NSArray *)brushWithCodes:(NSArray *)codes;

#pragma mark - imageLoad
/**
 *  加载笔刷预览图片
 *
 *  @param brush     笔刷对象
 *  @param imageView 图片视图
 */
- (void)loadThumbWithBrush:(TuBrush *)brush imageView:(UIImageView *)imageView;

/**
 *  取消加载图片
 *
 *  @param imageView 图片视图
 */
- (void)cancelLoadImage:(UIImageView *)imageView;

/**
 *  加载笔刷数据
 *
 *  @param brush  笔刷对象
 *
 *  @return  是否加载贴纸数据对象
 */
- (BOOL)loadBrushData:(TuBrush *)brush;

#pragma mark - download
/**
 *  下载笔刷
 *
 *  @param idt 笔刷ID
 *  @param key 下载SN
 *  @param fileId 文件ID
 */
- (void)downloadWithIdt:(uint64_t)idt key:(NSString *)key fileId:(NSString *)fileId;

/**
 *  取消下载笔刷
 *
 *  @param idt 笔刷ID
 */
- (void)cancelDownloadWithIdt:(uint64_t)idt;

/**
 *  删除下载笔刷
 *
 *  @param idt 笔刷ID
 */
- (void)removeDownloadWithIdt:(uint64_t)idt;

/**
 *  获取所有json数据
 *
 *  @return json数据
 */
- (NSString *)jsonAllData;


@end
