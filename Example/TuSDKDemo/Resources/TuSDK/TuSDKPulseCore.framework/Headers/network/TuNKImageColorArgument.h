//
//  TuNKImageColorArgument.h
//  TuSDKPulseCore
//
//  Created by 言有理 on 2021/4/19.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulseCore/TuDataJson.h>
NS_ASSUME_NONNULL_BEGIN

@interface TuNKImageColorArgument : TuDataJson
@property (nonatomic) float maxR;
@property (nonatomic) float maxG;
@property (nonatomic) float maxB;
@property (nonatomic) float maxY;
@property (nonatomic) float minR;
@property (nonatomic) float minG;
@property (nonatomic) float minB;
@property (nonatomic) float minY;
@property (nonatomic) float midR;
@property (nonatomic) float midG;
@property (nonatomic) float midB;
- (void) toArray:(float *)args;
@end

NS_ASSUME_NONNULL_END
