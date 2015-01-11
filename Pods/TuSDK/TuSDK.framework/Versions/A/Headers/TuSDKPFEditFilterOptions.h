//
//  TuSDKPFEditFilterOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPImageResultOptions.h"
#import "TuSDKPFEditFilterController.h"

/**
 *  图片编辑滤镜控制器配置选项
 */
@interface TuSDKPFEditFilterOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditFilterView, 需要继承 TuSDKPFEditFilterView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
 */
@property (nonatomic, retain) NSArray *filterGroup;

/**
 *  开启滤镜配置选项
 */
@property (nonatomic) BOOL enableFilterConfig;

/**
 *  是否仅返回滤镜，不返回处理图片
 */
@property (nonatomic) BOOL onlyReturnFilter;

/**
 *  创建图片编辑滤镜控制器对象
 *
 *  @return 图片编辑滤镜控制器对象
 */
- (TuSDKPFEditFilterController *)viewController;
@end
