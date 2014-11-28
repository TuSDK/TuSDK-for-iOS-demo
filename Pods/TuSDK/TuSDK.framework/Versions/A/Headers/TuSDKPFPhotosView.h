//
//  TuSDKPFPhotosView.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/1.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKICTableView.h"
#import "TuSDKPFPhotosCell.h"

/**
 *  相册照片列表视图
 */
@interface TuSDKPFPhotosView : TuSDKICTableView<UITableViewDataSource, UITableViewDelegate>
/**
 *  系统相册组
 */
@property (nonatomic, retain) ALAssetsGroup *group;

/**
 *  相册照片列表行视图委托
 */
@property (nonatomic, assign) id<TuSDKPFPhotosCellProtocol> gridProtocol;
@end
