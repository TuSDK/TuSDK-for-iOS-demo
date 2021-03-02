//
//  TUPFPBubbleTextFilter.h
//  TuSDKPulseFilter
//
//  Created by tusdk on 2021/2/1.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const TUPFPBubbleTextFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPBubbleTextFilter_CONFIG_MODEL;
FOUNDATION_EXPORT NSString *const TUPFPBubbleTextFilter_CONFIG_FONT_DIR;
FOUNDATION_EXPORT NSString *const TUPFPBubbleTextFilter_PROP_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPBubbleTextFilter_PROP_INTERACTION_INFO;

@interface TUPFPBubbleTextFilter_InteractionInfo : NSObject {
 
    
}

// range [0, 1]
@property(nonatomic) double rotate;     // 旋转
@property(nonatomic) double posX;       // x坐标
@property(nonatomic) double posY;       // y坐标
@property(nonatomic) int width;         // 宽度
@property(nonatomic) int height;        // 高度

@property(nonatomic) NSMutableArray<NSValue*>* rects;


- (instancetype) init:(TUPProperty*)prop;

@end

@interface TUPFPBubbleTextFilter_PropertyBuilder : NSObject {
 
    
}

// range [0, 1]
@property(nonatomic) double scale;      // 缩放
@property(nonatomic) double rotate;     // 旋转
@property(nonatomic) double posX;       // x坐标
@property(nonatomic) double posY;       // y坐标

@property(nonatomic) NSArray<NSString *>* texts;//文本


- (instancetype) init;

- (TUPProperty*) makeProperty;

@end

@interface TUPFPBubbleTextFilter : NSObject



@end

NS_ASSUME_NONNULL_END
