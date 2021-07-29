//
//  TUPFPJigsawFilter.h
//  TuSDKPulseFilter
//
//  Created by 言有理 on 2021/7/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_MODEL_TYPE;
FOUNDATION_EXPORT int const TUPFPJigsawFilter_MODEL_TYPE_FILE;
FOUNDATION_EXPORT int const TUPFPJigsawFilter_MODEL_TYPE_JSON;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_WIDTH;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_HEIGHT;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_MODEL_PATH;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_MODEL_JSON;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_PROP_INTERACTION_INFO;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_PROP_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_PROP_PARAM_COLOR;
@interface TUPFPJigsawFilter_InteractionInfo_LayerInfo : NSObject
@property (nonatomic, assign) int index;
@property (nonatomic, assign) int layerType;
@property (nonatomic, assign) int rotation;
@property (nonatomic, assign) CGRect dsc_rect; // 左上右下
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *text;

@end

@interface TUPFPJigsawFilter_InteractionInfo : NSObject
@property (nonatomic, strong) NSMutableArray<TUPFPJigsawFilter_InteractionInfo_LayerInfo *> *layerInfos;
@property (nonatomic, assign) int modelWidth;
@property (nonatomic, assign) int modelHeight;
@property (nonatomic, assign) int pitsCount;
- (instancetype)init:(TUPProperty*)prop;
@end

@interface TUPFPJigsawFilter_ImageLayerInfo : NSObject
@property (nonatomic, assign) int index;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, assign) double scale;
@property (nonatomic, assign) int rotation;
@property (nonatomic, assign) BOOL isHorizontalFlip;
@property (nonatomic, assign) BOOL isVerticallyFlip;
@property (nonatomic, assign) UIEdgeInsets padding;
@property (nonatomic, assign) CGRect dsc_rect;// 左上右下
@property (nonatomic, assign) CGPoint offset;
@end

@interface TUPFPJigsawFilter_PropertyHolder : NSObject
@property (nonatomic, strong) NSMutableArray<TUPFPJigsawFilter_ImageLayerInfo *> *layerInfos;
@property (nonatomic, strong) UIColor *backgroundColor;
@end

@interface TUPFPJigsawFilter_PropertyBuilder : NSObject
@property (nonatomic, strong) TUPFPJigsawFilter_PropertyHolder *holder;
- (instancetype)initWithHolder:(TUPFPJigsawFilter_PropertyHolder *)holder;
- (TUPProperty*) makeProperty;
- (TUPProperty*) makeBackgroundColorProperty;
@end

@interface TUPFPJigsawFilter : NSObject

@end

NS_ASSUME_NONNULL_END
