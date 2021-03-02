//
//  TuEditFilterGroupViewBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/9.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuGroupFilterBaseView.h"
#import "TuSDKPulseCore/cx/seles/extend/SelesParameters.h"

// 图片编辑滤镜控制器滤镜栏视图基础类
@interface TuEditFilterGroupViewBase : TuGroupFilterBaseView
// 滤镜参数对象
@property (nonatomic, strong) SelesParameters *filterParams;
// 设置配置视图参数
- (void)setConfigViewParams:(NSArray *)keys;
// 显示配置视图
- (void)configViewShow:(BOOL)isShow;
// 取消设置
- (void)handleCancelAction;
/**
 *  选中一个滤镜数据
 *  @param data 滤镜数据
 *  @return 是否允许继续执行
 */
- (BOOL)onFilterSelectedWithData:(TuGroupFilterItem *)data;

/**
 *  获取滤镜参数
 *  @param index 索引
 *  @return 滤镜参数
 */
- (SelesParameterArg *)filterArgWithIndex:(NSUInteger)index;
@end
