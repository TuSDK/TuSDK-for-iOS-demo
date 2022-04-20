

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




- (void)destory;
@end

NS_ASSUME_NONNULL_END
