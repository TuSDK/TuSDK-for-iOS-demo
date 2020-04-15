//
//  TuSDKLiveStickerImage.h
//  TuSDKVideo
//
//  Created by Yanlin Qiu on 16/11/2016.
//  Copyright © 2016 TuSDK. All rights reserved.
//
#import "TuSDKPFSticker.h"
#import <CoreMedia/CoreMedia.h>


/**************************************************/
@interface TuSDKStickerAnimationItem:NSObject

- (instancetype)initWithTextueID:(GLuint)textureID imageWidth:(NSUInteger)imageWidth;
@property (nonatomic, assign) NSUInteger imageWidth;
@property (nonatomic, assign) GLuint textureID;
@end


/**************************************************/
@interface LiveStickerTextureResources:NSObject

- (instancetype)initWithImageData:(GLubyte *)data
                            width:(NSUInteger)width
                           height:(NSUInteger)height
                           format:(GLenum)format;

@property (nonatomic, readonly) GLubyte *imageData;
@property (nonatomic, readonly) NSUInteger imageWidth;
@property (nonatomic, readonly) NSUInteger imageHeight;
@property (nonatomic, readonly) GLenum imageFormat;
@end

@protocol TuSDKLiveStickerImageDelegate<NSObject>
- (void)StickerLoadCompleted:(NSInteger)id;
@end

/**************************************************/
@interface TuSDKLiveStickerImage : NSObject

@property (nonatomic, assign) NSInteger id;

@property (nonatomic, readonly, weak) TuSDKPFSticker *pfSticker;

@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, assign) BOOL isLoading;

// 设置是否根据计时时间自动播放贴纸  默认为 YES 即，使用计时器自动更改贴纸index
@property (nonatomic, assign) BOOL isAutoplayStickers;
// 贴纸显示时间，当选择了某一段视频时，需要传入此参数进行贴纸帧和视频帧时间的校对
@property (nonatomic) CMTime stickerShowTime;
@property (nonatomic, weak) id<TuSDKLiveStickerImageDelegate> delegate;


+ (instancetype)initWithImage:(UIImage *)image;

- (void)updateSticker:(TuSDKPFSticker *)newSticker;
- (TuSDKStickerAnimationItem *)getCurrentTexture;

- (void)playFromFrameIndex:(NSInteger)index;
- (void)seekToFrameByTime:(CMTime)frameTime;

@end
