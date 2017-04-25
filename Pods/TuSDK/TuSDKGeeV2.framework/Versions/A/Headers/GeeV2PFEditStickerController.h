//
//  GeeV2PFEditStickerController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditStickerView.h"
#import "GeeV2PFStickerOnlineController.h"
#import "GeeV2PFStickerLocalController.h"

#pragma mark - GeeV2PFEditStickerControllerDelegate
@class GeeV2PFEditStickerController;
/**
 *  图片编辑贴纸选择控制器委托
 */
@protocol GeeV2PFEditStickerControllerDelegate <TuSDKCPComponentErrorDelegate>
/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 */
- (void)onGeeV2EditSticker:(GeeV2PFEditStickerController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 图片编辑控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncGeeV2EditSticker:(GeeV2PFEditStickerController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - GeeV2PFEditStickerController
/**
 *  图片编辑贴纸选择控制器
 */
@interface GeeV2PFEditStickerController : TuSDKPFEditStickerControllerBase<GeeV2PFStickerBarViewDelegate,
GeeV2PFStickerOnlineControllerDelegate, GeeV2PFStickerLocalControllerDelegate>
{
    // 默认样式视图
    GeeV2PFEditStickerView *_defaultStyleView;
}

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFEditStickerView *defaultStyleView;

/**
 *  美颜控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFEditStickerControllerDelegate> delegate;

/**
 *  视图类 (默认:GeeV2PFEditStickerView, 需要继承 GeeV2PFEditStickerView)
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
 *  单元格视图类 (默认:GeeV2PFStickerTableCell, 需要继承 GeeV2PFStickerTableCell)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 * 贴纸分类列表 (默认: [TuSDKPFStickerLocalPackage package])
 */
@property (nonatomic, retain) NSArray *categories;

/**
 *  贴纸视图委托
 */
@property (nonatomic, weak) id<TuSDKPFStickerViewDelegate> stickerViewDelegate;

/**
 *  开启详细列表动作按钮动作
 */
- (void)openListDetailAtion;

/**
 *  开启在线动作按钮动作
 */
- (void)openOnlineAtion;
@end
