//
//  GeeV2PFCameraPreviewController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/20.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV2Import.h"

#pragma mark - GeeV2PFCameraPreviewControllerDelegate
@class GeeV2PFCameraPreviewController;
/**
 *  相机预览视图控制器委托
 */
@protocol GeeV2PFCameraPreviewControllerDelegate<NSObject>

/**
 *  图片编辑完成
 *
 *  @param controller 相机预览视图控制器
 *  @param result 处理结果
 */
- (void)onGeeV2PFCameraPreview:(GeeV2PFCameraPreviewController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 相机预览视图控制器
 *  @param result 处理结果
 *  @return BOOL 是否截断默认处理逻辑 (默认: NO, 设置为YES时使用自定义处理逻辑)
 */
- (BOOL)onAsyncGeeV2PFCameraPreview:(GeeV2PFCameraPreviewController *)controller result:(TuSDKResult *)result;

@end


@interface GeeV2CameraPreviewBottomBar : UIView
/**
 *  左侧按钮
 */
@property(nonatomic, retain) UIButton *cancleButton;

/**
 *  右侧按钮
 */
@property(nonatomic, retain) UIButton *completeButton;

@end


@interface GeeV2PFCameraPreview : UIView
/**
 *  预览视图底部栏
 */
@property(nonatomic, retain) GeeV2CameraPreviewBottomBar *bottomBar;

/**
 *  预览图像视图
 */
@property(nonatomic, retain) UIImageView *imageView;

@end

/**
 *  相机预览视图控制器
 */
@interface GeeV2PFCameraPreviewController : TuSDKPFCameraPreviewControllerBase
/**
 *  拍照结果
 */
@property(nonatomic, retain) TuSDKResult *result;

/**
 *  预览视图
 */
@property(nonatomic, retain) GeeV2PFCameraPreview *defaultView;
/**
 *  视图类 (默认:GeeV2PFCameraPreview, 需要继承 GeeV2PFCameraPreview 重写LSQInitView，可以改变工具栏样式)
 */
@property (nonatomic, strong) Class defaultViewClazz;

/**
 *  相机预览视图控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFCameraPreviewControllerDelegate> delegate;

@end

