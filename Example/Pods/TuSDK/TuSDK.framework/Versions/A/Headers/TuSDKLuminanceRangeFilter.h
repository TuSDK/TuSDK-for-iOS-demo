#import "TuSDKFilterAdapter.h"
#import "TuSDKFilterParameter.h"


@interface TuSDKLuminanceRangeFilter : TuSDKFilter
{
    GLint rangeReductionUniform;
    GLint saturationUniform;
}

/** Saturation ranges from 0.0 (fully desaturated) to 2.0 (max saturation), with 1.0 as the normal level */
@property(readwrite, nonatomic) CGFloat saturation;
/** The degree to reduce the luminance range, from 0.0 to 1.0. Default is 0.6. */
@property(readwrite, nonatomic) CGFloat rangeReductionFactor;

@end
