//
//  TuSDKPFEditAdjustController.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/29.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPFilterResultController.h"
#import "TuSDKPFEditAdjustView.h"

#pragma mark - TuSDKPFEditAdjustController
/**
 *  颜色调整控制器
 */
@interface TuSDKPFEditAdjustController : TuSDKCPFilterResultController
/**
 *  视图类 (默认:TuSDKPFEditAdjustView, 需要继承 TuSDKPFEditAdjustView)
 */
@property (nonatomic, strong) Class viewClazz;
@end
