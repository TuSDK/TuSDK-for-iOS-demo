//
//  TuSDKPFBrushAdapter.h
//  TuSDK
//
//  Created by Yanlin on 10/27/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "TuSDKNKDownloadAdapter.h"
#import "TuSDKConfig.h"
#import "TuSDKPFBrush.h"

/**
 *  笔刷适配器
 */
@interface TuSDKBrushAdapter : TuSDKNKDownloadAdapter

/**
 *  本地笔刷包
 *
 *  @param config Sdk配置
 *
 *  @return 本地笔刷包
 */
+ (instancetype)initWithConfig:(TuSDKConfig *)config;

/**
 *  原生笔刷代号列表
 */
@property (nonatomic, readonly) NSArray *codes;

/**
 *  是否已初始化
 */
@property (nonatomic, readonly) BOOL isInited;

#pragma mark - data
/**
 *  获取橡皮擦笔刷对象
 *
 *  @return 笔刷对象 (如果未找到对应选项，返回默认配置)
 */
- (TuSDKPFBrush *)eraserBrush;

/**
 *  获取笔刷对象
 *
 *  @param code 笔刷代号
 *
 *  @return 笔刷对象 (如果未找到对应选项，返回默认配置)
 */
- (TuSDKPFBrush *)brushWithCode:(NSString *)code;

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
- (void)loadThumbWithBrush:(TuSDKPFBrush *)brush imageView:(UIImageView *)imageView;

/**
 *  加载笔刷数据
 *
 *  @param brush  笔刷对象
 *
 *  @return  是否加载贴纸数据对象
 */
- (BOOL)loadBrushData:(TuSDKPFBrush *)brush;

@end
