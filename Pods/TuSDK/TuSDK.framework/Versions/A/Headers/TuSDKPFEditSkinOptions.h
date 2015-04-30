//
//  TuSDKPFEditSkinOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/26.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPImageResultOptions.h"
#import "TuSDKPFEditSkinController.h"

/**
 *  美颜控制器视图配置选项
 */
@interface TuSDKPFEditSkinOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKCPFilterResultView, 需要继承 TuSDKCPFilterResultView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  创建图片编辑滤镜控制器对象
 *
 *  @return 图片编辑滤镜控制器对象
 */
- (TuSDKPFEditSkinController *)viewController;
@end
