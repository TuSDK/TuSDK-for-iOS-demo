//
//  GeeV2PFEditFilterView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeeV2CPFilterResultView.h"
#import "GeeV2PFEditFilterGroupView.h"
#import "TuSDKGeeV2Import.h"

#pragma mark - GeeV2PFEditFilterView
/**
 *  图片编辑滤镜控制器视图
 */
@interface GeeV2PFEditFilterView : UIView
{
    // 图片视图
    UIView<TuSDKICFilterImageViewInterface> *_imageView;
    // 顶部动作栏
    GeeV2PFEditFilterBottomBar *_topBar;
    // 滤镜列表视图
    GeeV2PFEditFilterGroupView *_filterBar;
}
/**
 *  图片视图
 */
@property (nonatomic, readonly) UIView<TuSDKICFilterImageViewInterface> *imageView;

/**
 *  顶部动作栏
 */
@property (nonatomic, readonly) GeeV2PFEditFilterBottomBar *topBar;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) GeeV2PFEditFilterGroupView *filterBar;
@end
