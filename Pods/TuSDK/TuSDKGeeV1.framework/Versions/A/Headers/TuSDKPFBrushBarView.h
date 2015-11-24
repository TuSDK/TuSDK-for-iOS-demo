//
//  TuSDKPFBrushBarView.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 10/27/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKPFBrushTableItemCell.h"

#pragma mark - TuSDKPFEditSmudgeBottomBar
/**
 *  底部动作栏
 */
@interface TuSDKPFEditSmudgeBottomBar : UIView
{
    // 取消按钮
    UIButton *_cancelButton;
    // 完成按钮
    UIButton *_completeButton;
    // 撤销按钮
    UIButton *_undoButton;
    // 重做按钮
    UIButton *_redoButton;
    // 查看原图按钮
    UIButton *_originalButton;
}

/**
 *  取消按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *completeButton;

/**
 *  撤销按钮
 */
@property (nonatomic, readonly) UIButton *undoButton;

/**
 *  重做按钮
 */
@property (nonatomic, readonly) UIButton *redoButton;

/**
 *  查看原图按钮
 */
@property (nonatomic, readonly) UIButton *originalButton;

/**
 *  更新布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - TuSDKPFBrushTableView
/**
 *  笔刷列表视图
 */
@interface TuSDKPFBrushTableView : UIView<UITableViewDataSource, UITableViewDelegate, TuSDKPFBrushTableViewInterface>
/**
 *  滤镜分组元素视图类 (默认:TuSDKPFBrushTableItemCell, 需要继承 TuSDKPFBrushTableItemCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  行视图宽度
 */
@property (nonatomic)CGFloat cellWidth;

/**
 *  滤镜分组元素类型
 */
@property (nonatomic) lsqBrushAction action;

/**
 *  笔刷列表视图委托
 */
@property (nonatomic, assign) id<TuSDKPFBrushTableViewDelegate> delegate;

/**
 *  数据列表
 */
@property (nonatomic, retain) NSArray *modeList;

/**
 *  列表视图
 */
@property (nonatomic, readonly)TuSDKICTableView *tableView;

@end

#pragma mark - TuSDKPFBrushBarView


@class TuSDKPFBrushBarView;
/**
 *  笔刷栏视图委托
 */
@protocol TuSDKPFBrushBarViewDelegate <NSObject>
/**
 *  选中一个笔刷数据
 *
 *  @param view    笔刷栏视图
 *  @param data    笔刷数据对象
 */
- (void)brushBarView:(TuSDKPFBrushBarView *)view selectBrush:(TuSDKPFBrush *)data;

/**
 *  点击笔刷粗细按钮
 */
- (void)onBrushSizeButtonClick;
@end


@interface TuSDKPFBrushBarView : TuSDKPFBrushBarViewBase<TuSDKPFBrushTableViewDelegate>
{
    @protected
    // 参数配置视图
    UIView *_configView;
    // 空数据标题
    UIButton *_emptyTitle;
    // 笔刷列表视图
    TuSDKPFBrushTableView *_tableView;
}

/**
 *  笔刷栏视图委托
 */
@property (nonatomic, assign) id<TuSDKPFBrushBarViewDelegate> delegate;

/**
 *  参数配置视图
 */
@property (nonatomic, readonly) UIView *configView;

/**
 *  单元格高度
 */
@property (nonatomic) NSUInteger brushBarHeight;

/**
 *  更新布局
 */
- (void)needUpdateLayout;

/**
 *  加载笔刷列表
 */
- (void)loadBrushes;

/**
 *  显示当前笔刷粗细
 *
 *  @param mBrushSize 笔刷粗细
 */
- (void)setBrushSize:(lsqBrushSize)mBrushSize;

@end
