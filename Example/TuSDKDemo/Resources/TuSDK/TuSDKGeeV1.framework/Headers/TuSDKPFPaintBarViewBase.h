//
//  TuSDKPFPaintBarViewBase.h
//  TuSDK
//
//  Created by tutu on 2018/11/30.
//  Copyright © 2018 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPaintMode.h"
#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKPFPaintTableViewDelegate

@protocol TuSDKPFPaintTableViewInterface;

/**
 *  笔刷列表视图委托
 *  @since v3.1.0
 */
@protocol TuSDKPFPaintTableViewDelegate <NSObject>
/**
 *  选中一个行视图
 *
 *  @param view      笔刷列表视图
 *  @param color     选中颜色
 *  @param indexPath 选中索引
 */
- (void)paintTableView:(UIView<TuSDKPFPaintTableViewInterface> *)view
         selectedColor:(NSString *)color
             indexPath:(NSIndexPath *)indexPath;
@end

#pragma mark - TuSDKPFPaintTableViewInterface

/**
 *  笔刷列表接口
 *  @since v3.1.0
 */
@protocol TuSDKPFPaintTableViewInterface <NSObject>
/**
 *  笔刷分组列表行视图委托
 *  @since v3.1.0
 */
@property (nonatomic, weak) id<TuSDKPFPaintTableViewDelegate> delegate;

/**
 *  初始化视图
 *  @since v3.1.0
 */
- (void)lsqInitView;

/**
 *  滤镜分组元素视图类 (默认:TuSDKCPGroupFilterItemCell, 需要继承 UITableViewCell<TuGroupFilterItemCellInterface>)
 *  @since v3.1.0
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  行视图宽度
 *  @since v3.1.0
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  数据列表
 *  @since v3.1.0
 */
@property (nonatomic, retain) NSArray *modeList;

/**
 *  选中索引
 *
 *  @since v3.1.0
 *  @param position 索引
 *  @param toCenter 是否滚动到中心位置
 *  @param reload   是否刷新数据
 */
- (void)selectPostion:(NSUInteger)position scrollToCenter:(BOOL)toCenter reload:(BOOL)reload;

/**
 *  改变选中索引
 *
 *  @since v3.1.0
 *  @param position 索引
 *  @param toCenter 是否滚动到中心位置
 *  @param anim     是否使用动画
 */
- (void)changeSelectPostion:(NSUInteger)position scrollToCenter:(BOOL)toCenter anim:(BOOL)anim;

/**
 *  刷新数据
 *  @since v3.1.0
 */
- (void)reloadData;


/**
 同 tableViewDelegate
 @since v3.1.0
 */

- (NSIndexPath *)indexPathForSelectedRow;
- (void)insertRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)deleteRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)scrollToRowAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;

@end

#pragma mark - TuSDKPFPaintBarViewBase
/**
 *  笔刷选择栏
 *  @since v3.1.0
 */
@interface TuSDKPFPaintBarViewBase : UIView

/**
 *  笔刷列表
 *  @since v3.1.0
 */
@property (nonatomic, readonly) UIView<TuSDKPFPaintTableViewInterface> *tableView;

/**
 *  单元格宽度
 *  @since v3.1.0
 */
@property (nonatomic) CGFloat cellWidth;

/**
 *  需要显示的笔刷名称列表 (如果为空将显示所有自定义笔刷)
 *  @since v3.1.0
 */
@property (nonatomic, retain) NSArray<NSString *> * brushGroup;

/**
 *  是否保存最后一次使用的笔刷
 *  @since v3.1.0
 */
@property (nonatomic) BOOL saveLastBrush;

/**
 *  初始化视图
 *  @since v3.1.0
 */
- (void)lsqInitView;

/**
 *  加载笔刷列表
 *  @since v3.1.0
 */
- (void)loadBrushes;
/**
 *  加载最后使用的笔刷
 *  @since v3.1.0
 */
- (NSString *)loadLastBrush;
/**
 *  选中笔刷
 *
 *  @since v3.1.0
 *  @param brush 笔刷
 */
- (void)selectBrush:(NSString *)brush;

/**
 *  发送事件通知
 *
 *  @since v3.1.0
 *  @param brush 笔刷对象
 */
- (void)notifySelectedBrush:(NSString *)brush;
@end
