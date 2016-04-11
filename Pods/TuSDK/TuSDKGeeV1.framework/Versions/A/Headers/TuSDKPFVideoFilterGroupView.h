//
//  TuSDKPFVideoFilterGroupView.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 2/3/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import "TuSDKVideoUIImport.h"

@class TuSDKPFVideoFilterGroupView;
/**
 *  视频滤镜视图委托
 */
@protocol TuSDKPFVideoFilterGroupViewDelegate <NSObject>
/**
 *  选中一个滤镜
 *
 *  @param view    相机滤镜视图
 *  @param item    滤镜分组元素
 *
 *  @return 是否允许继续执行
 */
- (BOOL)onTuSDKPFVideoFilterGroup:(TuSDKPFVideoFilterGroupView *)view
                     selectedItem:(TuSDKCPGroupFilterItem *)item;

/**
 *  相机滤镜视图状态改变
 *
 *  @param view   相机滤镜视图
 *  @param isShow 是否显示
 */
- (void)onTuSDKPFVideoFilterGroup:(TuSDKPFVideoFilterGroupView *)view
                     stateChanged:(BOOL)isShow;
@end

/**
 *  视频滤镜视图
 */
@interface TuSDKPFVideoFilterGroupView : TuSDKCPGroupFilterBaseView {
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
@property (nonatomic, assign) id<TuSDKPFVideoFilterGroupViewDelegate> delegate;

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
@end
