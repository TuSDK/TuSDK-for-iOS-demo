//
//  CustomizedCameraComponent.h
//  TuSDKDemo
//
//  Created by Clear Hu on 15/5/11.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "SampleBase.h"

#pragma mark - CustomizedCameraComponent
/**
 *  基础相机组件范例 (对现有组件进行扩展 - 修改界面)
 */
@interface CustomizedCameraComponent : SampleBase

@end

#pragma mark - CustomizedCameraController
/**
 *  基础相机组件范例 - 相机视图控制器
 */
@interface CustomizedCameraController : TuSDKPFCameraViewController

@end


#pragma mark - CustomizedCameraView
/**
 *  基础相机组件范例视图自定义
 */
@interface CustomizedCameraView : TuSDKPFCameraView

@end

#pragma mark - CustomizedCameraFilterItemCell
/**
 *  基础相机组件范例视图 滤镜行视图
 */
@interface CustomizedCameraFilterItemCell : TuSDKCPGroupFilterItemCell

@end