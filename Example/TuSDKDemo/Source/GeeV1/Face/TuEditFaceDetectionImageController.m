//
//  TuEditFaceDetectionImageController.m
//  TuSDKDemo
//
//  Created by Clear Hu on 16/3/10.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuEditFaceDetectionImageController.h"

#import "TuSDKFramework.h"
#pragma mark - TuEditFaceDetectionImageView
/**
 *  图片头像检测 视图
 */
@implementation TuEditFaceDetectionImageView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self lsqInitView];
    }
    return self;
}

/**
 *  初始化视图
 */
- (void)lsqInitView;
{
    self.backgroundColor = lsqRGB(0,0,0);
    
    // 图片视图
    _imageView = [UIImageView initWithFrame:self.bounds];
    _imageView.contentMode = UIViewContentModeScaleAspectFit;
    [self addSubview:_imageView];
}
@end

#pragma mark - TuEditFaceDetectionImageController
@implementation TuEditFaceDetectionImageController
#pragma mark - init
// 隐藏状态栏 for IOS7
- (BOOL)prefersStatusBarHidden;
{
    return YES;
}

-(void)loadView
{
    [super loadView];

    [self setNavigationBarHidden:NO animated:NO];
    [self setStatusBarHidden:YES withAnimation:UIStatusBarAnimationFade];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = NSLocalizedString(@"lsq_face_detection_title", @"人脸检测");
    
    self.navigationItem.hidesBackButton = YES;
    [self lsqNavLeftButtonWithTitle:LSQString(@"lsq_nav_back", @"返回")
                       textColor:[TuSDKGeeV1Theme shared].navigationLeftTextColor
                          action:@selector(lsqBackActionHadAnimated)];
    
    // 修正视图被盖住的问题
    if ([UIDevice lsqSystemFloatVersion] >= 7.0f) {
        self.edgesForExtendedLayout = UIRectEdgeNone;
    }
}

/**
 *  创建默认样式视图 (如需创建自定义视图，请覆盖该方法，并创建自己的视图类)
 */
- (void)buildDefaultStyleView;
{
    if (_defaultStyleView) return;
    
    CGFloat top = ([[UIApplication sharedApplication]isStatusBarHidden]) ? [UIScreen topIfNavgationBarLayout] : [UIScreen topIfStatusNavgationBarLayout];
    _defaultStyleView = [TuEditFaceDetectionImageView initWithFrame:CGRectMake(0, 0, self.view.lsqGetSizeWidth, lsqScreenHeight-top)];
    [self.view addSubview:_defaultStyleView];

    // 异步加载输入图片
//    [self asyncLoadInputImageWithBlock:^id{
//        return [self inputImage];
//    }];
    [self loadedInputImage:self.inputImage];
}

/**
 *  异步加载输入图片完成
 *
 *  @param image 输入图片
 */
- (void)loadedInputImage:(UIImage *)image;
{
    if (!image) return;
    self.inputImage = image;
    if (_defaultStyleView) {
        [_defaultStyleView.imageView setImage:image];
    }
    
    [TuSDKTKThread initWithStart:^id{
        return [self testFaceDetectorWithImage: image];
    } completed:^(id result) {
        [self marksFaces:result];
    }];
}

//- (void)testimage: (UIImage *)image;
//{
//    image = [[image imageRotatedToUp] imageLimit:512];
//    
//    
//    
//    TuSDKTSPixSort *sort = [image pixSort];
//    
//    
//    
//    // 获取图片像素引用
//    CFDataRef pixelData = CGDataProviderCopyData(CGImageGetDataProvider(image.CGImage));
//    
//    lsqLDebug(@"pixelData: %d | %d |%d |%d |%d", CGImageGetAlphaInfo(image.CGImage), sort.red, sort.green, sort.blue, sort.alpha);
//    lsqLDebug(@"pixelData size: %@ | %d | %d | %d | %d | %d",
//              NSStringFromCGSize(image.size),
//              CGImageGetWidth(image.CGImage),
//              CGImageGetHeight(image.CGImage),
//              CGImageGetBitsPerPixel(image.CGImage),
//              CGImageGetBytesPerRow(image.CGImage),
//              CGImageGetBytesPerRow(image.CGImage) / CGImageGetWidth(image.CGImage));
//    
//    size_t rwidth = (CGImageGetBytesPerRow(image.CGImage)+3)/4;
//    
//    
//    
//    // 获取像素开始指针
//    const uint32_t *src = (uint32_t *)CFDataGetBytePtr(pixelData);
//    size_t length = rwidth * CGImageGetHeight(image.CGImage);
//    uint32_t* output = (uint32_t*)malloc(length);
//    
//    
//    size_t index = rwidth * 266 + 126;
//    uint8_t *dottt = (uint8_t *)&src[index];
//    lsqLDebug(@"pixelData rwidth: %d | %d | %d | %d", rwidth, CGImageGetWidth(image.CGImage) * 4, length, CFDataGetLength(pixelData));
//    lsqLDebug(@"pixelData color: %d | %d | %d", dottt[sort.red], dottt[sort.green], dottt[sort.blue]);
//    
//    for (size_t i = 0, j =  length; i < j; i++) {
//
//        if (i % rwidth > CGImageGetWidth(image.CGImage)) {
//            continue;
//        }
//        
//        uint8_t *color = (uint8_t *)&src[i];
//        uint8_t *oclor = (uint8_t *)&output[i];
//        
//        //uint8_t gray = (uint8_t)(((uint32_t)color[1] * 38 + (uint32_t)color[2] * 75 + (uint32_t)color[3] * 15) >> 7);
////        if (color[0] < 255) {
////            lsqLDebug(@"a: %d | r:%d | g: %d | b:%d", color[0], color[1], color[2], color[3]);
////        }
//        
//        if (i < rwidth * 9 || i > rwidth * ((CGImageGetHeight(image.CGImage)) - 9)){
//            oclor[sort.red] = 0;
//            oclor[sort.green] = 255;
//            oclor[sort.blue] = 0;
//            continue;
//        }
//        else if (126 == i % CGImageGetWidth(image.CGImage)) {
//            oclor[sort.red] = 255;
//            oclor[sort.green] = 0;
//            oclor[sort.blue] = 0;
//            continue;
//        }
//        uint8_t gray = (uint8_t)((color[1] * 38 + color[2] * 75 + color[3] * 15) >> 7);
//        
//        oclor[sort.red] = gray;
//        oclor[sort.green] = gray;
//        oclor[sort.blue] = gray;
//    }
//    
//    
//    CGContextRef ctx = CGBitmapContextCreate(output,
//                                             CGImageGetWidth(image.CGImage),
//                                             CGImageGetHeight(image.CGImage),
//                                             8,
//                                             CGImageGetBytesPerRow(image.CGImage),
//                                             CGImageGetColorSpace(image.CGImage),
//                                             CGImageGetBitmapInfo(image.CGImage));
//    
//    
//    
//    
//    CGImageRef imageRef = CGBitmapContextCreateImage (ctx);
//    
//    UIImage *returnImage = [UIImage imageWithCGImage:imageRef];
//    CGContextRelease(ctx);
//
//    CFRelease(pixelData);
//    
//    dispatch_async(dispatch_get_main_queue(), ^(void) {
//        [_defaultStyleView.imageView setImage:returnImage];
//    });
//}

// 测试脸部识别
- (NSArray<TuSDKFaceAligment *> *)testFaceDetectorWithImage:(UIImage *)image;
{
    NSArray<TuSDKFaceAligment *> *faces = [TuSDKFace markFaceWithImage:image];
    return faces;
}

// 为脸部标点
- (void)marksFaces:(NSArray<TuSDKFaceAligment *> *)faces;
{
    if (faces == nil) {
        lsqLDebug(@"Can not find any face");
        return;
    }

    CGRect rect = AVMakeRectWithAspectRatioInsideRect(self.inputImage.size, _defaultStyleView.imageView.frame);
    
    for (TuSDKFaceAligment *face in faces) {
        CGRect frame = CGRectMake(face.rect.origin.x * rect.size.width + rect.origin.x,
                                  face.rect.origin.y * rect.size.height + rect.origin.y,
                                  face.rect.size.width * rect.size.width,
                                  face.rect.size.height * rect.size.height);
        
        UIView *view = [UIView initWithFrame:frame];
        view.backgroundColor = lsqRGBA(128, 128, 128, 0.5);
        [_defaultStyleView addSubview:view];
        
        for (NSValue *pv in face.marks) {
            CGPoint point = pv.CGPointValue;
            
            frame = CGRectMake(point.x * rect.size.width + rect.origin.x - 1,
                               point.y * rect.size.height + rect.origin.y - 1,
                               2, 2);
            view = [UIView initWithFrame:frame];
            view.backgroundColor = lsqRGB(0, 255, 0);
            [_defaultStyleView addSubview:view];
        }
    }
}
@end
