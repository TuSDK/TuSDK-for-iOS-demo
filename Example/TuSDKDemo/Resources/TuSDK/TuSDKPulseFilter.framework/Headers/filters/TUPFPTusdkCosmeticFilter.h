//
//  TUPFPTusdkCosmeticFilter.h
//  TuSDKPulseFilter
//
//  Created by tusdk on 2021/1/29.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN


FOUNDATION_EXPORT NSString *const TUPFPTusdkCosmeticFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPTusdkCosmeticFilter_PROP_PARAM;

@interface TUPFPTusdkCosmeticFilter_PropertyBuilder : NSObject {
 
    
}

// range [0, 1]
@property(nonatomic) double facialEnable;       // 修容开关
@property(nonatomic) double lipEnable;          // 口红开关
@property(nonatomic) double blushEnable;        // 腮红开关
@property(nonatomic) double browEnable;         // 眉毛开关
@property(nonatomic) double eyeshadowEnable;    // 眼影开关
@property(nonatomic) double eyelineEnable;      // 眼线开关
@property(nonatomic) double eyelashEnable;      // 睫毛开关

@property(nonatomic) double facialOpacity;      // 修容不透明度
@property(nonatomic) double lipOpacity;         // 口红不透明度
@property(nonatomic) double blushOpacity;       // 腮红不透明度
@property(nonatomic) double browOpacity;        // 眉毛不透明度
@property(nonatomic) double eyeshadowOpacity;   // 眼影不透明度
@property(nonatomic) double eyelineOpacity;     // 眼线不透明度
@property(nonatomic) double eyelashOpacity;     // 睫毛不透明度

@property(nonatomic) double lipStyle;           // 口红类型
@property(nonatomic) double lipColor;           // 口红颜色
@property(nonatomic) double facialId;           // 修容贴纸id
@property(nonatomic) double blushId;            // 腮红贴纸id
@property(nonatomic) double browId;             // 眉毛贴纸id
@property(nonatomic) double eyeshadowId;        // 眼影贴纸id
@property(nonatomic) double eyelineId;          // 眼线贴纸id
@property(nonatomic) double eyelashId;          // 睫毛贴纸id

- (instancetype) init;

- (TUPProperty*) makeProperty;

@end

@interface TUPFPTusdkCosmeticFilter : NSObject

@end

NS_ASSUME_NONNULL_END
