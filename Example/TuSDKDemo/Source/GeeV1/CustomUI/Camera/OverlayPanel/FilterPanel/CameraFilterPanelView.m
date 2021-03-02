//
//  CameraFilterPanelView.m
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/23.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import "CameraFilterPanelView.h"
#import "CameraNormalFilterListView.h"
#import "CameraComicsFilterListView.h"
#import "PageTabbar.h"
#import "ViewSlider.h"
#import "Constants.h"

// 滤镜列表高度
static const CGFloat kFilterListHeight = 120;
// 滤镜列表与参数面板的间隔
static const CGFloat kFilterListParamtersViewSpacing = 24;
// tabbar 高度
static const CGFloat kFilterTabbarHeight = 30;

@interface CameraFilterPanelView () <PageTabbarDelegate, ViewSliderDataSource, ViewSliderDelegate>

/**
 普通滤镜列表
 */
@property (nonatomic, strong, readonly) CameraNormalFilterListView *normalFilterListView;

/**
 漫画滤镜列表
 */
@property (nonatomic, strong, readonly) CameraComicsFilterListView *comicsFilterListView;

/**
 参数面板
 */
@property (nonatomic, strong, readonly) ParametersAdjustView *paramtersView;

/**
 模糊背景
 */
@property (nonatomic, strong) UIVisualEffectView *effectBackgroundView;

/**
 面板切换标签栏
 */
@property (nonatomic, strong) PageTabbar *tabbar;

/**
 页面切换控件
 */
@property (nonatomic, strong) ViewSlider *pageSlider;

/**
 需要过滤的滤镜参数
 */
@property (nonatomic, strong) NSArray *skippedFilterKeys;

@end

@implementation CameraFilterPanelView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self commonInit];
    }
    return self;
}
- (instancetype)initWithCoder:(NSCoder *)decoder {
    if (self = [super initWithCoder:decoder]) {
        [self commonInit];
    }
    return self;
}

- (void)commonInit {
    _skippedFilterKeys = @[kBeautySkinKeys, kBeautyFaceKeys];
    __weak typeof(self) weakSelf = self;
    
    // 模糊背景
    _effectBackgroundView = [[UIVisualEffectView alloc] initWithEffect:[UIBlurEffect effectWithStyle:UIBlurEffectStyleDark]];
    [self addSubview:_effectBackgroundView];
    
    // 普通滤镜列表
    _normalFilterListView = [[CameraNormalFilterListView alloc] initWithFrame:CGRectZero];
    _normalFilterListView.itemViewTapActionHandler = ^(HorizontalListItemView *filterListView, HorizontalListItemView *selectedItemView, NSString *filterCode) {
        weakSelf.paramtersView.hidden = selectedItemView.tapCount < selectedItemView.maxTapCount;
       
        if ([weakSelf.delegate respondsToSelector:@selector(filterPanel:didSelectedFilterCode:)]) {
            [weakSelf.delegate filterPanel:weakSelf didSelectedFilterCode:filterCode];
        }
        // 不能在此处调用 reloadData，应在外部滤镜应用后才调用
    };
    
    // 漫画滤镜列表
//    _comicsFilterListView = [[CameraComicsFilterListView alloc] initWithFrame:CGRectZero];
//    _comicsFilterListView.itemViewTapActionHandler = ^(HorizontalListItemView *filterListView, HorizontalListItemView *selectedItemView, NSString *filterCode) {
//        //weakSelf.paramtersView.hidden = selectedItemView.tapCount < selectedItemView.maxTapCount;
//        weakSelf.paramtersView.hidden = YES;
//        if ([weakSelf.delegate respondsToSelector:@selector(filterPanel:didSelectedFilterCode:)]) {
//            [weakSelf.delegate filterPanel:weakSelf didSelectedFilterCode:filterCode];
//        }
//        // 不能在此处调用 reloadData，应在外部滤镜应用后才调用
//    };
    
    // 参数面板
    _paramtersView = [[ParametersAdjustView alloc] initWithFrame:CGRectZero];
    [self addSubview:_paramtersView];
    _paramtersView.hidden = YES;
    
    // 分页标签栏
    PageTabbar *tabbar = [[PageTabbar alloc] initWithFrame:CGRectZero];
    [self addSubview:tabbar];
    _tabbar = tabbar;
    tabbar.trackerSize = CGSizeMake(20, 2);
    tabbar.itemSelectedColor = [UIColor whiteColor];
    tabbar.itemNormalColor = [UIColor colorWithWhite:1 alpha:.25];
    tabbar.delegate = self;
//    tabbar.itemTitles = @[LSQString(@"lsq_edit_entry_filter", @"滤镜"), LSQString(@"lsq_filter_group_Cartoon_image", @"漫画")];
    tabbar.itemTitles = @[LSQString(@"lsq_edit_entry_filter", @"滤镜")];
    tabbar.disableAnimation = YES;
    tabbar.itemTitleFont = [UIFont systemFontOfSize:13];
    
    // 分页控件
    ViewSlider *pageSlider = [[ViewSlider alloc] initWithFrame:CGRectZero];
    [self addSubview:pageSlider];
    _pageSlider = pageSlider;
    pageSlider.dataSource = self;
    pageSlider.delegate = self;
    pageSlider.selectedIndex = 0 ;
    pageSlider.disableSlide = YES;
    
    // 默认选中第一个滤镜
//    [tabbar setSelectedIndex:0];
    _normalFilterListView.selectedIndex  = 0;

}

- (void)layoutSubviews {
    CGSize size = self.bounds.size;
    CGRect safeBounds = self.bounds;
    if (@available(iOS 11.0, *)) {
        safeBounds = UIEdgeInsetsInsetRect(safeBounds, self.safeAreaInsets);
    }
    
    _tabbar.itemWidth = CGRectGetWidth(safeBounds) / 2;
    const CGFloat tabbarY = CGRectGetMaxY(safeBounds) - kFilterListHeight;
    _tabbar.frame = CGRectMake(CGRectGetMinX(safeBounds), tabbarY, CGRectGetWidth(safeBounds), kFilterTabbarHeight);
    const CGFloat pageSliderHeight = kFilterListHeight - kFilterTabbarHeight;
    _pageSlider.frame = CGRectMake(CGRectGetMinX(safeBounds), CGRectGetMaxY(_tabbar.frame), CGRectGetWidth(safeBounds), pageSliderHeight);

    const CGFloat paramtersViewAvailableHeight = CGRectGetMaxY(safeBounds) - kFilterListHeight - kFilterListParamtersViewSpacing;
    const CGFloat paramtersViewLeftMargin = 16;
    const CGFloat paramtersViewRightMargin = 9;
    const CGFloat paramtersViewHeight = _paramtersView.contentHeight;
    _paramtersView.frame =
    CGRectMake(CGRectGetMinX(safeBounds) + paramtersViewLeftMargin,
               paramtersViewAvailableHeight - paramtersViewHeight,
               CGRectGetWidth(_tabbar.frame) - paramtersViewLeftMargin - paramtersViewRightMargin,
               paramtersViewHeight);
    _effectBackgroundView.frame = CGRectMake(0, tabbarY, size.width, size.height - tabbarY);
}

- (CGSize)intrinsicContentSize {
    return CGSizeMake(-1, kFilterListParamtersViewSpacing + kFilterListHeight + _paramtersView.intrinsicContentSize.height);
}

/**
 判断滤镜参数是否过滤

 @param key 滤镜参数
 @return 是否过滤
 */
- (BOOL)shouldSkipFilterKey:(NSString *)key {
    BOOL isBeautyFilterKey = NO;
    if (!key.length) return isBeautyFilterKey;
    for (NSString *beautyFilterKey in _skippedFilterKeys) {
        if ([beautyFilterKey isEqualToString:key]) {
            isBeautyFilterKey = YES;
            break;
        }
    }
    return isBeautyFilterKey;
}

#pragma mark - property

- (void)setSelectedFilterCode:(NSString *)selectedFilterCode {
    _selectedFilterCode = selectedFilterCode;
    switch (_tabbar.selectedIndex) {
        case 1:{
            _comicsFilterListView.selectedFilterCode = selectedFilterCode;
        } break;
        case 0:{
            _normalFilterListView.selectedFilterCode = selectedFilterCode;
        } break;
    }
}

- (BOOL)display {
    return self.alpha > 0.0;
}

- (NSInteger)selectedTabIndex {
    return _tabbar.selectedIndex;
}

#pragma mark - public

/**
 重载滤镜参数数据
 */
- (void)reloadFilterParamters {
    if (!self.display) return;
    if (_tabbar.selectedIndex == 1) {
        _paramtersView.hidden = YES;
        return;
    }
    __weak typeof(self) weakSelf = self;
    
    
    [_paramtersView setupWithParameterCount:[self.dataSource numberOfParamter:self] config:^(NSUInteger index, ParameterAdjustItemView *itemView, void (^parameterItemConfig)(NSString *name, double percent)) {
        NSString *parameterName = [self.dataSource filterPanel:weakSelf  paramterNameAtIndex:index];
        // 跳过美颜、美型滤镜参数
        BOOL shouldSkip = [self shouldSkipFilterKey:parameterName];
        if (!shouldSkip) {
            double percentVale = [self.dataSource filterPanel:weakSelf percentValueAtIndex:index];
            parameterName = [NSString stringWithFormat:@"lsq_filter_set_%@", parameterName];
            parameterItemConfig(LSQString(parameterName, @"无需国际化"), percentVale);
        }
    } valueChange:^(NSUInteger index, double percent) {
        if ([weakSelf.delegate respondsToSelector:@selector(filterPanel:didChangeValue:paramterIndex:)]) {
            [weakSelf.delegate filterPanel:weakSelf didChangeValue:percent paramterIndex:index];
        }
    }];
}

#pragma mark - PageTabbarDelegate


/**
 标签项选中回调
 
 @param tabbar 标签栏对象
 @param fromIndex 起始索引
 @param toIndex 目标索引
 */
- (void)tabbar:(PageTabbar *)tabbar didSwitchFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex {
    _pageSlider.selectedIndex = toIndex;
//    self.selectedFilterCode = _selectedFilterCode;
    [self reloadFilterParamters];
//    if ([self.delegate respondsToSelector:@selector(filterPanel:didSwitchTabIndex:)]) {
//        [self.delegate filterPanel:self didSwitchTabIndex:toIndex];
//    }
}

#pragma mark - ViewSliderDataSource

/**
 分页数量
 */
- (NSInteger)numberOfViewsInSlider:(ViewSlider *)slider {
//    return 2;
    return 1;
}

/**
 各分页显示的视图
 */
- (UIView *)viewSlider:(ViewSlider *)slider viewAtIndex:(NSInteger)index {
    switch (index) {
        case 1:{
            return _comicsFilterListView;
        } break;
        case 0:{
            return _normalFilterListView;
        } break;
        default:{
            return nil;
        } break;
    }
}

#pragma mark - touch

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    if (self.userInteractionEnabled == NO || self.hidden == YES || self.alpha <= 0.01 || ![self pointInside:point withEvent:event]) return nil;
    UIView *hitView = [super hitTest:point withEvent:event];
    // 响应子视图
    if (hitView != self && !hitView.hidden) {
        return hitView;
    }
    return nil;
}

@end
