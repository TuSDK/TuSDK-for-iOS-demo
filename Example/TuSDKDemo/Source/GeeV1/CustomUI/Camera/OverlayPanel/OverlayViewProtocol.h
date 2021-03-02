//
//  OverlayViewPtotocol.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/24.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

/**
 浮层协议
 */
@protocol OverlayViewProtocol <NSObject>

/**
 触发者
 */
@property (nonatomic, weak) UIControl *sender;

@end
