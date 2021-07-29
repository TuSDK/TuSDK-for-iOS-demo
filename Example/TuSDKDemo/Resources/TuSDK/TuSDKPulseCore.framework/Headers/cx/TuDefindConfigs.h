//
//  TuCameraConfigs.h
//  TuSDK
//
//  Created by Clear Hu on 2020/4/22.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <TuSDKPulseCore/TUCEnum.h>
NS_ASSUME_NONNULL_BEGIN


#pragma mark - TuRotationMode


#pragma mark - TuFormatMode
// 格式模式
typedef NS_ENUM(NSInteger, TuFormatMode)
{
    TuFormatMode_Data            = 0,   // 数据模式
    TuFormatMode_Picture         = 1,   // 单帧图片
    TuFormatMode_Texture         = 20,  // 材质模式
    TuFormatMode_yuv420_I420     = 30,  // YYYYYYYY UU VV => YUV420P
    TuFormatMode_yuv420_YV12     = 31,  // YYYYYYYY VV UU => YUV420P
    TuFormatMode_yuv420_NV12     = 32,  // YYYYYYYY UVUV  => YUV420SP
    TuFormatMode_yuv420_NV21     = 33,  // YYYYYYYY VUVU  => YUV420SP
};

#pragma mark - TuFormatRange
// 颜色范围
typedef NS_ENUM(NSInteger, TuFormatRange)
{
    TuFormatRange_Unknow      = 0,
    TuFormatRange_Video_610   = 1,
    TuFormatRange_Full_610    = 2,
    TuFormatRange_Video_709   = 3,
    TuFormatRange_Full_709    = 4,
};

#pragma mark - TuCoderFormat
// 编解码格式
typedef struct
{
    TuFormatMode  format;    // 输出格式 tutu::Yuv420Type
    TuFormatRange yuvRange;  // Yuv范围 tutu::YuvColorRange
} TuCoderFormat;

#pragma mark - TuCanvsPosition
// 位置
typedef NS_ENUM(NSInteger, TuCanvsPosition)
{
    TuCanvsPosition_TopLeft     = 0,    // 左上角
    TuCanvsPosition_TopRight    = 1,    // 右上角
    TuCanvsPosition_BottomLeft  = 2,    // 左下角
    TuCanvsPosition_BottomRight = 3,    // 右下角
    TuCanvsPosition_Center      = 4,    // 居中显示
};

#pragma mark - TuDefindConfigs
/** 定义配置 */
@interface TuDefindConfigs : NSObject
// 转换UIImageOrientation为方向定义
+ (TuRotationMode)rotationModeWithImageOrientation:(UIImageOrientation)imageOrientation;
// 转换方向定义为UIImageOrientation
+ (UIImageOrientation)rotationModeWithTuRotationMode:(TuRotationMode)orientation;
// 转换方向
+ (TuRotationMode)rotationModeWithUIDevice:(UIDeviceOrientation)rotation mirror:(BOOL)mirror;
// 镜像方向
+ (TuRotationMode)mirrorWithTuRotation:(TuRotationMode)orientation;

// 是否交换长宽
+ (BOOL)isTransposedUI:(UIInterfaceOrientation)uiRotate;

// 通过TuRotationMode方向旋转归一化区域
+ (CGRect)rotationWithRect:(CGRect)rect rotation:(TuRotationMode)rotation;

@end

NS_ASSUME_NONNULL_END
