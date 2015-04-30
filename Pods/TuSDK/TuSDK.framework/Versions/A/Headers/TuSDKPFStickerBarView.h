//
//  TuSDKPFStickerBarView.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/28.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFStickerCategory.h"
#import "TuSDKICTableView.h"
#import "TuSDKPFStickerLocalView.h"

#pragma mark - TuSDKPFStickerTableCell
/**
 *  贴纸列表行视图
 */
@interface TuSDKPFStickerTableCell : TuSDKICTableViewCell{
    @protected
    // 单元格视图
    TuSDKPFStickerLocalGridView *_gridView;
}
/**
 *  单元格视图
 */
@property (nonatomic, readonly) TuSDKPFStickerLocalGridView *gridView;

/**
 *  图片边距
 */
@property (nonatomic) NSInteger innerWarpSpace;

/**
 *  数据对象
 */
@property (nonatomic, retain) TuSDKPFSticker *mode;
@end
#pragma mark - TuSDKPFStickerTableView
@class TuSDKPFStickerTableView;
/**
 *  贴纸列表视图委托
 */
@protocol TuSDKPFStickerTableViewDelegate <NSObject>
/**
 *  选中一个行视图
 *
 *  @param view      贴纸列表视图
 *  @param data      数据对象
 *  @param indexPath 选中索引
 */
- (void)stickerTableView:(TuSDKPFStickerTableView *)view
            selectedData:(TuSDKPFSticker *)data
               indexPath:(NSIndexPath *)indexPath;
@end

/**
 *  贴纸列表视图
 */
@interface TuSDKPFStickerTableView : UIView<UITableViewDataSource, UITableViewDelegate>
/**
 *  滤镜分组元素视图类 (默认:TuSDKPFStickerTableCell, 需要继承 TuSDKPFStickerTableCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  贴纸列表视图委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerTableViewDelegate> delegate;

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

#pragma mark - TuSDKPFStickerBarView

@class TuSDKPFStickerBarView;
/**
 *  贴纸栏视图委托
 */
@protocol TuSDKPFStickerBarViewDelegate <NSObject>
/**
 *  选中一个贴纸数据
 *
 *  @param view    贴纸栏视图
 *  @param data    贴纸数据对象
 */
- (void)stickerBarView:(TuSDKPFStickerBarView *)view selectSticker:(TuSDKPFSticker *)data;

/**
 *  选择一个空分类
 *
 *  @param view 贴纸栏视图
 *  @param cate 贴纸分类
 */
- (void)stickerBarView:(TuSDKPFStickerBarView *)view emptyWithCategory:(TuSDKPFStickerCategory *)cate;
@end

/**
 *  贴纸栏视图
 */
@interface TuSDKPFStickerBarView : UIView<TuSDKPFStickerLocalPackageDelegate, TuSDKPFStickerTableViewDelegate>{
    @protected
    // 参数选项视图
    UIView *_paramsView;
    // 分割线1
    UIView *_splitOne;
    // 分割线2
    UIView *_splitTwo;
    // 空数据标题
    UIButton *_emptyTitle;
    // 贴纸列表视图
    TuSDKPFStickerTableView *_tableBar;
}
/**
 *  贴纸栏视图委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerBarViewDelegate> delegate;
/**
 *  参数选项视图
 */
@property (nonatomic, readonly) UIView *paramsView;
/**
 *  分割线1
 */
@property (nonatomic, readonly) UIView *splitOne;
/**
 *  分割线2
 */
@property (nonatomic, readonly) UIView *splitTwo;
/**
 *  空数据标题
 */
@property (nonatomic, readonly) UIButton *emptyTitle;
/**
 *  贴纸列表视图
 */
@property (nonatomic, readonly) TuSDKPFStickerTableView *tableView;

/**
 *  单元格高度
 */
@property (nonatomic) NSUInteger gridHeight;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  加载分类数据
 *
 *  @param categories 分类数据
 */
- (void)loadCatategories: (NSArray *)categories;

/**
 *  创建分类按钮
 *
 *  @param cate  贴纸分类
 *  @param frame 位置信息
 *
 *  @return 分类按钮
 */
- (UIButton *)buildButtonWithCategory:(TuSDKPFStickerCategory *)cate frame:(CGRect)frame;

/**
 *  刷新分类贴纸数据
 */
- (void)refreshCateDatas;

/**
 *  选中一个空数据分类
 */
- (void)onCategoryEmptyAction;
@end
