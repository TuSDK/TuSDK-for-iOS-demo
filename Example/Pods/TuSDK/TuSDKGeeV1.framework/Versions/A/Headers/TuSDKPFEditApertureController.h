//
//  TuSDKPFEditApertureController.h
//  TuSDK
//
//  Created by Clear Hu on 15/5/7.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditApertureView.h"

#pragma mark - TuSDKPFEditApertureController
/**
 *  大光圈控制器
 */
@interface TuSDKPFEditApertureController : TuSDKPFEditApertureControllerBase

@end


#pragma mark - TuSDKPFEditApertureOptions
/**
 *  大光圈控制器配置选项
 */
@interface TuSDKPFEditApertureOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditApertureView, 需要继承 TuSDKPFEditApertureView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建大光圈控制器对象
 *
 *  @return controller 大光圈控制器对象
 */
- (TuSDKPFEditApertureController *)viewController;
@end
