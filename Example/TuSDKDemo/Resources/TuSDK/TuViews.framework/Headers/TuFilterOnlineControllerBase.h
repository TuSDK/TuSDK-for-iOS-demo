//
//  TuFilterOnlineControllerBase.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuOnlineController.h"
#import "TuGroupFilterItemCellBase.h"

/**
 *  在线滤镜控制器基础类
 */
@interface TuFilterOnlineControllerBase : TuOnlineController

/**
 *  滤镜栏类型
 */
@property (nonatomic) lsqGroupFilterAction action;

/** 选中对象ID */
- (void)onHandleSelectedWithID:(uint64_t)idt;

/** 选中对象ID */
- (void)onHandleDetailWithID:(uint64_t)idt;
@end
