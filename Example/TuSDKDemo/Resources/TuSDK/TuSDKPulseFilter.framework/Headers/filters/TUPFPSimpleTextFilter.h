//
//  TUPFPSimpleTextFilter.h
//  TuSDKPulseFilter
//
//  Created by tusdk on 2021/1/29.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const TUPFPSimpleTextFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPSimpleTextFilter_PROP_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPSimpleTextFilter_PROP_INTERACTION_INFO; // 获取文字对应显示位置

/**
 * 文字显示位置信息
 */
@interface TUPFPSimpleTextFilter_InteractionInfo : NSObject {
}


@property(nonatomic) double rotation;   // 旋转
@property(nonatomic) double posX;       // x坐标
@property(nonatomic) double posY;       // y坐标
@property(nonatomic) int width;         // 宽度
@property(nonatomic) int height;        // 高度

- (instancetype) init:(TUPProperty*)prop;


@end

/**
 * 文字对齐位置
 */
typedef NS_ENUM(NSUInteger, SimpleTextAlignment) {
    SimpleTextAlignment_LEFT = 0,
    SimpleTextAlignment_CENTER = 1,
    SimpleTextAlignment_RIGHT = 2,
};


typedef NS_ENUM(NSUInteger, SimpleTextStyle) {
    SimpleTextStyle_NORMAL = 0,
    SimpleTextStyle_UNDERLINE = 1,
};


@interface TUPFPSimpleTextFilter_PropertyBuilder : NSObject {
 
    
}


// range [0, 1]
@property(nonatomic) NSString* font;
@property(nonatomic) NSString* text;
@property(nonatomic) double posX;
@property(nonatomic) double posY;
@property(nonatomic) double fontScale;
@property(nonatomic) double rotate;
@property(nonatomic) double textScaleX;
@property(nonatomic) double textScaleY;
@property(nonatomic) double strokeWidth;
@property(nonatomic) int strokeColor;
@property(nonatomic) int fillColor;
@property(nonatomic) int bgColor;
@property(nonatomic) SimpleTextAlignment alignment;
@property(nonatomic) SimpleTextStyle style;


- (instancetype) init;

- (TUPProperty*) makeProperty;

@end

@interface TUPFPSimpleTextFilter : NSObject

@end

NS_ASSUME_NONNULL_END
