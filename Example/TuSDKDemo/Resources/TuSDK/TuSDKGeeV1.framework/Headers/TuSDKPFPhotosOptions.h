//
//  TuSDKPFPhotosOptions.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/11/6.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import "TuSDKPFPhotosViewController.h"


/**
 *  相册照片列表控制器配置选项
 */
@interface TuSDKPFPhotosOptions : TuOptions
/**
 *  视图类 (默认:TuSDKPFPhotosView, 需要继承 TuSDKPFPhotosView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  表格行视图类 (默认:TuSDKPFPhotosCell, 需要继承 TuSDKPFPhotosCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  表格单元格视图类 (默认:TuSDKPFPhotosGrid, 需要继承 TuSDKPFPhotosGrid)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 *  表格行头部视图类 (默认:TuSDKPFPhotosCellSectionHeader, 需要继承 TuSDKPFPhotosCellSectionHeader)
 */
@property (nonatomic, strong) Class cellHeaderViewClazz;

/**
 *  空数据视图类 (默认:TuEmptyView, 需要继承 TuEmptyView)
 */
@property (nonatomic, strong) Class emptyViewClazz;

/**
 *  选择图片的尺寸限制 默认：CGSize(8000,8000)
 */
@property (nonatomic,assign) CGSize maxSelectionImageSize;

/**
 *  创建系统相册照片列表控制器对象
 *
 *  @return controller 相册照片列表控制器对象
 */
- (TuSDKPFPhotosViewController *)viewController;
@end
