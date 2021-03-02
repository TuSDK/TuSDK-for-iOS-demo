//
//  TUPStreamInfo.h
//  TuSDKPulse
//
//  Created by tutu on 2020/11/17.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPStreamInfo : NSObject

@property (nonatomic) int64_t duration;

@end



@interface TUPAudioStreamInfo : TUPStreamInfo

@property (nonatomic) NSInteger channels;
@property (nonatomic) NSInteger sampleRate;
@property (nonatomic) NSInteger sampleCount;

@end



@interface TUPVideoStreamInfo : TUPStreamInfo

@property (nonatomic) NSInteger width;
@property (nonatomic) NSInteger height;
@property (nonatomic) double frameRate;

@end



NS_ASSUME_NONNULL_END
