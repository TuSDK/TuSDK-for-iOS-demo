//
//  ExtendCameraBaseComponent.h
//  TuSDKDemo
//
//  Created by Clear Hu on 15/5/11.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "DemoSimpleBase.h"

#pragma mark - ExtendCameraBaseComponent
/**
 *  基础相机组件范例 (对现有组件进行扩展 - 修改界面)
 */
@interface ExtendCameraBaseComponent : DemoSimpleBase

@end

#pragma mark - ExtendCameraBaseController
/**
 *  基础相机组件范例 - 相机视图控制器
 */
@interface ExtendCameraBaseController : TuSDKPFCameraViewController

@end


#pragma mark - ExtendCameraBaseView
/**
 *  基础相机组件范例视图自定义
 */
@interface ExtendCameraBaseView : TuSDKPFCameraView

@end

#pragma mark - ExtendCameraBaseFilterItemCell
/**
 *  基础相机组件范例视图 滤镜行视图
 */
@interface ExtendCameraBaseFilterItemCell : TuSDKCPGroupFilterItemCell

@end