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
    
    // TuSDKPFAlbumOptions *opt = _albumComponent.options.albumOptions;
    
    // 视图类 (默认:TuSDKPFAlbumView, 需要继承 TuSDKPFAlbumView)
    // opt.viewClazz = [TuSDKPFAlbumView class];
    
    // 表格行视图类 (默认:TuSDKPFAlbumCell, 需要继承 TuSDKPFAlbumCell)
    // opt.cellViewClazz = [TuSDKPFAlbumCell class];
    
    // 空数据视图类 (默认:TuSDKPFEmptyView, 需要继承 TuSDKPFEmptyView)
    // opt.emptyViewClazz = [TuSDKPFEmptyView class];
    
    // 是否自动选择相册组 (默认: YES, 如果没有设定相册组名称，自动跳转到系统相册组)
    // opt.autoSelectedAblumGroup = YES;
    
    // 需要自动跳转到相册组名称 (需要设定 autoSkipToPhotoList = YES)
    // opt.skipAlbumName = @"相机胶卷";
    
    // TuSDKPFPhotosOptions *opt = _albumComponent.options.photosOptions;
    // 视图类 (默认:TuSDKPFPhotosView, 需要继承 TuSDKPFPhotosView)
    // opt.viewClazz = [TuSDKPFPhotosView class];
    
    // 表格行视图类 (默认:TuSDKPFPhotosCell, 需要继承 TuSDKPFPhotosCell)
    // opt.cellViewClazz = [TuSDKPFPhotosCell class];
    
    // 表格单元格视图类 (默认:TuSDKPFPhotosGrid, 需要继承 TuSDKPFPhotosGrid)
    // opt.gridViewClazz = [TuSDKPFPhotosGrid class];
    
    // 表格行头部视图类 (默认:TuSDKPFPhotosCellSectionHeader, 需要继承 TuSDKPFPhotosCellSectionHeader)
    // opt.cellHeaderViewClazz = [TuSDKPFPhotosCellSectionHeader class];
    
    // 空数据视图类 (默认:TuSDKPFEmptyView, 需要继承 TuSDKPFEmptyView)
    // opt.emptyViewClazz = [TuSDKPFEmptyView class];
    
    lsqLDebug(@"avatarComponentHandler");
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
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKCPAvatarOptions.html
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
