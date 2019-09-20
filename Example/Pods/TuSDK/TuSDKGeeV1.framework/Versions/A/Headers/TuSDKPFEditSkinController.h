//
//  TuSDKPFEditSkinController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/26.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditSkinView.h"
#import "TuSDKGeeV1Import.h"

/**
 *  多功能美肤控制器
 */
@interface TuSDKPFEditSkinController : TuSDKPFEditSkinControllerBase
/**
 *  视图类 (默认:TuSDKPFEditSkinView, 需要继承 TuSDKPFEditSkinView)
 */
@property (nonatomic, strong) Class viewClazz;
@end

#pragma mark - TuSDKPFEditSkinMultipleOptions
/**
 *  多功能美肤控制器配置选项
 */
@interface TuSDKPFEditSkinOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditSkinView, 需要继承 TuSDKPFEditSkinView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 一键美颜 0 - 1.0，默认 1.0
 
 @since v3.0.0
 */
@property (nonatomic, assign) CGFloat retouchSize;

/**
 *  创建颜色调整控制器对象
 *
 *  @return controller 颜色调整控制器对象
 */
- (TuSDKPFEditSkinController *)viewController;
@end
