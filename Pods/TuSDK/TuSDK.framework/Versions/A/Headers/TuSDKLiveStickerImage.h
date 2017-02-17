//
//  TuSDKLiveStickerImage.h
//  TuSDKVideo
//
//  Created by Yanlin Qiu on 16/11/2016.
//  Copyright © 2016 TuSDK. All rights reserved.
//

#import "TuSDKPFSticker.h"

/**
 *  处理智能贴纸素材，转为 GL Texture
 */
@interface TuSDKLiveStickerImage : NSObject

/**
 根据图片进行初始化

 @param image 图片
 @return 
 */
+ (instancetype)initWithImage:(UIImage *)image;

/**
 *  当前贴纸对象
 */
@property (nonatomic, readonly) TuSDKPFSticker *currentSticker;

/**
 *  是否可用，在材质加载完毕后置为 YES
 */
@property (nonatomic, readonly) BOOL enabled;

/**
 *  是否处于使用状态
 */
@property (nonatomic, readonly) BOOL actived;

/**
 *  更新智能贴纸素材
 *
 *  @param newSticker TuSDKPFSticker 对象
 *
 */
- (void)updateSticker:(TuSDKPFSticker *)newSticker;

/**
 *  移除贴纸
 */
- (void)removeSticker;

/**
 *  获取当前 Texture ID
 */
- (GLuint)getCurrentTextureID;

/**
 *  重置
 */
- (void)reset;

@end
