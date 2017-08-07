//
//  TuSDKGPUImageFilter.h
//  TuSDK
//
//  Created by Yanlin Qiu on 17/03/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import <GPUImage/GPUImage.h>
#import "TuSDKFilterParameter.h"
#import "TuSDKFilterAdapter.h"

@interface TuSDKGPUImageFilter : TuSDKFilter


/**
 enable live sticker (default: NO)
 */
@property (nonatomic) BOOL enableLiveSticker;

/**
 Bind texture with input frameBuffer
 */
- (void)inputFramebufferBindTexture;

/**
 unlock input frameBuffer
 */
- (void)inputFramebufferUnlock;

/**
 根据某个时间设置贴纸 index
 
 @param time 时间参数
 */
- (void)seekToStickerIndexByTime:(CMTime)time;

#pragma mark - TuSDKFilterStickerProtocol
/**
 *  更新贴纸数据
 *
 *  @param stickers 要显示的贴纸数据
 */
- (void)setLiveStickers:(NSArray *)stickers;

/**
 设置显示区域和视图比例
 
 @param displayRect 显示区域
 @param ratio 画面尺寸
 */
- (void)setDisplayRect:(CGRect)displayRect withRatio:(CGFloat)ratio;

/**
 设置是否显示贴纸
 
 @param isVisibility 是否显示贴纸，YES：显示贴纸   NO：不显示
 */
- (void)setStickerVisibility:(BOOL)isVisibility;

/**
 设置是否根据计时时间自动播放贴纸  注：视频剪辑中贴纸时间使用视频帧时间设置贴纸帧的index，录制中贴纸时间根据定时器时间自动播放
 
 @param isAutoplay 是否根据计时时间自动播放贴纸，若不调用该方法，默认值为 YES
 */
- (void)setAutoplayStickers:(BOOL)isAutoplay;

/**
 设置贴纸显示时间，当选择了某一段视频时，需要传入此参数进行贴纸帧和视频帧时间的校对
 */
- (void)setStickerShowTime:(CMTime)stickerShowTime;

#pragma mark - TuSDKFilterFacePositionProtocol
/**
 *  更新位置
 *
 *  @param points 特征点坐标
 *  @param angle  设备角度
 */
- (void)updateFaceFeatures:(NSArray<NSValue *> *)points angle:(float)angle;

@end
