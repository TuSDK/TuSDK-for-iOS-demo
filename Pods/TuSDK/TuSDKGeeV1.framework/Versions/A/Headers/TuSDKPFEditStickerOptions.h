//
//  TuSDKPFEditStickerOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/28.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditStickerController.h"

/**
 *  图片编辑贴纸选择控制器配置选项
 */
@interface TuSDKPFEditStickerOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditStickerView, 需要继承 TuSDKPFEditStickerView)
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
 *  单元格视图类 (默认:TuSDKPFStickerTableCell, 需要继承 TuSDKPFStickerTableCell)
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
- (TuSDKPFEditStickerController *)viewController;
@end
