//
//  CameraNormalFilterListView.m
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/11/14.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import "CameraNormalFilterListView.h"
#import "Constants.h"

@implementation CameraNormalFilterListView

- (void)commonInit {
    [super commonInit];
    [self setupData];
}

+ (Class)listItemViewClass {
    return [HorizontalListItemView class];
}

- (void)setupData {
    NSArray *filterCodes = @[kCameraNormalFilterCodes];
    
    
    
    _filterCodes = filterCodes;
    
    // 配置 UI
    [self addItemViewsWithCount:filterCodes.count config:^(HorizontalListView *listView, NSUInteger index, HorizontalListItemView *itemView) {
        NSString *filterCode = filterCodes[index];
        // 标题
        NSString *title = [NSString stringWithFormat:@"lsq_filter_%@", filterCode];
        itemView.titleLabel.text = LSQString(title, @"");
        // 缩略图
        NSString *imageName = [NSString stringWithFormat:@"lsq_filter_thumb_%@", filterCode];
        NSString *imagePath = [[NSBundle mainBundle] pathForResource:imageName ofType:@"jpg"];
        itemView.thumbnailView.image = [UIImage imageWithContentsOfFile:imagePath];
        // 点击次数
        itemView.maxTapCount = 2;
    }];
    [self insertItemView:[HorizontalListItemView disableItemView] atIndex:0];
}

#pragma mark - property

- (void)setSelectedFilterCode:(NSString *)selectedFilterCode {
    if ([_selectedFilterCode isEqualToString:selectedFilterCode]) return;
    if (!_selectedFilterCode && (!selectedFilterCode || [selectedFilterCode isEqualToString:@"Normal"]))return;
    
    _selectedFilterCode = selectedFilterCode;
    NSInteger selectedIndex = [_filterCodes indexOfObject:selectedFilterCode];
    if (selectedIndex < 0 || selectedIndex >= _filterCodes.count) { // 若不在 _filterCodes 范围内，则选中无效果
        _selectedFilterCode = nil;
        selectedIndex = -1;
    }
    selectedIndex += 1;
    self.selectedIndex = selectedIndex;


}

#pragma mark - HorizontalListItemViewDelegate

/**
 列表项点击回调
 */
- (void)itemViewDidTap:(HorizontalListItemView *)itemView {
    [super itemViewDidTap:itemView];
    NSString *code = nil;
    if (self.selectedIndex > 0) {
        code = _filterCodes[self.selectedIndex - 1];
    }
    self.selectedFilterCode = code;
//    if (self.itemViewTapActionHandler) self.itemViewTapActionHandler(self, itemView, code);


}

@end
