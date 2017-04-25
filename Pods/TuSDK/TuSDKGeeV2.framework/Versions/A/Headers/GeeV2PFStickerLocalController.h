//
//  GeeV2PFStickerLocalController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFStickerLocalView.h"
#import "GeeV2PFStickerOnlineController.h"

#pragma mark - GeeV2PFEditFilterControllerDelegate
@class GeeV2PFStickerLocalController;
/**
 *  本地贴纸选择控制器委托
 */
@protocol GeeV2PFStickerLocalControllerDelegate <NSObject>
/**
 *  图片编辑完成
 *
 *  @param controller 本地贴纸选择控制器
 *  @param result 处理结果
 */
- (void)onGeeV2PFStickerLocal:(GeeV2PFStickerLocalController *)controller sticker:(TuSDKPFSticker *)sticker stickerGroup:(TuSDKPFStickerGroup *)stickerGroup;
@end

#pragma mark - GeeV2PFStickerLocalController
/**
 *  本地贴纸选择控制器
 */
@interface GeeV2PFStickerLocalController : TuSDKPFStickerLocalControllerBase<TuSDKICPagerViewDataSource, GeeV2PFStickerLocalViewProtocol, GeeV2PFStickerOnlineControllerDelegate>{
@protected
    // 默认样式视图
    GeeV2PFStickerLocalView *_defaultStyleView;
}
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
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFStickerLocalView *defaultStyleView;

/**
 * 是否跳转到上一个视图控制器
 */
@property (nonatomic) BOOL isBackPreviousController;

/**
 *  本地贴纸选择控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFStickerLocalControllerDelegate> delegate;

/**
 *  视图类 (默认:GeeV2PFStickerLocalView, 需要继承 GeeV2PFStickerLocalView)
 */
@property (nonatomic, strong) Class viewClazz;

@end
