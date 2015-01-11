//
//  TuSDKTKFiltersTaskBase.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/9.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TuSDKTKFilterImageWare.h"

/**
 *  滤镜任务基类
 */
@interface TuSDKTKFiltersTaskBase : NSObject{
    @protected
    // 预览图根路径
    NSString *_sampleRootPath;
    // 图片视图列表
    NSMutableArray *_viewGroups;
    // 任务是否已完成
    BOOL _taskCompleted;
}
/**
 *  输入滤镜名称
 */
@property (nonatomic, retain) NSArray *filerNames;

/**
 *  图片视图列表
 */
@property (nonatomic, readonly) NSArray *viewGroups;

/**
 *  任务是否已完成
 */
@property (nonatomic, readonly) BOOL taskCompleted;

/**
 *  开始执行任务
 */
- (void)start;

/**
 *  根据类型获取滤镜预览图
 *
 *  @param name 滤镜名称
 *
 *  @return 滤镜预览图
 */
- (UIImage *)sampleImageWithFilterName:(NSString *)name;

/**
 *  通知视图处理结果
 *
 *  @param result 处理结果
 */
- (void)notifyImageViewWithResult:(TuSDKTKFilterTaskResult *)result;

/**
 *  重置滤镜列表
 */
- (void)resetQueues;

/**
 *  加载图片
 *
 *  @param view 图片视图
 *  @param name 滤镜名称
 */
- (void)loadImageWithView:(UIImageView *)view filterName:(NSString *)name;

/**
 *  取消加载图片
 *
 *  @param view 图片视图
 */
- (void)cancelLoadImageWithView:(UIImageView *)view;
@end
