//
//  GeeV2PFEditTabBar.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/10/9.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"

@class GeeV2PFEditTabBar;

@protocol GeeV2PFEditTabBarDelegate <NSObject>
/**
 *  工具栏按钮被选中, 记录从哪里跳转到哪里.
 */
- (void)onTuSDKPFFragmentTabBar:(GeeV2PFEditTabBar *)tabBar selectedFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;

@end

@interface GeeV2PFEditTabBar : UIView

@property(nonatomic,weak) id<GeeV2PFEditTabBarDelegate> delegate;
/**
 *  添加按钮
 *
 *  @param title     标题
 *  @param imageName 图片
 */
- (void)addButtonWithTitle:(NSString *)title imageLSQBundleNamed:(NSString *)imageName;

@end

#pragma mark - GeeV2PFEditTabBarView

@interface GeeV2PFEditTabBarView : UIView

/**
 *  返回按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *doneButton;
/**
 *  顶部部工具栏
 */
@property (nonatomic, readonly) UIView *topView;
/**
 *  底部工具栏
 */
@property (nonatomic, readonly) GeeV2PFEditTabBar *bottomTabBar;

/**
 *  绑定功能模块
 *
 *  @param modules 功能模块列表
 *  @param target  绑定事件对象
 *  @param action  绑定事件
 */
- (void)bindModules:(NSArray *)modules target:(id)target;

@end
