//
//  TuSDKStickerImage.h
//  TuSDKVideo
//
//  Created by Yanlin Qiu on 16/11/2016.
//  Copyright © 2016 TuSDK. All rights reserved.
//
#import "TuSDKPFSticker.h"
#import <CoreMedia/CoreMedia.h>

/**************************************************/
@interface TuSDKStickerImage : NSObject

@property (nonatomic, assign) GLuint textureId;

+ (instancetype)initWithImage:(UIImage *)image;

@end
