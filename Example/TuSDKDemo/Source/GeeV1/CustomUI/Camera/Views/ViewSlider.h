//
//  ViewSlider.h
//  ControllerSlider
//
//  Created by bqlin on 2018/6/14.
//  Copyright © 2018年 bqlin. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ViewSliderDataSource, ViewSliderDelegate;

/**
 视图分页控件
 */
@interface ViewSlider : UIView

@property (nonatomic, weak) IBOutlet id<ViewSliderDataSource> dataSource;

@property (nonatomic, weak) IBOutlet id<ViewSliderDelegate> delegate;

/**
 当前视图
 */
@property (nonatomic, strong, readonly) UIView *currentView;

/**
 选中索引
 */
@property (nonatomic, assign) NSInteger selectedIndex;

/**
 禁用手势滑动切换
 */
@property (nonatomic, assign) BOOL disableSlide;

@end

/**
 数据源
 */
@protocol ViewSliderDataSource <NSObject>

/**
 分页数量
 */
- (NSInteger)numberOfViewsInSlider:(ViewSlider *)slider;

/**
 各分页显示的视图
 */
- (UIView *)viewSlider:(ViewSlider *)slider viewAtIndex:(NSInteger)index;

@end

/**
 回调代理
 */
@protocol ViewSliderDelegate <NSObject>
@optional

/**
 切换分页过程回调

 @param slider 分页控件
 @param fromIndex 初始页面索引
 @param toIndex 结束页面索引
 @param progress 进度
 */
- (void)viewSlider:(ViewSlider *)slider switchingFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex progress:(CGFloat)progress;

/**
 切换分页回调

 @param slider 分页控件
 @param index 目标页面索引
 */
- (void)viewSlider:(ViewSlider *)slider didSwitchToIndex:(NSInteger)index;

/**
 回退切换回调

 @param slider 分页控件
 @param index 目标页面索引
 */
- (void)viewSlider:(ViewSlider *)slider didSwitchBackIndex:(NSInteger)index;

@end

