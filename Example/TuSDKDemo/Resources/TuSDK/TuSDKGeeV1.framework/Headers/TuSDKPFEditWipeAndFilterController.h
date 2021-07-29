//
//  TuSDKPFEditWipeAndFilterController.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 12/3/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFEditWipeAndFilterView.h"

#pragma mark - TuSDKPFEditCuterControllerDelegate
@class TuSDKPFEditWipeAndFilterController;
/**
 *  滤镜涂抹控制器委托
 */
@protocol TuSDKPFEditWipeAndFilterControllerDelegate <TuComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 滤镜涂抹控制器
 *  @param result 处理结果
 */
- (void)onTuSDKPFEditWipeAndFilter:(TuSDKPFEditWipeAndFilterController *)controller result:(TuResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 滤镜涂抹控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditWipeAndFilter:(TuSDKPFEditWipeAndFilterController *)controller result:(TuResult *)result;
@end


#pragma mark - TuSDKPFEditWipeAndFilterController
/**
 *  滤镜涂抹控制器
 */
@interface TuSDKPFEditWipeAndFilterController : TuEditWipeAndFilterControllerBase<TuSDKPFEditWipeAndFilterConfigBarDelegate>
{
    // 默认样式视图
    TuSDKPFEditWipeAndFilterView *_defaultStyleView;
}

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditWipeAndFilterView *defaultStyleView;

/**
 *  滤镜涂抹控制器委托
 */
@property (nonatomic, weak) id<TuSDKPFEditWipeAndFilterControllerDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFEditWipeAndFilterView, 需要继承 TuSDKPFEditWipeAndFilterView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  默认的笔刷大小 (默认: lsqMediumBrush，中等粗细)
 */
@property (nonatomic, assign) TuSDKBrushSize defaultBrushSize;

/**
 *  默认撤销的最大次数 (默认: 5)
 */
@property (nonatomic, assign) NSUInteger maxUndoCount;

@end
