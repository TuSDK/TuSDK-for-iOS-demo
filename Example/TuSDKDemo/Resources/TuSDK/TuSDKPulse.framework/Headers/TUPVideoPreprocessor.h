//
//  TUPVideoPreprocessor.h
//  TuSDKPulse
//
//  Created by tutu on 2021/6/9.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



typedef NS_ENUM(NSUInteger, TUPVideoPreprocessorState) {
    kTUPVideoPreprocessorState_OPEN,
    kTUPVideoPreprocessorState_CLOSE,
    kTUPVideoPreprocessorState_START,
    kTUPVideoPreprocessorState_CANCEL,
    kTUPVideoPreprocessorState_WRITTING,
    kTUPVideoPreprocessorState_END
};


@protocol TUPVideoPreprocessorDelegate <NSObject>

- (void) onVideoPreprocessorEvent:(TUPVideoPreprocessorState)state withTimestamp:(NSInteger) ts;

@end


@interface TUPVideoPreprocessor_Config : NSObject

@property(nonatomic, copy) NSString* inputPath;
@property(nonatomic, copy) NSString* outputPath;

@property(nonatomic) double outFramerate;
@property(nonatomic) int keyint;

@end

@interface TUPVideoPreprocessor : NSObject


@property(nonatomic, weak) id<TUPVideoPreprocessorDelegate> delegate;



- (instancetype) init;

- (BOOL) open:(TUPVideoPreprocessor_Config*) config;

- (void) close:(BOOL) wait;


- (BOOL) start;

- (BOOL) cancel;



@end

NS_ASSUME_NONNULL_END
