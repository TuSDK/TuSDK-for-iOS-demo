//
//  GeeV2PFEditAdjustController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditAdjustView.h"

#pragma mark - GeeV2PFEditAdjustController
/**
 *  颜色调整控制器
 */
@interface GeeV2PFEditAdjustController : TuSDKPFEditAdjustControllerBase
/**
 *  视图类 (默认:GeeV2PFEditAdjustView, 需要继承 GeeV2PFEditAdjustView)
 */
@property (nonatomic, strong) Class viewClazz;
@end

#pragma mark - GeeV2PFEditAdjustOptions
/**
 *  颜色调整控制器配置选项
 */
@interface GeeV2PFEditAdjustOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:GeeV2PFEditAdjustView, 需要继承 GeeV2PFEditAdjustView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建颜色调整控制器对象
 *
 *  @return controller 颜色调整控制器对象
 */
- (GeeV2PFEditAdjustController *)viewController;
@end
