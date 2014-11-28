//
//  TuSDKPFAlbumOptions.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/6.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKCPOptions.h"
#import "TuSDKPFAlbumViewController.h"

/**
 *  系统相册控制器配置选项
 */
@interface TuSDKPFAlbumOptions : TuSDKCPOptions
/**
 *  系统相册列表控制类 (默认: TuSDKPFAlbumViewController，如需自定义请继承自 TuSDKPFAlbumViewController)
 */
@property (nonatomic, strong) Class controllerClazz;

/**
 *  创建系统相册列表控制器对象
 *
 *  @return 系统相册列表控制器对象
 */
- (TuSDKPFAlbumViewController *)viewController;
@end
