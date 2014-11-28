//
//  TuSDKPFEditTurnAndCutOptions.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/7.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKCPOptions.h"
#import "TuSDKPFEditTurnAndCutViewController.h"

/**
 *  旋转和裁剪视图控制器配置选项
 */
@interface TuSDKPFEditTurnAndCutOptions : TuSDKCPOptions
/**
 *  旋转和裁剪视图控制器类  (默认: TuSDKPFEditTurnAndCutViewController，如需自定义请继承自 TuSDKPFEditTurnAndCutViewController)
 */
@property (nonatomic, strong) Class controllerClazz;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  需要裁剪的长宽
 */
@property (nonatomic) CGSize cutSize;

/**
 *  保存到系统相册 (默认不保存, 当设置为YES时, TuSDKCaputorResult.asset)
 */
@property (nonatomic) BOOL saveToAlbum;

/**
 *  保存到系统相册的相册名称
 */
@property (nonatomic, copy) NSString *saveToAlbumName;

/**
 *  是否显示处理结果预览图 (默认：关闭，调试时可以开启)
 */
@property (nonatomic) BOOL showResultPreview;

/**
 *  创建旋转和裁剪视图控制器对象
 *
 *  @return 旋转和裁剪视图控制器对象
 */
- (TuSDKPFEditTurnAndCutViewController *)viewController;
@end
