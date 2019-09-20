//
//  GeeV2PFEditMultipleView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"
#pragma mark - GeeV2PFEditImageSelectTableViewCell
/**
 *  单元格视图
 */
@interface GeeV2PFEditImageSelectTableViewCell : TuSDKICTableViewCell

/**
 *  单元格数据
 */
@property (nonatomic) BOOL isShowThumbnail;

/**
 *  图片边距
 */
@property (nonatomic) NSInteger innerWarpSpace;

/**
 *  单元格数据
 */
@property (nonatomic, retain) TuSDKResult *mode;

/**
 *  单元格选中覆盖
 */
@property (nonatomic, retain) UIView *selectedMask;

/**
 *  单元格展示图片
 */
@property (nonatomic, retain) UIImageView *displayImage;

@end
#pragma mark - GeeV2PFEditImageSelectTableView
@protocol GeeV2PFEditImageSelectTableViewDelegate <NSObject>
@optional

/**
 *  选中一个行视图
 *
 *  @param index 索引
 *
 */
- (void)onTuSDKPFEditImageSelectTableViewDidSelectIndex:(NSInteger)index;

/**
 *  滑动到一个单元格
 *
 *  @param index 索引
 *
 */
- (void)imageSelectTableViewDidScrollIndex:(NSInteger)index;
@end

/**
 *  滤镜分组列表
 */
@interface GeeV2PFDisplayImageWrap : UIView<UITableViewDataSource, UITableViewDelegate>

/**
 *  列表视图
 */
@property (nonatomic, readonly) TuSDKICTableView *tableView;

/**
 *  单元格高度
 */
@property (nonatomic) NSUInteger gridHeight;

/**
 *  单元格间距
 */
@property (nonatomic) NSInteger gridPadding;

/**
 *  是否显示选中覆盖，默认显示
 */
@property (nonatomic) BOOL enableShowSelectedMask;

/**
 *  单元格数据
 */
@property (nonatomic) BOOL isShowThumbnail;

/**
 *  行视图宽度
 */
@property (nonatomic) CGFloat cellWidth;

/**
 *  单元格视图类
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  列表资源数组
 */
@property (nonatomic, retain) NSArray<TuSDKResult *> *modeList;

/**
 *  滤镜分组视图委托
 */
@property (nonatomic, weak) id<GeeV2PFEditImageSelectTableViewDelegate> delegate;

@end
#pragma mark - GeeV2PFEditEntryStepView
/**
 *  操作步骤视图
 */
@interface GeeV2PFEditEntryStepView : UIView
{
    // 后退按钮
    UIButton *_prevButton;
    // 前进按钮
    UIButton *_nextButton;
}
/**
 *  后退按钮
 */
@property (nonatomic, readonly) UIButton *prevButton;

/**
 *  前进按钮
 */
@property (nonatomic, readonly) UIButton *nextButton;
@end

#pragma mark - GeeV2PFEditMultipleOptionBar
/**
 *  选项栏目
 */
@interface GeeV2PFEditMultipleOptionBar : UIView
{
    // 横向滚动视图
    UIScrollView *_wrapView;
    // 模块按钮列表
    NSMutableArray *_buttons;
}

/**
 *  横向滚动视图
 */
@property (nonatomic, readonly) UIScrollView *wrapView;
/**
 *  绑定功能模块
 *
 *  @param modules 功能模块列表
 *  @param target  绑定事件对象
 *  @param action  绑定事件
 */
- (void)bindModules:(NSArray *)modules target:(id)target action:(SEL)action;

/**
 *  创建动作按钮
 *
 *  @param module 图片编辑动作类型
 *  @param count  按钮总数
 *
 *  @return button 动作按钮
 */
- (UIButton *)buildButtonWithActionType:(lsqTuSDKCPEditActionType)type moduleCount:(NSUInteger)count;

/**
 *  更新按钮布局
 */
- (void)needUpdateLayout;
@end

#pragma mark - GeeV2PFEditMultipleView
/**
 *  多功能图像编辑控制器视图
 */
@interface GeeV2PFEditMultipleView : UIView
{
    // 操作步骤视图
    GeeV2PFEditEntryStepView *_stepView;
    // 自动校色按钮
    UIButton *_autoAdjustButton;
    // 返回按钮
    UIButton *_cancelButton;
    // 完成按钮
    UIButton *_doneButton;
    // 选项栏目
    GeeV2PFEditMultipleOptionBar *_optionBar;
    // 图片视图
    UIImageView *_imageView;
}

/**
 *  操作步骤视图
 */
@property (nonatomic, readonly) GeeV2PFEditEntryStepView *stepView;

/**
 *  自动校色按钮
 */
@property (nonatomic, readonly) UIButton *autoAdjustButton;

/**
 *  返回按钮
 */
@property (nonatomic, readonly) UIButton *cancelButton;

/**
 *  完成按钮
 */
@property (nonatomic, readonly) UIButton *doneButton;

/**
 *  图片选择视图
 */
@property (nonatomic, readonly) GeeV2PFDisplayImageWrap *imageSelectTableView;

/**
 *  选项栏目
 */
@property (nonatomic, readonly) GeeV2PFEditMultipleOptionBar *optionBar;

/**
 *  图片视图
 */
@property (nonatomic, readonly) GeeV2PFDisplayImageWrap *imageViewWrap;
/**
 *  更新布局
 */
- (void)needUpdateLayout;
@end
