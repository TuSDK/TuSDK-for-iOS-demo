//
//  GeeV2PFEditFilterGroupView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV2Import.h"

@class GeeV2PFEditFilterGroupView;

/**
 *  图片编辑滤镜控制器滤镜栏视图委托
 */
@protocol GeeV2PFEditFilterGroupDelegate <NSObject>
/**
 *  选中一个滤镜
 *
 *  @param view 图片编辑滤镜控制器滤镜栏视图
 *  @param item 滤镜分组元素
 *
 *  @return BOOL 是否允许继续执行
 */
- (BOOL)onTuSDKPFEditFilterGroup:(GeeV2PFEditFilterGroupView *)view
                    selectedItem:(TuGroupFilterItem *)item;
@end
/**
 *  图片编辑滤镜控制器滤镜栏视图
 */
@interface GeeV2PFEditFilterGroupView : TuEditFilterGroupViewBase<TuParameterConfigDelegate>
{
@protected
    // 滤镜组选择栏
    UIView<TuStackFilterBarInterface> *_filterBar;
    // 滤镜标题视图
    UIView<TuSubtitlesViewInterface> *_titleView;
    // 参数配置视图
    UIView<TuParameterConfigViewInterface> *_configView;
    // 控制栏
    UIView *_bottomBar;
}

/**
 *  图片编辑滤镜控制器滤镜栏视图委托
 */
@property (nonatomic, weak) id<GeeV2PFEditFilterGroupDelegate> delegate;

/**
 *  参数配置视图
 */
@property (nonatomic, readonly) UIView<TuParameterConfigViewInterface> *configView;

/**
 *  滤镜组选择栏底部距离
 */
@property (nonatomic) CGFloat filterBarBottom;

/**
 *  加载滤镜
 *
 *  @param option 滤镜配置选项
 */
- (void)loadFilters:(TuFilterOption *)option;
@end
