//
//  TuImageShower.h
//  TuSDK
//
//  Created by Clear Hu on 2020/4/27.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

//#import "TuSDKPulseCore/TuSDKPulseCore.h"
#import <TuSDKPulseCore/TuSDKPulseCore.h>
#pragma mark - TuImageShower
@class SelesParameters;

// 图片渲染接口
@protocol TuImageShower<NSObject>
@property(nonatomic, strong) UIColor *displayBackgroundColor; // 视频背景区域颜色
/**是否开启滤镜渲染效果，默认为YES*/
@property (nonatomic) BOOL enableFilter;

- (instancetype)initWithRootView:(UIView *)rootView;
- (void)setImage:(UIImage *)image rotation:(TuRotationMode)rotation;   // 设置图片
- (SelesParameters *)changeFilter:(NSString *)code params:(SelesParameters *)params;            // 切换滤镜 [返回参数列表]

+ (UIImage *)autoColorAnalysis:(UIImage *)image args:(TuNKImageColorArgument *)args;
+ (UIImage *)filterImage:(UIImage *)image code:(NSString *)code params:(SelesParameters *)params; // 对图片使用滤镜

@end
