
#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "TuSDKPulse/TUPBase.h"
#import "TuSDKPulseFilter/TUPFPImage.h"



NS_ASSUME_NONNULL_BEGIN





@interface TUPFPFileExporter_Config : NSObject


/// encoder configuration
@property(nonatomic) int width;
@property(nonatomic) int height;
@property(nonatomic) double stretch; // 快慢速
@property(nonatomic) int framerate; // 采集帧率

@property(nonatomic) int channels;
@property(nonatomic) int sampleRate;
@property(nonatomic) int pitchType; // 变声

/// watermark image & position
@property(nonatomic) UIImage* watermark;
@property(nonatomic) int watermarkPosition; // default = -1(tr),  0 : tl, 1 : tr, 2 : bl, 3 : br


@property(nonatomic, copy) NSString* savePath;

@end




@interface TUPFPFileExporter : TUPBase 


- (BOOL) open:(TUPFPFileExporter_Config*) config;

- (void) close;

- (BOOL) sendVideo:(TUPFPImage*) image withTimestamp:(int64_t) ts;

- (BOOL) sendAudio:(void*) pcm andSize:(size_t) size withTimestamp:(int64_t) ts;




+ (BOOL) mergeVideoFiles:(NSArray<NSString*>*) paths to:(NSString*) output;



@end

NS_ASSUME_NONNULL_END
