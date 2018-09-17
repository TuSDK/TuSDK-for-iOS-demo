//
//  GeeV2PFAlbumPopListCell.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV2Import.h"

/**
 *  默认相册列表样式行视图
 */
@interface GeeV2PFAlbumPopListCell : TuSDKICTableViewCell

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
@property (nonatomic, strong, readonly) UILabel *title;

@end

