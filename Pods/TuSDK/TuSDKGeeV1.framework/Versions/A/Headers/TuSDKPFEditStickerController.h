//
//  TuSDKPFEditStickerController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/28.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditStickerView.h"
#import "TuSDKPFStickerOnlineController.h"
#import "TuSDKPFStickerLocalController.h"

#pragma mark - TuSDKPFEditStickerControllerDelegate
@class TuSDKPFEditStickerController;
/**
 *  图片编辑贴纸选择控制器委托
 */
@protocol TuSDKPFEditStickerControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 */
- (void)onTuSDKEditSticker:(TuSDKPFEditStickerController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 *  @return 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncTuSDKEditSticker:(TuSDKPFEditStickerController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - TuSDKPFEditStickerController
/**
 *  图片编辑贴纸选择控制器
 */
@interface TuSDKPFEditStickerController : TuSDKPFEditStickerControllerBase<TuSDKPFStickerBarViewDelegate,
TuSDKPFStickerOnlineControllerDelegate, TuSDKPFStickerLocalControllerDelegate>
{
    // 默认样式视图
    TuSDKPFEditStickerView *_defaultStyleView;
}

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFEditStickerView *defaultStyleView;

/**
 *  美颜控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFEditStickerControllerDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFEditStickerView, 需要继承 TuSDKPFEditStickerView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  单元格宽度
 */
@property (nonatomic) NSUInteger gridWidth;

/**
 *  单元格高度
 */
@property (nonatomic) NSUInteger gridHeight;

/**
 *  单元格间距
 */
@property (nonatomic) NSInteger gridPadding;

/**
 *  单元格视图类 (默认:TuSDKPFStickerTableCell, 需要继承 TuSDKPFStickerTableCell)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 * 贴纸分类列表 (默认: [TuSDKPFStickerLocalPackage package])
 */
@property (nonatomic, retain) NSArray *categories;

/**
 *  贴纸视图委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerViewDelegate> stickerViewDelegate;

/**
 *  开启详细列表动作按钮动作
 */
- (void)openListDetailAtion;

/**
 *  开启在线动作按钮动作
 */
- (void)openOnlineAtion;
@end
