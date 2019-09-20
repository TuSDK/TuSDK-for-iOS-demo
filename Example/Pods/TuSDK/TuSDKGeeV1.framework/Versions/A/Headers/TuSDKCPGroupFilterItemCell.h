//
//  TuSDKCPGroupFilterItemCell.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/18.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"

#pragma mark - TuSDKCPGroupFilterItemCell
/**
 *  滤镜分组元素视图
 */
@interface TuSDKCPGroupFilterItemCell : TuSDKCPGroupFilterItemCellBase<TuSDKCPGroupFilterItemCellInterface>{
    @protected
    // 包装视图
    UIView *_wrapView;
    // 图片视图
    UIImageView *_thumbView;
    // 标题视图
    UILabel *_titleView;
    // 选中状态视图
    UIView *_selectedView;
    // 图标视图
    UIImageView *_iconView;
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
 *  标识视图
 */
@property (nonatomic, readonly) UIView *flagView;
/**
 *  选中状态视图
 */
@property (nonatomic, readonly) UIView *selectedView;
/**
 *  图标视图
 */
@property (nonatomic, readonly) UIImageView *iconView;
@end

#pragma mark - TuSDKCPGroupFilterGroupCell
/**
 *  滤镜分组视图
 */
@interface TuSDKCPGroupFilterGroupCell : TuSDKCPGroupFilterGroupCellBase{
    @protected
    // 包装视图
    UIView *_wrapView;
    // 图片视图
    UIImageView *_thumbView;
    // 图片视图蒙版效果
    UIView *_thumbMaskView;
    // 标题视图
    UILabel *_titleView;
    // 选中状态视图
    UIView *_selectedView;
    // 图标视图
    UIImageView *_iconView;
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
 *  标识视图
 */
@property (nonatomic, readonly) UIView *flagView;
/**
 *  选中状态视图
 */
@property (nonatomic, readonly) UIView *selectedView;
/**
 *  图标视图
 */
@property (nonatomic, readonly) UIImageView *iconView;
/**
 *  删除按钮
 */
@property (nonatomic, readonly) UIButton *removeButton;
@end