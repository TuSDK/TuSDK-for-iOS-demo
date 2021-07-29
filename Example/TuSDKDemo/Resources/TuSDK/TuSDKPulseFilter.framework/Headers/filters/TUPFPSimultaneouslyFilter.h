//
//  TUPFPSimultaneouslyFilter.h
//  TuSDKPulseFilter
//
//  Created by 言有理 on 2021/6/15.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPProperty.h>
#import <CoreGraphics/CoreGraphics.h>
NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_PROP_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_PROP_RECT_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_PROP_SEEK_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_INDEX_CAMERA;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_INDEX_FILE;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_PATH;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_WIDTH;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_HEIGHT;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_FIRST_LAYER;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_STRETCH;

@interface TUPFPSimultaneouslyFilter_PropertyBuilder : NSObject
@property (nonatomic, assign) BOOL enable_play;
@property (nonatomic, assign) CGRect cameraDstRect; // normalization
@property (nonatomic, assign) CGRect cameraSrcRect; // normalization
@property (nonatomic, assign) CGRect videoDstRect; // normalization
@property (nonatomic, assign) CGRect videoSrcRect; // normalization
@property (nonatomic, copy) NSString *firstLayer;
@property (nonatomic, assign) NSInteger currentPos;

- (instancetype) init;

- (TUPProperty*) makeProperty;
- (TUPProperty*) makeSeekProperty;
- (TUPProperty*) makeRectProperty;

@end
@interface TUPFPSimultaneouslyFilter : NSObject

@end

NS_ASSUME_NONNULL_END
