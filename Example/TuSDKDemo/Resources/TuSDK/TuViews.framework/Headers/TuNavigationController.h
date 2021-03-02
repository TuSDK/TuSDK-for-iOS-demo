//
//  TuNavigationController.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/28.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuViewController.h"

/**
 *  导航控制器基类
 */
@interface TuNavigationController : UINavigationController

@end

/**
 *  导航控制器基类扩展
 */
@interface UINavigationController(TuSDKICNavigationControllerExtend)
// 删除所有子控制器
-(void)lsqRemoveAllControllers;
@end
