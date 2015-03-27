//
//  TuSDKPFEmptyView.h
//  TuSDK
//
//  Created by Clear Hu on 14/12/12.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  照片空视图
 */
@interface TuSDKPFEmptyView : UIView
{
    /**
     *  图标视图
     */
    UIImageView *_iconView;
    /**
     *  标题视图
     */
    UILabel *_titleView;
}

/**
 *  图标视图
 */
@property (nonatomic, readonly) UIImageView *iconView;
/**
 *  标题视图
 */
@property (nonatomic, readonly) UILabel *titleView;
/**
 *  初始化视图
 */
- (void)initView;

/**
 *  重置位置大小
 *
 *  @param frame 重置位置大小
 */
- (void)resetFrame:(CGRect)frame;
@end
