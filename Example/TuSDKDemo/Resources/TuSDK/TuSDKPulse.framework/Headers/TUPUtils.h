//
//  TUPUtils.h
//  TuSDKPulse
//
//  Created by tutu on 2020/6/17.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface TUPUtils : NSObject


+ (void) raiseException:(id)obj format:(NSString*)format, ...;

+ (void) raiseException:(NSObject*)obj format:(NSString*)format arguments:(va_list)argList;

+ (NSUInteger)hexWithColor:(UIColor *)color;

+ (UIColor *)colorWithHex:(NSUInteger)hex;
@end

NS_ASSUME_NONNULL_END
