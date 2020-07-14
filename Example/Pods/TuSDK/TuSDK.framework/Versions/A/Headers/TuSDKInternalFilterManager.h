//
//  TuSDKInternalFilterManager.h
//  TuSDK
//
//  Created by Yanlin on 3/29/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKFilterWrap.h"
#import "TuSDKConfig.h"

/**
 *  Internal Filter API interface
 */
@interface TuSDKInternalFilterManager : NSObject

/**
 *  滤镜控管理器
 *
 *  @return manager 滤镜控管理器
 */
+ (instancetype) manager;

/**
 *  获取滤镜包装对象
 *
 *  @param code 滤镜代号
 *
 *  @return filterWrap 滤镜包装对象
 */
- (TuSDKFilterWrap *)filterWrapWithCode:(NSString *)code;

/**
 *  执行滤镜 并输出图形
 *
 *  @param image image 输入图像
 *  @param code  滤镜代号
 *
 *  @return image 滤镜处理过的图像 (默认使用图像自身的方向属性)
 */
- (UIImage *)processWithImage:(UIImage *)image byFilterCode:(NSString *)code;

/**
 *  执行滤镜 并输出图形
 *
 *  @param image            输入图像
 *  @param imageOrientation 图像方向
 *  @param code             滤镜代号
 *
 *  @return image 滤镜处理过的图像
 */
- (UIImage *)processWithImage:(UIImage *)image orientation:(UIImageOrientation)imageOrientation byFilterCode:(NSString *)code;


@end
