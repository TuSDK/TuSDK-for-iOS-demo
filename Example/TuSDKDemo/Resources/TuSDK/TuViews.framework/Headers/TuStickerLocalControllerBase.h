//
//  TuStickerLocalControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuComponentsViewController.h"
//#import "TuSDKPulseCore/components/widgets/sticker/TuStickerGroup.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>

/**
 *  本地贴纸选择控制器基础类
 */
@interface TuStickerLocalControllerBase : TuComponentsViewController
/**
 * 贴纸分类列表
 */
@property (nonatomic, retain) NSArray *categories;

/**
 *  删除一组贴纸
 *
 *  @param group 贴纸分组对象
 */
- (void)removeWithStickerGroup:(TuStickerGroup *)group;

/**
 *  重新加载贴纸
 */
- (void)reloadStickers;
@end
