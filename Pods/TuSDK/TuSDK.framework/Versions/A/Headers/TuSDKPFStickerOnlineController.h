//
//  TuSDKPFStickerOnlineController.h
//  TuSDK
//
//  Created by Clear Hu on 15/3/21.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPViewController.h"
#import "TuSDKICWebView.h"
#import "TuSDKPFStickerLocalPackage.h"
#import "TuSDKPFSticker.h"

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

#pragma mark - TuSDKPFStickerOnlineView
/**
 *  在线贴纸选择视图
 */
@interface TuSDKPFStickerOnlineView : UIView
{
    @protected
    //Web视图
    TuSDKICWebView *_webView;
}
/**
 *  Web视图
 */
@property (nonatomic, readonly)TuSDKICWebView *webView;
@end

#pragma mark - TuSDKPFStickerOnlineController
/**
 *  在线贴纸选择控制器
 */
@interface TuSDKPFStickerOnlineController : TuSDKCPViewController<TuSDKICWebViewDelegate, TuSDKPFStickerLocalPackageDelegate>
{
@protected
    // 默认样式视图
    TuSDKPFStickerOnlineView *_defaultStyleView;
}

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFStickerOnlineView *defaultStyleView;

/**
 *  视图类 (默认:TuSDKPFStickerOnlineView, 需要继承 TuSDKPFStickerOnlineView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  在线贴纸选择控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerOnlineControllerDelegate> delegate;

/**
 *  详细数据ID
 */
@property (nonatomic) uint64_t detailDataId;
@end
