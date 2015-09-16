//
//  TuSDKPFFilterOnlineController.h
//  TuSDK
//
//  Created by Clear Hu on 15/5/21.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKPFFilterOnlineController
/**
 *  在线滤镜控制器
 */
@interface TuSDKPFFilterOnlineController : TuSDKPFFilterOnlineControllerBase<TuSDKCPFilterOnlineControllerInterface>
{
@protected
    // 默认样式视图
    TuSDKCPOnlineView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKCPOnlineView *defaultStyleView;
/**
 *  在线滤镜选择控制器委托
 */
@property (nonatomic, assign) id<TuSDKCPFilterOnlineControllerDelegate> delegate;
@end
