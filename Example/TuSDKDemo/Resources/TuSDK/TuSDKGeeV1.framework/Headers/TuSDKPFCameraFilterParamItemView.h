//
//  TuSDKPFCameraFilterParamItemView.h
//  TuSDKGeeV1
//
//  Created by wen on 13/09/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>

#pragma mark - TuSDKPFCameraFilterParamItemView
/**
 滤镜调节栏item类
 */
@interface TuSDKPFCameraFilterParamItemView : UIView
// 记录参数的 key
@property (nonatomic, strong) NSString *paramKey;
// 记录当前 progress
@property (nonatomic, assign) CGFloat progress;
// 控件主色调
@property (nonatomic, strong) UIColor *mainColor;
// 参数对象
@property (nonatomic, strong) SelesParameterArg *arg;

/**
 初始化调节栏视图的方法
 
 @param title 调节栏显示名称
 @param progress 初始显示progress
 */
- (void)initParamViewWith:(NSString *)title originProgress:(CGFloat)progress;
@end
