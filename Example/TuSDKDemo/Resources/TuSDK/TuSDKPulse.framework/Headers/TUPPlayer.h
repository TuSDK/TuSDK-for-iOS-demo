//
//  TUPPlayer.h
//  TuSDKPulse
//
//  Created by tutu on 2020/6/15.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "TuSDKPulse/TUPBase.h"


NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, TUPPlayerState) {
    kREADY,
    kPLAYING,
    kEOS,
    kAUDIO_EOS,
    kVIDEO_EOS,
    kDO_PLAY,
    kDO_PAUSE,
    kDO_RESUME,
    kDO_PREVIEW,
    kDO_SEEK,
};


@protocol TUPPlayerDelegate <NSObject>

- (void) onPlayerEvent:(TUPPlayerState)state withTimestamp:(NSInteger) ts;

@end


@interface TUPPlayer_OutputConfig : NSObject


@property(nonatomic) double scale;
@property(nonatomic) int framerate;

/// trim range;
@property(nonatomic) int64_t rangeStart; //default = 0
@property(nonatomic) int64_t rangeDuration; //default =-1

/// watermark image & position
@property(nonatomic) UIImage* watermark;
@property(nonatomic) int watermarkPosition; // default = -1(tr),  0 : tl, 1 : tr, 2 : bl, 3 : br


@end



//struct TUPPlayerImpl;
@interface TUPPlayer : TUPBase {
    @public
    void* _impl;
}


@property(nonatomic, weak) id<TUPPlayerDelegate> delegate;

//- (void) dealloc;

//- (BOOL) open:(NSString*)

- (void) close;

- (BOOL) setOutputConfig:(TUPPlayer_OutputConfig*)config;


- (BOOL) play;

- (BOOL) pause;

- (BOOL) seekTo:(NSInteger)pts;

- (BOOL) previewFrame:(NSInteger)pts;



- (NSInteger) getDuration;


//- (void) _signalEvent:(TUPPlayerState)state withTimestamp:(NSInteger)pts;


@end

NS_ASSUME_NONNULL_END
