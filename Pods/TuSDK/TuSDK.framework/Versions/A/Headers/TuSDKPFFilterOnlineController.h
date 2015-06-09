//
//  TuSDKPFFilterOnlineController.h
//  TuSDK
//
//  Created by Clear Hu on 15/5/21.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCPOnlineController.h"
#import "TuSDKFilterLocalPackage.h"

@class TuSDKPFFilterOnlineController;
/**
 *  在线滤镜选择控制器委托
 */
@protocol TuSDKPFFilterOnlineControllerDelegate <NSObject>
/**
 *  选中一个滤镜对象
 *
 *  @param controller 在线滤镜选择控制器
 *  @param groupId    滤镜组ID
 */
- (void)onTuSDKPFStickerOnline:(TuSDKPFFilterOnlineController *)controller
               selectedGroupId:(uint64_t)groupId;
@end

#pragma mark - TuSDKPFFilterOnlineController
/**
 *  在线滤镜控制器
 */
@interface TuSDKPFFilterOnlineController : TuSDKCPOnlineController<TuSDKFilterLocalPackageDelegate>
/**
 *  在线滤镜选择控制器委托
 */
@property (nonatomic, assign) id<TuSDKPFFilterOnlineControllerDelegate> delegate;
@end
