//
//  TuSDKPFPhotosOptions.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/6.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKCPOptions.h"
#import "TuSDKPFPhotosViewController.h"

/**
 *  相册照片列表控制器配置选项
 */
@interface TuSDKPFPhotosOptions : TuSDKCPOptions
/**
 *  系统相册照片列表控制类 (默认: TuSDKPFPhotosViewController，如需自定义请继承自 TuSDKPFPhotosViewController)
 */
@property (nonatomic, strong) Class controllerClazz;

/**
 *  创建系统相册照片列表控制器对象
 *
 *  @return 相册照片列表控制器对象
 */
- (TuSDKPFPhotosViewController *)viewController;
@end
