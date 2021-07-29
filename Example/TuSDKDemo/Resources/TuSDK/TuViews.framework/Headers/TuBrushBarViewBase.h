//
//  TuBrushBarViewBase.h
//  TuSDK
//
//  Created by Yanlin on 10/27/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "TuSDKPulseCore/components/widgets/smudge/TuBrush.h"
#import "TuBrushTableItemCellBase.h"
//#import "TuSDKPulseCore/tools/TuICView+Extend.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>
/**
 *  笔刷类型
 */
typedef NS_ENUM(NSInteger, lsqBrushAction)
{
    /**
     * 默认
     */
    lsqBrushActionNormal,
    /**
     * 编辑
     */
    lsqBrushActionEdit
};

#pragma mark - TuBrushTableViewDelegate

@protocol TuBrushTableViewInterface;
/**
 *  笔刷列表视图委托
 */
@protocol TuBrushTableViewDelegate <NSObject>
/**
 *  选中一个行视图
 *
 *  @param view      笔刷列表视图
 *  @param data      数据对象
 *  @param indexPath 选中索引
 */
- (void)brushTableView:(UIView<TuBrushTableViewInterface> *)view
          selectedData:(TuBrush *)data
             indexPath:(NSIndexPath *)indexPath;
@end


#pragma mark - TuBrushTableViewInterface

/**
 *  笔刷列表接口
 */
@protocol TuBrushTableViewInterface <NSObject>
/**
 *  笔刷分组列表行视图委托
 */
@property (nonatomic, weak) id<TuBrushTableViewDelegate> delegate;

/**
 *  笔刷使用类型
 */
@property (nonatomic)lsqBrushAction action;

/**
 *  初始化视图
 */
- (void)lsqInitView;

/**
 *  滤镜分组元素视图类 (默认:TuSDKCPGroupFilterItemCell, 需要继承 UITableViewCell<TuGroupFilterItemCellInterface>)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  数据列表
 */
@property (nonatomic, retain) NSArray *modeList;

/**
 *  选中索引
 *
 *  @param position 索引
 *  @param toCenter 是否滚动到中心位置
 *  @param reload   是否刷新数据
 */
- (void)selectPostion:(NSUInteger)position scrollToCenter:(BOOL)toCenter reload:(BOOL)reload;

/**
 *  改变选中索引
 *
 *  @param position 索引
 *  @param toCenter 是否滚动到中心位置
 *  @param anim     是否使用动画
 */
- (void)changeSelectPostion:(NSUInteger)position scrollToCenter:(BOOL)toCenter anim:(BOOL)anim;

/**
 *  刷新数据
 */
- (void)reloadData;

- (NSIndexPath *)indexPathForSelectedRow;
- (void)insertRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)deleteRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)scrollToRowAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;

@end

#pragma mark - TuBrushBarViewBase
/**
 *  笔刷选择栏
 */
@interface TuBrushBarViewBase : UIView

/**
 *  笔刷列表
 */
@property (nonatomic, readonly) UIView<TuBrushTableViewInterface> *tableView;

/**
 *  笔刷使用类型
 */
@property (nonatomic)lsqBrushAction action;

/**
 *  单元格宽度
 */
@property (nonatomic) CGFloat cellWidth;

/**
 *  需要显示的笔刷名称列表 (如果为空将显示所有自定义笔刷)
 */
@property (nonatomic, retain) NSArray * brushGroup;

/**
 *  是否保存最后一次使用的笔刷
 */
@property (nonatomic) BOOL saveLastBrush;

/**
 *  初始化视图
 */
- (void)lsqInitView;

/**
 *  加载笔刷列表
 */
- (void)loadBrushes;
/**
 *  加载最后使用的笔刷
 */
- (TuBrush *)loadLastBrush;
/**
 *  选中笔刷
 *
 *  @param brush 笔刷
 */
- (void)selectBrush:(TuBrush *)brush;

/**
 *  发送事件通知
 *
 *  @param brush 笔刷对象
 */
- (void)notifySelectedBrush:(TuBrush *)brush;
@end
