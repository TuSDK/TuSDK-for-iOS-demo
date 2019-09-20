//
//  GeeV2PFEditTabBarSubControllerInterface.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/10/24.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//
#import <UIKit/UIKit.h>

/**
 *  进度信息提示接口
 */
@protocol GeeV2PFEditTabBarSubControllerInterface <NSObject>
/**
 * 重置控制器到初始状态
 */
- (void)resetController;
/**
 *  编辑图片完成按钮动作
 */
- (void)onImageCompleteAtion;
/**
 * 准备保存，重新配置控制器
 */
- (void)prepareToSaveConfigWith:(TuSDKCPResultViewController *)controller;
@end
