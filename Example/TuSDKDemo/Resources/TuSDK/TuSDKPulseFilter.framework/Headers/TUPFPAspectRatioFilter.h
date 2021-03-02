

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>

#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN



FOUNDATION_EXPORT NSString *const TUPFPAspectRatioFilter_TYPE_NAME;


FOUNDATION_EXPORT NSString *const TUPFPAspectRatioFilter_PROP_PARAM;





@interface TUPFPAspectRatioFilter_PropertyBuilder : NSObject {
    
}


@property(nonatomic) int widthRatio;
@property(nonatomic) int heightRatio;


- (instancetype) init;

- (TUPProperty*) makeProperty;

@end



@interface TUPFPAspectRatioFilter : NSObject

@end

NS_ASSUME_NONNULL_END
