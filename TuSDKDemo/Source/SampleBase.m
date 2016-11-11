//
//  SampleBase.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "SampleBase.h"

#pragma mark - SampleBase
/**
 *  范例基础类
 */
@implementation SampleBase
/**
 *  范例基础类
 *
 *  @return 范例基础类
 */
+ (instancetype)sample;
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
- (instancetype)initWithGroupId:(SampleType)groupId title:(NSString *)title;
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
- (void)showSampleWithController:(UIViewController *)controller;
{
    lsqLDebug(@"You need rewrite the %@ func: - (void)showSampleWithController:(UIViewController *)controller;", [self class]);
}
@end


#pragma mark - GroupHeader
/**
 *  范例分组头部信息
 */
@implementation GroupHeader : NSObject
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

#pragma mark - SampleGroup
/**
 *  范例分组
 */
@implementation SampleGroup : NSObject
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
                         [GroupHeader headerWithGroupId:RecommendSample title:NSLocalizedString(@"sample_group_recommend", @"官方推荐")],
                         [GroupHeader headerWithGroupId:SuiteSample title:NSLocalizedString(@"sample_group_suite", @"功能套件")],
                         [GroupHeader headerWithGroupId:ComponentSample title:NSLocalizedString(@"sample_group_comp", @"常用组件")],
                         [GroupHeader headerWithGroupId:FeatureSample title:NSLocalizedString(@"sample_group_examples", @"组件用法示例")],
                         [GroupHeader headerWithGroupId:UISample title:NSLocalizedString(@"sample_group_extend", @"自定义界面示例")],
                         [GroupHeader headerWithGroupId:APISample title:NSLocalizedString(@"sample_group_define", @"API 使用示例")],
                         ];
    }
    return self;
}


/**
 *  添加范例
 *
 *  @param simple 范例
 */
- (void)appenWithSample:(SampleBase *)sample;
{
    if (!sample) return;
    
    for (GroupHeader *header in self.headers) {
        if (header.groupId == sample.groupId) {
            [header.datas addObject:sample];
        }
    }
}

/**
 *  添加范例
 *
 *  @param title               标题
 *  @param type                分组
 *  @param viewControllerClazz 控制器类
 */
- (void)appenWithTitle:(NSString *)title group:(SampleType)type clazz:(Class)viewControllerClazz;
{
    SampleBase *sample = [SampleBase new];
    sample.title = title;
    sample.groupId = type;
    sample.controllerClazz = viewControllerClazz;
    
    [self appenWithSample:sample];
}

/**
 *  获取范例分组头部信息
 *
 *  @param index 索引
 *
 *  @return 范例分组头部信息
 */
- (GroupHeader *)headerWithIndex:(NSUInteger)index;
{
    if (!self.headers || self.headers.count <= index) return nil;
    return [self.headers objectAtIndex:index];
}
@end