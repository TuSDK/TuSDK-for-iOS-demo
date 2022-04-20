
#import <CoreMedia/CMSampleBuffer.h>
#import <CoreVideo/CVPixelBuffer.h>

#import "TUPFPImage.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUPFPImage_CMSampleBufferCvt : NSObject

@property (nonatomic) CGSize outputSize;

- (instancetype) init;

- (instancetype) initWithPixelFormatType_32BGRA;

- (instancetype)initWithPixelFormatTexture2D;

- (TUPFPImage* _Nullable) convert:(CMSampleBufferRef) sb;

- (TUPFPImage* _Nullable) convertImage:(TUPFPImage *)inputImage;


- (TUPFPImage* _Nullable) convert:(CMSampleBufferRef) sb orientaion:(int)orientaion flip:(BOOL)flip mirror:(BOOL)mirror;

- (TUPFPImage* _Nullable) convert:(CVPixelBufferRef)pb
                    withTimestamp:(int64_t)ts
                       orientaion:(int)orientaion
                             flip:(BOOL)flip
                           mirror:(BOOL)mirror;

- (TUPFPImage* _Nullable) convert:(CVPixelBufferRef) pb withTimestamp:(int64_t) ts;

/**
 * 纹理ID转换
 * @param textureId 纹理ID
 * @param ts 时间
 * @param width 纹理宽度
 * @param height 纹理高度
 * @return TUPFPImage 对象
 */
- (TUPFPImage * _Nullable)convert:(GLuint)textureId timestamp:(int64_t)ts width:(int)width height:(int)height;

@end


//
//@interface TUPFPImage_BufferCvt : NSObject
//
//- (instancetype) init;
//
//- (TUPFPImage* _Nullable) convert:() sb;
//
//- (TUPFPImage* _Nullable) convert:(CVPixelBufferRef) pb withTimestamp:(int64_t) ts;
//
//@end





NS_ASSUME_NONNULL_END
