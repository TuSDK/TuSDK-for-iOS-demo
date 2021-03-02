//
//  TuBrushAdapter.h
//  TuSDK
//
//  Created by Yanlin on 10/27/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "network/TuNKDownloadAdapter.h"
#import "TuBrushGroup.h"

/**
 *  笔刷适配器
 */
@interface TuBrushAdapter : TuNKDownloadAdapter

/**原生笔刷代号列表*/
@property (nonatomic, readonly) NSArray *codes;


#pragma mark - data
// 加载配置信息
- (void)loadConfig;

/**
 *  获取橡皮擦笔刷对象
 *
 *  @return eraserBrush 笔刷对象 (如果未找到对应选项，返回默认配置)
 */
- (TuBrush *)eraserBrush;

/**
 *  获取笔刷对象
 *
 *  @param code 笔刷代号
 *
 *  @return code 笔刷对象 (如果未找到对应选项，返回默认配置)
 */
- (TuBrush *)brushWithCode:(NSString *)code;

/**
 *  验证笔刷代号
 *
 *  @param codes 笔刷代号列表
 *
 *  @return codes 笔刷名称
 */
- (NSArray *)verifyCodes:(NSArray *)codes;

/**
 *  获取指定名称的笔刷列表
 *
 *  @param codes 笔刷代号列表
 *
 *  @return codes 笔刷列表
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
 *  加载笔刷数据
 *
 *  @param brush  笔刷对象
 *
 *  @return  BOOL 是否加载贴纸数据对象
 */
- (BOOL)loadBrushData:(TuBrush *)brush;

@end
