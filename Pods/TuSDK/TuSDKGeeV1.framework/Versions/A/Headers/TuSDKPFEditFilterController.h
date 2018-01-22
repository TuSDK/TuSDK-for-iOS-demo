//
//  TuSDKPFEditFilterController.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditFilterView.h"

#pragma mark - TuSDKPFEditFilterControllerDelegate
@class TuSDKPFEditFilterController;
/**
 *  图片编辑滤镜控制器委托
 */
@protocol TuSDKPFEditFilterControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑滤镜控制器
 *  @param result 处理结果
 */
- (void)onTuSDKPFEditFilter:(TuSDKPFEditFilterController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑滤镜控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditFilter:(TuSDKPFEditFilterController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - TuSDKPFEditFilterController
/**
 *  图片编辑滤镜控制器
 */
@interface TuSDKPFEditFilterController : TuSDKPFEditFilterControllerBase<TuSDKPFEditFilterGroupDelegate>{
@protected
    // 默认样式视图
    TuSDKPFEditFilterView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditFilterView *defaultStyleView;

/**
 *  图片编辑滤镜控制器委托
 */
@property (nonatomic, weak) id<TuSDKPFEditFilterControllerDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFEditFilterView, 需要继承 TuSDKPFEditFilterView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  需要显示的滤镜名称列表 (如果为空将显示所有自定义滤镜)
 */
@property (nonatomic, retain) NSArray *filterGroup;

/**
 *  滤镜列表行视图宽度
 */
@property (nonatomic)CGFloat filterBarCellWidth;

/**
 *  滤镜列表选择栏高度
 */
@property (nonatomic)CGFloat filterBarHeight;

/**
 *  滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
 */
@property (nonatomic, strong)Class filterBarGroupCellClazz;

/**
 *  滤镜列表行视图类 (默认:TuSDKCPGroupFilterItemCell, 需要继承 TuSDKCPGroupFilterItemCell)
 */
@property (nonatomic, strong)Class filterBarTableCellClazz;

/**
 *  开启滤镜配置选项 (默认: 开启)
 */
@property (nonatomic) BOOL enableFilterConfig;

/**
 *  开启滤镜历史记录
 */
@property (nonatomic) BOOL enableFilterHistory;

/**
 *  开启无效果滤镜 (默认: 开启)
 */
@property (nonatomic) BOOL enableNormalFilter;

/**
 *  开启在线滤镜
 */
@property (nonatomic) BOOL enableOnlineFilter;

/**
 *  显示滤镜标题视图
 */
@property (nonatomic) BOOL displayFilterSubtitles;

/**
 *  在线滤镜控制器类型 (需要继承 UIViewController,以及实现TuSDKCPFilterOnlineControllerInterface接口)
 */
@property (nonatomic) Class onlineControllerClazz;

/**
 *  是否渲染滤镜封面 (使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TUTUCLOUD.com控制台)
 */
@property (nonatomic) BOOL isRenderFilterThumb;

/**
 *  配置滤镜栏视图
 *
 *  @param view 滤镜栏视图
 */
- (void)configWithGroupFilterView:(TuSDKCPGroupFilterBaseView *)view;
@end
