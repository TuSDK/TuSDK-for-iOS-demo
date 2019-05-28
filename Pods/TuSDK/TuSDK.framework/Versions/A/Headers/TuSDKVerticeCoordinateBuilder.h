//
//  TuSDKVerticeCoordinateBuilder.h
//  TuSDKVideo
//
//  Created by sprint on 04/05/2018.
//  Copyright © 2018 TuSDK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKOpenGLAssistant.h"


@protocol TuSDKVerticeCoordinateBuilder

/**
 设置输出尺寸
 设置输出 outputSize, 如果输出比例和原视频比例不一致时，将自动居中裁剪
 */
@property (nonatomic) CGSize outputSize;

/**
 设置输出 outputSize, 如果输出比例和原视频比例不一致时，自动缩放视频大小，视频不会被裁剪

 @param outputSize 输出尺寸
 @param aspectOutputRatioInSideCanvas 比例不一致时是否将视频自适应画布大小 默认：NO
 */
- (void)setOutputSize:(CGSize)outputSize aspectOutputRatioInSideCanvas:(BOOL)aspectOutputRatioInSideCanvas;

- (BOOL)calculate:(CGSize) size orientation:(LSQGPUImageRotationMode) orientation verticesCoordinates:(GLfloat[]) verticesCoordinates textureCoorinates:(GLfloat[])textureBuffer;

@end
