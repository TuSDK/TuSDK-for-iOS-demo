//
//  SampleBase.h
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKFramework.h"

typedef NS_ENUM(NSUInteger, SampleType)
{
    /**
     * 套件
     */
    RecommendSample,
    /**
     * 套件
     */
    SuiteSample,
    /**
     * 视图控件类
     */
    ComponentSample,
    /**
     * 组件示例
     */
    FeatureSample,
    /**
     * 自定义UI示例
     */
    UISample,
    /**
     * API示例
     */
    APISample
};

#pragma mark - SampleBase
/**
 *  范例基础类
 */
@interface SampleBase : NSObject
/**
 *  分组ID
 */
@property (nonatomic) SampleType groupId;
/**
 *  标题
 */
@property (nonatomic, copy) NSString *title;

/**
 *  启动控制器
 */
@property (nonatomic, assign) UIViewController *controller;

/**
 *  控制器类
 */
@property (nonatomic, assign) Class controllerClazz;

/**
 *  范例基础类
 *
 *  @return 范例基础类
 */
+ (instancetype)sample;

/**
 *  范例基础类
 *
 *  @param groupId 分组ID
 *  @param title   标题
 *
 *  @return 范例基础类
 */
- (instancetype)initWithGroupId:(SampleType)groupId title:(NSString *)title;

/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSampleWithController:(UIViewController *)controller;
@end

#pragma mark - GroupHeader
/**
 *  范例分组头部信息
 */
@interface GroupHeader : NSObject
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

#pragma mark - SampleGroup
/**
 *  范例分组
 */
@interface SampleGroup : NSObject
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
- (void)appenWithSample:(SampleBase *)sample;

/**
 *  添加范例
 *
 *  @param title               标题
 *  @param type                分组
 *  @param viewControllerClazz 控制器类
 */
- (void)appenWithTitle:(NSString *)title group:(SampleType)type clazz:(Class)viewControllerClazz;

/**
 *  获取范例分组头部信息
 *
 *  @param index 索引
 *
 *  @return 范例分组头部信息
 */
- (GroupHeader *)headerWithIndex:(NSUInteger)index;
@end