//
//  DemoRootView.h
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKFramework.h"
#import "SampleBase.h"

/**
 *  范例列表行点击动作
 */
typedef NS_ENUM(NSInteger, demoListItemAction)
{
    /**
     * 选中
     */
    demoListItemActionSelected,
    /**
     * 配置
     */
    demoListItemActionConfig,
};

@class DemoRootView;

/**
 *  范例列表视图委托
 */
@protocol DemoRootViewDelegate <NSObject>
/**
 *  选中范例
 *
 *  @param view   入口控制器视图
 *  @param simple 范例
 *  @param action 范例列表行点击动作
 */
- (void)demoRootView:(DemoRootView *)view
      selectedSample:(SampleBase *)simple
          withAction:(demoListItemAction)action;
@end


#pragma mark - DemoRootView
/**
 *  入口控制器视图
 */
@interface DemoRootView : UIView
/**
 *  范例列表视图委托
 */
@property (nonatomic, weak) id<DemoRootViewDelegate> delegate;

/**
 *  范例分组
 */
@property (nonatomic, retain) SampleGroup *group;
@end