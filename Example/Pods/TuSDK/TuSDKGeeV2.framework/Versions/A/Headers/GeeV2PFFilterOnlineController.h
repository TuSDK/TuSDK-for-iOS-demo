//
//  GeeV2PFFilterOnlineController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"

#pragma mark - GeeV2PFFilterOnlineController
/**
 *  在线滤镜控制器
 */
@interface GeeV2PFFilterOnlineController : TuSDKPFFilterOnlineControllerBase<TuSDKCPFilterOnlineControllerInterface>
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
@property (nonatomic, weak) id<TuSDKCPFilterOnlineControllerDelegate> delegate;
@end
