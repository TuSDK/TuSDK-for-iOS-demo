//
//  TuSDKPFEditTurnAndCutViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/7.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKPFEditTurnAndCutView.h"

@class TuSDKPFEditTurnAndCutViewController;

#pragma mark - TuSDKPFEditTurnAndCutDelegate
/**
 *  旋转和裁剪视图控制器委托
 */
@protocol TuSDKPFEditTurnAndCutDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 旋转和裁剪视图控制器
 *  @param result 旋转和裁剪视图控制器处理结果
 */
- (void)onTuSDKPFEditTurnAndCut:(TuSDKPFEditTurnAndCutViewController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 旋转和裁剪视图控制器
 *  @param result 旋转和裁剪视图控制器处理结果
 *  @return 是否截断默认处理逻辑 (默认: false, 设置为True时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditTurnAndCut:(TuSDKPFEditTurnAndCutViewController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - TuSDKPFEditTurnAndCutViewController
/**
 *  旋转和裁剪视图控制器
 */
@interface TuSDKPFEditTurnAndCutViewController : TuSDKPFEditTurnAndCutViewControllerBase<TuSDKPFNormalFilterGroupDelegate>{
    @protected
    // 默认样式视图
    TuSDKPFEditTurnAndCutView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditTurnAndCutView *defaultStyleView;

/**
 *  旋转和裁剪视图控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFEditTurnAndCutDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFEditTurnAndCutView, 需要继承 TuSDKPFEditTurnAndCutView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  旋转和裁剪视图控制栏类 (默认:TuSDKPFEditTurnAndCutBottomView, 需要继承 TuSDKPFEditTurnAndCutBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  图片编辑视图 (旋转，缩放)类 (默认:TuSDKICTouchImageView, 需要继承 TuSDKICTouchImageView)
 */
@property (nonatomic, strong) Class editImageViewClazz;

/**
 *  滤镜列表视图类 (默认:TuSDKPFNormalFilterGroupView, 需要继承 TuSDKPFNormalFilterGroupView)
 */
@property (nonatomic, strong) Class filterViewClazz;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  开启滤镜历史记录
 */
@property (nonatomic) BOOL enableFilterHistory;

/**
 *  开启在线滤镜
 */
@property (nonatomic) BOOL enableOnlineFilter;

/**
 *  在线滤镜控制器类型 (需要继承 UIViewController,以及实现TuSDKCPFilterOnlineControllerInterface接口)
 */
@property (nonatomic) Class onlineControllerClazz;

/**
 *  显示滤镜标题视图
 */
@property (nonatomic) BOOL displayFilterSubtitles;

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
 *  滤镜列表行视图类 (默认:TuSDKCPGroupFilterItem, 需要继承 TuSDKCPGroupFilterItem)
 */
@property (nonatomic, strong)Class filterBarTableCellClazz;

/**
 *  是否渲染滤镜封面 (使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TuSDK.com控制台)
 */
@property (nonatomic) BOOL isRenderFilterThumb;

/**
 *  配置滤镜栏视图
 *
 *  @param view 滤镜栏视图
 */
- (void)configWithGroupFilterView:(TuSDKCPGroupFilterBaseView *)view;
@end
