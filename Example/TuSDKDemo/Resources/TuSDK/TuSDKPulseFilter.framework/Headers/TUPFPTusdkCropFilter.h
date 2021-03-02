//
//  TUPFPTusdkFacePlasticFilter.h
//  TuSDKPulseFilter
//
//  Created by tutu on 2020/12/2.
//

#import <Foundation/Foundation.h>

#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN


FOUNDATION_EXPORT NSString *const TUPFPTusdkCrop_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPTusdkCrop_PROP_PARAM;

// range [0, 1]

FOUNDATION_EXPORT NSString *const TUPFPTusdkCrop_CONFIG_LEFT; // 左
FOUNDATION_EXPORT NSString *const TUPFPTusdkCrop_CONFIG_TOP;  // 上
FOUNDATION_EXPORT NSString *const TUPFPTusdkCrop_CONFIG_RIGHT;// 右
FOUNDATION_EXPORT NSString *const TUPFPTusdkCrop_CONFIG_BOTTOM;// 下


@interface TUPFPTusdkCropFilter_PropertyBuilder : NSObject {
 
    
}




- (instancetype) init;

- (TUPProperty*) makeProperty;

@end


@interface TUPFPTusdkCropFilter : NSObject

@end

NS_ASSUME_NONNULL_END
