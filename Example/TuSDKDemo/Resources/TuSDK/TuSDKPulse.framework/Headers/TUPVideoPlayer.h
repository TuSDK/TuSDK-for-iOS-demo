//
//  TUPAVPlayer.h
//  TuSDKPulse
//
//  Created by tutu on 2020/6/15.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TUPPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUPVideoPlayer : TUPPlayer


- (BOOL) open:(NSString*)path;

@end

NS_ASSUME_NONNULL_END
