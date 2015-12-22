//
//  TuSDKPFEditHolyLightController.h
//  TuSDKGeeV1
//
//  Created by Clear Hu on 15/12/16.
//  Copyright © 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKCPFilterResultView.h"

#pragma mark - TuSDKPFEditHolyLightController
/**
 *  圣光控制器
 */
@interface TuSDKPFEditHolyLightController : TuSDKPFEditHolyLightControllerBase

@end

#pragma mark - TuSDKPFEditSkinOptions
/**
 *  圣光控制器视图配置选项
 */
@interface TuSDKPFEditHolyLightOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKCPFilterResultView, 需要继承 TuSDKCPFilterResultView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建图片编辑滤镜控制器对象
 *
 *  @return 图片编辑滤镜控制器对象
 */
- (TuSDKPFEditHolyLightController *)viewController;
@end