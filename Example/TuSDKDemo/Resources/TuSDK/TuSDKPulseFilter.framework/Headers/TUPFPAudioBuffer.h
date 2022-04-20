//
//  TUPFPAudioBuffer.h
//  TuSDKPulseFilter
//
//  Created by 言有理 on 2021/12/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPFPAudioBuffer : NSObject
- (size_t)enqueue:(void*) pcm andLength:(size_t) len;
- (size_t)dequeue:(void*) pcm andLength:(size_t) len;
- (size_t)getSize;
- (void) close;
@end

NS_ASSUME_NONNULL_END
