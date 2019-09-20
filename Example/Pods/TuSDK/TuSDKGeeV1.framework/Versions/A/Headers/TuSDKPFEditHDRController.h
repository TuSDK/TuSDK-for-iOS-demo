//
//  TuSDKPFEditHDRController.h
//  TuSDKGeeV1
//
//  Created by Yanlin Qiu on 13/04/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import "TuSDKCPFilterResultView.h"

#pragma mark - TuSDKPFEditHDRController
/**
 HDR 滤镜控制器
 */
@interface TuSDKPFEditHDRController : TuSDKPFEditHDRControllerBase

@end

#pragma mark - TuSDKPFEditHDROptions
/**
 *  HDR 控制器视图配置选项
 */
@interface TuSDKPFEditHDROptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKCPFilterResultView, 需要继承 TuSDKCPFilterResultView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建图片编辑滤镜控制器对象
 *
 *  @return controller 图片编辑滤镜控制器对象
 */
- (TuSDKPFEditHDRController *)viewController;
@end
