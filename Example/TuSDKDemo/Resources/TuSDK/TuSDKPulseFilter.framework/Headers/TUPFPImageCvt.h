
#import <CoreMedia/CMSampleBuffer.h>
#import <CoreVideo/CVPixelBuffer.h>

#import "TUPFPImage.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUPFPImage_CMSampleBufferCvt : NSObject

@property (nonatomic) CGSize outputSize;

- (instancetype) init;

- (TUPFPImage* _Nullable) convert:(CMSampleBufferRef) sb;

- (TUPFPImage* _Nullable) convert:(CMSampleBufferRef) sb orientaion:(int)orientaion flip:(BOOL)flip mirror:(BOOL)mirror;

- (TUPFPImage* _Nullable) convert:(CVPixelBufferRef) pb withTimestamp:(int64_t) ts;

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
