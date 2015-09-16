//
//  TuSDKGPUImageHelper.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/17.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GPUImage/GPUImage.h>
/**
 *  GPUImage帮助类
 */
@interface TuSDKGPUImageHelper : NSObject
/**
 *  通过图片方向获取GPUImage方向
 *
 *  @param imageOrientation 图片方向
 *
 *  @return GPUImage方向
 */
+ (GPUImageRotationMode)rotationModeWithImageOrientation:(UIImageOrientation)imageOrientation;
@end
