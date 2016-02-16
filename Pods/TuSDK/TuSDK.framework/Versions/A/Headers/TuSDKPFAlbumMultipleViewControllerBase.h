//
//  TuSDKPFAlbumMultipleViewControllerBase.h
//  TuSDK
//
//  Created by Yanlin on 10/23/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCPViewController.h"

@interface TuSDKPFAlbumMultipleViewControllerBase : TuSDKCPViewController

/**
 *  系统相册列表
 */
@property (nonatomic, retain) NSArray<TuSDKTSAssetsGroupInterface> *groups;



/**
 *  需要自动跳转到相册组名称
 */
@property (nonatomic, copy) NSString *skipAlbumName;

/**
 *  通知获取一个相册组
 *
 *  @param group 相册组
 */
- (void)notifySelectedGroup:(id<TuSDKTSAssetsGroupInterface>)group;

@end
