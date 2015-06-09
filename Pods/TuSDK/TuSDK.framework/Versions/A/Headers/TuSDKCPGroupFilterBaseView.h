//
//  TuSDKCPGroupFilterBaseView.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/19.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCPGroupFilterBar.h"
#import "TuSDKCPSubtitlesView.h"

/**
 *  滤镜分组视图基类
 */
@interface TuSDKCPGroupFilterBaseView : UIView<TuSDKCPGroupFilterBarDelegate>{
    // 滤镜组选择栏
    TuSDKCPGroupFilterBar *_filterBar;
    // 滤镜标题视图
    TuSDKCPSubtitlesView *_titleView;
}
/**
 *  滤镜分组元素类型
 */
@property (nonatomic) lsqGroupFilterAction action;

/**
 *  是否为隐藏状态
 */
@property (nonatomic) BOOL stateHidden;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  滤镜组选择栏高度
 */
@property (nonatomic)CGFloat filterBarHeight;

/**
 *  滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
 */
@property (nonatomic, strong)Class groupTableCellClazz;

/**
 *  滤镜列表行视图类 (默认:TuSDKCPGroupFilterItemCell, 需要继承 TuSDKCPGroupFilterItemCell)
 */
@property (nonatomic, strong)Class filterTableCellClazz;

/**
 *  滤镜组选择栏
 */
@property (nonatomic, readonly) TuSDKCPGroupFilterBar *filterBar;

/**
 *  滤镜标题视图
 */
@property (nonatomic, readonly) TuSDKCPSubtitlesView *titleView;

/**
 *  需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
 */
@property (nonatomic, retain) NSArray * filterGroup;

/**
 *  是否保存最后一次使用的滤镜
 */
@property (nonatomic) BOOL saveLastFilter;

/**
 *  自动选择分组滤镜指定的默认滤镜
 */
@property (nonatomic) BOOL autoSelectGroupDefaultFilter;

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
 *  通知显示标题
 *
 *  @param cell 滤镜分组元素视图
 *  @param mode 滤镜分组元素
 *
 *  @return 是否通知
 */
- (BOOL)notifyTitleWithCell:(TuSDKCPGroupFilterItemCell *)cell
                       mode:(TuSDKCPGroupFilterItem *)mode;

/**
 *  通知显示标题
 *
 *  @param mode 滤镜分组元素
 */
- (void)notifyTitleWithMode:(TuSDKCPGroupFilterItem *)mode;

/**
 *  加载滤镜分组
 */
- (void)loadFilters;

/**
 *  设置默认显示状态
 *
 *  @param isShow 是否显示
 */
- (void)setDefaultShowState:(BOOL)isShow;

/**
 *  退出删除状态
 */
- (void)exitRemoveState;
@end
