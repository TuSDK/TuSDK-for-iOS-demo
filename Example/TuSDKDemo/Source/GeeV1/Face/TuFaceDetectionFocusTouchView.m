//
//  TuFaceDetectionFocusTouchView.m
//  TuSDKDemo
//
//  Created by Clear Hu on 16/3/11.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuFaceDetectionFocusTouchView.h"
#import "TuSDKFramework.h"

/**
 *  视频触摸视图
 */
@interface TuFaceDetectionFocusTouchView()<TuSDKVideoCameraSampleBufferDelegate>{
    NSMutableArray<UIView *> *_markViews;
    
    // 上次检测时间
    NSDate *_lastDetectionTime;
    
    UILabel *_faceInfoLabel;
}
@end

@implementation TuFaceDetectionFocusTouchView

-(void)lsqInitView;
{
    [super lsqInitView];
    _markViews = [NSMutableArray array];
    
    _faceInfoLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 60, 160, 120)];
    _faceInfoLabel.textAlignment = NSTextAlignmentLeft;
    _faceInfoLabel.textColor = [UIColor whiteColor];
    [self addSubview:_faceInfoLabel];
}

- (void)setCamera:(id<TuSDKVideoCameraInterface>)camera;
{
    [super setCamera:camera];
    if (camera) {
        camera.sampleBufferDelegate = self;
    }
}

/** hidden Face Views */
- (void)hiddenFaceViews;
{
    [super hiddenFaceViews];
    for (UIView *view in _markViews)
    {
        view.hidden = YES;
    }
}

- (UIView *)buildFaceDetectionView;
{
    UIView * view = [UIView initWithFrame:CGRectMake(0, 0, 0, 0)];
    
    [view setBackgroundColor:[UIColor clearColor]];
    [view lsqSetBorderWidth:1 color:lsqRGB(255, 192, 0)];
    [view lsqSetCornerRadius:10];
    
    return view;
}
#pragma mark - TuSDKVideoCameraSampleBufferDelegate
/**
 *  原始帧采样缓冲数据
 *
 *  @param sampleBuffer 帧采样缓冲
 *  @param rotation     原始图像方向
 *  @param previewSize  预览尺寸
 *  @param angle        设备角度
 */
- (void)onProcessVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer rotation:(UIImageOrientation)rotation previewSize:(CGSize)previewSize angle:(float)angle;
{
    // 避免过多的检测消耗资源
    if (_lastDetectionTime && fabs([_lastDetectionTime timeIntervalSinceNow]) < 0.025f)
    {
        return;
    }
    
    _lastDetectionTime = [NSDate date];
    
    CVPixelBufferRef pixelBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    CVPixelBufferLockBaseAddress(pixelBuffer, 0);
    
    int width = (int)CVPixelBufferGetWidth(pixelBuffer);
    int height =  (int)CVPixelBufferGetHeight(pixelBuffer);
    
    uint8_t *yBuffer = (uint8_t *)CVPixelBufferGetBaseAddressOfPlane(pixelBuffer, 0);
    int stride = (int)CVPixelBufferGetBytesPerRowOfPlane(pixelBuffer, 0);
    
    BOOL doFlip = NO;
    
    if ([self.camera cameraPosition] == AVCaptureDevicePositionFront)
    {
        doFlip = self.camera.horizontallyMirrorFrontFacingCamera;
    }
    else
    {
        doFlip = self.camera.horizontallyMirrorRearFacingCamera;
    }
    
    angle += M_PI_2;
    
    NSArray<TuSDKFaceAligment *> *faceAligment = [TuSDKFace markFaceWithGrayBuffer:yBuffer width:width height:height stride:stride ori:M_PI * -90/180 radian:-angle flip:doFlip];
    
    CVPixelBufferUnlockBaseAddress(pixelBuffer, 0);
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self onFaceAligmented:faceAligment size:previewSize];
    });
}

#pragma mark - onFaceAligmented
/*对人脸标点完成*/
- (void) onFaceAligmented:(NSArray<TuSDKFaceAligment *> *)aligments
                     size:(CGSize)size;
{
    if (aligments == nil || aligments.count == 0 || CGSizeEqualToSize(size, CGSizeZero))
    {
        [self hiddenFaceViews];
        return;
    }
    
    lsqLDebug(@"onFaceAligmented: %d", aligments.count);
    
    if (self.disableContinueFoucs)
    {
        return;
    }
    
    NSMutableArray<TuSDKTSFaceFeature *> *faces = [NSMutableArray array];
    TuSDKTSFaceFeature *faceFeature = [[TuSDKTSFaceFeature alloc] init];
    faceFeature.bounds = aligments[0].rect;
    faceFeature.frameRatio = size.width/size.height;
    [faces addObject:faceFeature];

    [self notifyFaceDetection:faces];
}

- (void)buildMarkViews:(NSUInteger)index point:(CGPoint)point imageRect:(CGRect)imageRect offset:(CGPoint)offset;
{
    UIView *mark = nil;
    if (_markViews.count > index) {
        mark = _markViews[index];
        mark.hidden = NO;
    }else{
        mark = [UIView initWithFrame:CGRectMake(0, 0, 4, 4)];
        mark.backgroundColor = lsqRGB(0, 255, 0);
        [_markViews addObject:mark];
        [self addSubview:mark];
    }
    
    CGPoint origin = CGPointMake(0, 0);
    origin.x = ((point.x + offset.x) * imageRect.size.width - imageRect.origin.x) - 2;
    origin.y = ((point.y + offset.y) * imageRect.size.height - imageRect.origin.y) - 2;
    [mark lsqSetOrigin:origin];
}

- (void)updateFaceAngleInfo:(TuSDKFaceAligment *)face;
{
    _faceInfoLabel.numberOfLines = 0;
    
    NSString *info = [NSString stringWithFormat:@"Roll  %f\nYaw   %f\nPitch %f", face.roll,
                      face.yaw,
                      face.pitch];
    
    _faceInfoLabel.text = info;
}
@end
