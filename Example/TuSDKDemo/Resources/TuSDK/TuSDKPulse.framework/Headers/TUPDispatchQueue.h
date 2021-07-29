//
//  TUPDispatchQueue.h
//  TuSDKPulse
//
//  Created by abbeyant on 2021/3/15.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPDispatchQueue : NSObject


- (instancetype) init NS_UNAVAILABLE;
- (instancetype) initWithName:(NSString*) name;

- (void) runSync:(void(^)()) block;


@end

NS_ASSUME_NONNULL_END
