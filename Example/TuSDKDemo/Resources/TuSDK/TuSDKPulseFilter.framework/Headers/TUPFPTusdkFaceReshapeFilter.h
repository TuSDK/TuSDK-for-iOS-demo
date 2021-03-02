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

@interface TUPFPTusdkFaceReshapeFilter_PropertyBuilder : NSObject {
 
    
}

// range [0, 1]
@property(nonatomic) double eyeDetailOpacity;       // 亮眼
@property(nonatomic) double removePouchOpacity;     // 祛除眼袋
@property(nonatomic) double removeWrinklesOpacity;  // 祛除法令纹
@property(nonatomic) double whitenTeethOpacity;     // 白牙
@property(nonatomic) double eyelidOpacity;          // 双眼皮
@property(nonatomic) double eyemazingOpacity;       // 卧蚕


- (instancetype) init;

- (TUPProperty*) makeProperty;

@end

@interface TUPFPTusdkFaceReshapeFilter : NSObject

@end

NS_ASSUME_NONNULL_END
