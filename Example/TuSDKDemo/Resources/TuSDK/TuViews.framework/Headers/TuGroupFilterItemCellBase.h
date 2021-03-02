//
//  TuSDKCPGroupFilterItemCell.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/18.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuGroupFilterItemCellBase.h"
#import "TuSDKPulseCore/core/TuFilterOption.h"
#import "TuSDKPulseCore/core/TuFilterGroup.h"
#import "TuTableViewCell.h"
#import "TuFiltersTaskBase.h"

/**
 *  滤镜分组元素类型
 */
typedef NS_ENUM(NSInteger, lsqGroupFilterItemType)
{
    /**
     * 占位视图
     */
    lsqGroupFilterItemHolder,
    /**
     * 滤镜
     */
    lsqGroupFilterItemFilter,
    /**
     * 滤镜分组
     */
    lsqGroupFilterItemGroup,
    /**
     * 历史
     */
    lsqGroupFilterItemHistory,
    /**
     * 在线滤镜
     */
    lsqGroupFilterItemOnline,
};

/**
 *  滤镜分组元素类型
 */
typedef NS_ENUM(NSInteger, lsqGroupFilterAction)
{
    /**
     * 默认
     */
    lsqGroupFilterActionNormal = 0,
    /**
     * 编辑
     */
    lsqGroupFilterActionEdit,
    /**
     * 相机
     */
    lsqGroupFilterActionCamera
};

#pragma mark - TuGroupFilterItemCellInterface
@class TuGroupFilterItem;

/**
 *  滤镜分组元素视图接口
 */
@protocol TuGroupFilterItemCellInterface <NSObject>
/**
 *  滤镜分组元素类型
 */
@property (nonatomic)lsqGroupFilterAction action;

/**
 *  是否激活
 */
@property (nonatomic, readonly)BOOL activating;

/**
 *  滤镜分组元素
 */
@property (nonatomic, retain)TuGroupFilterItem *mode;

/**
 *  是否显示第一次选择后的图标
 */
@property (nonatomic) BOOL displaySelectionIcon;

/**
 *  滤镜任务
 */
@property (nonatomic, assign) id<TuFiltersTaskInterface> filterTask;

/**
 *  是否为相机动作
 *
 *  @return BOOL 是否为相机动作
 */
- (BOOL)isCameraAction;

/**
 *  启动激活状态
 *
 *  @param wait 等待秒
 */
- (void)waitInActivate:(CGFloat)wait;

/**
 *  停止激活
 */
- (void)stopActivating;
@end

#pragma mark - TuGroupFilterItemColor
/**
 *  滤镜分组元素颜色
 */
@interface TuGroupFilterItemColor : NSObject
/**
 *  历史记录背景色
 */
@property (nonatomic, retain) UIColor *history;
/**
 *  在线滤镜背景色
 */
@property (nonatomic, retain) UIColor *online;
/**
 *  原始效果背景色
 */
@property (nonatomic, retain) UIColor *orgin;
/**
 *  滤镜分组元素颜色
 *
 *  @return shared 滤镜分组元素颜色
 */
+ (instancetype)shared;
@end
#pragma mark - TuGroupFilterItem
/**
 *  滤镜分组元素
 */
@interface TuGroupFilterItem : NSObject
/**
 *  滤镜分组元素类型
 */
@property (nonatomic)lsqGroupFilterItemType type;
/**
 *  滤镜配置选项
 */
@property (nonatomic, retain) TuFilterOption *option;
/**
 *  滤镜分组
 */
@property (nonatomic, retain) TuFilterGroup *group;

/**
 *  是否为动作状态
 */
@property (nonatomic) BOOL isInActingType;
/**
 *  是否为选中状态
 */
@property (nonatomic) BOOL isSelected;

/**
 *  初始化
 *
 *  @param type 滤镜分组元素类型
 *
 *  @return type 滤镜分组元素
 */
+ (instancetype)initWithType:(lsqGroupFilterItemType)type;

/**
 *  初始化
 *
 *  @param option 滤镜配置选项
 *
 *  @return option 滤镜分组元素
 */
+ (instancetype)initWithOption:(TuFilterOption *)option;

/**
 *  初始化
 *
 *  @param group 滤镜分组
 *
 *  @return group 滤镜分组元素
 */
+ (instancetype)initWithGroup:(TuFilterGroup *)group;

/**
 *  获取滤镜代号
 *
 *  @return filterCode 滤镜代号
 */
- (NSString *)filterCode;
@end
#pragma mark - TuGroupFilterItemCellBase
/**
 *  滤镜分组元素视图基础类
 */
@interface TuGroupFilterItemCellBase : TuTableViewCell<TuGroupFilterItemCellInterface>
/**
 *  滤镜分组元素类型
 */
@property (nonatomic)lsqGroupFilterAction action;

/**
 *  是否激活
 */
@property (nonatomic, readonly)BOOL activating;
/**
 *  滤镜分组元素
 */
@property (nonatomic, retain)TuGroupFilterItem *mode;

/**
 *  是否显示第一次选择后的图标
 */
@property (nonatomic) BOOL displaySelectionIcon;

/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *thumbView;

/**
 *  滤镜任务
 */
@property (nonatomic, assign) id<TuFiltersTaskInterface> filterTask;

/**
 *  是否渲染封面 (使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TUTUCLOUD.com控制台)
 */
@property (nonatomic, readonly) BOOL isRenderFilterThumb;

/**
 *  初始化视图 (空方法, 默认当使用+(id)initWithFrame:(CGRect)frame;初始化视图时调用)
 */
- (void)lsqInitView;

/**
 *  设置选中图标
 *
 *  @param mode     滤镜分组元素
 *  @param needIcon 是否需要Icon
 */
- (void)setSelectedIcon:(TuGroupFilterItem *)mode needIcon:(BOOL)needIcon;

/**
 *  原始效果
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeOrgin:(TuGroupFilterItem *)mode;

/**
 *  滤镜分组
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeGroup:(TuGroupFilterItem *)mode;

/**
 *  滤镜
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeFilter:(TuGroupFilterItem *)mode;

/**
 *  历史记录
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeHistory:(TuGroupFilterItem *)mode;

/**
 *  在线滤镜
 *
 *  @param mode 滤镜分组元素
 */
- (void)handleTypeOnlie:(TuGroupFilterItem *)mode;

/**
 *  设置功能块视图
 *
 *  @param color 颜色
 *  @param icon  图标
 */
- (void)handleBlockView:(UIColor *)color icon:(NSString *)icon;
@end

#pragma mark - TuGroupFilterGroupCellBase

@class TuGroupFilterGroupCellBase;

/**
 *  滤镜分组视图基础类委托
 */
@protocol TuGroupFilterGroupCellDelegate <NSObject>

/**
 *  长按视图
 *
 *  @param cell 滤镜分组视图
 */
- (void)onFilterGroupCellLongClick:(TuGroupFilterGroupCellBase *)cell;

/**
 *  删除滤镜组
 *
 *  @param cell 滤镜分组视图
 */
- (void)onFilterGroupCellRemove:(TuGroupFilterGroupCellBase *)cell;

/**
 *  折叠视图点击事件
 *
 *  @param stackView  折叠视图对象
 *  @param mode       滤镜分组元素
 *  @param enableStack  是否允许展开的折叠
 *
 */
- (void)onFilterGroupViewClick:(UITableViewCell<TuGroupFilterItemCellInterface> *)stackView mode:(TuGroupFilterItem *)mode enableStack:(BOOL)enableStack;

@end


/**
 *  滤镜分组视图基础类
 */
@interface TuGroupFilterGroupCellBase : TuGroupFilterItemCellBase
/**
 *  滤镜分组视图委托
 */
@property (nonatomic, weak) id<TuGroupFilterGroupCellDelegate> delegate;

/**
 *  是否隐藏删除标识
 *
 *  @return BOOL 是否隐藏删除标识
 */
- (BOOL)canHiddenRemoveFlag;

/**
 *  是否为动作状态
 *
 *  @return BOOL 是否为动作状态
 */
- (BOOL)isInActingType;
@end
