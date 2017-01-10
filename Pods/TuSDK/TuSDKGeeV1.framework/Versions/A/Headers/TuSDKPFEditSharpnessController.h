//
//  TuSDKPFEditSharpnessController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/29.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"
#import "TuSDKCPFilterResultView.h"

#pragma mark - TuSDKPFEditSharpnessController
/**
 *  锐化功能控制器
 */
@interface TuSDKPFEditSharpnessController : TuSDKPFEditSharpnessControllerBase

@end

#pragma mark - TuSDKPFEditSharpnessOptions
/**
 *  锐化功能控制器配置选项
 */
@interface TuSDKPFEditSharpnessOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKCPFilterResultView, 需要继承 TuSDKCPFilterResultView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建锐化功能控制器对象
 *
 *  @return controller 锐化功能控制器对象
 */
- (TuSDKPFEditSharpnessController *)viewController;
@end
