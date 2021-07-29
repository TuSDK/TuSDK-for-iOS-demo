//
//  TUPFPTusdkBeautifyFilter.h
//  TuSDKPulseFilter
//
//  Created by tutu on 2020/12/2.
//

#import <Foundation/Foundation.h>

#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN



FOUNDATION_EXPORT NSString *const TUPFPTusdkBeautifyFilter_TYPE_NAME;


FOUNDATION_EXPORT NSString *const TUPFPTusdkBeautifyFilter_PROP_PARAM;



@interface TUPFPTusdkBeautifyFilter_PropertyBuilder : NSObject {
 
    
}

//磨皮: [0, 1]
@property(nonatomic) float smoothing;
//美白: [0, 1]
@property(nonatomic) float fair;
//红润: [0, 1]
@property(nonatomic) float ruddy;


- (instancetype) init;

- (TUPProperty*) makeProperty;

@end


@interface TUPFPTusdkBeautifyFilter : NSObject

@end

NS_ASSUME_NONNULL_END
