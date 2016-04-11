//
//  TuSDKPFCameraFilterGroupView.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 15/2/19.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"
#import "TuSDKCPGroupFilterBar.h"

@class TuSDKPFCameraFilterGroupView;
/**
 *  相机滤镜视图委托
 */
@protocol TuSDKPFCameraFilterGroupViewDelegate <NSObject>
/**
 *  选中一个滤镜
 *
 *  @param view    相机滤镜视图
 *  @param item    滤镜分组元素
 *  @param capture 是否允许拍摄
 *
 *  @return 是否允许继续执行
 */
- (BOOL)onTuSDKPFCameraFilterGroup:(TuSDKPFCameraFilterGroupView *)view
                      selectedItem:(TuSDKCPGroupFilterItem *)item
                           capture:(BOOL)capture;

/**
 *  相机滤镜视图状态改变
 *
 *  @param view   相机滤镜视图
 *  @param isShow 是否显示
 */
- (void)onTuSDKPFCameraFilterGroup:(TuSDKPFCameraFilterGroupView *)view
                      stateChanged:(BOOL)isShow;
@end

/**
 *  相机滤镜视图
 */
@interface TuSDKPFCameraFilterGroupView : TuSDKPFCameraFilterGroupViewBase{
    @protected
    // 滤镜组选择栏
    UIView<TuSDKCPGroupFilterBarInterface> *_filterBar;
    // 滤镜标题视图
    UIView<TuSDKCPSubtitlesViewInterface> *_titleView;
    // 底部栏目
    UIView *_bottomView;
    // 关闭按钮
    UIButton *_closeButton;
}

/**
 *  相机滤镜视图委托
 */
@property (nonatomic, assign) id<TuSDKPFCameraFilterGroupViewDelegate> delegate;

/**
 *  底部栏目
 */
@property (nonatomic, readonly) UIView *bottomView;
/**
 *  关闭按钮
 */
@property (nonatomic, readonly) UIButton *closeButton;

/**
 *  显示滤镜组视图
 */
- (void)showGroupView;

/**
 *  加载滤镜，并选中指定滤镜
 *
 *  @param option 默认显示的滤镜配置选项
 */
- (void)loadFilters:(TuSDKFilterOption *)option;
@end
