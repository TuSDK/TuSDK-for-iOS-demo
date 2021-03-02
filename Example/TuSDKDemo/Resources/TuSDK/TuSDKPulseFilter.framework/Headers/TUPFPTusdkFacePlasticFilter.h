//
//  TUPFPTusdkFacePlasticFilter.h
//  TuSDKPulseFilter
//
//  Created by tutu on 2020/12/2.
//

#import <Foundation/Foundation.h>

#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN


// --------------------------------------------------
FOUNDATION_EXPORT NSString *const TUPFPTusdkFacePlasticFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPTusdkFacePlasticFilter_PROP_PARAM;

@interface TUPFPTusdkFacePlasticFilter_PropertyBuilder : NSObject
{
}
@property(nonatomic) double foreheadHeight; // 额头高低
@property(nonatomic) double faceSmall;  // 小脸
@property(nonatomic) double cheekThin; // 瘦脸
@property(nonatomic) double cheekNarrow; // 窄脸
@property(nonatomic) double cheekBoneNarrow; // 瘦颧骨
@property(nonatomic) double cheekLowBoneNarrow; // 下颌骨
@property(nonatomic) double browThickness; // 眉毛粗细
@property(nonatomic) double browHeight; // 眉毛高低
@property(nonatomic) double eyeEnlarge; // 眼睛大小
@property(nonatomic) double eyeAngle; // 眼角
@property(nonatomic) double eyeDistance; // 眼距
@property(nonatomic) double eyeHeight; // 眼睛高低
@property(nonatomic) double eyeInnerConer; // 内眼角
@property(nonatomic) double eyeOuterConer; // 外眼角
@property(nonatomic) double noseWidth; // 鼻子宽度
@property(nonatomic) double noseHeight; // 鼻子长度
@property(nonatomic) double philterumThickness; // 缩人中
@property(nonatomic) double mouthWidth; // 嘴巴宽度
@property(nonatomic) double lipsThickness; // 嘴唇厚度
@property(nonatomic) double chinThickness; // 下巴高低

- (instancetype) init;
- (TUPProperty*) makeProperty;
@end

@interface TUPFPTusdkFacePlasticFilter : NSObject
@end


// --------------------------------------------------
FOUNDATION_EXPORT NSString *const TUPFPTusdkFaceEditPlasticFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPTusdkFaceEditPlasticFilter_PROP_PARAM;

@interface TUPFPTusdkFaceEditPlasticFilter_PropertyBuilder : NSObject
{
}
@property(nonatomic) double cheekThin; // 瘦脸
@property(nonatomic) double eyeEnlarge; // 眼睛大小

- (instancetype) init;
- (TUPProperty*) makeProperty;
@end

@interface TUPFPTusdkFaceEditPlasticFilter : NSObject
@end




NS_ASSUME_NONNULL_END
