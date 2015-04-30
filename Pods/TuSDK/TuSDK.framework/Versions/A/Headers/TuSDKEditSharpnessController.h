//
//  TuSDKEditSharpnessController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/29.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPFilterResultController.h"
#import "TuSDKCPImageResultOptions.h"

#pragma mark - TuSDKEditSharpnessController
/**
 *  锐化功能控制器
 */
@interface TuSDKEditSharpnessController : TuSDKCPFilterResultController

@end

#pragma mark - TuSDKEditSharpnessOptions
/**
 *  锐化功能控制器配置选项
 */
@interface TuSDKEditSharpnessOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKCPFilterResultView, 需要继承 TuSDKCPFilterResultView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建锐化功能控制器对象
 *
 *  @return 锐化功能控制器对象
 */
- (TuSDKEditSharpnessController *)viewController;
@end