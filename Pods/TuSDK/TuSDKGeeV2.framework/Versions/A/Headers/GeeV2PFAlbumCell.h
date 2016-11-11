//
//  GeeV2PFAlbumCell.h
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
@interface GeeV2PFAlbumCell : TuSDKICTableViewCell
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
