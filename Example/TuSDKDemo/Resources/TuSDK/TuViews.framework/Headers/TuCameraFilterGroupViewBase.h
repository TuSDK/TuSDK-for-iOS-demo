//
//  TuCameraFilterGroupViewBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/9.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuGroupFilterBaseView.h"

/**
 *  相机滤镜视图基础类
 */
@interface TuCameraFilterGroupViewBase : TuGroupFilterBaseView
/**
 *  等待拍照状态激活秒 (默认：3秒)
 */
@property (nonatomic) CGFloat captureActivateWait;

/**
 *  选择一个滤镜组
 *
 *  @return 是否选中
 */
- (BOOL)onGroupFilterSelectedWithItem:(TuGroupFilterItem *)item capture:(BOOL)capture;
@end
