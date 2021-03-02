//
//  TUPBase.h
//  TuSDKPulse
//
//  Created by tutu on 2020/6/17.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


//NS_ENUM，定义状态等普通枚举
typedef NS_ENUM(NSUInteger, TUPLogLevel) {
    //TUPLogLevel_None = 0,
    TUPLogLevel_Debug = 0,
    TUPLogLevel_Info,
    TUPLogLevel_Warn,
    TUPLogLevel_Error,
    TUPLogLevel_Fatal,
    TUPLogLevel_NUM
};

@interface TUPBase : NSObject



- (void) raiseException:(NSString*) format, ...;

- (void) raiseException:(NSString*) format arguments:(va_list) argList;



- (void) log:(NSString*) format, ...;

- (void) log:(NSString*) format arguments:(va_list) argList;


- (void) log:(TUPLogLevel) level format:(NSString*) format, ...;

- (void) log:(TUPLogLevel) level format:(NSString*) format arguments:(va_list) argList;


- (void) checkImpl:(void*)impl;



@end

NS_ASSUME_NONNULL_END
