//
//  TuEditSkinControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuFilterResultController.h"
/**
 *  多功能美肤基类
 */
@interface TuEditSkinControllerBase : TuFilterResultController

/**
 一键美颜 0 - 1.0，默认 1.0
 */
@property (nonatomic, assign) CGFloat retouchSize;

/**
 * 一键美颜是否开启，默认为YES
 * @return
 */
@property (nonatomic, assign) BOOL enableAutoSkin;

/**
 *  选中一个参数动作
 *
 *  @param btn 选中按钮
 */
- (void)onArgSelectedAction:(UIView *)btn;

/**
 *  获取当前选中动作
 *
 *  @return 当前动作索引
 */
- (NSUInteger)getCurrentAction;

/**
 *  设置配置视图隐藏状态
 *
 *  @param isHidden 是否隐藏
 */
- (void)setConfigViewHiddenState:(BOOL)isHidden;

/**
 *  人脸检测结果回调
 *
 *  @param found 是否检测到人脸
 */
- (void)onFaceDetectionResult:(BOOL)found;

/**
 *  配置返回无保存
 *
 *  @param view     参数配置视图
 */
- (void)onTuSDKCPParameterConfigBackNotSave:(UIView<TuParameterConfigViewInterface> *)view;
@end
