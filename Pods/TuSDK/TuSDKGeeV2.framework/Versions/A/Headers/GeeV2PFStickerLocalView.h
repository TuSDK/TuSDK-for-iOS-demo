//
//  GeeV2PFStickerLocalView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"

/**
 *  本地贴纸列表行标题视图动作
 */
typedef NS_ENUM(NSInteger, lsqGeeV2StickerSectionHeaderAction)
{
    /**
     * 删除动作
     */
    lsqGeeV2StickerSectionHeaderActionRemove,
    /**
     * 查看详细动作
     */
    lsqGeeV2StickerSectionHeaderActionDetail,
};

/**
 *  本地贴纸列表行标题视图委托
 */
@protocol GeeV2PFStickerLocalSectionHeaderProtocol <NSObject>
/**
 *  删除下载贴纸
 *
 *  @param action 本地贴纸列表行标题视图动作
 *  @param group 贴纸包
 */
- (void)onTuSDKPFStickerLocalViewAction:(lsqGeeV2StickerSectionHeaderAction)action
                                  group:(TuSDKPFStickerGroup *)group;
@end

/**
 *  本地贴纸选择列表委托
 */
@protocol GeeV2PFStickerLocalViewProtocol <GeeV2PFStickerLocalSectionHeaderProtocol>
/**
 *  选中一个贴纸
 *
 *  @param sticker 贴纸对象
 */
- (void)onTuSDKPFStickerLocalViewSelected:(TuSDKPFSticker *)sticker stickerGroup:(TuSDKPFStickerGroup *)stickerGroup;

/**
 *  空视图动作
 */
- (void)onTuSDKPFStickerLocalViewEmptyAction;
@end
#pragma mark - GeeV2PFStickerLocalEmptyView
/**
 *  本地贴纸空视图
 */
@interface GeeV2PFStickerLocalEmptyView : TuSDKICEmptyView
{
    /**
     *  信息视图
     */
    UILabel *_msgView;
}
/**
 *  信息视图
 */
@property (nonatomic, readonly) UILabel *msgView;
@end

#pragma mark - GeeV2PFStickerLocalSectionHeader
/**
 *  本地贴纸列表行标题视图
 */
@interface GeeV2PFStickerLocalSectionHeader : UIView
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
@property (nonatomic, weak) id<GeeV2PFStickerLocalSectionHeaderProtocol> delegate;
@end

#pragma mark - GeeV2PFStickerLocalGridView
/**
 *  本地贴纸选择单元格视图
 */
@interface GeeV2PFStickerLocalGridView : TuSDKPFStickerLocalGridViewBase
{
    // 图片视图
    UIImageView *_thumbView;
}

/**
 *  图片边距
 */
@property (nonatomic) NSInteger innerWarpSpace;

/**
 *  绘制成圆形
 */
- (void)makeRadius;
@end

#pragma mark - GeeV2PFStickerLocalCellView
/**
 *  本地贴纸选择列表行视图
 */
@interface GeeV2PFStickerLocalCellView : TuSDKICTableViewCell
/**
 *  表格单元格视图类 (默认:GeeV2PFStickerLocalGridView, 需要继承 GeeV2PFStickerLocalGridView)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 *  单元格视图
 */
@property (nonatomic, readonly) NSArray *gridViews;

/**
 *  当前贴纸组
 */
@property (nonatomic, retain) TuSDKPFStickerGroup *stickerGroup;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<GeeV2PFStickerLocalViewProtocol> gridProtocol;

/**
 *  设置数据
 *
 *  @param data 数据
 */
- (void)setData:(NSArray *)data;
@end

#pragma mark - GeeV2PFStickerLocalListView
/**
 *  本地贴纸选择列表视图
 */
@interface GeeV2PFStickerLocalListView : UIView<TuSDKICPagerHolderViewProtocol, UITableViewDataSource, UITableViewDelegate>
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
@property (nonatomic, assign) id<GeeV2PFStickerLocalViewProtocol> gridProtocol;

/**
 *  表格行视图类 (默认:GeeV2PFStickerLocalCellView, 需要继承 GeeV2PFStickerLocalCellView)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  表格单元格视图类 (默认:GeeV2PFStickerLocalGridView, 需要继承 GeeV2PFStickerLocalGridView)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 *  表格行头部视图类 (默认:GeeV2PFStickerLocalSectionHeader, 需要继承 GeeV2PFStickerLocalSectionHeader)
 */
@property (nonatomic, strong) Class cellHeaderViewClazz;

/**
 *  空数据视图类 (默认:GeeV2PFStickerLocalEmptyView, 需要继承 GeeV2PFStickerLocalEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;
@end

#pragma mark - GeeV2PFEditFilterBottomBar
/**
 *  底部动作栏
 */
@interface GeeV2PFStickerLocalBottomBar : UIView
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

@end

#pragma mark - GeeV2PFStickerLocalView
/**
 *  本地贴纸选择控制器视图
 */
@interface GeeV2PFStickerLocalView : UIView
{
    // 横向分页视图
    TuSDKICPagerView *_pagerView;
    // 底部动作栏
    GeeV2PFStickerLocalBottomBar *_bottomBar;
}

/**
 *  横向分页视图
 */
@property (nonatomic, readonly) TuSDKICPagerView *pagerView;

/**
 *  底部动作栏
 */
@property (nonatomic, readonly) GeeV2PFStickerLocalBottomBar *bottomBar;
@end
