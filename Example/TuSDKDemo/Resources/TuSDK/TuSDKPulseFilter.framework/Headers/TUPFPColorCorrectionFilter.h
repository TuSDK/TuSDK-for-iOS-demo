
#import <Foundation/Foundation.h>

#import <TuSDKPulse/TUPProperty.h>


NS_ASSUME_NONNULL_BEGIN


FOUNDATION_EXPORT NSString *const TUPFPColorCorrectionFilter_TYPE_NAME;


FOUNDATION_EXPORT NSString *const TUPFPColorCorrectionFilter_PROP_PARAM;




@interface TUPFPColorCorrectionFilter_PropertyBuilder : NSObject
{
    
}

@property(nonatomic) NSMutableArray<NSNumber *> *args;


- (instancetype) init;
- (TUPProperty*) makeProperty;

@end



@interface TUPFPColorCorrectionFilter : NSObject

@end

NS_ASSUME_NONNULL_END
