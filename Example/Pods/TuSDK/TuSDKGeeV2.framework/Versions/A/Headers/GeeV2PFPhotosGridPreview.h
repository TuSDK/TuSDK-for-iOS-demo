//
//  GeeV2PFPhotosGridPreview.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "GeeV2ICGridView.h"
#import "GeeV2PFPhotosGridCell.h"
#import "TuSDKGeeV2Import.h"
#import "TuSDKGeeV2Theme.h"

/**
 *  相册照片列表行视图委托
 */
@protocol GeeV2PFPhotoGridPreviewProtocol <NSObject>

@optional

/**
 *  预览视图滑动的图片索引
 *
 *  @param index 当前图片索引
 */
- (void)photosGridVPreviewScrollToIndex:(NSInteger)index;

@end

@interface GeeV2PFPhotosGridPreview : GeeV2ICGridView<UICollectionViewDataSource, UICollectionViewDelegate>
/**
 *  照片列表单元格视图类 (默认:GeeV2PFPhotosGridCell, 需要继承 GeeV2PFPhotosGridCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  当前选中相册组
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;

/**
 *  照片排序字段 默认根据创建时间排序 ( lsqAssetSortKeyModificationDate 类型 iOS8以上可用)
 */
@property (nonatomic,assign) lsqAssetSortKeyType photosSortKeyType;

/**
 *  用户点击的图片的索引
 */
@property (nonatomic, assign) NSInteger currentIndex;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<GeeV2PFPhotoGridPreviewProtocol> gridProtocol;

@end

