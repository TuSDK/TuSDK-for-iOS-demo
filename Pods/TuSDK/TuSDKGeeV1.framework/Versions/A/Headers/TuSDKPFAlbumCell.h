//
//  TuSDKPFAlbumCell.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKGeeV1Import.h"
/**
 *  默认相册列表样式行视图
 */
@interface TuSDKPFAlbumCell : TuSDKICTableViewCell
{
@protected
    /**
     *  封面
     */
    UIImageView *_posterImage;
    /**
     *  进入箭头
     */
    UIImageView *_arrow;
    /**
     *  标题
     */
    UILabel *_title;
}

/**
 *  相册组数据
 */
@property (nonatomic, retain) id<TuSDKTSAssetsGroupInterface> group;
@end
