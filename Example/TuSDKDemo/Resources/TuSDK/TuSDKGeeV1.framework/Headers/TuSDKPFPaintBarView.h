//
//  TuSDKPFPaintBarView.h
//  TuSDKGeeV1
//
//  Created by tutu on 2018/11/30.
//  Copyright © 2018 tusdk.com. All rights reserved.
//

#import "TuSDKPFPaintBarViewBase.h"
#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKPFPaintTableItemCell.h"

#pragma mark - TuSDKPFBrushTableView
/**
 *  笔刷列表视图
 *  @since v3.1.0
 */
@interface TuSDKPFPaintTableView : UIView<UITableViewDataSource, UITableViewDelegate, TuSDKPFPaintTableViewInterface>
/**
 *  滤镜分组元素视图类 (默认:TuSDKPFBrushTableItemCell, 需要继承 TuSDKPFBrushTableItemCell)
 *  @since v3.1.0
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  行视图宽度
 *  @since v3.1.0
 */
@property (nonatomic) CGFloat cellWidth;

/**
 *  笔刷列表视图委托
 *  @since v3.1.0
 */
@property (nonatomic, weak) id<TuSDKPFPaintTableViewDelegate> delegate;

/**
 *  数据列表
 *  @since v3.1.0
 */
@property (nonatomic, retain) NSArray *modeList;

/**
 *  列表视图
 *  @since v3.1.0
 */
@property (nonatomic, readonly)TuTableView *tableView;

@end

#pragma mark - TuSDKPFBrushBarViewDelegate

@class TuSDKPFPaintBarView;
/**
 *  笔刷栏视图委托
 *  @since v3.1.0
 */
@protocol TuSDKPFPaintBarViewDelegate <NSObject>
/**
 *  选中一个笔刷数据
 *
 *  @since v3.1.0
 *  @param view    笔刷栏视图
 *  @param data    笔刷数据对象
 */
- (void)paintBarView:(TuSDKPFPaintBarView *)view selectPaintColor:(NSString *)colorCode;

/**
 *  点击笔刷粗细按钮
 *  @since v3.1.0
 */
- (void)onPaintSizeButtonClick;
@end

#pragma mark - TuSDKPFBrushBarView


/**
 *  笔刷选择组件类
 *  @since v3.1.0
 */
@interface TuSDKPFPaintBarView : TuSDKPFPaintBarViewBase<TuSDKPFPaintBarViewDelegate>
{
@protected
    // 参数配置视图
    UIView *_configView;
    // 笔刷列表视图
    TuSDKPFPaintTableView *_tableView;
}

/**
 *  笔刷栏视图委托
 *  @since v3.1.0
 */
@property (nonatomic, weak) id<TuSDKPFPaintBarViewDelegate> delegate;

/**
 *  参数配置视图
 *  @since v3.1.0
 */
@property (nonatomic, readonly) UIView *configView;

/**
 *  单元格高度
 *  @since v3.1.0
 */
@property (nonatomic) NSUInteger brushBarHeight;

/**
 *  更新布局
 *  @since v3.1.0
 */
- (void)needUpdateLayout;

/**
 *  加载笔刷列表
 *  @since v3.1.0
 */
- (void)loadBrushes;

/**
 *  显示当前笔刷粗细
 *
 *  @since v3.1.0
 *  @param mBrushSize 笔刷粗细
 */
- (void)setBrushSize:(TuSDKBrushSize)mBrushSize;

@end
