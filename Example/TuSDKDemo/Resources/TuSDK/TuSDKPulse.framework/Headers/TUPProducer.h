//
//  TUPProducer.h
//  TuSDKPulse
//
//  Created by tutu on 2020/6/18.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "TuSDKPulse/TUPBase.h"



NS_ASSUME_NONNULL_BEGIN





typedef NS_ENUM(NSUInteger, TUPProducerState) {
    kWRITING,
    kEND,
    kDO_START,
    kDO_STOP,
    kDO_CANCEL
};


@protocol TUPProducerDelegate <NSObject>

- (void) onProducerEvent:(TUPProducerState)state withTimestamp:(NSInteger) ts;

@end


@interface TUPProducer_OutputConfig : NSObject


/// trim range;
@property(nonatomic) int64_t rangeStart; //default = 0
@property(nonatomic) int64_t rangeDuration; //default =-1

/// encoder configuration
@property(nonatomic) int width;
@property(nonatomic) int height;
@property(nonatomic) double scale;
//@property(nonatomic) int framerate;

@property(nonatomic) int bitrate;
@property(nonatomic) int keyint;

/// watermark image & position
@property(nonatomic) UIImage* watermark;
@property(nonatomic) int watermarkPosition; // default = -1(tr),  0 : tl, 1 : tr, 2 : bl, 3 : br


@end




@interface TUPProducer : TUPBase {
    @public
    void* _impl;
}

@property(nonatomic, weak) id<TUPProducerDelegate> delegate;
@property(nonatomic, copy) NSString* savePath;

//- (void) dealloc;

//- (instancetype) init;



//- (BOOL) create...

//- (BOOL) open;

- (void) close;


- (BOOL) setOutputConfig:(TUPProducer_OutputConfig*)config;


- (BOOL) start;

- (void) cancel;

//- (void) waitComplete;



- (NSInteger) getDuration;





@end

NS_ASSUME_NONNULL_END
