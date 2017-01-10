//
//  GeeV2PFEditTurnAndMirrorOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditTurnAndMirrorViewController.h"

/**
 *  旋转视图控制器配置选项
 */
@interface GeeV2PFEditTurnAndMirrorOptions : TuSDKCPImageResultOptions

/**
 *  视图类 (默认:GeeV2PFEditTurnAndMirrorView, 需要继承 GeeV2PFEditTurnAndMirrorView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  旋转视图控制栏类 (默认:GeeV2PFEditTurnAndMirrorBottomView, 需要继承 GeeV2PFEditTurnAndMirrorBottomView)
 */
@property (nonatomic, strong) Class bottomBarViewClazz;

/**
 *  图片编辑视图 (旋转，缩放)类 (默认:TuSDKICTouchImageView, 需要继承 TuSDKICTouchImageView)
 */
@property (nonatomic, strong) Class editImageViewClazz;

/**
 *  创建旋转视图控制器对象
 *
 *  @return controller 旋转视图控制器对象
 */
- (GeeV2PFEditTurnAndMirrorViewController *)viewController;
@end
