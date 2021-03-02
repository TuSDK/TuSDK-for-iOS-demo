

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>

#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN



FOUNDATION_EXPORT NSString *const TUPFPCanvasResizeFilter_TYPE_NAME;


FOUNDATION_EXPORT NSString *const TUPFPCanvasResizeFilter_PROP_PARAM;





typedef NS_ENUM(NSInteger, TUPFPCanvasResizeFilter_BackgroundType) {
    TUPFPCanvasResizeFilter_BackgroundType_Color,
    TUPFPCanvasResizeFilter_BackgroundType_Blur
};


@interface TUPFPCanvasResizeFilter_PropertyBuilder : NSObject {
    
}


@property(nonatomic) TUPFPCanvasResizeFilter_BackgroundType type;
@property(nonatomic) UIColor* color;
@property(nonatomic) double blurStrength;
@property(nonatomic) double panX;
@property(nonatomic) double panY;
@property(nonatomic) double zoom;
@property(nonatomic) int rotate;


- (instancetype) init;

- (TUPProperty*) makeProperty;

@end



@interface TUPFPCanvasResizeFilter : NSObject

@end

NS_ASSUME_NONNULL_END
