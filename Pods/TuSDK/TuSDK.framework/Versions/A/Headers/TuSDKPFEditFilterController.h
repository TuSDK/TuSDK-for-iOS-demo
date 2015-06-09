//
//  TuSDKPFEditFilterController.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPImageResultController.h"
#import "TuSDKPFEditFilterController.h"
#import "TuSDKPFEditFilterView.h"
#import "TuSDKFilterWrap.h"

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
 *  @return 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKPFEditFilter:(TuSDKPFEditFilterController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - TuSDKPFEditFilterController
/**
 *  图片编辑滤镜控制器
 */
@interface TuSDKPFEditFilterController : TuSDKCPImageResultController<TuSDKPFEditFilterBarDelegate, TuSDKICGPUImageViewDelegate>{
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
@property (nonatomic, assign) id<TuSDKPFEditFilterControllerDelegate> delegate;

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
 *  滤镜列表行视图类 (默认:TuSDKCPGroupFilterItem, 需要继承 TuSDKCPGroupFilterItem)
 */
@property (nonatomic, strong)Class filterBarTableCellClazz;

/**
 *  开启滤镜配置选项
 */
@property (nonatomic) BOOL enableFilterConfig;

/**
 *  开启滤镜历史记录
 */
@property (nonatomic) BOOL enableFilterHistory;

/**
 *  是否仅返回滤镜，不返回处理图片
 */
@property (nonatomic) BOOL onlyReturnFilter;

/**
 *  当前所使用的滤镜
 */
@property (nonatomic, retain) TuSDKFilterWrap *filterWrap;

/**
 *  配置滤镜栏视图
 *
 *  @param view 滤镜栏视图
 */
- (void)configWithGroupFilterView:(TuSDKCPGroupFilterBaseView *)view;

/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion;
@end
