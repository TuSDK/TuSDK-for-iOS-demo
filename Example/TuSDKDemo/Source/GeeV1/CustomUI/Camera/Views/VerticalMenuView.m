//
//  VerticalMenuView.m
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/18.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import "VerticalMenuView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunguarded-availability"

/**
 纵向列表项
 */
@interface VerticalMenuItemCell : UITableViewCell

/**
 选项组视图
 */
@property (nonatomic, strong) UIStackView *optionsStackView;

@end

@implementation VerticalMenuItemCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        [self commonInit];
    }
    return self;
}

- (void)commonInit {
    self.backgroundColor = [UIColor clearColor];
    
    _optionsStackView = [[UIStackView alloc] initWithFrame:CGRectZero];
    self.accessoryView = _optionsStackView;
    _optionsStackView.alignment = UIStackViewAlignmentCenter;
    _optionsStackView.axis = UILayoutConstraintAxisHorizontal;
    
    self.textLabel.textColor = [UIColor colorWithWhite:1 alpha:0.4];
    self.textLabel.font = [UIFont systemFontOfSize:12];
}

+ (instancetype)titleCellWithTitle:(NSString *)title {
    VerticalMenuItemCell *cell = [[VerticalMenuItemCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"titleCell"];
    cell.textLabel.font = [UIFont systemFontOfSize:16];
    cell.textLabel.textColor = [UIColor whiteColor];
    cell.textLabel.text = title;
    return cell;
}

@end


@interface VerticalMenuView ()<UITableViewDataSource>

/**
 模糊背景视图
 */
@property (nonatomic, strong) UIVisualEffectView *effectBackgroundView;

/**
 菜单表视图
 */
@property (nonatomic, strong) UITableView *tableView;

/**
 添加进来的单元格
 */
@property (nonatomic, strong) NSMutableArray<VerticalMenuItemCell *> *cells;

/**
 排除隐藏行后显示的单元格
 */
@property (nonatomic, strong) NSArray<VerticalMenuItemCell *> *displayCells;

/**
 隐藏的行
 */
@property (nonatomic, strong) NSMutableArray<NSNumber *> *hiddenRows;

/**
 动态计算的行高
 */
@property (nonatomic, assign, readonly) CGFloat contetHeight;

@end

@implementation VerticalMenuView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self commonInit];
    }
    return self;
}

- (void)commonInit {
    self.clipsToBounds = YES;
    
    _effectBackgroundView = [[UIVisualEffectView alloc] initWithEffect:[UIBlurEffect effectWithStyle:UIBlurEffectStyleDark]];
    [self addSubview:_effectBackgroundView];
    _effectBackgroundView.frame = self.bounds;
    _effectBackgroundView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    _tableView = [[UITableView alloc] initWithFrame:self.bounds style:UITableViewStylePlain];
    [_effectBackgroundView.contentView addSubview:_tableView];
    _tableView.dataSource = self;
    _tableView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    _tableView.backgroundColor = [UIColor clearColor];
    _tableView.tableFooterView = [UIView new];
    _tableView.allowsSelection = NO;
    _tableView.bounces = NO;
    _tableView.separatorInset = UIEdgeInsetsMake(0, 16, 0, 16);
    _tableView.separatorColor = [UIColor colorWithWhite:1 alpha:0.1];
    _tableView.rowHeight = 52;
    
    _cells = [NSMutableArray array];
    _hiddenRows = [NSMutableArray array];
}

- (CGSize)intrinsicContentSize {
    return CGSizeMake(-1, self.contetHeight);
}

#pragma mark - property

- (CGFloat)contetHeight {
    return _tableView.rowHeight * self.displayCells.count;
}

- (void)setTitle:(NSString *)title {
    if ([_title isEqualToString:title]) return;
    if ([_cells.firstObject.textLabel.text isEqualToString:_title]) {
        [_cells removeObjectAtIndex:0];
    }
    
    _title = title;
    [_cells addObject:[VerticalMenuItemCell titleCellWithTitle:title]];
}

- (NSArray<VerticalMenuItemCell *> *)displayCells {
    if (!_displayCells) {
        if (_hiddenRows.count) {
            NSMutableArray *displayCells = _cells.mutableCopy;
            for (NSNumber *rowNumber in _hiddenRows) {
                NSInteger row = rowNumber.integerValue;
                id cell = _cells[row];
                [displayCells removeObject:cell];
            }
            _displayCells = displayCells.copy;
        } else {
            _displayCells = _cells.copy;
        }
    }
    return _displayCells;
}

#pragma mark - table view data source

- (NSInteger)tableView:(nonnull UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.displayCells.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    return self.displayCells[indexPath.row];
}

#pragma mark - public

- (void)addCellWithTitle:(NSString *)title optionsConfig:(VerticalMenuItemOptionsViewConfig)configHandler {
    VerticalMenuItemCell *cell = [[VerticalMenuItemCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"menuItemCell"];
    [_cells addObject:cell];
    cell.textLabel.text = title;
    configHandler(cell.optionsStackView);
    UIStackView *stackView = cell.optionsStackView;
    CGRect optionsStackFrame = stackView.frame;
    optionsStackFrame.size = [self.class contentSizeFromStackView:stackView];
    stackView.frame = optionsStackFrame;
}

- (void)addHiddenRow:(NSInteger)hiddenRow {
    // 确保设置的 row 是合法的
    if (hiddenRow < 0 || hiddenRow >= _cells.count) {
        return;
    }
    [_hiddenRows addObject:@(hiddenRow)];
    _displayCells = nil;
    [_tableView reloadData];
}

- (void)removeHiddenRow:(NSInteger)hiddenRow {
    // 确保设置的 row 是合法的
    if (hiddenRow < 0 || hiddenRow >= _cells.count) {
        return;
    }
    [_hiddenRows removeObject:@(hiddenRow)];
    _displayCells = nil;
    [_tableView reloadData];
}

- (BOOL)isRowHidden:(NSInteger)row {
    return [_hiddenRows containsObject:@(row)];
}

#pragma mark - tool

/**
 计算栈视图内容尺寸

 @param stackView 栈视图
 @return 视图内容尺寸
 */
+ (CGSize)contentSizeFromStackView:(UIStackView *)stackView {
    CGFloat height = 0;
    CGFloat width = 0;
    for (UIView *view in stackView.arrangedSubviews) {
        CGSize subviewContentSize = view.intrinsicContentSize;
        if (stackView.axis == UILayoutConstraintAxisVertical) {
            if (subviewContentSize.width > width) width = subviewContentSize.width + stackView.spacing;
            height += subviewContentSize.height + stackView.spacing;
        } else if (stackView.axis == UILayoutConstraintAxisHorizontal) {
            if (subviewContentSize.height > height) height = subviewContentSize.height + stackView.spacing;
            width += subviewContentSize.width + stackView.spacing;
        }
    }
    height -= stackView.spacing;
    width -= stackView.spacing;
    return CGSizeMake(width, height);
}

@end

#pragma clang diagnostic pop
