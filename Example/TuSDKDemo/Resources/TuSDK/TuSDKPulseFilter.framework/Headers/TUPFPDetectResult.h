

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreVideo/CVPixelBuffer.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPFPDetectResult : NSObject {
    @package
    void* _pimpl;
}

- (instancetype) initWithImpl:(void*) impl;

@end


@interface TUPFPFaceDetectResult : TUPFPDetectResult {

}

@property (nonatomic, readonly) NSInteger faceCount;

- (instancetype) initWithImpl:(void*) impl;
@end



NS_ASSUME_NONNULL_END
