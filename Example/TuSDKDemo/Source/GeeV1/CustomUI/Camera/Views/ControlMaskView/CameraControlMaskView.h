//
//  CameraControlMaskView.h
//  TuSDKDemo
//
//  Created by 刘鹏程 on 2020/6/10.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "CameraMoreMenuView.h"
#import "CameraFilterPanelView.h"

NS_ASSUME_NONNULL_BEGIN
/**
 相机操作按钮类型
 */
typedef NS_ENUM(NSInteger, lsqCameraHandleType)
{
    /**返回操作*/
    lsqCameraHandleTypeBack,
    /**切换摄像头操作*/
    lsqCameraHandleTypeSwitchCamera,
    /**拍照操作*/
    lsqCameraHandleTypeTakePhoto,
};

@protocol CameraControlMaskViewDelegate <NSObject>

/**
 操作按钮点击相应事件聚合
 */
- (void)onClickButtonCompletion:(lsqCameraHandleType)handleType;

@end

@interface CameraControlMaskView : UIView


/**
 更多按钮
 */
@property (nonatomic, strong) UIButton *moreButton;

/**
 更多菜单叠层视图
 */
@property (nonatomic, strong) CameraMoreMenuView *moreMenuView;

/**
 滤镜面板叠层视图
 */
@property (nonatomic, strong) CameraFilterPanelView *filterPanelView;
/**
 添加代理，此处使用 NSHashTable 存储添加的代理对象，以消除强引用
 */
- (void)addDelegate:(id<CameraControlMaskViewDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
