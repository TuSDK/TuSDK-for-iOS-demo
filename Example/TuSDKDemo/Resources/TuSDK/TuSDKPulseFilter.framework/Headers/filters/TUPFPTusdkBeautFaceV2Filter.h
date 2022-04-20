//
//  TUPFPTusdkBeautFaceV2Filter.h
//  TuSDKPulseFilter
//
//  Created by tusdk on 2021/1/29.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN


FOUNDATION_EXPORT NSString *const TUPFPTusdkBeautFaceV2Filter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPTusdkBeautFaceV2Filter_PROP_PARAM;

@interface TUPFPTusdkBeautFaceV2Filter_PropertyBuilder : NSObject<TUPPropertyProtocol>

// range [0, 1]
@property(nonatomic) double smoothing;  // 磨皮
@property(nonatomic) double whiten;     // 美白
@property(nonatomic) double sharpen;    // 锐化


- (instancetype) init;


@end

@interface TUPFPTusdkBeautFaceV2Filter : NSObject



@end

NS_ASSUME_NONNULL_END
