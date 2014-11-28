//
//  TuSDKTSAVAudioPlayer+Extend.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/5.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
/**
 *  音频设备扩展
 */
@interface AVAudioPlayer(TuSDKTSAVAudioPlayerExtend)

/**
 *  播放 lasFilterUIBundle 相机对焦音效
 *
 *  @return 音频播放对象
 */
+ (instancetype)playerLsqBundleCameraFocusBeep;

/**
 *  播放 lasFilterUIBundle 内的音频文件
 *
 *  @param audioName 音频文件名
 *
 *  @return 音频播放对象
 */
+ (instancetype)playerLsqBundlePathWithName:(NSString *)audioName;

/**
 *  播放音频文件
 *
 *  @param path 音频文件路径
 *
 *  @return 音频播放对象
 */
+ (instancetype)playerWithFilePath:(NSString *)path;
@end
