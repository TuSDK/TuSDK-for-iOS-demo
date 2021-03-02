//
//  TUPUtils.h
//  TuSDKPulse
//
//  Created by tutu on 2020/6/17.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPUtils : NSObject


+ (void) raiseException:(NSObject*)obj format:(NSString*)format, ...;

+ (void) raiseException:(NSObject*)obj format:(NSString*)format arguments:(va_list)argList;



@end

NS_ASSUME_NONNULL_END
