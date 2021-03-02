

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPThumbnailMaker : NSObject

//@property(nonatomic) CGSize size;

- (instancetype) init NS_UNAVAILABLE;

- (instancetype) initWithPath:(NSString*) path andSize:(int) size;

- (UIImage* _Nullable) readImage:(int64_t) ts;
//

@end

NS_ASSUME_NONNULL_END
