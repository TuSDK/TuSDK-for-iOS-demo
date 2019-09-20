//
//  GeeV2PFStickerBarView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeeV2PFStickerLocalView.h"

#pragma mark - GeeV2PFStickerTableCell
/**
 *  贴纸列表行视图
 */
@interface GeeV2PFStickerTableCell : TuSDKICTableViewCell{
@protected
    // 单元格视图
    GeeV2PFStickerLocalGridView *_gridView;
}
/**
 *  单元格视图
 */
@property (nonatomic, readonly) GeeV2PFStickerLocalGridView *gridView;

/**
 *  图片边距
 */
@property (nonatomic) NSInteger innerWarpSpace;

/**
 *  数据对象
 */
@property (nonatomic, retain) TuSDKPFSticker *mode;
@end

#pragma mark - GeeV2PFStickerTableView

@class GeeV2PFStickerTableView;
/**
 *  贴纸列表视图委托
 */
@protocol GeeV2PFStickerTableViewDelegate <NSObject>
/**
 *  选中一个行视图
 *
 *  @param view      贴纸列表视图
 *  @param data      数据对象
 *  @param indexPath 选中索引
 */
- (void)stickerTableView:(GeeV2PFStickerTableView *)view
            selectedData:(TuSDKPFSticker *)data
               indexPath:(NSIndexPath *)indexPath;
@end

/**
 *  贴纸列表视图
 */
@interface GeeV2PFStickerTableView : UIView<UITableViewDataSource, UITableViewDelegate>
/**
 *  滤镜分组元素视图类 (默认:GeeV2PFStickerTableCell, 需要继承 GeeV2PFStickerTableCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  贴纸列表视图委托
 */
@property (nonatomic, weak) id<GeeV2PFStickerTableViewDelegate> delegate;

/**
 *  数据列表
 */
@property (nonatomic, retain) NSArray *modeList;

/**
 *  单元格间距
 */
@property (nonatomic) NSInteger gridPadding;

/**
 *  列表视图
 */
@property (nonatomic, readonly)TuSDKICTableView *tableView;

/**
 *  刷新数据
 *
 *  @param goHeader 是否回到头部
 */
- (void)reloadData:(BOOL)goHeader;
@end

#pragma mark - GeeV2PFStickerBarView

@class GeeV2PFStickerBarView;
/**
 *  贴纸栏视图委托
 */
@protocol GeeV2PFStickerBarViewDelegate <NSObject>
/**
 *  选中一个贴纸数据
 *
 *  @param view    贴纸栏视图
 *  @param data    贴纸数据对象
 */
- (void)stickerBarView:(GeeV2PFStickerBarView *)view selectSticker:(TuSDKPFSticker *)data;

/**
 *  选择一个空分类
 *
 *  @param view 贴纸栏视图
 *  @param cate 贴纸分类
 */
- (void)stickerBarView:(GeeV2PFStickerBarView *)view emptyWithCategory:(TuSDKPFStickerCategory *)cate;
@end

/**
 *  贴纸栏视图
 */
@interface GeeV2PFStickerBarView : TuSDKPFStickerBarViewBase<GeeV2PFStickerTableViewDelegate>{
@protected
    // 贴纸列表视图
    GeeV2PFStickerTableView *_tableBar;
}
/**
 *  贴纸栏视图委托
 */
@property (nonatomic, weak) id<GeeV2PFStickerBarViewDelegate> delegate;

/**
 *  贴纸列表视图
 */
@property (nonatomic, readonly) GeeV2PFStickerTableView *tableView;

/**
 *  数据列表
 */
@property (nonatomic, retain) TuSDKPFStickerGroup *stickerGroup;

/**
 *  单元格高度
 */
@property (nonatomic) NSUInteger gridHeight;

/**
 *  更新布局
 */
- (void)needUpdateLayout;
@end
