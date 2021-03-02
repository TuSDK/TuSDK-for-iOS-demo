//
//  TUPEngine.h
//  TuSDKPulse
//
//  Created by Zoeric on 2020/06/16.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <OpenGLES/EAGL.h>
#import "TUPBase.h"

NS_ASSUME_NONNULL_BEGIN

struct TUPEngineParameter {
    ///TODO
    //EAGLContext* glctx;
    //
};

@interface TUPEngine : TUPBase


- (instancetype) init NS_UNAVAILABLE;


+ (BOOL) Init:(EAGLContext* _Nullable)glctx;

+ (void) Terminate;


@end

NS_ASSUME_NONNULL_END
