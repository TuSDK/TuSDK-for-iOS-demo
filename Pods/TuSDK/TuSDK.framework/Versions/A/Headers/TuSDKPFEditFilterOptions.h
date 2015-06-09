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
 *  滤镜列表行视图宽度
 */
@property (nonatomic)CGFloat filterBarCellWidth;

/**
 *  滤镜列表选择栏高度
 */
@property (nonatomic)CGFloat filterBarHeight;

/**
 *  滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
 */
@property (nonatomic, strong)Class filterBarGroupCellClazz;

/**
 *  滤镜列表行视图类 (默认:TuSDKCPGroupFilterItem, 需要继承 TuSDKCPGroupFilterItem)
 */
@property (nonatomic, strong)Class filterBarTableCellClazz;

/**
 *  开启滤镜配置选项
 */
@property (nonatomic) BOOL enableFilterConfig;

/**
 *  开启滤镜历史记录
 */
@property (nonatomic) BOOL enableFilterHistory;

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
