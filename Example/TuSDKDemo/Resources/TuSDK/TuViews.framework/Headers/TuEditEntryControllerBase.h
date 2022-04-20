//
//  TuEditEntryControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "TuSDKPulseCore/core/TuRatioType.h"
//#import "TuSDKPulseCore/cx/seles/extend/SelesParameters.h"
#import "TuImageResultController.h"
#import "TuFilterStickerView.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>
// 图片编辑入口控制器基础类
@interface TuEditEntryControllerBase : TuImageResultController
// 图片视图
@property (nonatomic, readonly) UIView<TuFilterStickerViewInterface> *imageView;
// 滤镜参数
@property (nonatomic, strong) SelesParameters * filterParams;
// 显示背景区域颜色
@property (nonatomic, strong) UIColor* displayBackgroundColor;
// 显示图片
@property (nonatomic, strong) UIImage* displayImage;
// 最大输出图片边长 (默认:0, 不限制图片宽高)
@property (nonatomic) NSUInteger limitSideSize;
// 最大输出图片按照设备屏幕 (默认:true, 如果设置了LimitSideSize, 将忽略LimitForScreen)
@property (nonatomic) BOOL limitForScreen;
// 视频视图显示比例类型 (默认:TTRatioDefault, 如果设置cameraViewRatio > 0, 将忽略ratioType)
@property (nonatomic) TTRatioType ratioType;
/**
 *  视图显示比例类型列表 ( 优先级 ratioTypeList > ratioType, 默认：lsqTuSDKRatioDefaultTypes)
 *  设置 NSNumber 型数组来控制显示的按钮顺序， 例如:
 *	@[@(lsqRatioOrgin), @(lsqRatio_1_1), @(lsqRatio_2_3), @(lsqRatio_3_4)]
 */
@property (nonatomic, strong) NSArray<NSNumber *> *ratioTypeList;
// 获取当前可用比例列表
@property (nonatomic, readonly) NSArray<NSNumber *> *ratioTypes;
#pragma mark - inner config
// 滤镜处理过的原始图片
@property (nonatomic, readonly) UIImage *filterImage;
// 经过裁剪的原始图片
@property (nonatomic, readonly) UIImage *cuterImage;
// 裁剪结果
@property (nonatomic, retain) TuResult *cuterResult;
/**
 *  开启响应处理控制器
 *  @param btn 入口按钮
 */
- (void)onEntryAction:(UIButton *)btn;

/**
 *  添加贴纸数据
 *  @param sticker 贴纸数据
 */
- (void)appendSticker:(TuSticker *)sticker;

- (void)appendSticker:(TuSticker *)sticker frame:(CGRect)frame;
// 编辑图片完成按钮动作
- (void)onImageCompleteAtion;
@end
