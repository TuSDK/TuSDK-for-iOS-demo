//
//  GeeV2PFBrushTableItemCell.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV2Import.h"

#pragma mark - GeeV2PFBrushTableItemCell
/**
 *  笔刷列表行视图
 */
@interface GeeV2PFBrushTableItemCell : TuSDKPFBrushTableItemCellBase
{
@protected
    // 包装视图
    UIView *_wrapView;
    // 图片视图
    UIImageView *_thumbView;
    // 标题视图
    UILabel *_titleView;
    // 标题背景
    UIView *_titleBgView;
    // 选中状态视图
    UIImageView *_selectedView;
    /**删除按钮*/
    UIButton *_removeButton;
}

/**
 *  包装视图
 */
@property (nonatomic, readonly) UIView *wrapView;
/**
 *  标题视图
 */
@property (nonatomic, readonly) UILabel *titleView;
/**
 *  标题视图
 */
@property (nonatomic, readonly) UIView *titleBgView;
/**
 *  选中状态视图
 */
@property (nonatomic, readonly) UIImageView *selectedView;

@end

