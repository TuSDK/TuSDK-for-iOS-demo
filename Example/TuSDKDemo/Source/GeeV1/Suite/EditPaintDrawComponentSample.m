//
//  EditPaintDrawComponentSample.m
//  TuSDKDemo
//
//  Created by tutu on 2019/4/23.
//  Copyright © 2019 tusdk.com. All rights reserved.
//

#import "EditPaintDrawComponentSample.h"

@interface EditPaintDrawComponentSample ()
{
    // 自定义系统相册组件
    TuSDKCPAlbumMultipleComponent *_albumComponent;
}
@end

@implementation EditPaintDrawComponentSample

- (instancetype)init;
{
    self = [super initWithGroupId:SuiteSample title:NSLocalizedString(@"sample_PaintDrawComponent", @"涂鸦组件")];
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
                                                         callbackBlock:^(TuResult *result, NSError *error, UIViewController *controller)
      {
          // 获取图片错误
          if (error) {
              lsqLError(@"album reader error: %@", error.userInfo);
              return;
          }
          [self openPaintWithController:controller result:result];
      }];
    
    [_albumComponent showComponent];
}

/**
 *  开启裁切+滤镜组件
 *
 *  @param controller 来源控制器
 *  @param result     处理结果
 */
- (void)openPaintWithController:(UIViewController *)controller
                              result:(TuResult *)result;
{
    if (!controller || !result) return;
    
    // 组件选项
    TuSDKPFEditPaintOptions *opt = [TuSDKPFEditPaintOptions build];
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuResult.asset)
     opt.saveToAlbum = YES;
    
    // 保存到系统相册的相册名称
     opt.saveToAlbumName = @"TuSdk";
    
    // 可设置最大撤销步骤，默认5
    opt.maxUndoCount = 5;
    // 是否保存上一次使用的笔刷 (默认: YES)
    opt.saveLastBrush = YES;

    // 笔刷大小等级设置（默认: 中等----细、中、粗三个等级）（1, 2, 4）
    opt.defaultBrushSize = lsqLargeBrush;
    // 笔刷大小比例设置（默认: 1.5----1-3的范围，小于1或大于3都将被限制在1或3）
    // 真正涂鸦是笔刷的大小就是 defaultBrushSize*brushScaleSize
    opt.brushScaleSize = 1.5;
    // 两点间的最小距离，绘制时距离大于此值才开始绘制，默认10
    opt.minDistance = 10;
    // 笔刷的颜色选择---- 默认 @[@"#f9f9f9", @"#2b2b2b", @"#ff1d12", @"#fbf606", @"#14e213", @"#199bff", @"#8c06ff"]
    opt.brushGroup = @[@"#f9f9f9", @"#2b2b2b", @"#ff1d12", @"#fbf606", @"#14e213", @"#199bff", @"#8c06ff"];
//    opt.brushGroup = @[@"#14e213", @"#199bff", @"#8c06ff"];

    
    // 控制器
    TuSDKPFEditPaintViewController *vc = [opt viewController];
    vc.inputImage = result.image;
    vc.inputAsset = result.imageAsset;
    vc.inputTempFilePath = result.imagePath;
    [controller.navigationController pushViewController:vc animated:YES];
}

/**
 *  图片编辑完成
 *
 *  @param controller 旋转和裁剪视图控制器
 *  @param result 旋转和裁剪视图控制器处理结果
 */
- (void)onTuSDKPFEditTurnAndCut:(TuSDKPFEditTurnAndCutViewController *)controller result:(TuResult *)result;
{
    
    // 清除所有控件
    [controller lsqDismissModalViewControllerAnimated];
    lsqLDebug(@"onTuSDKPFEditTurnAndCut: %@", result);
}

/**
 *  获取组件返回错误信息
 *
 *  @param controller 控制器
 *  @param result     返回结果
 *  @param error      异常信息
 */
- (void)onComponent:(TuComponentsViewController *)controller result:(TuResult *)result error:(NSError *)error;
{
    lsqLDebug(@"onComponent: controller - %@, result - %@, error - %@", controller, result, error);
}
@end
