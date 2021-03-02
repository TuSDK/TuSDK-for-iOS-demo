//
//  TUFPContext.h
//  TuSDKPulseFilter
//
//  Created by tutu on 2020/11/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPFilterCtx : NSObject
{
    @package
    void* _ctx;
    //FilterContext* _ctx;
}



- (instancetype) init NS_UNAVAILABLE;


- (instancetype) initWithImpl:(void*) impl;



@end

NS_ASSUME_NONNULL_END
