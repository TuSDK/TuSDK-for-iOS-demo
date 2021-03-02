//
//  TUPMediaInspector.h
//  TuSDKPulse
//
//  Created by tutu on 2020/11/27.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



@interface TUPMediaInspector_Result_Item : NSObject

@property(nonatomic) uint64_t duration;
@property(nonatomic) int bitrate;

@end


@interface TUPMediaInspector_Result_VideoItem : TUPMediaInspector_Result_Item

@property(nonatomic) int width;
@property(nonatomic) int height;
@property(nonatomic) int rotation;
@property(nonatomic) double framerate;
@property(nonatomic) BOOL directReverse;

@end


@interface TUPMediaInspector_Result_AudioItem : TUPMediaInspector_Result_Item

@property(nonatomic) int channels;
@property(nonatomic) int sampleRate;

@end

@interface TUPMediaInspector_Result : NSObject

@property(nonatomic) NSArray<TUPMediaInspector_Result_Item*>* streams;

- (instancetype) init;

@end

@interface TUPMediaInspector : NSObject




- (instancetype) init NS_UNAVAILABLE;

+ (TUPMediaInspector*) shared;



- (TUPMediaInspector_Result*) inspect:(NSString*) path;


@end

NS_ASSUME_NONNULL_END
