//
//  TuSDKFilterWrap.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/27.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GPUImage/GPUImage.h>
#import "TuSDKFilterOption.h"
#import "TuSDKFilterParameter.h"

/**
 *  滤镜对象包装
 */
@interface TuSDKFilterWrap : NSObject

/**
 *  滤镜配置选项
 */
@property (nonatomic, readonly) TuSDKFilterOption *opt;

/**
 *  滤镜对象
 */
@property (nonatomic, readonly) GPUImageOutput <GPUImageInput> *filter;

/**
 *  滤镜配置选项
 */
@property (nonatomic, readwrite) TuSDKFilterParameter *filterParameter;

/**
 *  初始化滤镜对象包装
 *
 *  @param opt 滤镜配置选项
 *
 *  @return 滤镜对象包装
 */
+ (instancetype) initWithOpt:(TuSDKFilterOption *)opt;

/**
 *  绑定视频视图
 *
 *  @param view 视频视图
 */
- (void)bindWithCameraView:(GPUImageView *)view;

/**
 *  提交滤镜配置选项
 */
- (void)submitParameter;

/**
 *  处理材质
 */
- (void)processImage;

/**
 *  旋转材质到图片方向
 *
 *  @param imageOrientation 图片方向
 */
- (void)rotationTextures:(UIImageOrientation)imageOrientation;

/**
 *  执行滤镜 并输出图形
 *
 *  @param image 输入图像
 *
 *  @return 滤镜处理过的图像 (默认使用图像自身的方向属性)
 */
- (UIImage *)processWithImage:(UIImage *)image;

/**
 *  执行滤镜 并输出图形
 *
 *  @param image            输入图像
 *  @param imageOrientation 图像方向
 *
 *  @return 滤镜处理过的图像
 */
- (UIImage *)processWithImage:(UIImage *)image orientation:(UIImageOrientation)imageOrientation;

/**
 *  销毁
 */
- (void)destroy;

/**
 *  克隆滤镜对象包装
 *
 *  @return 滤镜对象包装
 */
- (instancetype)clone;
@end
