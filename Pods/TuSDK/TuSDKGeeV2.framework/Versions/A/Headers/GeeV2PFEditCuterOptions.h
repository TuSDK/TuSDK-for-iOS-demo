//
//  GeeV2PFEditCuterOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditCuterController.h"

/**
 *  图片编辑裁切旋转控制器配置选项
 */
@interface GeeV2PFEditCuterOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:GeeV2PFEditCuterView, 需要继承 GeeV2PFEditCuterView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建图片编辑裁切旋转控制器对象
 *
 *  @return controller 图片编辑裁切旋转控制器对象
 */
- (GeeV2PFEditCuterController *)viewController;
@end
