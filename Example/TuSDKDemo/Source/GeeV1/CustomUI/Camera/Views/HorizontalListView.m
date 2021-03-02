//
//  HorizontalListView.m
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/6/28.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import "HorizontalListView.h"

@interface HorizontalListView ()

/**
 滚动视图
 */
@property (nonatomic, strong) UIScrollView *scrollView;

/**
 列表项组
 */
@property (nonatomic, strong) NSMutableArray<HorizontalListItemBaseView *> *itemViews;

@end

@implementation HorizontalListView

+ (Class)listItemViewClass {
    return [HorizontalListItemBaseView class];
}

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
    self.backgroundColor = [UIColor clearColor];
    _itemViews = [NSMutableArray array];
    _scrollView = [[UIScrollView alloc] init];
    _scrollView.showsHorizontalScrollIndicator = NO;
    _scrollView.showsVerticalScrollIndicator = NO;
    
    [self addSubview:_scrollView];
    _selectedIndex = -1;
    
    _sideMargin = 16;
    _itemSize = CGSizeMake(60, 60);
    _itemSpacing = 10;
}

-(CGFloat)itemCount;{
    return _itemViews.count;
}


- (void)layoutSubviews {
    CGSize size = self.bounds.size;
    _scrollView.frame = CGRectMake(0, 0, size.width, size.height);
    
    // 布局列表项
    CGFloat contentWidth = _sideMargin;
    for (int i = 0; i < _itemViews.count; i++) {
        HorizontalListItemBaseView *itemView = _itemViews[i];
        if (_autoItemSize) {
            CGSize contentSize = itemView.intrinsicContentSize;
            itemView.frame = CGRectMake(contentWidth, (size.height - contentSize.height) / 2, contentSize.width, contentSize.height);
        } else {
            itemView.frame = CGRectMake(contentWidth, (size.height - _itemSize.width) / 2, _itemSize.width, _itemSize.height);
        }
        contentWidth += _itemSpacing + CGRectGetWidth(itemView.frame);
    }
    contentWidth = contentWidth - _itemSpacing + _sideMargin;
    _scrollView.contentSize = CGSizeMake(contentWidth, self.bounds.size.height);
}

#pragma mark - property

- (void)setScrollEnabled:(BOOL)scrollEnabled {
    _scrollView.scrollEnabled = scrollEnabled;
}
- (BOOL)scrollEnabled {
    return _scrollView.scrollEnabled;
}

- (void)setSelectedIndex:(NSInteger)selectedIndex {
    BOOL valueChanged = _selectedIndex != selectedIndex;
    if (!valueChanged) return;
    
    // 清理状态
    HorizontalListItemBaseView * itemViewShouldDeselect = [self itemViewAtIndex:_selectedIndex];
    itemViewShouldDeselect.selected = NO;
    
    // 应用状态
    HorizontalListItemBaseView *itemViewShouldSelect = [self itemViewAtIndex:selectedIndex];
    itemViewShouldSelect.selected = YES;
    
    // 让选中项可见
    CGRect rectShouldVisible = CGRectInset(itemViewShouldSelect.frame, -_itemSpacing, 0);
    [_scrollView scrollRectToVisible:rectShouldVisible animated:YES];
    
    _selectedIndex = selectedIndex;
}

#pragma mark - public

- (void)addItemViewsWithCount:(NSInteger)itemCount config:(HorizontalListItemViewConfigBlock)configHandler {
    for (int i = 0; i < itemCount; i++) {
        HorizontalListItemBaseView *itemView = [[[self.class listItemViewClass] alloc] initWithFrame:CGRectZero];
        if (configHandler) configHandler(self, i, itemView);
        itemView.delegate = self;
        [_scrollView addSubview:itemView];
        [_itemViews addObject:itemView];
    }
}


- (void)addItemViewsFromXIBWithCount:(NSInteger)itemCount config:(HorizontalListItemViewConfigBlock)configHandler {
    for (int i = 0; i < itemCount; i++) {
        
        NSArray* nibViews = [[NSBundle mainBundle] loadNibNamed:NSStringFromClass([self.class listItemViewClass]) owner:self options:nil];
        HorizontalListItemBaseView *itemView = nibViews.firstObject;
        if (configHandler) configHandler(self, i, itemView);
        itemView.delegate = self;
        [_scrollView addSubview:itemView];
        [_itemViews addObject:itemView];
    }
}


- (void)insertItemView:(HorizontalListItemBaseView *)itemView atIndex:(NSInteger)index {
    itemView.delegate = self;
    [_itemViews insertObject:itemView atIndex:index];
    [_scrollView addSubview:itemView];
}

- (NSInteger)indexOfItemView:(HorizontalListItemBaseView *)itemView {
    return [self.itemViews indexOfObject:itemView];
}

- (HorizontalListItemBaseView *)itemViewAtIndex:(NSInteger)index {
    if (index < 0 || index >= _itemViews.count) return nil;
    return _itemViews[index];
}

#pragma mark - HorizontalListItemViewDelegate

/**
 列表项点击回调
 */
- (void)itemViewDidTap:(HorizontalListItemBaseView *)itemView {
    if (_disableAutoSelect) return;
    self.selectedIndex = [_itemViews indexOfObject:itemView];
}

/**
 列表项按下回调
 */
- (void)itemViewDidTouchDown:(HorizontalListItemBaseView *)itemView {
    // 子类重写
}

/**
 列表项抬起回调
 */
- (void)itemViewDidTouchUp:(HorizontalListItemBaseView *)itemView {
    // 子类重写
}

@end

#pragma mark HorizontalListItemBaseView

@implementation HorizontalListItemBaseView

- (void)commonInit;{
    _maxTapCount = 1;
}

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

- (void)itemViewDidTouchDown;{}
-(void)itemViewDidTouchUp;{}

- (void)setTapCount:(NSInteger)tapCount {
    if (_maxTapCount >= 0 && tapCount > _maxTapCount) {
        tapCount = 1;
    }
    _tapCount = tapCount;
}

#pragma mark touch

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [super touchesBegan:touches withEvent:event];
    if (touches.count > 1) return;
    [self itemViewDidTouchDown];
    
    if ([self.delegate respondsToSelector:@selector(itemViewDidTouchDown:)]) {
        [self.delegate itemViewDidTouchDown:self];
    }
    
    
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [super touchesBegan:touches withEvent:event];
    if (touches.count > 1) return;
    [self itemViewDidTouchUp];
    
    if ([self.delegate respondsToSelector:@selector(itemViewDidTouchUp:)]) {
        [self.delegate itemViewDidTouchUp:self];
    }
    
    CGPoint touchPoint = [touches.anyObject locationInView:self];
    BOOL inside = CGRectContainsPoint(self.bounds, touchPoint);
    if (inside) {
        if (!_disableSelect) _tapCount += 1;
        if ([self.delegate respondsToSelector:@selector(itemViewDidTap:)]) {
            [self.delegate itemViewDidTap:self];
        }
    }
}

- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [super touchesCancelled:touches withEvent:event];
    [self itemViewDidTouchUp];
    if ([self.delegate respondsToSelector:@selector(itemViewDidTouchUp:)]) {
        [self.delegate itemViewDidTouchUp:self];
    }
}

@end
