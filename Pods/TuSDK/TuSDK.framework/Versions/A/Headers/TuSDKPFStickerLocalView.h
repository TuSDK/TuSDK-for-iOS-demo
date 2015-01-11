//
//  TuSDKPFStickerLocalView.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKICTableView.h"
#import "TuSDKICPagerView.h"
#import "TuSDKAOCellGridViewAlgorithmic.h"
#import "TuSDKICTableViewCell.h"
#import "TuSDKPFStickerLocalPackage.h"

/**
 *  本地贴纸选择列表委托
 */
@protocol TuSDKPFStickerLocalViewProtocol <NSObject>
/**
 *  选中一个贴纸
 *
 *  @param sticker 贴纸对象
 */
- (void)onTuSDKPFStickerLocalViewSelected:(TuSDKPFSticker *)sticker;
@end

#pragma mark - TuSDKPFStickerLocalGridView
/**
 *  本地贴纸选择单元格视图
 */
@interface TuSDKPFStickerLocalGridView : UIButton
/**
 *  图片视图
 */
@property(nonatomic,readonly) UIImageView *thumbView;
/**
 *  贴纸对象数据
 */
@property (nonatomic, retain) TuSDKPFSticker *data;
@end

#pragma mark - TuSDKPFStickerLocalCellView
/**
 *  本地贴纸选择列表行视图
 */
@interface TuSDKPFStickerLocalCellView : TuSDKICTableViewCell
/**
 *  单元格视图
 */
@property (nonatomic, readonly) NSArray *gridViews;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerLocalViewProtocol> gridProtocol;

/**
 *  设置数据
 *
 *  @param data 数据
 */
- (void)setData:(NSArray *)data;
@end

#pragma mark - TuSDKPFStickerLocalListView
/**
 *  本地贴纸选择列表视图
 */
@interface TuSDKPFStickerLocalListView : UIView<TuSDKICPagerHolderViewProtocol, UITableViewDataSource, UITableViewDelegate>
/**
 *  列表视图
 */
@property (nonatomic, readonly) TuSDKICTableView *tableView;
/**
 *  输入的数据
 */
@property (nonatomic, retain) TuSDKPFStickerCategory *data;
/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerLocalViewProtocol> gridProtocol;
@end

#pragma mark - TuSDKPFEditFilterBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFStickerLocalBottomBar : UIView
/**
 *  取消按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  分类视图
 */
@property (nonatomic, readonly) UIView *categoryView;

/**
 *  选中标识视图
 */
@property (nonatomic, readonly) UIView *cursorView;

/**
 *  分类按钮
 */
@property (nonatomic, readonly) NSArray *buttons;

/**
 *  按钮宽度
 */
@property (nonatomic, readonly) CGFloat buttonWidth;

/**
 *  当前选中索引
 */
@property (nonatomic) NSUInteger selectedIndex;

/**
 *  创建分类按钮
 *
 *  @param categories 分类
 *  @param target 目标对象
 *  @param action 动作
 */
- (void)categories:(NSArray *)categories touchTarget:(id)target action:(SEL)action;

/**
 *  创建分类按钮
 *
 *  @param index 索引
 *  @param left  左边距离
 *  @param title 按钮标题
 *
 *  @return 分类按钮
 */
- (UIButton *)buildCategoryButtonWithIndex:(NSUInteger)index left:(NSUInteger)left title:(NSString *)title;
@end

#pragma mark - TuSDKPFStickerLocalView
/**
 *  本地贴纸选择控制器视图
 */
@interface TuSDKPFStickerLocalView : UIView
/**
 *  横向分页视图
 */
@property (nonatomic, readonly) TuSDKICPagerView *pagerView;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFStickerLocalBottomBar *bottomBar;
@end
