//
//  FaceDetectionImageSample.m
//  TuSDKDemo
//
//  Created by Clear Hu on 16/3/10.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "FaceDetectionImageSample.h"
#import "TuEditFaceDetectionImageController.h"

/**
 *  人脸检测 图片
 */
@interface FaceDetectionImageSample ()
{
    // 自定义系统相册组件
    TuSDKCPAlbumMultipleComponent *_albumComponent;
}
@end

@implementation FaceDetectionImageSample
- (instancetype)init;
{
    self = [super initWithGroupId:APISample title:NSLocalizedString(@"sample_api_face_detection_image", @"人脸检测 (图片)")];
    return self;
}


/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSampleWithController:(UIViewController *)controller;
{
    if (!controller) return;
    self.controller = controller;
    
    _albumComponent = [TuSDKGeeV1 albumMultipleCommponentWithController:controller
                                                          callbackBlock:^(TuSDKResult *result, NSError *error, UIViewController *controller)
                       {
                           // 获取图片错误
                           if (error) {
                               lsqLError(@"album reader error: %@", error.userInfo);
                               return;
                           }
                           [self openFaceDetctionWithController:controller result:result];
                       }];
    
    [_albumComponent showComponent];
}

- (void)openFaceDetctionWithController:(UIViewController *)controller
                                result:(TuSDKResult *)result;
{
    if (!controller || !result) return;
    
    
    TuEditFaceDetectionImageController *faceController = [TuEditFaceDetectionImageController controller];
    faceController.inputImage = result.image;
    faceController.inputTempFilePath = result.imagePath;
    faceController.inputAsset = result.imageAsset;
    [controller lsqPushViewController:faceController animated:YES];
}

/**
 *  获取组件返回错误信息
 *
 *  @param controller 控制器
 *  @param result     返回结果
 *  @param error      异常信息
 */
- (void)onComponent:(TuSDKCPViewController *)controller result:(TuSDKResult *)result error:(NSError *)error;
{
    lsqLDebug(@"onComponent: controller - %@, result - %@, error - %@", controller, result, error);
}
@end
