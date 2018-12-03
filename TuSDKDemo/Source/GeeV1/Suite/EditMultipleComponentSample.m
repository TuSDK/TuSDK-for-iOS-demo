//
//  EditMultipleComponentSample.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//


#import "EditMultipleComponentSample.h"

/**
 *  照片美化组件范例
 */
@interface EditMultipleComponentSample ()
{
    // 相册组件
    TuSDKCPAlbumComponent *_albumComponent;
    // 照片美化编辑组件
    TuSDKCPPhotoEditMultipleComponent *_photoEditMultipleComponent;
}
@end

@implementation EditMultipleComponentSample
- (instancetype)init;
{
    self = [super initWithGroupId:SuiteSample title:NSLocalizedString(@"sample_EditMultipleComponent", @"照片美化")];
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
    
    lsqLDebug(@"editAdvancedComponentHandler");
    
    _albumComponent =
    [TuSDKGeeV1 albumCommponentWithController:controller
                           callbackBlock:^(TuSDKResult *result, NSError *error, UIViewController *controller)
     {
         // 获取图片错误
         if (error) {
             lsqLError(@"album reader error: %@", error.userInfo);
             return;
         }
         [self openEditMultipleWithController:controller result:result];
     }];
    
    [_albumComponent showComponent];
}

/**
 *  开启照片美化组件
 *
 *  @param controller 来源控制器
 *  @param result     处理结果
 */
- (void)openEditMultipleWithController:(UIViewController *)controller
                                result:(TuSDKResult *)result;
{
    // 组件使用文档教程
    // @see-https://tutucloud.com/docs/ios/editor-usage
    
    if (!controller || !result) return;
    
    // 组件选项配置
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKCPPhotoEditMultipleComponent.html
    _photoEditMultipleComponent =
    [TuSDKGeeV1 photoEditMultipleWithController:controller
                               callbackBlock:^(TuSDKResult *result, NSError *error, UIViewController *controller)
     {
         _albumComponent = nil;
         
         // 如果以 pushViewController 方式打开编辑器, autoDismissWhenCompelted参数将无效, 请使用以下方法关闭
         //if (_photoEditMultipleComponent.autoDismissWhenCompelted && controller) {
         //    [controller popViewControllerAnimated:YES];
         //}
         
         // 获取图片失败
         if (error) {
             lsqLError(@"editMultiple error: %@", error.userInfo);
             return;
         }
         [result logInfo];
         
         //
         // 可在此添加自定义方法，在编辑完成时进行页面跳转操，例如 ：
         // [controller presentViewController:[[UIViewController alloc] init] animated:YES completion:nil];
         
         // 图片处理结果 TuSDKResult *result 具有三种属性，分别是 ：
         // result.image 是 UIImage 类型
         // result.imagePath 是 NSString 类型
         // result.imageAsset 是 TuSDKTSAssetInterface 类型
         
         // 下面以 result.image 举例如何将图片编辑结果持有并进行其他操作
         // 可在此添加自定义方法，将 result 结果传出，例如 ：  [self openEditorWithImage:result.image];
         // 并在外部使用方法接收 result 结果，例如 ： -(void)openEditorWithImage:(UIImage *)image;
         // 用户也可以在 result 结果的外部接受的方法中实现页面的跳转操作，用户可根据自身需求使用。
         
         // 用户在获取到 result.image 结果并跳转到其他页面进行操作的时候可能会出现无法持有对象的情况
         // 此时用户可以将 result.image 对象转换成 NSData 类型的对象，然后再进行操作，例如 ：
         // NSData *imageData = UIImageJPEGRepresentation(result.image, 1.0);
         // ViewController *viewController = [[ViewController alloc]init];
         // [self.controller pushViewController:viewController animated:YES];
         // viewController.currentImage = [UIImage imageWithData:imageData];
         
         // 获取 result 对象的不同属性，需要对 option 选项中的保存到相册和保存到临时文件相关项进行设置。
         //
     }];
    
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKCPPhotoEditMultipleOptions.html
    // _photoEditMultipleComponent.options
    
    //    // 照片美化组件入口控制器配置选项
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditMultipleOptions.html
    // _photoEditMultipleComponent.options.editMultipleOptions
    //    // 禁用功能模块 默认：加载全部模块
    //    [_photoEditMultipleComponent.options.editMultipleOptions disableModule:lsqTuSDKCPEditActionCuter];
    //    // 最大输出图片按照设备屏幕 (默认:true, 如果设置了LimitSideSize, 将忽略LimitForScreen)
    //    _photoEditMultipleComponent.options.editMultipleOptions.limitForScreen = YES;
    //    // 保存到系统相册
    //    _photoEditMultipleComponent.options.editMultipleOptions.saveToAlbum = YES;
    //    // 控制器关闭后是否自动删除临时文件
    //    _photoEditMultipleComponent.options.editMultipleOptions.isAutoRemoveTemp = YES;
    //    // 设置水印选项 (默认为空，如果设置不为空，则输出的图片上将带有水印)
    //    _photoEditMultipleComponent.options.editMultipleOptions.waterMarkOption = [self waterMarkOption];
    //
    //    // 滤镜模块控制器配置选项
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditFilterOptions.html
    // _photoEditMultipleComponent.options.editFilterOptions
    //    // 默认: true, 开启滤镜配置选项
    //    _photoEditMultipleComponent.options.editFilterOptions.enableFilterConfig = YES;
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editFilterOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editFilterOptions.outputCompress = 0.95f;
    //    // 滤镜列表行视图宽度
    //    _photoEditMultipleComponent.options.editFilterOptions.filterBarCellWidth = 75;
    //    // 滤镜列表选择栏高度
    //    _photoEditMultipleComponent.options.editFilterOptions.filterBarHeight = 100;
    //    // 滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
    //    _photoEditMultipleComponent.options.editFilterOptions.filterBarGroupCellClazz = [TuSDKCPGroupFilterGroupCell class];
    //    // 滤镜列表行视图类 (默认:TuSDKCPGroupFilterItem, 需要继承 TuSDKCPGroupFilterItem)
    //    _photoEditMultipleComponent.options.editFilterOptions.filterBarTableCellClazz = [TuSDKCPGroupFilterItem class];
    //    // 开启用户滤镜历史记录
    //    _photoEditMultipleComponent.options.editFilterOptions.enableFilterHistory = YES;
    //    // 显示滤镜标题视图
    //    _photoEditMultipleComponent.options.editFilterOptions.displayFilterSubtitles = YES;
    //    // 是否渲染滤镜封面 (使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TUTUCLOUD.com控制台)
    //    _photoEditMultipleComponent.options.editFilterOptions.isRenderFilterThumb = YES;
    //
    //    // 裁切模块旋转控制器配置选项
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditCuterOptions.html
    // _photoEditMultipleComponent.options.editCuterOptions
    //    // 是否开启图片旋转(默认: false)
    //    _photoEditMultipleComponent.options.editCuterOptions.enableTrun = YES;
    //    // 是否开启图片镜像(默认: false)
    //    _photoEditMultipleComponent.options.editCuterOptions.enableMirror = YES;
    //    // 裁剪比例 (默认:lsqRatioDefault)
    //    _photoEditMultipleComponent.options.editCuterOptions.ratioType = lsqRatioDefault;
    //    // 裁剪比例排序 (例如：@[@(lsqRatioOrgin), @(lsqRatio_1_1), @(lsqRatio_2_3), @(lsqRatio_3_4)])
    //    _photoEditMultipleComponent.options.editCuterOptions.ratioTypeList = @[@(lsqRatioOrgin), @(lsqRatio_1_1), @(lsqRatio_2_3)];
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editCuterOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editCuterOptions.outputCompress = 0.95f;
    //
    //    // 美颜模块控制器视图配置选项
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditSkinOptions.html
    // _photoEditMultipleComponent.options.editSkinOptions
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editSkinOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editSkinOptions.outputCompress = 0.95f;
    //    // 一键美颜选项参数设置 0 - 1，默认为 1（该功能需要联网）
        _photoEditMultipleComponent.options.editSkinOptions.retouchSize = 0.5f;

    //    // 贴纸模块选择控制器配置选项
    // _photoEditMultipleComponent.options.editStickerOptions
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditStickerOptions.html
    //    // 单元格间距 (单位：DP)
    //    _photoEditMultipleComponent.options.editStickerOptions.gridPadding = 2;
    //    // 保存到临时文
    //    _photoEditMultipleComponent.options.editStickerOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editStickerOptions.outputCompress = 0.95f;
    //
    //    // 图片编辑文字添加控制器配置选项
    //    _photoEditMultipleComponent.options.editTextOptions;
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editTextOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editTextOptions.outputCompress = 0.95f;
    //    // 文字初始化创建样式
    //    _photoEditMultipleComponent.options.editTextOptions.textOptions = [TuSDKPFEditTextViewOptions defaultOptions];
    //
    //    // 颜色调整模块控制器配置选项
    // _photoEditMultipleComponent.options.editAdjustOptions
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditAdjustOptions.html
    //    // 保存到临时文
    //    _photoEditMultipleComponent.options.editAdjustOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editAdjustOptions.outputCompress = 0.95f;
    //
    //    // 锐化模块控制器配置选项
    // _photoEditMultipleComponent.options.editSharpnessOptions
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditSharpnessOptions.html
    //    // 保存到临时文
    //    _photoEditMultipleComponent.options.editSharpnessOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editSharpnessOptions.outputCompress = 0.95f;
    //
    //    // 大光圈模块控制器配置选项
    // _photoEditMultipleComponent.options.editApertureOptions
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditApertureOptions.html
    //    // 保存到临时文
    //    _photoEditMultipleComponent.options.editApertureOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editApertureOptions.outputCompress = 0.95f;
    //
    //    // 暗角模块控制器配置选项
    // _photoEditMultipleComponent.options.editVignetteOptions
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditVignetteOptions.html
    //    // 保存到临时文
    //    _photoEditMultipleComponent.options.editVignetteOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editVignetteOptions.outputCompress = 0.95f;
    //
    //    // 涂抹模块控制器配置选项
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditSmudgeOptions.html
    // _photoEditMultipleComponent.options.editSmudgeOptions
    //    // 默认的笔刷大小 (默认: lsqBrushMedium，中等粗细)
    //    _photoEditMultipleComponent.options.editSmudgeOptions.defaultBrushSize = lsqMediumBrush;
    //    // 是否保存上一次使用的笔刷 (默认: YES)
    //    _photoEditMultipleComponent.options.editSmudgeOptions.saveLastBrush = YES;
    //    // 默认撤销的最大次数 (默认: 5)
    //    _photoEditMultipleComponent.options.editSmudgeOptions.maxUndoCount = 5;
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editSmudgeOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editSmudgeOptions.outputCompress = 0.95f;
    //
    //    // 模糊模块控制器配置选项
    // @see-https://tutucloud.com/docs/ios/image/api-geev1/Classes/TuSDKPFEditWipeAndFilterOptions.html
    // _photoEditMultipleComponent.options.editWipeAndFilterOptions
    //    // 默认的笔刷大小 (默认: lsqBrushMedium，中等粗细)
    //    _photoEditMultipleComponent.options.editWipeAndFilterOptions.defaultBrushSize = lsqMediumBrush;
    //    // 默认撤销的最大次数 (默认: 5)
    //    _photoEditMultipleComponent.options.editWipeAndFilterOptions.maxUndoCount = 5;
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editWipeAndFilterOptions.saveToTemp = YES;
    //    // 显示放大镜 (默认: true)
    //    _photoEditMultipleComponent.options.editWipeAndFilterOptions.displayMagnifier = YES;
    //    // 笔刷效果强度 (默认: 0.2, 范围为0 ~ 1，值为1时强度最高)
    //    _photoEditMultipleComponent.options.editWipeAndFilterOptions.brushStrength = 0.2f;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editWipeAndFilterOptions.outputCompress = 0.95f;
    //
    
    // 设置图片
    _photoEditMultipleComponent.inputImage = result.image;
    _photoEditMultipleComponent.inputTempFilePath = result.imagePath;
    _photoEditMultipleComponent.inputAsset = result.imageAsset;
    // 是否在组件执行完成后自动关闭组件 (默认:NO)
    _photoEditMultipleComponent.autoDismissWhenCompelted = YES;
    // 当上一个页面是NavigationController时,是否通过 pushViewController 方式打开编辑器视图 (默认：NO，默认以 presentViewController 方式打开）
    // SDK 内部组件采用了一致的界面设计，会通过 push 方式打开视图。如果用户开启了该选项，在调用时可能会遇到布局不兼容问题，请谨慎处理。
    _photoEditMultipleComponent.autoPushViewController = YES;
    [_photoEditMultipleComponent showComponent];
}

/**
 *  编辑器水印
 *
 *  @return
 */
- (TuSDKWaterMarkOption *)waterMarkOption;
{
    TuSDKWaterMarkOption *option = [[TuSDKWaterMarkOption alloc] init];
    
    // 水印文字或者图片需要至少设置一个
    // 设置水印文字
    option.markText = @"";
    
    // 设置水印文字颜色
    option.markTextColor = [UIColor whiteColor];
    
    // 文字大小 (默认: 24 SP)
    option.markTextSize = 24;
    
    // 文字阴影颜色 (默认:[UIColor grayColor])
    option.markTextShadowColor = [UIColor grayColor];
    
    // 设置水印图片
    option.markImage = [UIImage imageNamed:@"sample_watermark.png"];
    
    // 文字和图片顺序 (仅当图片和文字都非空时生效，默认: 文字在右)
    option.markTextPosition = lsqMarkTextPositionRight;
    
    // 设置水印位置 (默认: lsqWaterMarkBottomRight)
    option.markPosition = lsqWaterMarkBottomRight;
    
    // 设置水印距离图片边距 (默认: 6dp)
    option.markMargin = 6;
    
    // 文字和图片间距 (默认: 2dp)
    option.markTextPadding = 5;
    
    return option;
}
@end
