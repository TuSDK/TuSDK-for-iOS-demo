//
//  TUPFPTusdkFaceReshapeFilter.h
//  TuSDKPulseFilter
//
//  Created by tusdk on 2021/1/29.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN


FOUNDATION_EXPORT NSString *const TUPFPTusdkFaceReshapeFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPTusdkFaceReshapeFilter_PROP_PARAM;

@interface TUPFPTusdkFaceReshapeFilter_PropertyBuilder : NSObject<TUPPropertyProtocol>
// range [0, 1]

/// 双眼皮
@property(nonatomic) double eyelidOpacity;
/// 卧蚕
@property(nonatomic) double eyemazingOpacity;
/// 白牙
@property(nonatomic) double whitenTeethOpacity;
/// 亮眼
@property(nonatomic) double eyeDetailOpacity;
/// 祛除眼袋
@property(nonatomic) double removePouchOpacity;
/// 祛除法令纹
@property(nonatomic) double removeWrinklesOpacity;

- (instancetype) init;

@end

@interface TUPFPTusdkFaceReshapeFilter : NSObject

@end

NS_ASSUME_NONNULL_END
