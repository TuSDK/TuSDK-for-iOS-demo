//
//  HorizontalListView.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/6/28.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HorizontalListItemBaseView;
@protocol HorizontalListItemViewDelegate;

@class HorizontalListView;

// 横向视图项配置 Block
typedef void(^HorizontalListItemViewConfigBlock)(HorizontalListView *listView, NSUInteger index, __kindof HorizontalListItemBaseView *itemView);

/**
 横向滚动列表视图
 */
@interface HorizontalListView : UIView <HorizontalListItemViewDelegate>

/**
 是否可滚动
 */
@property (nonatomic, assign) BOOL scrollEnabled;

/**
 左右缩进
 */
@property (nonatomic, assign) CGFloat sideMargin;

/**
 列表项尺寸
 */
@property (nonatomic, assign) CGSize itemSize;

/**
 列表数量
 */
@property (nonatomic, readonly) CGFloat itemCount;

/**
 列表项自动尺寸，根据列表项的内容来计算宽高
 */
@property (nonatomic, assign) BOOL autoItemSize;

/**
 列表项间隔
 */
@property (nonatomic, assign) CGFloat itemSpacing;

/**
 选中索引
 */
@property (nonatomic, assign) NSInteger selectedIndex;

/**
 禁用自动选中
 */
@property (nonatomic, assign) BOOL disableAutoSelect;

/**
 列表项的类型
 */
+ (Class)listItemViewClass;
- (void)commonInit;

/**
 插入列表项

 @param itemView 列表项视图
 @param index 插入索引
 */
- (void)insertItemView:(HorizontalListItemBaseView *)itemView atIndex:(NSInteger)index;

/**
 添加列表项

 @param itemCount 列表项数量
 @param configHandler 配置处理块
 */
- (void)addItemViewsWithCount:(NSInteger)itemCount config:(HorizontalListItemViewConfigBlock)configHandler;

- (void)addItemViewsFromXIBWithCount:(NSInteger)itemCount config:(HorizontalListItemViewConfigBlock)configHandler;

/**
 获取给定列表项的索引

 @param itemView 列表项
 @return 列表项索引
 */
- (NSInteger)indexOfItemView:(HorizontalListItemBaseView *)itemView;

/**
 获取给定索引的列表项

 @param index 列表项索引
 @return 列表项
 */
- (HorizontalListItemBaseView *)itemViewAtIndex:(NSInteger)index;

@end


#pragma mark - HorizontalListItemBaseView


@interface HorizontalListItemBaseView : UIView
{
    BOOL _selected;
    BOOL _disableSelect;
    NSInteger _tapCount;
}

/**
 禁止选中
 */
@property (nonatomic, assign) BOOL disableSelect;

/**
 选中状态
 */
@property (nonatomic, assign) BOOL selected;

/**
 点击次数
 */
@property (nonatomic, assign, readonly) NSInteger tapCount;

/**
 最大点击次数，默认为 1，tapCount 大于该值则切换对未选中状态，并归零 tapCount；若设置为 -1，则不归零 tapCount
 */
@property (nonatomic, assign) NSInteger maxTapCount;


@property (nonatomic, weak) id<HorizontalListItemViewDelegate> delegate;

- (void)commonInit;

- (void)itemViewDidTouchDown;
- (void)itemViewDidTouchUp;

@end


@protocol HorizontalListItemViewDelegate <NSObject>

@optional

/**
 按下回调
 */
- (void)itemViewDidTouchDown:(HorizontalListItemBaseView *)itemView;

/**
 抬起回调
 */
- (void)itemViewDidTouchUp:(HorizontalListItemBaseView *)itemView;

/**
 点击回调
 */
- (void)itemViewDidTap:(HorizontalListItemBaseView *)itemView;

@end
