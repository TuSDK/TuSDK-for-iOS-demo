//
//  GeeV2PFEditFilterOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditFilterController.h"

/**
 *  图片编辑滤镜控制器配置选项
 */
@interface GeeV2PFEditFilterOptions : TuImageResultOptions
/**
 *  视图类 (默认:GeeV2PFEditFilterView, 需要继承 GeeV2PFEditFilterView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  滤镜列表行视图宽度
 */
@property (nonatomic)CGFloat filterBarCellWidth;

/**
 *  滤镜列表折叠视图宽度
 */
@property (nonatomic)CGFloat filterBarStackViewWidth;

/**
 *  滤镜列表折叠视图类 (默认:TuGroupFilterGroupCellBase, 需要继承 UITableViewCell<TuGroupFilterItemCellInterface>)
 */
@property (nonatomic, strong) Class stackViewClazz;

/**
 *  滤镜列表行视图类 (默认:TuGroupFilterItem, 需要继承 TuGroupFilterItem)
 */
@property (nonatomic, strong)Class filterBarTableCellClazz;

/**
 *  开启滤镜配置选项 (默认: 开启)
 */
@property (nonatomic) BOOL enableFilterConfig;

/**
 *  开启滤镜历史记录
 */
@property (nonatomic) BOOL enableFilterHistory;

/**
 *  开启无效果滤镜 (默认: 开启)
 */
@property (nonatomic) BOOL enableNormalFilter;

/**
 *  开启在线滤镜
 */
@property (nonatomic) BOOL enableOnlineFilter;

/**
 *  显示滤镜标题视图
 */
@property (nonatomic) BOOL displayFilterSubtitles;

/**
 *  在线滤镜控制器类型 (需要继承 UIViewController,以及实现TuFilterOnlineControllerInterface接口)
 */
@property (nonatomic) Class onlineControllerClazz;

/**
 *  是否仅返回滤镜，不返回处理图片
 */
@property (nonatomic) BOOL onlyReturnFilter;

/**
 *  是否渲染滤镜封面 (使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TUTUCLOUD.com控制台)
 */
@property (nonatomic) BOOL isRenderFilterThumb;

/**
 *  创建图片编辑滤镜控制器对象
 *
 *  @return controller 图片编辑滤镜控制器对象
 */
- (GeeV2PFEditFilterController *)viewController;
@end

