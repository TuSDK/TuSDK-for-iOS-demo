//
//  TUPAudioCtx.h
//  TuSDKPulseFilter
//
//  Created by 言有理 on 2021/7/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPAudioCtx : NSObject {
    @package
    void* _ctx;
    //FilterContext* _ctx;
}

- (instancetype) init NS_UNAVAILABLE;

- (instancetype) initWithImpl:(void*) impl;
@end

NS_ASSUME_NONNULL_END
