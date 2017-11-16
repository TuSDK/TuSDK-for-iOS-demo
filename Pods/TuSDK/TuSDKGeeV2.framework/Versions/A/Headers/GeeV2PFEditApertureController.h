//
//  GeeV2PFEditApertureController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditApertureView.h"
#import "GeeV2PFEditTabBarSubControllerInterface.h"
#pragma mark - GeeV2PFEditApertureController
/**
 *  大光圈控制器
 */
@interface GeeV2PFEditApertureController : TuSDKPFEditApertureControllerBase<GeeV2PFEditTabBarSubControllerInterface>

@end

#pragma mark - GeeV2PFEditApertureOptions
/**
 *  大光圈控制器配置选项
 */
@interface GeeV2PFEditApertureOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:GeeV2PFEditApertureView, 需要继承 GeeV2PFEditApertureView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建大光圈控制器对象
 *
 *  @return controller 大光圈控制器对象
 */
- (GeeV2PFEditApertureController *)viewController;
@end
