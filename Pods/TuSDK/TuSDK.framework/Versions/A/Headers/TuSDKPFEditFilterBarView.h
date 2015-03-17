//
//  TuSDKPFEditFilterBarView.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/20.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPGroupFilterBaseView.h"
#import "TuSDKCPParameterConfigView.h"
#import "TuSDKFilterWrap.h"

@class TuSDKPFEditFilterBarView;

/**
 *  图片编辑滤镜控制器滤镜栏视图委托
 */
@protocol TuSDKPFEditFilterBarDelegate <NSObject>
/**
 *  选中一个滤镜
 *
 *  @param view 图片编辑滤镜控制器滤镜栏视图
 *  @param item 滤镜分组元素
 *
 *  @return 是否允许继续执行
 */
- (BOOL)onTuSDKPFEditFilterBar:(TuSDKPFEditFilterBarView *)view
                  selectedItem:(TuSDKCPGroupFilterItem *)item;

/**
 *  通知重新绘制
 *
 *  @param view 图片编辑滤镜控制器滤镜栏视图
 */
- (void)requestRenderTuSDKPFEditFilterBar:(TuSDKPFEditFilterBarView *)view;
@end
/**
 *  图片编辑滤镜控制器滤镜栏视图
 */
@interface TuSDKPFEditFilterBarView : TuSDKCPGroupFilterBaseView<TuSDKCPParameterConfigDelegate>
{
    @protected
    // 参数配置视图
    TuSDKCPParameterConfigView *_configView;
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
@property (nonatomic, assign) id<TuSDKPFEditFilterBarDelegate> delegate;

/**
 *  参数配置视图
 */
@property (nonatomic, readonly) TuSDKCPParameterConfigView *configView;

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
 *  滤镜对象
 */
@property (nonatomic, retain) TuSDKFilterWrap *filter;

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
