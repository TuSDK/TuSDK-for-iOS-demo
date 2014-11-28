//
//  TuSDKPFEditTurnAndCutViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/7.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import "TuSDKCPResultViewController.h"
#import "TuSDKPFEditTurnAndCutView.h"

@class TuSDKPFEditTurnAndCutViewController;

#pragma mark - TuSDKPFEditTurnAndCutDelegate
/**
 *  旋转和裁剪视图控制器委托
 */
@protocol TuSDKPFEditTurnAndCutDelegate <NSObject>
/**
 *  图片编辑完成
 *
 *  @param controller 旋转和裁剪视图控制器
 *  @param result 旋转和裁剪视图控制器处理结果
 */
- (void)onTuSDKPFEditTurnAndCut:(TuSDKPFEditTurnAndCutViewController *)controller result:(TuSDKResult *)result;
@optional
/**
 *  图片编辑完成  (异步方法)
 *
 *  @param controller 旋转和裁剪视图控制器
 *  @param result 旋转和裁剪视图控制器处理结果
 */
- (void)onAsyncTuSDKPFEditTurnAndCut:(TuSDKPFEditTurnAndCutViewController *)controller result:(TuSDKResult *)result;
@end

#pragma mark - TuSDKPFEditTurnAndCutViewController
/**
 *  旋转和裁剪视图控制器
 */
@interface TuSDKPFEditTurnAndCutViewController : TuSDKCPResultViewController<TuSDKPFCameraFilterDelegate>{
    @protected
    // 默认样式视图
    TuSDKPFEditTurnAndCutView *_defaultStyleView;
    // 选中的滤镜名称
    NSString *_selectedFilterName;
    // 预览图片视图
    UIButton *_preview;
}

/**
 *  旋转和裁剪视图控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFEditTurnAndCutDelegate> delegate;

/**
 *  输入的临时文件目录 (处理优先级: inputImage > inputTempFilePath > inputAsset)
 */
@property (nonatomic, copy) NSString *inputTempFilePath;

/**
 *  输入的相册图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
 */
@property (nonatomic, retain) ALAsset *inputAsset;

/**
 *  输入的图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
 */
@property (nonatomic, retain) UIImage *inputImage;

/**
 *  是否开启滤镜支持 (默认: 关闭)
 */
@property (nonatomic) BOOL enableFilters;

/**
 *  需要裁剪的长宽
 */
@property (nonatomic) CGSize cutSize;

/**
 *  预览图片视图
 */
@property (nonatomic, readonly) UIButton *preview;

/**
 *  是否显示处理结果预览图 (默认：关闭，调试时可以开启)
 */
@property (nonatomic) BOOL showResultPreview;

/**
 *  创建默认样式视图 (如需创建自定义视图，请覆盖该方法，并创建自己的视图类)
 */
- (void)buildDefaultStyleView;

/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion;

/**
 *  图片编辑处理完成
 *
 *  @param image 返回处理过的图片
 */
- (void)onEditCompleted:(UIImage *)image;
@end
