//
//  TuSDKCPGroupFilterTableView.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/18.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKICTableView.h"
#import "TuSDKCPGroupFilterItemCell.h"

@class TuSDKCPGroupFilterTableView;

/**
 *  滤镜分组列表行视图委托
 */
@protocol TuSDKCPGroupFilterTableViewDelegate <NSObject>
/**
 *  选中一个行视图
 *
 *  @param tableView 滤镜分组列表
 *  @param cell      滤镜分组元素视图
 *  @param mode      滤镜分组元素
 *  @param indexPath 索引
 *
 *  @return 是否允许选中
 */
- (BOOL)onTuSDKCPGroupFilterTableView:(TuSDKCPGroupFilterTableView *)tableView
                         selectedCell:(TuSDKCPGroupFilterItemCell *)cell
                                model:(TuSDKCPGroupFilterItem *)mode
                            indexPath:(NSIndexPath *)indexPath;
@end

/**
 *  滤镜分组列表
 */
@interface TuSDKCPGroupFilterTableView : UIView<UITableViewDataSource, UITableViewDelegate>
/**
 *  滤镜分组元素类型
 */
@property (nonatomic)lsqGroupFilterAction action;

/**
 *  滤镜分组元素视图类 (默认:TuSDKCPGroupFilterItemCell, 需要继承 TuSDKCPGroupFilterItemCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  滤镜分组列表行视图委托
 */
@property (nonatomic, assign) id<TuSDKCPGroupFilterTableViewDelegate> delegate;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  数据列表
 */
@property (nonatomic, retain) NSArray *modeList;

/**
 *  列表视图
 */
@property (nonatomic, readonly)TuSDKICTableView *tableView;

/**
 *  是否允许选择列表
 */
@property (nonatomic) BOOL allowsSelection;

/**
 *  滤镜分组视图委托
 */
@property (nonatomic, assign) id<TuSDKCPGroupFilterGroupCellDelegate> groupDelegate;

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
@end