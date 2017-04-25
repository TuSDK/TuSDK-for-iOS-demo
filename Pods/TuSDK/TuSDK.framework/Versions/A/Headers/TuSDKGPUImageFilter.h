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

#pragma mark - TuSDKFilterStickerProtocol
/**
 *  更新贴纸数据
 *
 *  @param stickers 要显示的贴纸数据
 */
- (void)setLiveStickers:(NSArray *)stickers;

#pragma mark - TuSDKFilterFacePositionProtocol
/**
 *  更新位置
 *
 *  @param points 特征点坐标
 *  @param angle  设备角度
 */
- (void)updateFaceFeatures:(NSArray<NSValue *> *)points angle:(float)angle;

@end
