//
//  TuSDKGeeV1Theme.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 9/23/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TuSDKGeeV1Theme : NSObject

/**
 *  TuSDKGeeV1 导航条样色
 *
 *  @return 界面颜色主题
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
 *  设置导航条样式，包括背景色，标题颜色，左边按钮，右边按钮
 */
- (void)setNavigationBarStyle:(UINavigationBar *)bar;

@end
