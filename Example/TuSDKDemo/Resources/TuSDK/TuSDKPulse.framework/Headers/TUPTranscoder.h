//
//  TUPTransProducer.h
//  TuSDKPulse
//
//  Created by tutu on 2020/6/18.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TUPProducer.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUPTranscoder : TUPProducer



- (BOOL) open:(NSString*)path;


@end

NS_ASSUME_NONNULL_END
