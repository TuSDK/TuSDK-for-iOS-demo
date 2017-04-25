//
//  GeeV2PFBrushBarView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"
#import "GeeV2PFBrushTableItemCell.h"

#pragma mark - GeeV2PFBrushTableView
/**
 *  笔刷列表视图
 */
@interface GeeV2PFBrushTableView : UIView<UITableViewDataSource, UITableViewDelegate, TuSDKPFBrushTableViewInterface>
/**
 *  滤镜分组元素视图类 (默认:GeeV2PFBrushTableItemCell, 需要继承 GeeV2PFBrushTableItemCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  滤镜分组元素类型
 */
@property (nonatomic) lsqBrushAction action;

/**
 *  笔刷列表视图委托
 */
@property (nonatomic, weak) id<TuSDKPFBrushTableViewDelegate> delegate;

/**
 *  数据列表
 */
@property (nonatomic, retain) NSArray *modeList;

/**
 *  列表视图
 */
@property (nonatomic, readonly)TuSDKICTableView *tableView;

@end

#pragma mark - GeeV2PFBrushBarViewDelegate

@class GeeV2PFBrushBarView;
/**
 *  笔刷栏视图委托
 */
@protocol GeeV2PFBrushBarViewDelegate <NSObject>
/**
 *  选中一个笔刷数据
 *
 *  @param view    笔刷栏视图
 *  @param data    笔刷数据对象
 */
- (void)brushBarView:(GeeV2PFBrushBarView *)view selectBrush:(TuSDKPFBrush *)data;

@end

#pragma mark - GeeV2PFBrushBarView

@interface GeeV2PFBrushBarView : TuSDKPFBrushBarViewBase<TuSDKPFBrushTableViewDelegate>
{
@protected
    // 笔刷列表视图
    GeeV2PFBrushTableView *_tableView;
}

/**
 *  笔刷栏视图委托
 */
@property (nonatomic, weak) id<GeeV2PFBrushBarViewDelegate> delegate;

/**
 *  单元格高度
 */
@property (nonatomic) NSUInteger brushBarHeight;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  加载笔刷列表
 */
- (void)loadBrushes;

@end
