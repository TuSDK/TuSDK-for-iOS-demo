//
//  GeeV2PFEditWipeAndFilterController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeeV2PFEditWipeAndFilterView.h"
#import "GeeV2PFEditTabBarSubControllerInterface.h"

#pragma mark - GeeV2PFEditCuterControllerDelegate
@class GeeV2PFEditWipeAndFilterController;
/**
 *  滤镜涂抹控制器委托
 */
@protocol GeeV2PFEditWipeAndFilterControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 滤镜涂抹控制器
 *  @param result 处理结果
 */
- (void)onGeeV2PFEditWipeAndFilter:(GeeV2PFEditWipeAndFilterController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 滤镜涂抹控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncGeeV2PFEditWipeAndFilter:(GeeV2PFEditWipeAndFilterController *)controller result:(TuSDKResult *)result;
@end


#pragma mark - GeeV2PFEditWipeAndFilterController
/**
 *  滤镜涂抹控制器
 */
@interface GeeV2PFEditWipeAndFilterController : TuSDKPFEditWipeAndFilterControllerBase<GeeV2PFEditTabBarSubControllerInterface,GeeV2PFEditWipeAndFilterConfigBarDelegate>
{
    // 默认样式视图
    GeeV2PFEditWipeAndFilterView *_defaultStyleView;
}

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFEditWipeAndFilterView *defaultStyleView;

/**
 *  滤镜涂抹控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFEditWipeAndFilterControllerDelegate> delegate;

/**
 *  视图类 (默认:GeeV2PFEditWipeAndFilterView, 需要继承 GeeV2PFEditWipeAndFilterView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  默认的笔刷大小 (默认: lsqMediumBrush，中等粗细)
 */
@property (nonatomic, assign) lsqBrushSize defaultBrushSize;

/**
 *  默认撤销的最大次数 (默认: 5)
 */
@property (nonatomic, assign) NSUInteger maxUndoCount;

@end
