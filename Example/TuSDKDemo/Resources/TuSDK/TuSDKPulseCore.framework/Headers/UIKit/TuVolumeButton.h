//
//  TuVolumeButton.h
//  TuSDKPulseCore
//
//  Created by 刘鹏程 on 2023/3/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  音量事件回调
 *
 *  @param isVolumeUpPressed 音量 + 按钮按下
 */
typedef void (^TuVolumeButtonBlock)(BOOL isVolumeUpPressed);

@interface TuVolumeButton : NSObject

/**
 *  音量事件回调Block
 */
@property (nonatomic, copy) TuVolumeButtonBlock volumeBlock;


/**
 *  开始侦听音量键
 */
- (void)startListenVolumeButtonEvents;

/**
 *  停止侦听音量键
 */
- (void)stopListenVolumeButtonEvents;

@end

NS_ASSUME_NONNULL_END
