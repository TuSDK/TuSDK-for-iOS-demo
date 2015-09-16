//
//  TuSDKPFStickerLocalOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

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
