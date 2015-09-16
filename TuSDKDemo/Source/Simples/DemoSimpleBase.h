//
//  DemoSimpleBase.h
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKFramework.h"

#pragma mark - DemoSimpleBase
/**
 *  范例基础类
 */
@interface DemoSimpleBase : NSObject
/**
 *  分组ID
 */
@property (nonatomic) NSUInteger groupId;
/**
 *  标题
 */
@property (nonatomic, copy) NSString *title;

/**
 *  启动控制器
 */
@property (nonatomic, assign) UIViewController *controller;

/**
 *  范例基础类
 *
 *  @return 范例基础类
 */
+ (instancetype)simple;

/**
 *  范例基础类
 *
 *  @param groupId 分组ID
 *  @param title   标题
 *
 *  @return 范例基础类
 */
- (instancetype)initWithGroupId:(NSUInteger)groupId title:(NSString *)title;

/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSimpleWithController:(UIViewController *)controller;
@end

#pragma mark - DemoGroupHeader
/**
 *  范例分组头部信息
 */
@interface DemoGroupHeader : NSObject
/**
 *  分组ID
 */
@property (nonatomic) NSUInteger groupId;
/**
 *  标题
 */
@property (nonatomic, copy) NSString *title;

/**
 *  数据列表
 */
@property (nonatomic, retain) NSMutableArray *datas;

/**
 *  范例分组头部信息
 *
 *  @param groupId 分组ID
 *  @param title   标题
 *
 *  @return 范例基础类
 */
+ (instancetype)headerWithGroupId:(NSUInteger)groupId title:(NSString *)title;
@end

#pragma mark - DemoSimpleGroup
/**
 *  范例分组
 */
@interface DemoSimpleGroup : NSObject
/**
 *  范例分组头部信息列表
 */
@property (nonatomic, retain) NSArray *headers;

/**
 *  范例分组
 *
 *  @return 范例分组
 */
+ (instancetype)group;

/**
 *  添加范例
 *
 *  @param simple 范例
 */
- (void)appenWithSimple:(DemoSimpleBase *)simple;

/**
 *  获取范例分组头部信息
 *
 *  @param index 索引
 *
 *  @return 范例分组头部信息
 */
- (DemoGroupHeader *)headerWithIndex:(NSUInteger)index;
@end