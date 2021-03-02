//
//  TuPagerView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/6.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - TuPagerHolderDelegate
@class TuPagerHolder;
/**
 *  分页占位视图委托
 */
@protocol TuPagerHolderDelegate <NSObject>
@optional

/**
 分页占位视图点击事件

 @param holder holder
 */
- (void)onPagerHolderTaped:(TuPagerHolder *)holder;
@end

#pragma mark - TuPagerHolderViewProtocol
/**
 *  显示的页视图接口
 */
@protocol TuPagerHolderViewProtocol <NSObject>
/**
 *  是否允许缩放
 *
 *  @return BOOL 是否允许缩放
 */
- (BOOL)canZoom;
@end

#pragma mark - TuPagerView
/**
 *  分页占位视图
 */
@interface TuPagerHolder : UIScrollView<UIScrollViewDelegate>
/**
 *  显示的页视图
 */
@property (nonatomic, retain) UIView<TuPagerHolderViewProtocol> *view;
/**
 *  页视图点击委托
 */
@property (nonatomic, weak) id<TuPagerHolderDelegate> tapDelegate;
/**
 *  初始化
 */
- (void)lsqInitView;
/**
 *  还原缩放
 */
- (void)resetZoom;
/**
 *  需要重置视图
 */
- (void)viewNeedRest;
/**
 *  取消单击事件 | 防止延迟执行方法导致异常
 */
- (void)cancelSingleTapAction;
@end

#pragma mark - TuPagerViewDataSource
@class TuPagerView;
/**
 *  横向分页视图数据源
 */
@protocol TuPagerViewDataSource <TuPagerHolderDelegate>
/**
 *  总页数
 *
 *  @param pagerView 横向分页视图
 *
 *  @return  pagerView 总页数
 */
- (NSUInteger)numberOfPagesInPagerView:(TuPagerView *)pagerView;

/**
 *  设置视图
 *
 *  @param pagerView 横向分页视图
 *  @param holder    分页占位视图
 *  @param pageIndex 分页页数
 */
- (void)pagerView:(TuPagerView *)pagerView holder:(TuPagerHolder *)holder pageIndex:(NSUInteger)pageIndex;

/**
 *  正在显示的页数
 *
 *  @param pagerView 横向分页视图
 *  @param pageIndex 分页页数
 */
- (void)pagerView:(TuPagerView *)pagerView didShowPageIndex:(NSUInteger)pageIndex;
@optional
/**
 *  滚动到最后一页
 *
 *  @param pagerView 横向分页视图
 */
- (void)didScrollEndWithPagerView:(TuPagerView *)pagerView;
@end

#pragma mark - TuPagerView
/**
 *  横向分页视图
 */
@interface TuPagerView : UIScrollView<UIScrollViewDelegate>
/**
 *  横向分页视图数据源
 */
@property (nonatomic, assign) id<TuPagerViewDataSource> dataSource;
/**
 *  最大缩放 | 默认为1时不进行缩放
 */
@property (nonatomic) CGFloat scaleMaxZoom;
/**
 *  将要改变方向
 */
@property (nonatomic) BOOL willChangeOrientation;

/**
 *  当前分页占位视图
 */
@property (nonatomic, readonly) TuPagerHolder *currentHolder;

/**
 *  是否使用滚动动画
 */
@property (nonatomic, readonly) BOOL isAnimation;
/**
 *  初始化
 *
 *  @param frame       坐标大小
 *  @param pagePadding 分页边距 默认为10
 *
 *  @return self 照片查看器
 */
+ (id)initWithFrame:(CGRect)frame pagePadding:(CGFloat)pagePadding;

/**
 *  重新加载数据
 */
- (void)reloadData;
/**
 *  滚动到指定页数
 *
 *  @param index 分页页数
 */
- (void)scrollToIndex:(NSUInteger)index;

/**
 *  滚动到指定页数
 *
 *  @param index 分页页数
 *  @param animated 是否使用动画
 */
- (void)scrollToIndex:(NSUInteger)index animated:(BOOL)animated;

/**
 *  屏幕方向改变
 */
- (void)didChangeOrientation;

/**
 *  取消单击事件 | 防止延迟执行方法导致异常
 */
- (void)cancelSingleTapAction;

/**
 *  需要重置视图
 */
- (void)viewNeedRest;
@end
