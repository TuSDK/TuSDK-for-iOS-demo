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
#import "TuSDKPFEmptyView.h"

/**
 *  本地贴纸列表行标题视图动作
 */
typedef NS_ENUM(NSInteger, lsqStickerSectionHeaderAction)
{
    /**
     * 删除动作
     */
    lsqStickerSectionHeaderActionRemove,
    /**
     * 查看详细动作
     */
    lsqStickerSectionHeaderActionDetail,
};

/**
 *  本地贴纸列表行标题视图委托
 */
@protocol TuSDKPFStickerLocalSectionHeaderProtocol <NSObject>
/**
 *  删除下载贴纸
 *
 *  @param action 本地贴纸列表行标题视图动作
 *  @param group 贴纸包
 */
- (void)onTuSDKPFStickerLocalViewAction:(lsqStickerSectionHeaderAction)action
                                  group:(TuSDKPFStickerGroup *)group;
@end

/**
 *  本地贴纸选择列表委托
 */
@protocol TuSDKPFStickerLocalViewProtocol <TuSDKPFStickerLocalSectionHeaderProtocol>
/**
 *  选中一个贴纸
 *
 *  @param sticker 贴纸对象
 */
- (void)onTuSDKPFStickerLocalViewSelected:(TuSDKPFSticker *)sticker;

/**
 *  空视图动作
 */
- (void)onTuSDKPFStickerLocalViewEmptyAction;
@end
#pragma mark - TuSDKPFStickerLocalEmptyView
/**
 *  本地贴纸空视图
 */
@interface TuSDKPFStickerLocalEmptyView : TuSDKPFEmptyView
{
    /**
     *  信息视图
     */
    UILabel *_msgView;
    /**
     *  更多按钮
     */
    UIButton *_moreButton;
}
/**
 *  信息视图
 */
@property (nonatomic, readonly) UILabel *msgView;
/**
 *  更多按钮
 */
@property (nonatomic, readonly) UIButton *moreButton;
@end

#pragma mark - TuSDKPFStickerLocalSectionHeader
/**
 *  本地贴纸列表行标题视图
 */
@interface TuSDKPFStickerLocalSectionHeader : UIView
{
    // 标题标签
    UIButton *_titleLabel;
    // 删除按钮
    UIButton *_removeButton;
}
/**
 *  标题标签
 */
@property (nonatomic, readonly) UIButton *titleLabel;

/**
 *  删除按钮
 */
@property (nonatomic, readonly) UIButton *removeButton;

/**
 *  贴纸包
 */
@property (nonatomic, retain) TuSDKPFStickerGroup *group;

/**
 *  本地贴纸列表行标题视图委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerLocalSectionHeaderProtocol> delegate;
@end

#pragma mark - TuSDKPFStickerLocalGridView
/**
 *  本地贴纸选择单元格视图
 */
@interface TuSDKPFStickerLocalGridView : UIButton
{
    // 图片视图
    UIImageView *_thumbView;
}
/**
 *  图片视图
 */
@property(nonatomic,readonly) UIImageView *thumbView;
/**
 *  贴纸对象数据
 */
@property (nonatomic, retain) TuSDKPFSticker *data;

/**
 *  图片边距
 */
@property (nonatomic) NSInteger innerWarpSpace;

/**
 *  需要重置视图
 */
-(void)viewNeedRest;

/**
 *  绘制成圆形
 */
- (void)makeRadius;
@end

#pragma mark - TuSDKPFStickerLocalCellView
/**
 *  本地贴纸选择列表行视图
 */
@interface TuSDKPFStickerLocalCellView : TuSDKICTableViewCell
/**
 *  表格单元格视图类 (默认:TuSDKPFStickerLocalGridView, 需要继承 TuSDKPFStickerLocalGridView)
 */
@property (nonatomic, strong) Class gridViewClazz;

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
{
    // 列表视图
    TuSDKICTableView *_tableView;
}
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

/**
 *  表格行视图类 (默认:TuSDKPFStickerLocalCellView, 需要继承 TuSDKPFStickerLocalCellView)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  表格单元格视图类 (默认:TuSDKPFStickerLocalGridView, 需要继承 TuSDKPFStickerLocalGridView)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 *  表格行头部视图类 (默认:TuSDKPFStickerLocalSectionHeader, 需要继承 TuSDKPFStickerLocalSectionHeader)
 */
@property (nonatomic, strong) Class cellHeaderViewClazz;

/**
 *  空数据视图类 (默认:TuSDKPFStickerLocalEmptyView, 需要继承 TuSDKPFStickerLocalEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;
@end

#pragma mark - TuSDKPFEditFilterBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFStickerLocalBottomBar : UIView
{
    // 分类视图
    UIView *_categoryView;
    // 选中标识视图
    UIView *_cursorView;
}

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
{
    // 横向分页视图
    TuSDKICPagerView *_pagerView;
    // 底部动作栏
    TuSDKPFStickerLocalBottomBar *_bottomBar;
}

/**
 *  横向分页视图
 */
@property (nonatomic, readonly) TuSDKICPagerView *pagerView;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) TuSDKPFStickerLocalBottomBar *bottomBar;
@end
