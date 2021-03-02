//
//  ViewSlider.m
//  ControllerSlider
//
//  Created by bqlin on 2018/6/14.
//  Copyright © 2018年 bqlin. All rights reserved.
//

#import "ViewSlider.h"

// 响应切换页面的最小滑动水平位移
static const CGFloat kMinPanOffset = 50;
// 动画时长
static const NSTimeInterval kAnimationDuration = 0.25;

@interface ViewSlider ()

/**
 初始页面索引
 */
@property (nonatomic, assign) NSInteger fromIndex;

/**
 目标页面索引
 */
@property (nonatomic, assign) NSInteger toIndex;

/**
 滑动手势
 */
@property (nonatomic, strong) UIPanGestureRecognizer *pan;

/**
 滑动手势开始触发点
 */
@property (nonatomic, assign) CGPoint panStartPoint;

/**
 初始视图
 */
@property (nonatomic, strong) UIView *fromView;

/**
 目标视图
 */
@property (nonatomic, strong) UIView *toView;

/**
 切换中标记
 */
@property (nonatomic, assign, getter=isSwitching) BOOL switching;

@end


@implementation ViewSlider

- (instancetype)initWithCoder:(NSCoder *)decoder {
    if (self = [super initWithCoder:decoder]) {
        [self commonInit];
    }
    return self;
}
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self commonInit];
    }
    return self;
}

- (void)commonInit {
    _fromIndex = -1;
    _toIndex = -1;
    _pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panHandler:)];
    [self addGestureRecognizer:_pan];
}

- (void)layoutSubviews {
    if (_switching) return;
    _fromView.frame = self.bounds;
}

#pragma mark - property

- (NSInteger)selectedIndex {
    return _fromIndex;
}
- (void)setSelectedIndex:(NSInteger)selectedIndex {
    if (selectedIndex != _fromIndex) {
        [self switchToIndex:selectedIndex];
    }
}

- (void)setDisableSlide:(BOOL)disableSlide {
    _disableSlide = disableSlide;
    _pan.enabled = !disableSlide;
}

- (UIView *)currentView  {
    return _fromView;
}

#pragma mark - private

/**
 移除初始视图
 */
- (void)removeFromView {
    [_fromView removeFromSuperview];
    _fromView = nil;
    _fromIndex = -1;
}

/**
 移除目标视图
 */
- (void)removeToView {
    [_toView removeFromSuperview];
    _toView = nil;
    _toIndex = -1;
}

/**
 显示对应索引的视图

 @param index 视图索引
 */
- (void)showAtIndex:(NSInteger)index {
    if (_fromIndex == index) return;
    
    [self removeFromView];
    UIView *view = [self.dataSource viewSlider:self viewAtIndex:index];
    view.frame = self.bounds;
    [self insertSubview:view atIndex:0];
    _fromIndex = index;
    _fromView = view;
    
    if ([self.delegate respondsToSelector:@selector(viewSlider:didSwitchToIndex:)]) {
        [self.delegate viewSlider:self didSwitchToIndex:index];
    }
}

/**
 从上一个视图切换到对应索引的视图

 @param index 视图索引
 */
- (void)switchToIndex:(NSInteger)index {
    if (_fromIndex == index || _switching) return;
    if (!_fromView) {
        [self showAtIndex:index];
        return;
    }
    
    // 标记切换中
    _switching = YES;
    // 获取目标视图
    UIView *toView = [self.dataSource viewSlider:self viewAtIndex:index];
    
    // 布局
    CGRect currentFrame = self.bounds;
    CGRect leftFrame = currentFrame;
    leftFrame.origin.x -= leftFrame.size.width;
    CGRect rightFrame = currentFrame;
    rightFrame.origin.x += rightFrame.size.width;
    CGRect startSwitchingFrame;
    CGRect endSwitchingFrame;
    if (index > _fromIndex) {
        startSwitchingFrame = rightFrame;
        endSwitchingFrame = leftFrame;
    } else {
        startSwitchingFrame = leftFrame;
        endSwitchingFrame = rightFrame;
    }
    [self insertSubview:toView atIndex:0];
    toView.frame = startSwitchingFrame;

    // 动画切换
    [UIView setAnimationCurve:UIViewAnimationCurveEaseInOut];
    [UIView animateWithDuration:kAnimationDuration animations:^{
        self.fromView.frame = endSwitchingFrame;
        toView.frame = currentFrame;
    } completion:^(BOOL finished) {
        self.switching = NO;
        [self removeFromView];
        
        // 更新索引
        self.fromIndex = index;
        self.fromView = toView;

        // 回调结果
        if ([self.delegate respondsToSelector:@selector(viewSlider:didSwitchToIndex:)]) {
            [self.delegate viewSlider:self didSwitchToIndex:index];
        }
    }];
}

/**
 根据给定的横坐标偏移切换页面

 @param offsetX 横坐标偏移
 */
- (void)switchingWithOffsetX:(CGFloat)offsetX {
    CGFloat x = 0;
    if (_toIndex < _fromIndex) {
        x = offsetX - CGRectGetWidth(self.bounds);
    } else if (_toIndex > _fromIndex) {
        x = offsetX + CGRectGetWidth(self.bounds);
    }
    
    CGRect fromFrame = self.bounds;
    fromFrame.origin.x = offsetX;
    _fromView.frame = fromFrame;
    
    if (_toIndex >= 0 && _toIndex < [self.dataSource numberOfViewsInSlider:self]) {
        CGRect toFrame = self.bounds;
        toFrame.origin.x = x;
        _toView.frame = toFrame;
    }
    
    if ([self.delegate respondsToSelector:@selector(viewSlider:switchingFromIndex:toIndex:progress:)]) {
        [self.delegate viewSlider:self switchingFromIndex:_fromIndex toIndex:_toIndex progress:fabs(offsetX)/CGRectGetWidth(self.bounds)];
    }
}

/**
 根据给定的横坐标偏移回退页面

 @param offsetX 横坐标偏移
 */
- (void)switchBackWithOffsetX:(CGFloat)offsetX {
    NSTimeInterval animationDuration = 0.3;
    
    [UIView setAnimationCurve:UIViewAnimationCurveEaseInOut];
    [UIView animateWithDuration:animationDuration animations:^{
        [self switchingWithOffsetX:0];
    } completion:^(BOOL finished) {
        if (self.toIndex >= 0 && self.toIndex < [self.dataSource numberOfViewsInSlider:self] && self.toIndex != self.fromIndex) {
            [self removeToView];
        }
        if ([self.delegate respondsToSelector:@selector(viewSlider:didSwitchBackIndex:)]) {
            [self.delegate viewSlider:self didSwitchBackIndex:self.fromIndex];
        }
    }];
}

#pragma mark - pan recognizer

/**
 实现手势滑动切换控制器

 @param pan 手势
 */
- (void)panHandler:(UIPanGestureRecognizer *)pan {
    if (_fromIndex < 0) return;

    // 获取滑动点
    CGPoint point = [pan translationInView:self];

    if (pan.state == UIGestureRecognizerStateBegan) {
        _panStartPoint = point;
    } else if (pan.state == UIGestureRecognizerStateChanged) {
        // 计算目标索引
        NSInteger toIndex = -1;
        CGFloat offsetX = point.x - _panStartPoint.x;
        if (offsetX > 0) {
            toIndex = _fromIndex-1;
        } else if (offsetX < 0) {
            toIndex = _fromIndex + 1;
        }

        if (toIndex != _toIndex) {
            if (_toView) [self removeToView];
        }

        // 超出范围
        if (toIndex < 0 || toIndex >= [self.dataSource numberOfViewsInSlider:self]) {
            _toIndex = toIndex;
            [self switchingWithOffsetX:offsetX/2.0];
            return;
        }

        // 添加目标视图
        if (toIndex != _toIndex) {
            _toView = [self.dataSource viewSlider:self viewAtIndex:toIndex];
            [self insertSubview:_toView atIndex:0];
            _toIndex = toIndex;
        }
        
        // 切换页面
        [self switchingWithOffsetX:offsetX];
    } else if (pan.state == UIGestureRecognizerStateEnded) {
        CGFloat offsetX = point.x - _panStartPoint.x;
        CGFloat width = CGRectGetWidth(self.bounds);
        if (_toIndex >= 0 && _toIndex < [self.dataSource numberOfViewsInSlider:self] && _toIndex != _fromIndex && fabs(offsetX) > kMinPanOffset) {
            // 更新位置
            NSTimeInterval animationDuration = fabs(width - fabs(offsetX)) / width * kAnimationDuration;
            [UIView setAnimationCurve:UIViewAnimationCurveEaseInOut];
            [UIView animateWithDuration:animationDuration animations:^{
                [self switchingWithOffsetX:offsetX > 0 ? width : -width];
            } completion:^(BOOL finished) {
                [self removeFromView];
                self.fromIndex = self.toIndex;
                self.fromView = self.toView;
                self.toView = nil;
                self.toIndex = -1;

                if ([self.delegate respondsToSelector:@selector(viewSlider:didSwitchToIndex:)]) {
                    [self.delegate viewSlider:self didSwitchToIndex:self.fromIndex];
                }
            }];
        } else {
            // 无法切换时回退页面
            [self switchBackWithOffsetX:offsetX];
        }
    }
}

@end
