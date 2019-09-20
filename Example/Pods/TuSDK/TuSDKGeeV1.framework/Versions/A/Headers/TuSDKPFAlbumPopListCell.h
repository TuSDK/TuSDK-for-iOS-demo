//
//  TuSDKPFAlbumPopListCell.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV1Import.h"

/**
 *  默认相册列表样式行视图
 */
@interface TuSDKPFAlbumPopListCell : TuSDKICTableViewCell

/**
 *  相册组数据
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;

/**
 *  封面
 */
@property (nonatomic, strong, readonly) UIImageView *posterImage;

/**
 *  标题
 */
@property (nonatomic, strong) UILabel *title;

@end
