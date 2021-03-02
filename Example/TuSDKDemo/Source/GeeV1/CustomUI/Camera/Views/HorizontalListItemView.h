//
//  HorizontalListItemView.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/6/27.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HorizontalListView.h"


/**
 水平方向列表项视图，标题在下方内侧
 */
@interface HorizontalListItemView : HorizontalListItemBaseView

/**
 缩略图视图
 */
@property (nonatomic, strong) UIImageView *thumbnailView;

/**
 标题标签
 */
@property (nonatomic, strong, readonly) UILabel *titleLabel;

/**
 选中图片视图
 */
@property (nonatomic, strong, readonly) UIImageView *selectedImageView;

@property (nonatomic, strong, readonly) UIButton *touchButton;

/**
 tapCount 与选中状态同步

 @param selected 是否选中
 */
- (void)setTapCountWithSelected:(BOOL)selected;

/**
 创建禁用列表项
 */
+ (instancetype)disableItemView;

/**
 便利创建对象

 @param image 缩略图
 @param title 标题
 @return HorizontalListItemView 对象
 */
+ (instancetype)itemViewWithImage:(UIImage *)image title:(NSString *)title;

#pragma mark - rewrite

- (void)commonInit;

@end
