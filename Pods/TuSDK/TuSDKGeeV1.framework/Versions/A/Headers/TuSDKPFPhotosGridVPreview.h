//
//  TuSDKPhotosGridVPreview.h
//  TuSDKGeeV1
//
//  Created by Jimmy Zhao on 16/8/22.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKICGridView.h"
#import "TuSDKPFPhotosGridCell.h"
#import "TuSDKGeeV1Import.h"

/**
 *  相册照片列表行视图委托
 */
@protocol TuSDKPFPhotoGridPreviewProtocol <NSObject>

@optional

/**
 *  预览视图滑动的图片索引
 *
 *  @param index 当前图片索引
 */
- (void)photosGridVPreviewScrollToIndex:(NSInteger)index;

@end

@interface TuSDKPFPhotosGridVPreview : TuSDKICGridView<UICollectionViewDataSource, UICollectionViewDelegate>
/**
 *  照片列表单元格视图类 (默认:TuSDKPFPhotosGridCell, 需要继承 TuSDKPFPhotosGridCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  当前选中相册组
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;

/**
 *  用户点击的图片的索引
 */
@property (nonatomic, assign) NSInteger currentIndex;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<TuSDKPFPhotoGridPreviewProtocol> gridProtocol;

@end
