//
//  TuSDKPFEditFilterGroupView.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/20.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"

@class TuSDKPFEditFilterGroupView;

/**
 *  图片编辑滤镜控制器滤镜栏视图委托
 */
@protocol TuSDKPFEditFilterGroupDelegate <NSObject>
/**
 *  选中一个滤镜
 *
 *  @param view 图片编辑滤镜控制器滤镜栏视图
 *  @param item 滤镜分组元素
 *
 *  @return BOOL 是否允许继续执行
 */
- (BOOL)onTuSDKPFEditFilterGroup:(TuSDKPFEditFilterGroupView *)view
                    selectedItem:(TuSDKCPGroupFilterItem *)item;

/**
 *  通知重新绘制
 *
 *  @param view 图片编辑滤镜控制器滤镜栏视图
 */
- (void)requestRenderTuSDKPFEditFilterGroup:(TuSDKPFEditFilterGroupView *)view;
@end
/**
 *  图片编辑滤镜控制器滤镜栏视图
 */
@interface TuSDKPFEditFilterGroupView : TuSDKPFEditFilterGroupViewBase<TuSDKCPParameterConfigDelegate>
{
    @protected
    // 滤镜组选择栏
    UIView<TuSDKCPGroupFilterBarInterface> *_filterBar;
    // 滤镜标题视图
    UIView<TuSDKCPSubtitlesViewInterface> *_titleView;
    // 参数配置视图
    UIView<TuSDKCPParameterConfigViewInterface> *_configView;
    // 控制栏
    UIView *_bottomBar;
    // 取消按钮
    UIButton *_cancelButton;
    // 完成按钮
    UIButton *_completeButton;
}

/**
 *  图片编辑滤镜控制器滤镜栏视图委托
 */
@property (nonatomic, weak) id<TuSDKPFEditFilterGroupDelegate> delegate;

/**
 *  参数配置视图
 */
@property (nonatomic, readonly) UIView<TuSDKCPParameterConfigViewInterface> *configView;

/**
 *  控制栏
 */
@property (nonatomic, readonly) UIView *bottomBar;

/**
 *  取消按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *completeButton;

/**
 *  滤镜组选择栏底部距离
 */
@property (nonatomic) CGFloat filterBarBottom;

/**
 *  加载滤镜
 *
 *  @param option 滤镜配置选项
 */
- (void)loadFilters:(TuSDKFilterOption *)option;
@end
