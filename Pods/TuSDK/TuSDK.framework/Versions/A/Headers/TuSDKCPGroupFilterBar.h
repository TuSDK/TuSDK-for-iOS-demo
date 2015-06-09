//
//  TuSDKCPGroupFilterBar.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/18.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCPGroupFilterTableView.h"

@class TuSDKCPGroupFilterBar;

/**
 *  滤镜组选择栏委托
 */
@protocol TuSDKCPGroupFilterBarDelegate <NSObject>
/**
 *  选中一个滤镜数据
 *
 *  @param bar  滤镜组选择栏
 *  @param cell 滤镜分组元素视图
 *  @param mode 滤镜分组元素
 *
 *  @return 是否允许继续执行
 */
- (BOOL)onTuSDKCPGroupFilterBar:(TuSDKCPGroupFilterBar *)bar
                   selectedCell:(TuSDKCPGroupFilterItemCell *)cell
                           mode:(TuSDKCPGroupFilterItem *)mode;
@end

/**
 *  滤镜组选择栏
 */
@interface TuSDKCPGroupFilterBar : UIView<TuSDKCPGroupFilterTableViewDelegate, TuSDKCPGroupFilterGroupCellDelegate>
{
    // 滤镜分组列表
    TuSDKCPGroupFilterTableView *_groupTable;
    // 滤镜列表
    TuSDKCPGroupFilterTableView *_filterTable;
    // 后退按钮
    UIButton *_backButton;
}
/**
 *  滤镜分组列表
 */
@property (nonatomic, readonly) TuSDKCPGroupFilterTableView *groupTable;

/**
 *  滤镜列表
 */
@property (nonatomic, readonly) TuSDKCPGroupFilterTableView *filterTable;

/**
 *  后退按钮
 */
@property (nonatomic, readonly) UIButton *backButton;

/**
 *  滤镜组选择栏委托
 */
@property (nonatomic, assign) id<TuSDKCPGroupFilterBarDelegate> delegate;

/**
 *  滤镜分组元素类型
 */
@property (nonatomic)lsqGroupFilterAction action;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
 */
@property (nonatomic, strong)Class groupTableCellClazz;

/**
 *  滤镜列表行视图类 (默认:TuSDKCPGroupFilterItem, 需要继承 TuSDKCPGroupFilterItem)
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
 *  加载滤镜分组
 */
- (void)loadFilters;

/**
 *  加载滤镜分组
 *
 *  @param option 滤镜配置选项
 */
- (void)loadFiltersWithOption:(TuSDKFilterOption *)option;

/**
 *  退出删除状态
 */
- (void)exitRemoveState;
@end
