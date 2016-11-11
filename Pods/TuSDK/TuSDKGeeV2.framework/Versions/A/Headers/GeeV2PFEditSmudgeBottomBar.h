//
//  GeeV2PFEditSmudgeBottomBar.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeeV2PFBrushBarView.h"
/**
 *  笔刷旋转类型
 */
typedef NS_ENUM(NSInteger, lsqGeeV2BrushSize)
{
    /**
     * 小
     */
    lsqGeeV2SmallBrush = 0,
    /**
     * 中
     */
    lsqGeeV2MediumBrush,
    /**
     * 大
     */
    lsqGeeV2LargeBrush,
    /**
     * 超大
     */
    lsqGeeV2SuperBrush,
};

#pragma mark - GeeV2PFEditSmudgeBottomBar
/**
 *  底部动作栏
 */
@interface GeeV2PFEditSmudgeBottomBar : UIView

/**
 *  笔触按钮
 */
@property (nonatomic, readonly) NSMutableArray *brushButtons;

/**
 *  笔刷栏视图
 */
@property (nonatomic, readonly) GeeV2PFBrushBarView *brushBar;
@end
