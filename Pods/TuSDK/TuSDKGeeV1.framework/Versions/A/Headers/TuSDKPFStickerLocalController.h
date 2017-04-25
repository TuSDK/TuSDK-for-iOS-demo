//
//  TuSDKStickerLocalController.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFStickerLocalView.h"
#import "TuSDKPFStickerOnlineController.h"

#pragma mark - TuSDKPFEditFilterControllerDelegate
@class TuSDKPFStickerLocalController;
/**
 *  本地贴纸选择控制器委托
 */
@protocol TuSDKPFStickerLocalControllerDelegate <NSObject>
/**
 *  图片编辑完成
 *
 *  @param controller 本地贴纸选择控制器
 *  @param result 处理结果
 */
- (void)onTuSDKPFStickerLocal:(TuSDKPFStickerLocalController *)controller sticker:(TuSDKPFSticker *)sticker;
@end

#pragma mark - TuSDKPFStickerLocalController
/**
 *  本地贴纸选择控制器
 */
@interface TuSDKPFStickerLocalController : TuSDKPFStickerLocalControllerBase<TuSDKICPagerViewDataSource, TuSDKPFStickerLocalViewProtocol, TuSDKPFStickerOnlineControllerDelegate>{
@protected
    // 默认样式视图
    TuSDKPFStickerLocalView *_defaultStyleView;
}
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
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFStickerLocalView *defaultStyleView;

/**
 *  本地贴纸选择控制器委托
 */
@property (nonatomic, weak) id<TuSDKPFStickerLocalControllerDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFStickerLocalView, 需要继承 TuSDKPFStickerLocalView)
 */
@property (nonatomic, strong) Class viewClazz;

@end
