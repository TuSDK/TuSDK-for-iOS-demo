

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>
#import <CoreGraphics/CGGeometry.h>

#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN



FOUNDATION_EXPORT NSString *const TUPFPTusdkStickerFilter_TYPE_NAME;

FOUNDATION_EXPORT NSString *const TUPFPTusdkStickerFilter_CONFIG_NAME;


FOUNDATION_EXPORT NSString *const TUPFPTusdkStickerFilter_PROP_PARAM;



@interface TUPFPTusdkStickerFilter_InteractionInfo : NSObject {
    
}

@property(nonatomic) double posX;
@property(nonatomic) double posY;
@property(nonatomic) int width;
@property(nonatomic) int height;
@property(nonatomic) double rotation;

- (instancetype) init;

- (instancetype) init:(TUPProperty*) prop;


@end



@interface TUPFPTusdkStickerFilter_PropertyBuilder : NSObject {
    
}


@property(nonatomic) double panX;
@property(nonatomic) double panY;
@property(nonatomic) double zoom;
@property(nonatomic) double rotate;


- (instancetype) init;

- (TUPProperty*) makeProperty;

@end




@interface TUPFPTusdkStickerFilter : NSObject

@end

NS_ASSUME_NONNULL_END
