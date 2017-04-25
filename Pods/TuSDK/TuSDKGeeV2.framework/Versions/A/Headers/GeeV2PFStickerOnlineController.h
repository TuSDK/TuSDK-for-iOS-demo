//
//  GeeV2PFStickerOnlineController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV2Import.h"

@class GeeV2PFStickerOnlineController;
/**
 *  在线贴纸选择控制器委托
 */
@protocol GeeV2PFStickerOnlineControllerDelegate <NSObject>
/**
 *  选中一个贴纸对象
 *
 *  @param controller 在线贴纸选择控制器
 *  @param sticker    贴纸元素类型
 */
- (void)onGeeV2PFStickerOnline:(GeeV2PFStickerOnlineController *)controller
               selectedSticker:(TuSDKPFSticker *)sticker;
@end

#pragma mark - GeeV2PFStickerOnlineController
/**
 *  在线贴纸选择控制器
 */
@interface GeeV2PFStickerOnlineController : TuSDKPFStickerOnlineControllerBase
{
@protected
    // 默认样式视图
    TuSDKCPOnlineView *_defaultStyleView;
}

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKCPOnlineView *defaultStyleView;

/**
 *  在线贴纸选择控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFStickerOnlineControllerDelegate> delegate;
@end
