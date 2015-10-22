//
//  SimpleAlbumComponent.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "SimpleAlbumMultipleComponent.h"
/**
 *  相册组件范例
 */
@interface SimpleAlbumMultipleComponent ()
{
    // 自定义系统相册组件
    TuSDKCPAlbumMultipleComponent *_albumComponent;
}
@end

@implementation SimpleAlbumMultipleComponent
- (instancetype)init;
{
    self = [super initWithGroupId:1 title:NSLocalizedString(@"simple_MultipleAlbumComponent", @"相册组件（带相机）")];
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
    [TuSDKGeeV1 albumMultipleCommponentWithController:controller
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
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPFlatAlbumComponent.html
    // _albumComponent.options
    
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKPFFlatAlbumOptions.html
    // _albumComponent.options.albumOptions
    
    // 是否在组件执行完成后自动关闭组件 (默认:NO)
    _albumComponent.autoDismissWhenCompelted = YES;
    [_albumComponent showComponent];
}
@end
