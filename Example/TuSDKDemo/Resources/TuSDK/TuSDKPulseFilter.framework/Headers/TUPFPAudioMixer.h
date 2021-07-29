//
//  TUPFPAudioMixer.h
//  TuSDKPulseFilter
//
//  Created by tutu on 2021/6/18.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPFPAudioMixer_Config : NSObject

@property (nonatomic, copy) NSString* path;
@property (nonatomic) int sampleRate;
@property (nonatomic) int channels;
@property (nonatomic) int sampleCount;
@property (nonatomic) long startPos;
@property (nonatomic) float fileMixWeight; // (0,1]
@property (nonatomic) float recordMixWeight;
@property (nonatomic) float stretch;
@end


@interface TUPFPAudioMixer : TUPBase

@property (nonatomic, strong, readonly) TUPFPAudioMixer_Config *config;


- (BOOL) open:(TUPFPAudioMixer_Config*) config;

- (void) close;

- (int) sendPrimaryAudio:(void*) pcm andLength:(size_t) len;

- (int) getPCMForPlay:(void*) pcm andLength:(size_t) len;

- (int) getPCMForRecord:(void*) pcm andLength:(size_t) len;



@end

NS_ASSUME_NONNULL_END
