//
//  TuSDKPFEditFilterView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCPFilterResultView.h"
#import "TuSDKPFEditFilterGroupView.h"
#import "TuSDKGeeV1Import.h"


#pragma mark - TuSDKPFEditFilterView
/**
 *  图片编辑滤镜控制器视图
 */
@interface TuSDKPFEditFilterView : UIView
{
    // 图片视图
    UIView<TuSDKICFilterImageViewInterface> *_imageView;
    // 底部动作栏
    TuSDKPFEditFilterBottomBar *_bottomBar;
    // 滤镜列表视图
    TuSDKPFEditFilterGroupView *_filterBar;
}
/**
 *  图片视图
 */
@property (nonatomic, readonly) UIView<TuSDKICFilterImageViewInterface> *imageView;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFEditFilterBottomBar *bottomBar;

/**
 *  滤镜列表视图
 */
@property (nonatomic, readonly) TuSDKPFEditFilterGroupView *filterBar;
@end
