//
//  TuSDKICGridView.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 8/12/15.
//  Copyright (c) 2015 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"

/**
 *  网格视图
 */
@interface TuSDKICGridView : UICollectionView{

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
+ (instancetype)grid;

/**
 *  初始化(使用屏幕宽度)
 *
 *  @param height 高度
 *
 *  @return 表格视图
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
- (void)initView;


@end
