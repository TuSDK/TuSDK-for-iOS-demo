//
//  TuSDKCPSubtitlesView.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/19.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  字幕视图
 */
@interface TuSDKCPSubtitlesView : UIView{
    // 主标题视图
    UILabel *_titleView;
    // 子标题视图
    UILabel *_subTitleView;
}
/**
 *  主标题视图
 */
@property (nonatomic, readonly) UILabel *titleView;

/**
 *  子标题视图
 */
@property (nonatomic, readonly) UILabel *subTitleView;

/**
 *  设置标题
 *
 *  @param title    主标题
 *  @param subTitle 子标题
 */
- (void)setTitle:(NSString *)title subTitle:(NSString *)subTitle;
@end
