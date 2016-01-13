//
//  TuSDKCPGifImage.h
//  TuSDK
//
//  Created by Yanlin on 1/6/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKCPGifDecoder.h"

#define BUFFER_SIZE (10 * 1024 * 1024) // 10MB (minimum memory buffer size)

#define LOCK(...) OSSpinLockLock(&self->_lock); \
__VA_ARGS__; \
OSSpinLockUnlock(&self->_lock);

#define LOCK_VIEW(...) OSSpinLockLock(&view->_lock); \
__VA_ARGS__; \
OSSpinLockUnlock(&view->_lock);

#pragma mark - TuSDKCPAnimatedImage

@protocol TuSDKCPAnimationImage <NSObject>
@required
/**
 *  总帧数
 */
- (NSUInteger)frameCount;

/**
 *  动画播放次数, 0表示无限循环
 */
- (NSUInteger)loopCount;

/**
 *  指定帧的图片
 *
 *  @param index 帧索引
 *
 *  @return 图片
 */
- (UIImage *)imageFrameAtIndex:(NSUInteger)index;

/**
 *  获取指定帧的时长，单位: 秒
 *
 *  @param index 帧索引
 *
 *  @return 帧时长
 */
- (NSTimeInterval)durationAtIndex:(NSUInteger)index;

@optional
/**
 *  显示区域
 *
 *  @param index 帧索引
 *
 *  @return CGRect
 */
- (CGRect)contentsRectAtIndex:(NSUInteger)index;

@end

#pragma mark - TuSDKCPGifImage

/**
 *  GifImage对象
 *
 *  @return GifImage对象
 */
@interface TuSDKCPGifImage : TuSDKCPImage <TuSDKCPAnimationImage>

/**
 *  从Bundle文件创建GifImage对象
 *
 *  @param name 资源文件名
 *  @return GifImage对象
 */
+ (TuSDKCPGifImage *)imageNamed:(NSString *)name;

/**
 *  根据文件路径创建GifImage对象
 *
 *  @param name 绝对路径
 *  @return GifImage对象
 */
+ (TuSDKCPGifImage *)imageWithContentsOfFile:(NSString *)path;

/**
 *  从NSData对象创建GifImage对象
 *
 *  @param name 资源文件名
 *  @return GifImage对象
 */
+ (TuSDKCPGifImage *)imageWithData:(NSData *)data;


#pragma mark - properties

/**
 *  总帧数
 */
@property (nonatomic, readonly) NSUInteger frameCount;

/**
 *  当前帧索引
 */
@property (nonatomic, readonly) NSUInteger currentFrameIndex;


@end
