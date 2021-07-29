//
//  TUPPathMarshal.h
//  TuSDKPulse
//
//  Created by tutu on 2021/4/30.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPPathMarshal : NSObject






+ (NSString*) marshalPath:(NSString*) path;

+ (NSString*) unmarshalPath:(NSString*) path;




@end

NS_ASSUME_NONNULL_END
