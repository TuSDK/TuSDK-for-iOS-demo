//
//  TuSDKPFStickerOnlineController.h
//  TuSDK
//
//  Created by Clear Hu on 15/3/21.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"

@class TuSDKPFStickerOnlineController;
/**
 *  在线贴纸选择控制器委托
 */
@protocol TuSDKPFStickerOnlineControllerDelegate <NSObject>
/**
 *  选中一个贴纸对象
 *
 *  @param controller 在线贴纸选择控制器
 *  @param sticker    贴纸元素类型
 */
- (void)onTuSDKPFStickerOnline:(TuSDKPFStickerOnlineController *)controller
               selectedSticker:(TuSDKPFSticker *)sticker;
@end

#pragma mark - TuSDKPFStickerOnlineController
/**
 *  在线贴纸选择控制器
 */
@interface TuSDKPFStickerOnlineController : TuSDKPFStickerOnlineControllerBase
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
@property (nonatomic, assign) id<TuSDKPFStickerOnlineControllerDelegate> delegate;
@end
