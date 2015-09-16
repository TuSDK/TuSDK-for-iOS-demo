//
//  TuSDKPFEditEntryControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCPImageResultController.h"
#import "TuSDKRatioType.h"
#import "TuSDKCPFilterStickerView.h"

/**
 *  图片编辑入口控制器基础类
 */
@interface TuSDKPFEditEntryControllerBase : TuSDKCPImageResultController
/**
 *  图片视图
 */
@property (nonatomic, readonly) UIView<TuSDKCPFilterStickerViewInterface> *imageView;

/**
 *  最大输出图片边长 (默认:0, 不限制图片宽高)
 */
@property (nonatomic) NSUInteger limitSideSize;

/**
 *  最大输出图片按照设备屏幕 (默认:false, 如果设置了LimitSideSize, 将忽略LimitForScreen)
 */
@property (nonatomic) BOOL limitForScreen;

/**
 *  视频视图显示比例类型 (默认:lsqRatioAll, 如果设置cameraViewRatio > 0, 将忽略ratioType)
 */
@property (nonatomic) lsqRatioType ratioType;

#pragma mark - inner config
/**
 *  滤镜处理过的原始图片
 */
@property (nonatomic, readonly) UIImage *filterImage;

/**
 *  经过裁剪的原始图片
 */
@property (nonatomic, readonly) UIImage *cuterImage;

/**
 *  裁剪结果
 */
@property (nonatomic, retain) TuSDKResult *cuterResult;

/**
 *  当前所使用的滤镜
 */
@property (nonatomic, retain) TuSDKFilterWrap *filterWrap;

/**
 *  开启响应处理控制器
 *
 *  @param btn 入口按钮
 */
- (void)onEntryAction:(UIButton *)btn;

/**
 *  添加贴纸数据
 *
 *  @param sticker 贴纸数据
 */
- (void)appendSticker:(TuSDKPFSticker *)sticker;

/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion;
@end
