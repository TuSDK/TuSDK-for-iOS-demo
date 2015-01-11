//
//  TuSDKPFStickerLocalOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPOptions.h"
#import "TuSDKPFStickerLocalController.h"

/**
 *  本地贴纸选择控制器配置选项
 */
@interface TuSDKPFStickerLocalOptions : TuSDKCPOptions
/**
 *  视图类 (默认:TuSDKPFStickerLocalView, 需要继承 TuSDKPFStickerLocalView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 * 贴纸分类列表 (默认: [TuSDKPFStickerLocalPackage package])
 */
@property (nonatomic, retain) NSArray *categories;

/**
 *  创建本地贴纸选择控制器对象
 *
 *  @return 本地贴纸选择控制器对象
 */
- (TuSDKPFStickerLocalController *)viewController;
@end
