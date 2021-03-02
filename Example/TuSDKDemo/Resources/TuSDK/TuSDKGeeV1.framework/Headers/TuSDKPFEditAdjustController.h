//
//  TuSDKPFEditAdjustController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/29.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditAdjustView.h"

#pragma mark - TuSDKPFEditAdjustController
/**
 *  颜色调整控制器
 */
@interface TuSDKPFEditAdjustController : TuEditAdjustControllerBase
/**
 *  视图类 (默认:TuSDKPFEditAdjustView, 需要继承 TuSDKPFEditAdjustView)
 */
@property (nonatomic, strong) Class viewClazz;
@end

#pragma mark - TuSDKPFEditAdjustOptions
/**
 *  颜色调整控制器配置选项
 */
@interface TuSDKPFEditAdjustOptions : TuImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditAdjustView, 需要继承 TuSDKPFEditAdjustView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建颜色调整控制器对象
 *
 *  @return controller 颜色调整控制器对象
 */
- (TuSDKPFEditAdjustController *)viewController;
@end
