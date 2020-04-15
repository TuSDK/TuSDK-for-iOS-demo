//
//  TuSDKLiveStickerManager.h
//  TuSDKVideo
//
//  Created by Yanlin Qiu on 24/11/2016.
//  Copyright © 2016 TuSDK. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "TuSDKFilterAdapter.h"
#import "TuSDKLiveStickerImage.h"

@protocol TuSDKLiveStickerManagerDelegate<NSObject>
- (void)StickerLoadCompleted:(BOOL)isSucessed;
@end

@interface TuSDKLiveStickerManager:NSObject

@property (nonatomic, weak) id<TuSDKLiveStickerManagerDelegate> delegate;

+ (dispatch_queue_t)sharedLoadQueue;

- (BOOL)showStickerGroup:(TuSDKPFStickerGroup *)stickerGroup;
- (void)removeAllStickers;
- (NSArray *)getStickers;

@end
