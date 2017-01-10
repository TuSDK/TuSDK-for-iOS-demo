//
//  GeeV2PFStickerLocalOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFStickerLocalController.h"

/**
 *  本地贴纸选择控制器配置选项
 */
@interface GeeV2PFStickerLocalOptions : TuSDKCPOptions
/**
 *  视图类 (默认:GeeV2PFStickerLocalView, 需要继承 GeeV2PFStickerLocalView)
 */
@property (nonatomic, strong) Class viewClazz;

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
 * 贴纸分类列表 (默认: [TuSDKPFStickerLocalPackage package])
 */
@property (nonatomic, retain) NSArray *categories;

/**
 *  创建本地贴纸选择控制器对象
 *
 *  @return controller 本地贴纸选择控制器对象
 */
- (GeeV2PFStickerLocalController *)viewController;
@end
