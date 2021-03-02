
#import <Foundation/Foundation.h>

#import <TuSDKPulse/TUPProperty.h>


NS_ASSUME_NONNULL_BEGIN


FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_TYPE_NAME;


FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_PROP_PARAM;

FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_NAME_Adjust;


/// 0:temp:[-1, 1], 1:tint:[0, 1]
FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_PROP_TYPE_WhiteBalance;

/// 0:highlight:[0, 1], 1:shadow:[0, 1]
FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_PROP_TYPE_HighlightShadow;

/// 0:[-1, 1]
FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_PROP_TYPE_Sharpen;

/// 0:[-1, 1]
FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_PROP_TYPE_Brightness;

/// 0:[0, 1]
FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_PROP_TYPE_Contrast;

/// 0:[-1, 1]
FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_PROP_TYPE_Saturation;

/// 0:[-1, 1]
FOUNDATION_EXPORT NSString *const TUPFPColorAdjustFilter_PROP_TYPE_Exposure;


@interface TUPFPColorAdjustFilter_PropertyItem : NSObject

@property(nonatomic, copy) NSString* name;
@property(nonatomic) NSArray<NSNumber*>* values;

- (instancetype) init:(NSString*) name with:(double) v;
- (instancetype) init:(NSString*) name with:(double) v0 and:(double) v1;
- (instancetype) init:(NSString*) name withArray:(NSArray<NSNumber*>*) arr;


@end


@interface TUPFPColorAdjustFilter_PropertyBuilder : NSObject {
    
}

@property(nonatomic) NSMutableArray<TUPFPColorAdjustFilter_PropertyItem*>* items;

- (instancetype) init;

- (TUPProperty*) makeProperty;

@end



@interface TUPFPColorAdjustFilter : NSObject

@end

NS_ASSUME_NONNULL_END
