//
//  GeeV2PFEditStickerOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditStickerController.h"

/**
 *  图片编辑贴纸选择控制器配置选项
 */
@interface GeeV2PFEditStickerOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:GeeV2PFEditStickerView, 需要继承 GeeV2PFEditStickerView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  单元格宽度
 */
@property (nonatomic) NSUInteger gridWidth;

/**
 *  单元格高度
 */
@property (nonatomic) NSUInteger gridHeight;

/**
 *  单元格间距
 */
@property (nonatomic) NSInteger gridPadding;

/**
 *  单元格视图类 (默认:GeeV2PFStickerTableCell, 需要继承 GeeV2PFStickerTableCell)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 * 贴纸分类列表 (默认: [TuSDKPFStickerLocalPackage package])
 */
@property (nonatomic, retain) NSArray *categories;

/**
 *  贴纸视图委托
 */
@property (nonatomic, weak) id<TuSDKPFStickerViewDelegate> stickerViewDelegate;

/**
 *  创建图片编辑滤镜控制器对象
 *
 *  @return controller 图片编辑滤镜控制器对象
 */
- (GeeV2PFEditStickerController *)viewController;
@end
