//
//  TUPPermission.h
//  TuSDKPulse
//
//  Created by Zoeric on 2021/01/26.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN



@interface TUPPermission : NSObject



+ (instancetype) shared;



- (instancetype) init NS_UNAVAILABLE;

- (uint64_t) get:(NSString*) key;

- (BOOL) check:(NSString*) key;


@end

NS_ASSUME_NONNULL_END
