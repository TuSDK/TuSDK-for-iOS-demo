//
//  TuSDKStickerLocalController.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPViewController.h"
#import "TuSDKPFStickerLocalView.h"
#import "TuSDKPFSticker.h"
#import "TuSDKPFStickerLocalPackage.h"

#pragma mark - TuSDKPFEditFilterControllerDelegate
@class TuSDKPFStickerLocalController;
/**
 *  本地贴纸选择控制器委托
 */
@protocol TuSDKPFStickerLocalControllerDelegate <TuSDKCPComponentErrorDelegate>
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
@interface TuSDKPFStickerLocalController : TuSDKCPViewController<TuSDKICPagerViewDataSource, TuSDKPFStickerLocalViewProtocol>{
@protected
    // 默认样式视图
    TuSDKPFStickerLocalView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuSDKPFStickerLocalView *defaultStyleView;

/**
 *  本地贴纸选择控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerLocalControllerDelegate> delegate;

/**
 *  视图类 (默认:TuSDKPFStickerLocalView, 需要继承 TuSDKPFStickerLocalView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 * 贴纸分类列表 (默认: [TuSDKPFStickerLocalPackage package])
 */
@property (nonatomic, retain) NSArray *categories;

@end
