//
//  TuSDKICTableView.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/28.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  表格视图
 */
@interface TuSDKICTableView : UITableView{
@protected
    /**
     *  缓存标记 (初始化时自动创建: [NSString stringWithFormat:@"%@Cell", [self class]])
     */
    NSString *_cellIdentifier;
}
/**
 *  缓存标记 (初始化时自动创建: [NSString stringWithFormat:@"%@Cell", [self class]])
 */
@property (nonatomic, readonly) NSString *cellIdentifier;

/**
 *  初始化(使用全屏大小)
 *
 *  @return 表格视图 (默认以屏幕高宽 style = UITableViewStylePlain 初始化)
 */
+ (instancetype)table;

/**
 *  初始化(使用屏幕宽度)
 *
 *  @param height 高度
 *
 *  @return 表格视图
 */
+ (instancetype)tableWithHeight:(float)height;

/**
 *  初始化
 *
 *  @param frame 坐标长宽
 *
 *  @return 表格视图 默认以style = UITableViewStylePlain 初始化
 */
+ (instancetype)initWithFrame:(CGRect)frame;

/**
 *  初始化
 *
 *  @param frame 坐标长宽
 *  @param style 表格样式
 *
 *  @return 表格视图
 */
+ (instancetype)initWithFrame:(CGRect)frame style:(UITableViewStyle)style;

/**
 *  初始化视图
 */
- (void)initView;

/**
 *  使用tableHeaderView占位顶部
 *
 *  @param height 头部高度
 */
- (void)setTopHeight:(float)height;

/**
 *  取消默认选中状态
 *
 *  @param enable 是否取消选中
 */
- (void)deselectRow:(BOOL)enable;
@end
