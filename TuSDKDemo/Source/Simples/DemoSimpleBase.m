//
//  DemoSimpleBase.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "DemoSimpleBase.h"

#pragma mark - DemoSimpleBase
/**
 *  范例基础类
 */
@implementation DemoSimpleBase
/**
 *  范例基础类
 *
 *  @return 范例基础类
 */
+ (instancetype)simple;
{
    return [[self alloc]init];
}

/**
 *  范例基础类
 *
 *  @param groupId 分组ID
 *  @param title   标题
 *
 *  @return 范例基础类
 */
- (instancetype)initWithGroupId:(NSUInteger)groupId title:(NSString *)title;
{
    self = [super init];
    if (self) {
        _groupId = groupId;
        _title = title;
    }
    return self;
}

/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSimpleWithController:(UIViewController *)controller;
{
    lsqLDebug(@"You need rewrite the %@ func: - (void)showSimpleWithController:(UIViewController *)controller;", [self class]);
}
@end


#pragma mark - DemoGroupHeader
/**
 *  范例分组头部信息
 */
@implementation DemoGroupHeader : NSObject
/**
 *  范例分组头部信息
 *
 *  @param groupId 分组ID
 *  @param title   标题
 *
 *  @return 范例基础类
 */
+ (instancetype)headerWithGroupId:(NSUInteger)groupId title:(NSString *)title;
{
    return [[self alloc]initWithGroupId:groupId title:title];
}

- (instancetype)initWithGroupId:(NSUInteger)groupId title:(NSString *)title;
{
    self = [super init];
    if (self) {
        _groupId = groupId;
        _title = title;
        _datas = [NSMutableArray array];
    }
    return self;
}
@end

#pragma mark - DemoSimpleGroup
/**
 *  范例分组
 */
@implementation DemoSimpleGroup : NSObject
/**
 *  范例分组
 *
 *  @return 范例分组
 */
+ (instancetype)group;
{
    return [[self alloc]init];
}

- (instancetype)init;
{
    self = [super init];
    if (self) {
        self.headers = @[
                         [DemoGroupHeader headerWithGroupId:1 title:NSLocalizedString(@"simple_group_comp", @"基础组件")],
                         [DemoGroupHeader headerWithGroupId:2 title:NSLocalizedString(@"simple_group_adv_comp", @"高级组件")],
                         [DemoGroupHeader headerWithGroupId:3 title:NSLocalizedString(@"simple_group_extend", @"扩展组件")],
                         [DemoGroupHeader headerWithGroupId:4 title:NSLocalizedString(@"simple_group_define", @"自定义组件")],
                         ];
    }
    return self;
}


/**
 *  添加范例
 *
 *  @param simple 范例
 */
- (void)appenWithSimple:(DemoSimpleBase *)simple;
{
    if (!simple) return;
    
    for (DemoGroupHeader *header in self.headers) {
        if (header.groupId == simple.groupId) {
            [header.datas addObject:simple];
        }
    }
}

/**
 *  获取范例分组头部信息
 *
 *  @param index 索引
 *
 *  @return 范例分组头部信息
 */
- (DemoGroupHeader *)headerWithIndex:(NSUInteger)index;
{
    if (!self.headers || self.headers.count <= index) return nil;
    return [self.headers objectAtIndex:index];
}
@end