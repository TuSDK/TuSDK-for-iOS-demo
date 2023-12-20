//
//  TUPFPSVGImage.h
//  TuSDKPulseFilter
//
//  Created by 言有理 on 2022/1/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TUPFPImage.h"
NS_ASSUME_NONNULL_BEGIN

@interface TUPFPSVGImage : NSObject
/// svg 地址
- (instancetype)initWithPath:(NSString *)path width:(int)width height:(int)height;

/// 更新
/// @param cid 矢量图内部id
/// @param r 红(0~255)
/// @param g 绿(0~255)
/// @param b 蓝(0~255)
/// @param a 透明度(0~1)
- (BOOL)updateFillColor:(NSString *)cid r:(int)r g:(int)g b:(int)b a:(float)a;
- (BOOL)updateStokeColor:(NSString *)cid r:(int)r g:(int)g b:(int)b a:(float)a;
- (BOOL)updateStrokeWidth:(NSString *)cid px:(int)px;
- (BOOL)updateSize:(NSString *)cid width:(double)width height:(double)height;
- (BOOL)updateRootNodeSizeWithWidth:(double)width height:(double)height;


- (TUPFPImage *)getImage;

- (void)close;
@end

NS_ASSUME_NONNULL_END
