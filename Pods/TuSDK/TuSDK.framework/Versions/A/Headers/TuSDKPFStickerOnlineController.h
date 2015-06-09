//
//  TuSDKPFStickerOnlineController.h
//  TuSDK
//
//  Created by Clear Hu on 15/3/21.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPOnlineController.h"
#import "TuSDKPFStickerLocalPackage.h"

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
@interface TuSDKPFStickerOnlineController : TuSDKCPOnlineController<TuSDKPFStickerLocalPackageDelegate>
/**
 *  在线贴纸选择控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFStickerOnlineControllerDelegate> delegate;
@end
