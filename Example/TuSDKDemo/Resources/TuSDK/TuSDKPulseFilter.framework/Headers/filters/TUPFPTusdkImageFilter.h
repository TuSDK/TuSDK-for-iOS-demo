

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>
#import <CoreGraphics/CGGeometry.h>

#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN



FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_TYPE_NAME;

FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_CONFIG_NAME;


FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_PROP_PARAM;



// --------------------------------------------------
@interface TUPFPTusdkImageFilter_PropertyBuilder : NSObject

@property(nonatomic) NSMutableDictionary<NSString*, NSNumber*> *propertyDic;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithProperty:(TUPProperty *)property;
- (TUPProperty*)makeProperty;
@end


@interface TUPFPTusdkImageFilter_Type10PropertyBuilder : NSObject
{
}
@property(nonatomic) float strength; //强度: [0, 1]

- (instancetype)init;
- (TUPProperty*)makeProperty;
@end


@interface TUPFPTusdkImageFilter_Type20PropertyBuilder : NSObject
{
}
@property(nonatomic) float vignette;
@property(nonatomic) float mixied;

- (instancetype)init;
- (TUPProperty*)makeProperty;
@end


// 魔法色
@interface TUPFPTusdkImageFilter_Type62PropertyBuilder : NSObject
{

}
@property(nonatomic) float hue;
@property(nonatomic) float hue_space;

- (instancetype)init;
- (TUPProperty*)makeProperty;
@end






// 圣光 --------------------------------------------------
FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_HolyLight;
@interface TUPFPTusdkImageFilter_HolyLightPropertyBuilder : NSObject
{
}
@property(nonatomic) float strength; //强度: [0, 1]
@property(nonatomic) float brightness; //亮度: [0, 1]

- (instancetype)init;
- (TUPProperty*)makeProperty;
@end


// 斑驳 --------------------------------------------------
@interface TUPFPTusdkImageFilter_MottledPropertyBuilder : NSObject
{
}
@property(nonatomic) float mixed;
@property(nonatomic) float vignette;
@property(nonatomic) float texture;

- (instancetype)init;
- (TUPProperty*)makeProperty;
@end

// 边缘特效 --------------------------------------------------
@interface TUPFPTusdkImageFilter_SobelEdgePropertyBuilder : NSObject
{
}
@property(nonatomic) float edgeStrength;
@property(nonatomic) float thresholdLevel;
@property(nonatomic) float showType;

- (instancetype)init;
- (TUPProperty*)makeProperty;
@end

// 光效 --------------------------------------------------
@interface TUPFPTusdkImageFilter_LightGlarePropertyBuilder : NSObject
{
}
@property(nonatomic) float mixed;

- (instancetype)init;
- (TUPProperty*)makeProperty;
@end



FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_Vignette;

/// 暗角
@interface TUPFPTusdkImageFilter_VignettePropertyBuilder : NSObject
{
}
//开始位置: [0, 1]
@property(nonatomic) float start;
//结束位置: [0, 1]
@property(nonatomic) float end;
//中心位置: [0, 1]
@property(nonatomic) CGPoint center;
//颜色: [0, 1]
@property(nonatomic) UIColor* color;

- (instancetype) init;

- (TUPProperty*) makeProperty;

@end


FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_Aperture;

/// 光圈
@interface TUPFPTusdkImageFilter_AperturePropertyBuilder : NSObject
{
}
@property(nonatomic) float radius; //The radius of the distortion: [0, 1], default: 0.4
@property(nonatomic) float excessive; //The size of the area between the blurred portion and the clear circle: [0, 1], default: 0.12
@property(nonatomic) float degree; //旋转角度: [0, 360], default: 0
@property(nonatomic) float selective; //选区模式 (默认：0, 圆形 0.1, 矩形 0.2)
@property(nonatomic) CGPoint center; //中心: [0, 1], default:[0.5, 0.5]
@property(nonatomic) UIColor* color; //颜色:RGBA, default: 0xffffffff
@property(nonatomic) float blurSize; //模糊范围 (从0.0开始，数值越大越模糊), default:1.0

- (instancetype) init;
- (TUPProperty*) makeProperty;
@end


FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_Sharpen;

// 锐化 --------------------------------------------------
@interface TUPFPTusdkImageFilter_SharpenPropertyBuilder : NSObject
{
}
//强度: [-1, 1], default:0
@property(nonatomic) float sharpness;

- (instancetype) init;
- (TUPProperty*) makeProperty;
@end


FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_GaussianBlur;

/// 高斯模糊
@interface TUPFPTusdkImageFilter_GaussianBlurPropertyBuilder : NSObject
{
}
//强度: [0, 1], default:0
@property(nonatomic) float strength;
- (instancetype) init;
- (TUPProperty*) makeProperty;
@end


FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_HDR;

/// HDR
@interface TUPFPTusdkImageFilter_HDRPropertyBuilder : NSObject
{
}
//强度: [0, 1], default:0.5
@property(nonatomic) float strength;
- (instancetype) init;
- (TUPProperty*) makeProperty;
@end


FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_SkinHazy;

// SkinHazy
@interface TUPFPTusdkImageFilter_SkinHazyPropertyBuilder : NSObject
{
}
@property(nonatomic) float smoothing;
@property(nonatomic) float fair;
@property(nonatomic) float ruddy;

- (instancetype) init;
- (TUPProperty*) makeProperty;
@end


FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_SkinNatural;

// SkinNatural
@interface TUPFPTusdkImageFilter_SkinNaturalPropertyBuilder : NSObject
{
}
@property(nonatomic) float smoothing;
@property(nonatomic) float fair;
@property(nonatomic) float ruddy;

- (instancetype) init;
- (TUPProperty*) makeProperty;
@end


FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_SkinHazyColor;

// SkinHazyColor
@interface TUPFPTusdkImageFilter_SkinHazyColorPropertyBuilder : NSObject
{
}

@property(nonatomic) float smoothing;
@property(nonatomic) float fair;
@property(nonatomic) float mixed;

- (instancetype) init;
- (TUPProperty*) makeProperty;
@end


FOUNDATION_EXPORT NSString *const TUPFPTusdkImageFilter_NAME_SkinNaturalColor;

// SkinNaturalColor
@interface TUPFPTusdkImageFilter_SkinNaturalColorPropertyBuilder : NSObject
{
}
@property(nonatomic) float smoothing;
@property(nonatomic) float fair;
@property(nonatomic) float mixed;

- (instancetype) init;
- (TUPProperty*) makeProperty;
@end

@interface TUPFPTusdkImageFilter : NSObject

@end

NS_ASSUME_NONNULL_END
