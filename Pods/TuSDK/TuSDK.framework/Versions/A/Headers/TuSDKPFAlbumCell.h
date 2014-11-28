//
//  TuSDKPFAlbumCell.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/31.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKICTableViewCell.h"
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
@property (nonatomic, retain) ALAssetsGroup *group;
@end
