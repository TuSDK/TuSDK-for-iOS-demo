//
//  DemoRootView.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "DemoRootView.h"

#pragma mark - DemoRootView
/**
 *  入口控制器视图
 */
@interface DemoRootView()<UITableViewDelegate, UITableViewDataSource>
{
    // 表格视图
    TuSDKICTableView *_tableView;
    // 缓存标记
    NSString *_cellIdentifier;
}
@end

@implementation DemoRootView
- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self initView];
    }
    return self;
}
- (void)initView;
{
    // 缓存标记
    _cellIdentifier = [NSString stringWithFormat:@"%@", [self class]];
    
    // 表格视图
    _tableView = [TuSDKICTableView tableWithHeight:self.frame.size.height];
    _tableView.delegate = self;
    _tableView.dataSource = self;
    _tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
    _tableView.backgroundColor = [UIColor whiteColor];
    _tableView.rowHeight = 50;
    _tableView.sectionHeaderHeight = 30;
    [self addSubview:_tableView];
}

- (void)setGroup:(DemoSimpleGroup *)group;
{
    _group = group;
    
    if (_tableView) [_tableView reloadData];
}

/**
 *  获取一个范例
 *
 *  @param indexPath 索引
 *
 *  @return 范例
 */
- (DemoSimpleBase *)simpleWithIndexPath:(NSIndexPath *)indexPath;
{
    if (!indexPath || !_group) return nil;
    
    DemoGroupHeader *header = [_group headerWithIndex:indexPath.section];
    if (!header || !header.datas || header.datas.count <= indexPath.row) return nil;
    
    return [header.datas objectAtIndex:indexPath.row];
}
#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
{
    if (!self.delegate) return;
        
    DemoSimpleBase *simple = [self simpleWithIndexPath:indexPath];
    if (!simple) return;
    
    [self.delegate demoRootView:self selectedSimple:simple withAction:demoListItemActionSelected];
}
#pragma mark - UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView;
{
    if (!_group) return 1;
    return _group.headers.count;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
{
    if (!_group) return 0;
    DemoGroupHeader *header = [_group headerWithIndex:section];
    if (!header || !header.datas) return 0;
    return header.datas.count;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section;
{
    DemoGroupHeader *header = [_group headerWithIndex:section];
    if (!header) return nil;
    return header.title;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
{
    TuSDKICTableViewCell * cell = [tableView dequeueReusableCellWithIdentifier:_cellIdentifier];
    if (!cell) {
        cell = [TuSDKICTableViewCell initWithReuseIdentifier:_cellIdentifier];
        cell.textLabel.font = lsqFontSize(15);
    }
    
    DemoSimpleBase *simple = [self simpleWithIndexPath:indexPath];
    if (!simple) return cell;
    cell.textLabel.text = [NSString stringWithFormat:@"    %@", simple.title];
    return cell;
}
@end
