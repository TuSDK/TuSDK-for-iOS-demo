//
//  GeeV2PFEditSkinController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditSkinView.h"
#import "TuSDKGeeV2Import.h"

/**
 *  多功能美肤控制器
 */
@interface GeeV2PFEditSkinController : TuEditSkinControllerBase
/**
 *  视图类 (默认:GeeV2PFEditSkinView, 需要继承 GeeV2PFEditSkinView)
 */
@property (nonatomic, strong) Class viewClazz;
@end

#pragma mark - TuSDKPFEditSkinMultipleOptions
/**
 *  多功能美肤控制器配置选项
 */
@interface GeeV2PFEditSkinOptions : TuImageResultOptions
/**
 *  视图类 (默认:GeeV2PFEditSkinView, 需要继承 GeeV2PFEditSkinView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 一键美颜 0 - 1.0，默认 1.0
 
 @since v3.0.0
 */
@property (nonatomic, assign) CGFloat retouchSize;

/**
 * 一键美颜是否开启，默认为YES
 * @return
 */
@property (nonatomic, assign) BOOL enableAutoSkin;

/**
 *  创建颜色调整控制器对象
 *
 *  @return controller 颜色调整控制器对象
 */
- (GeeV2PFEditSkinController *)viewController;
@end
