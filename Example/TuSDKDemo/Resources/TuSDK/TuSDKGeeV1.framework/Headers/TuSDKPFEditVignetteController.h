//
//  TuSDKPFEditVignetteController.h
//  TuSDK
//
//  Created by Clear Hu on 15/5/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"
#import "TuSDKCPFilterResultView.h"

#pragma mark - TuSDKPFEditVignetteController
/**
 *  暗角控制器
 */
@interface TuSDKPFEditVignetteController : TuEditVignetteControllerBase

@end

#pragma mark - TuSDKPFEditVignetteOptions
/**
 *  暗角控制器功能控制器配置选项
 */
@interface TuSDKPFEditVignetteOptions : TuImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditApertureView, 需要继承 TuSDKCPFilterResultView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建暗角控制器功能控制器对象
 *
 *  @return controller 暗角控制器TuSDKCPFilterResultView功能控制器对象
 */
- (TuSDKPFEditVignetteController *)viewController;
@end
