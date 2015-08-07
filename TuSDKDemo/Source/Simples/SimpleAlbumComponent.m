//
//  SimpleAlbumComponent.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "SimpleAlbumComponent.h"
/**
 *  相册组件范例
 */
@interface SimpleAlbumComponent ()
{
    // 自定义系统相册组件
    TuSDKCPAlbumComponent *_albumComponent;
}
@end

@implementation SimpleAlbumComponent
- (instancetype)init;
{
    self = [super initWithGroupId:1 title:NSLocalizedString(@"simple_AlbumComponent", @"相册组件")];
    return self;
}

/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSimpleWithController:(UIViewController *)controller;
{
    if (!controller) return;
    self.controller = controller;

    lsqLDebug(@"albumComponentHandler");

    // 组件选项配置
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPAlbumComponent.html

    _albumComponent =
    [TuSDK albumCommponentWithController:controller
                           callbackBlock:^(TuSDKResult *result, NSError *error, UIViewController *controller)
     {
         _albumComponent = nil;
         // 获取头像图片
         if (error) {
             lsqLError(@"album reader error: %@", error.userInfo);
             return;
         }
         
         // if (controller) [controller dismissModalViewControllerAnimated];
         [result logInfo];
     }];
    
    // 组件选项配置
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPAlbumComponent.html
    // _albumComponent.options
    
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKPFAlbumOptions.html
    // _albumComponent.options.albumOptions
    
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKPFPhotosOptions.html
    // _albumComponent.options.photosOptions
    
    // 是否在组件执行完成后自动关闭组件 (默认:NO)
    _albumComponent.autoDismissWhenCompelted = YES;
    [_albumComponent showComponent];
}
@end
