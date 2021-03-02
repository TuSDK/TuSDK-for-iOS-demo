//
//  CameraFilterPanelView.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/23.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OverlayViewProtocol.h"
#import "ParametersAdjustView.h"
#import "CameraFilterPanelProtocol.h"

/**
 相机滤镜面板
 */
@interface CameraFilterPanelView : UIView <OverlayViewProtocol, CameraFilterPanelProtocol>

/**
 触发者
 */
@property (nonatomic, weak) UIControl *sender;

/**
 选中的滤镜 filterCode
 */
@property (nonatomic, copy) NSString *selectedFilterCode;

/**
 选中的标签索引
 */
@property (nonatomic, assign, readonly) NSInteger selectedTabIndex;

@property (nonatomic, weak) id<CameraFilterPanelDelegate> delegate;
@property (nonatomic, weak) id<CameraFilterPanelDataSource> dataSource;

@end
