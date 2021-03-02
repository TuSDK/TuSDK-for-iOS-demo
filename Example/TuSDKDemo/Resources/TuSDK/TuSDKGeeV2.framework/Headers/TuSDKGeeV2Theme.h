//
//  TuSDKGeeV2Theme.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TuSDKGeeV2Theme : NSObject
/**
 *  TuSDKGeeV2 导航条样色
 *
 *  @return shared 界面颜色主题
 */
+ (instancetype)shared;

/**
 *  导航条背景颜色
 */
@property (nonatomic, retain) UIColor *navigationBackgroundColor;

/**
 *  导航条左边按钮文本颜色
 */
@property (nonatomic, retain) UIColor *navigationLeftTextColor;
/**
 *  导航条右边按钮文本颜色
 */
@property (nonatomic, retain) UIColor *navigationRightTextColor;
/**
 *  导航条标题文本颜色
 */
@property (nonatomic, retain) UIColor *navigationTitleTextColor;

/**
 *  底部工具栏背景颜色
 */
@property (nonatomic, retain) UIColor *bottomBarBackgroundColor;

/**
 *  编辑器中部背景颜色
 */
@property (nonatomic, retain) UIColor *editorBackgroundColor;

/**
 *  编辑器工具选择栏背景颜色
 */
@property (nonatomic, retain) UIColor *editorOptionBarBackgroundColor;

/**
 *  视图边框颜色
 */
@property (nonatomic, retain) UIColor *viewBorderColor;

/**
 *  视图渲染颜色
 */
@property (nonatomic, retain) UIColor *viewTintColor;

/**
 *  选中文本颜色
 */
@property (nonatomic, retain) UIColor *selectedTextColor;

/**
 *  设置导航条样式，包括背景色，标题颜色，左边按钮，右边按钮
 */
- (void)setNavigationBarStyle:(UINavigationBar *)bar;

@end
