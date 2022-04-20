//
//  TUPAudioPipe.h
//  TuSDKPulseFilter
//
//  Created by 言有理 on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPBase.h>
#import <TuSDKPulse/TUPConfig.h>

@class TUPAudioProcessor;
@class TUPAudioCtx;
NS_ASSUME_NONNULL_BEGIN

@interface TUPAudioPipe : TUPBase
- (instancetype) init;
- (TUPAudioCtx*) getContext;
- (BOOL) setConfig:(TUPConfig*) config;
- (TUPConfig*) getConfig;

- (BOOL) open:(TUPConfig*) config;
- (void) close;
- (BOOL) deleteProcessorAt:(NSInteger)idx;
- (nullable TUPAudioProcessor *)getProcessor:(NSInteger)idx;
- (BOOL) add:(TUPAudioProcessor *)processor atIndex:(NSInteger)index;

- (int) sendPCM:(void*)pcm andLength:(size_t) len;
- (int) receive:(void*) pcm andLength:(size_t) len;

- (int) send:(void*) pcm andLength:(size_t) len;
- (size_t)enqueue:(void*) pcm andLength:(size_t) len;
- (size_t)dequeue:(void*) pcm andLength:(size_t) len;
- (size_t)getSize;
@end

NS_ASSUME_NONNULL_END
