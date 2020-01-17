
#import "TuSDKFilterAdapter.h"

NS_ASSUME_NONNULL_BEGIN
// 动漫边缘
@interface TuSDKGPULABFilter : TuSDKFilter
@property(readwrite, nonatomic) CGFloat strength;
@property(readwrite, nonatomic) CGFloat rangeOffset;
@end

NS_ASSUME_NONNULL_END
