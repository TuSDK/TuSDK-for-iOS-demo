

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreVideo/CVPixelBuffer.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPFPImage : NSObject {
    @package
    void* _pimpl;
}



- (instancetype) initWithImpl:(void*) impl;

- (instancetype) initWithUIImage:(UIImage*) im;

//- (instancetype) initWithCMSampleBuffer:(CMSampleBufferRef) sb;

//- (instancetype) initWithCVPixelBuffer:(CVPixelBufferRef) pb ;

- (UIImage*)getUIImage;
- (UIImage*)getSVGImage;

- (NSInteger)getWidth;
- (NSInteger)getHeight;

//GLuint
- (GLuint) getTextureID;


- (CVPixelBufferRef) getCVPixelBuffer;

- (void)setMotionDegree:(int)degree;
- (int)getMotionDegree;

- (void)setMarkSenceEnable:(bool)isEnable;
- (bool)getMarkSenceEnable;
- (int)getFaceCount;

/**
 * 设置config String 键值对
 */
- (void)setConfigString:(NSString *)key value:(NSString *)value;
/**
 * 设置config number 键值对
 */
- (void)setConfigNumber:(NSString *)key number:(double)number;
/**
 * 设置config int 键值对
 */
- (void)setConfigIntNumber:(NSString *)key intNumber:(int)intNumber;


- (void)destory;
@end

NS_ASSUME_NONNULL_END
