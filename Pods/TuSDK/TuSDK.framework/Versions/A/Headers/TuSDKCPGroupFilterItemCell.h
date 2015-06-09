//
//  TuSDKCPGroupFilterItemCell.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/18.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKICTableViewCell.h"
#import "TuSDKFilterOption.h"
#import "TuSDKFilterGroup.h"

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
    lsqGroupFilterActionNormal,
    /**
     * 编辑
     */
    lsqGroupFilterActionEdit,
    /**
     * 相机
     */
    lsqGroupFilterActionCamera
};
#pragma mark - TuSDKCPGroupFilterItemColor
/**
 *  滤镜分组元素颜色
 */
@interface TuSDKCPGroupFilterItemColor : NSObject
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
 *  @return 滤镜分组元素颜色
 */
+ (instancetype)shared;
@end
#pragma mark - TuSDKCPGroupFilterItem
/**
 *  滤镜分组元素
 */
@interface TuSDKCPGroupFilterItem : NSObject
/**
 *  滤镜分组元素类型
 */
@property (nonatomic)lsqGroupFilterItemType type;
/**
 *  滤镜配置选项
 */
@property (nonatomic, retain) TuSDKFilterOption *option;
/**
 *  滤镜分组
 */
@property (nonatomic, retain) TuSDKFilterGroup *group;

/**
 *  是否为动作状态
 */
@property (nonatomic) BOOL isInActingType;

/**
 *  初始化
 *
 *  @param type 滤镜分组元素类型
 *
 *  @return 滤镜分组元素
 */
+ (instancetype)initWithType:(lsqGroupFilterItemType)type;

/**
 *  初始化
 *
 *  @param option 滤镜配置选项
 *
 *  @return 滤镜分组元素
 */
+ (instancetype)initWithOption:(TuSDKFilterOption *)option;

/**
 *  初始化
 *
 *  @param group 滤镜分组
 *
 *  @return 滤镜分组元素
 */
+ (instancetype)initWithGroup:(TuSDKFilterGroup *)group;

/**
 *  获取滤镜代号
 *
 *  @return 滤镜代号
 */
- (NSString *)filterCode;
@end
#pragma mark - TuSDKCPGroupFilterItemCell
/**
 *  滤镜分组元素视图
 */
@interface TuSDKCPGroupFilterItemCell : TuSDKICTableViewCell{
    @protected
    // 是否激活
    BOOL _activating;
    // 包装视图
    UIView *_wrapView;
    // 图片视图
    UIImageView *_thumbView;
    // 标题视图
    UILabel *_titleView;
    // 标识视图
    UIView *_flagView;
    // 选中状态视图
    UIView *_selectedView;
    // 图标视图
    UIImageView *_iconView;
}
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
@property (nonatomic, retain)TuSDKCPGroupFilterItem *mode;
/**
 *  包装视图
 */
@property (nonatomic, readonly) UIView *wrapView;
/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *thumbView;
/**
 *  标题视图
 */
@property (nonatomic, readonly) UILabel *titleView;
/**
 *  标识视图
 */
@property (nonatomic, readonly) UIView *flagView;
/**
 *  选中状态视图
 */
@property (nonatomic, readonly) UIView *selectedView;
/**
 *  图标视图
 */
@property (nonatomic, readonly) UIImageView *iconView;

/**
 *  初始化视图 (空方法, 默认当使用+(id)initWithFrame:(CGRect)frame;初始化视图时调用)
 */
- (void)initView;

/**
 *  是否为相机动作
 *
 *  @return 是否为相机动作
 */
- (BOOL)isCameraAction;

#pragma mark - Runnable
/**
 *  开始延时处理
 *
 *  @param delay 延时秒
 */
- (void)startRunnableWithDelay:(CGFloat)delay;

/**
 *  取消延时处理
 */
- (void)cancelRunnable;

/**
 *  处理器执行任务
 */
- (void)onRunableRun;

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

#pragma mark - TuSDKCPGroupFilterGroupCell

@class TuSDKCPGroupFilterGroupCell;

/**
 *  滤镜分组视图委托
 */
@protocol TuSDKCPGroupFilterGroupCellDelegate <NSObject>

/**
 *  长按视图
 *
 *  @param cell 滤镜分组视图
 */
- (void)onFilterGroupCellLongClick:(TuSDKCPGroupFilterGroupCell *)cell;

/**
 *  删除滤镜组
 *
 *  @param cell 滤镜分组视图
 */
- (void)onFilterGroupCellRemove:(TuSDKCPGroupFilterGroupCell *)cell;
@end

/**
 *  滤镜分组视图
 */
@interface TuSDKCPGroupFilterGroupCell : TuSDKCPGroupFilterItemCell{
    @protected
    /**
     *  删除按钮
     */
    UIButton *_removeButton;
}
/**
 *  滤镜分组视图委托
 */
@property (nonatomic, assign) id<TuSDKCPGroupFilterGroupCellDelegate> delegate;

/**
 *  删除按钮
 */
@property (nonatomic, readonly) UIButton *removeButton;

/**
 *  处理按钮删除事件
 */
- (void)handleRemoveButton;
@end