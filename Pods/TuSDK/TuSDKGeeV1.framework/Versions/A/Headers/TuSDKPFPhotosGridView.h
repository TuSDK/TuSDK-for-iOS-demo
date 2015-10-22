//
//  TuSDKPFPhotosGridView.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/11/1.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKICGridView.h"
#import "TuSDKPFPhotosGridCell.h"
#import "TuSDKGeeV1Import.h"

/**
 *  相册照片列表行视图委托
 */
@protocol TuSDKPFPhotoGridProtocol <NSObject>
/**
 *  选中一张照片或者拍照
 *
 *  @param asset 照片对象
 */
- (void)onTuSDKPFPhotoGridSelectedWithAsset:(id)asset;
@end

/**
 *  相册照片列表视图
 */
@interface TuSDKPFPhotosGridView : TuSDKICGridView<UICollectionViewDataSource, UICollectionViewDelegate>

/**
 *  表格行视图类 (默认:TuSDKPFPhotosGridCell, 需要继承 TuSDKPFPhotosGridCell)
 */
@property (nonatomic, strong) Class cellViewClazz;

/**
 *  表格单元格视图类 (默认:TuSDKPFPhotosGrid, 需要继承 TuSDKPFPhotosGrid)
 */
@property (nonatomic, strong) Class gridViewClazz;

/**
 *  相册列表每行显示的照片数量 (默认:0, 程序自动适配设备)
 */
@property (nonatomic, assign) NSUInteger photoColumnNumber;


/**
 *  当前选中相册组
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<TuSDKPFPhotoGridProtocol> gridProtocol;
@end
