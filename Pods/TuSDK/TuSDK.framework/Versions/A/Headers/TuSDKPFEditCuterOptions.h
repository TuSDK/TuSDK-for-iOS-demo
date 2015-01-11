//
//  TuSDKPFEditCuterOptions.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/3.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPImageResultOptions.h"
#import "TuSDKPFEditCuterController.h"
#import "TuSDKRatioType.h"

/**
 *  图片编辑裁切旋转控制器配置选项
 */
@interface TuSDKPFEditCuterOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditCuterView, 需要继承 TuSDKPFEditCuterView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  是否开启图片旋转 (默认: false)
 */
@property (nonatomic) BOOL enableTrun;

/**
 *  是否开启图片镜像(默认: false)
 */
@property (nonatomic) BOOL enableMirror;
/**
 *  视图显示比例类型 (默认:lsqRatioAll, 如果设置cameraViewRatio > 0, 将忽略ratioType)
 */
@property (nonatomic) lsqRatioType ratioType;

/**
 *  是否仅返回裁切参数，不返回处理图片
 */
@property (nonatomic) BOOL onlyReturnCuter;

/**
 *  创建图片编辑裁切旋转控制器对象
 *
 *  @return 图片编辑裁切旋转控制器对象
 */
- (TuSDKPFEditCuterController *)viewController;
@end
