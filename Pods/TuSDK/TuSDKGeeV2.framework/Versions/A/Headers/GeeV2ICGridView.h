//
//  GeeV2ICGridView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"

/**
 *  网格视图
 */
@interface GeeV2ICGridView : UICollectionView{
    
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
 *  @return grid 表格视图 (默认以屏幕高宽 style = UITableViewStylePlain 初始化)
 */
+ (instancetype)grid;

/**
 *  初始化(使用屏幕宽度)
 *
 *  @param height 高度
 *
 *  @return height 表格视图
 */
+ (instancetype)gridWithHeight:(float)height;

/**
 *  初始化
 *
 *  @param frame 坐标长宽
 *
 *  @return 表格视图 默认以style = UITableViewStylePlain 初始化
 */
+ (instancetype)initWithFrame:(CGRect)frame;

/**
 *  初始化视图
 */
- (void)lsqInitView;

@end
