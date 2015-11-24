//
//  TuSDKPFBrushTableItemCell.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 11/8/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKPFBrushTableItemCell
/**
 *  笔刷列表行视图
 */
@interface TuSDKPFBrushTableItemCell : TuSDKPFBrushTableItemCellBase
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

