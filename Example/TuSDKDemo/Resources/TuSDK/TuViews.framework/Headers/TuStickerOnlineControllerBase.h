//
//  TuStickerOnlineControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuOnlineController.h"
#import "TuSDKPulseCore/components/widgets/sticker/TuSticker.h"

/**
 *  在线贴纸选择控制器委托基础类
 */
@interface TuStickerOnlineControllerBase : TuOnlineController
/** 选中对象 */
- (void)onHandleSelectedWithSticker:(TuSticker *)sticker;

/** 选中对象ID */
- (void)onHandleDetailWithID:(uint64_t)idt;
@end
