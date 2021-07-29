//
//  TuGroupFilterBarBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/18.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuGroupFilterTableView.h"
#import "TuFilterOnlineControllerInterface.h"

@protocol TuGroupFilterBarInterface;

/**
 *  滤镜组选择栏委托
 */
@protocol TuGroupFilterBarDelegate <NSObject>
/**
 *  选中一个滤镜数据
 *
 *  @param bar  滤镜组选择栏
 *  @param cell 滤镜分组元素视图
 *  @param mode 滤镜分组元素
 *
 *  @return 是否允许继续执行
 */
- (BOOL)onTuSDKCPGroupFilterBar:(UIView<TuGroupFilterBarInterface> *)bar
                   selectedCell:(UITableViewCell<TuGroupFilterItemCellInterface> *)cell
                           mode:(TuGroupFilterItem *)mode;
@end

#pragma mark - TuGroupFilterBarInterface
/**
 *  滤镜组选择栏接口
 */
@protocol TuGroupFilterBarInterface <NSObject>
/**
 *  滤镜组选择栏委托
 */
@property (nonatomic, weak) id<TuGroupFilterBarDelegate> delegate;
/**
 *  滤镜分组元素类型
 */
@property (nonatomic)TuGroupFilterAction action;

/**
 *  开启滤镜配置选项
 */
@property (nonatomic) BOOL enableFilterConfig;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  折叠区视图宽度
 */
@property (nonatomic)CGFloat stackViewWidth;

/**
 *  滤镜分组列表行视图类 (默认:TuGroupFilterGroupCellBase, 需要继承 TuGroupFilterGroupCellBase)
 */
@property (nonatomic, strong)Class groupTableCellClazz;

/**
 *  滤镜列表行视图类 (默认:TuGroupFilterItemCellBase, 需要继承 UITableViewCell<TuGroupFilterItemCellInterface>)
 */
@property (nonatomic, strong)Class filterTableCellClazz;

/**
 *  是否保存最后一次使用的滤镜
 */
@property (nonatomic) BOOL saveLastFilter;

/**
 *  自动选择分组滤镜指定的默认滤镜
 */
@property (nonatomic) BOOL autoSelectGroupDefaultFilter;

/**
 *  指定显示的滤镜组
 */
@property (nonatomic, retain) NSArray * filterGroup;
/**
 *  是否允许选择列表
 */
@property (nonatomic) BOOL allowsSelection;

/**
 *  开启无效果滤镜 (默认: 开启)
 */
@property (nonatomic) BOOL enableNormalFilter;

/**
 *  开启在线滤镜
 */
@property (nonatomic) BOOL enableOnlineFilter;

/**
 *  视图控制器
 */
@property (nonatomic, assign) UIViewController *controller;

/**
 *  开启用户历史记录
 */
@property (nonatomic) BOOL enableHistory;

/**
 *  在线滤镜控制器类型 (需要继承 UIViewController,以及实现TuFilterOnlineControllerInterface接口)
 */
@property (nonatomic) Class onlineControllerClazz;

/**
 *  是否渲染封面 (使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TUTUCLOUD.com控制台)
 */
@property (nonatomic) BOOL isRenderFilterThumb;

/**
 *  自定义封面原图(使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TUTUCLOUD.com控制台)
 *
 *  @param image 自定义封面原图
 */
- (void)setThumbImage:(UIImage *)image;

/**
 *  加载滤镜分组
 */
- (void)loadFilters;

/**
 *  加载滤镜分组
 *
 *  @param option 滤镜配置选项
 */
- (void)loadFiltersWithOption:(TuFilterOption *)option;

/**
 *  删除滤镜组
 *
 *  @param groupId 滤镜组ID
 */
- (void)removeWithGroupId:(uint64_t)groupId;

/**
 *  退出删除状态
 */
- (void)exitRemoveState;
@end

#pragma mark - TuGroupFilterBarBase
/**
 *  滤镜组选择栏
 */
@interface TuGroupFilterBarBase : UIView<TuGroupFilterTableViewDelegate, TuGroupFilterGroupCellDelegate, TuFilterOnlineControllerDelegate, TuGroupFilterBarInterface>
/**
 *  滤镜分组列表
 */
@property (nonatomic, readonly) UIView<TuGroupFilterTableViewInterface> *groupTable;

/**
 *  滤镜列表
 */
@property (nonatomic, readonly) UIView<TuGroupFilterTableViewInterface> *filterTable;

/**
 *  滤镜组选择栏委托
 */
@property (nonatomic, weak) id<TuGroupFilterBarDelegate> delegate;

/**
 *  滤镜分组元素类型
 */
@property (nonatomic)TuGroupFilterAction action;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  滤镜分组列表行视图类 (默认:TuGroupFilterGroupCellBase, 需要继承 TuGroupFilterGroupCellBase)
 */
@property (nonatomic, strong)Class groupTableCellClazz;

/**
 *  滤镜列表行视图类 (默认:TuGroupFilterItemCellBase, 需要继承 UITableViewCell<TuGroupFilterItemCellInterface>)
 */
@property (nonatomic, strong)Class filterTableCellClazz;

/**
 *  是否保存最后一次使用的滤镜
 */
@property (nonatomic) BOOL saveLastFilter;

/**
 *  自动选择分组滤镜指定的默认滤镜
 */
@property (nonatomic) BOOL autoSelectGroupDefaultFilter;

/**
 *  指定显示的滤镜组
 */
@property (nonatomic, retain) NSArray * filterGroup;

/**
 *  是否允许选择列表
 */
@property (nonatomic) BOOL allowsSelection;

/**
 *  开启滤镜配置选项
 */
@property (nonatomic) BOOL enableFilterConfig;

/**
 *  开启无效果滤镜 (默认: 开启)
 */
@property (nonatomic) BOOL enableNormalFilter;

/**
 *  开启在线滤镜
 */
@property (nonatomic) BOOL enableOnlineFilter;

/**
 *  视图控制器
 */
@property (nonatomic, assign) UIViewController *controller;

/**
 *  开启用户历史记录
 */
@property (nonatomic) BOOL enableHistory;

/**
 *  在线滤镜控制器类型 (需要继承 UIViewController,以及实现TuFilterOnlineControllerInterface接口)
 */
@property (nonatomic) Class onlineControllerClazz;

/**
 *  是否渲染封面 (使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TUTUCLOUD.com控制台)
 */
@property (nonatomic) BOOL isRenderFilterThumb;

/**
 *  返回上级动作
 */
- (void)handleBackAction;

/**
 *  显示 滤镜列表视图
 *
 *  @param centerX 居中位置
 *  @param showed  是否显示
 */
- (void)showFilterTableWithCenterX:(CGFloat)centerX showed:(BOOL)showed;
@end
