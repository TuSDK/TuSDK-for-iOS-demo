//
//  TUPAudioProcessor.h
//  TuSDKPulseFilter
//
//  Created by 言有理 on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPBase.h>
#import <TuSDKPulse/TUPConfig.h>
NS_ASSUME_NONNULL_BEGIN
@class TUPAudioCtx;
@interface TUPAudioProcessor : TUPBase {
    @package
    void* _pimpl;
}
- (instancetype) init:(TUPAudioCtx*) ctx withName:(NSString*) name;
- (instancetype) init:(TUPAudioCtx*) ctx withImpl:(void*) impl;


- (BOOL) setConfig:(TUPConfig*) config;
- (TUPConfig*) getConfig;
@end

NS_ASSUME_NONNULL_END
