//
//  GeeV2Sample.m
//  TuSDKDemo
//
//  Created by Jimmy Zhao on 16/9/19.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2Sample.h"

@interface GeeV2Sample()<GeeV2PFCameraDelegate>{
    // 照片美化编辑组件
    GeeV2CPPhotoEditMultipleComponent *_photoEditMultipleComponent;
    // 相册组件
    GeeV2CPAlbumMultipleComponent *_albumComponent;
    // 照片美化最大可编辑数量 和 多选相册选择的最大照片数量必须保持一致
    NSUInteger _maxSelection;
}
@end

@implementation GeeV2Sample

- (instancetype)init;
{
    self = [super initWithGroupId:RecommendSample title:NSLocalizedString(@"sample_GeeV2ThemeComponent", @"GeeV主题模板")];
    _maxSelection = 9;
    return self;
}
#pragma mark - 开启多选相册
/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSampleWithController:(UIViewController *)controller;
{
    // 组件使用文档教程
    // @see-https://tusdk.com/docs/ios/multiple-editor-usage
    
    if (!controller) return;
    
    // 指定主题包的 style
    [TuSDK shared].style = @"ui_geeV2";
    
    self.controller = controller;
    _albumComponent =
    [TuSDKGeeV2 albumMultipleCommponentWithController:controller
                                        callbackBlock:^(TuSDKResult *result, NSError *error, UIViewController *controller)
     {
         if (error) {
             lsqLError(@"album reader error: %@", error.userInfo);
             return;
         }
         [result logInfo];
         NSMutableArray *resultArray = [NSMutableArray arrayWithCapacity:result.imageAssets.count];
         for (id<TuSDKTSAssetInterface> asset in result.imageAssets) {
             TuSDKResult *result = [TuSDKResult result];
             result.imageAsset = asset;
             [resultArray addObject:result];
         }
         
         [self openEditMultipleWithController:controller result:resultArray];
     }
     openCameraCallback:^(GeeV2PFAlbumMultipleViewController *controller) {
         // 开启访问相机权限
         [TuSDKTSDeviceSettings checkAllowWithController:controller
                                                    type:lsqDeviceSettingsCamera
                                               completed:^(lsqDeviceSettingsType type, BOOL openSetting)
          {
              if (openSetting) {
                  lsqLError(@"Can not open camera");
                  return;
              }
              [self showCamera:controller];
          }];
     }                                    maxSelectionNumber:_maxSelection];
    
    // 组件选项配置
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2CPAlbumMultipleOptions.html
    // _albumComponent.options
    
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFAlbumMultipleOptions.html
    // _albumComponent.options.albumOptions
    
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFCameraOptions.html
    // _albumComponent.options.cameraOptions
    
    // 是否在组件执行完成后自动关闭组件 (默认:NO)
    // _albumComponent.autoDismissWhenCompelted = YES;
    
    // 设置相册照片排序方式 默认：lsqAssetSortKeyCreateDate （ lsqAssetSortKeyModificationDate iOS8及以上可用）
   //  _albumComponent.options.albumOptions.photosSortKeyType = lsqAssetSortKeyCreateDate;
    // 设置选择照片的最大尺寸 默认：8000*8000
   // _albumComponent.options.albumOptions.maxSelectionImageSize = CGSizeMake(8000, 8000);
    
    [_albumComponent showComponent];
}
#pragma mark - 开启照片美化组件
/**
 *  开启照片美化组件
 *
 *  @param controller     来源控制器
 *  @param inputResults   输入的结果集合
 */
- (void)openEditMultipleWithController:(UIViewController *)controller
                                result:(NSArray<TuSDKResult *>*)inputResults;
{
    if (!controller || !inputResults) return;
    // 组件选项配置
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2CPPhotoEditMultipleComponent.html
    _photoEditMultipleComponent =
    [TuSDKGeeV2 photoEditMultipleWithController:controller
                                  callbackBlock:^(NSArray<TuSDKResult *> *outputResults, NSError *error, UIViewController *controller)
     {
         // 获取图片失败
         if (error) {
             lsqLError(@"editMultiple error: %@", error.userInfo);
             return;
         }
         
         // 输出 outputResults 中的图片信息
         for (TuSDKResult *result in outputResults)
         {
             [result logInfo];
         }
         
         //
         // 可在此添加自定义方法，在编辑完成时进行页面跳转操，例如 ：
         // [controller presentViewController:[[UIViewController alloc] init] animated:YES completion:nil];
         
         // 图片处理结果 NSArray<TuSDKResult *> 的数组，数组中是 TuSDKResult 类型的对象。
         // TuSDKResult *firstResult 可获取的数据类型是 ：
         // firstResult.imagePath 是 NSString 类型
         // firstResult.imageAsset 是 TuSDKTSAssetInterface 类型
         
         // 可使用以下方式进行转换
         // 从数组中获取到第一张图片的 TuSDKResult 对象
         // TuSDKResult *firstRusult = [result objectAtIndex:0];
         // 通过转换 firstRusult.imageAsset 获取 UIImage
         // UIImage *firstOriginalImage = [firstRusult.imageAsset fullResolutionImage];
         // 通过转换 firstRusult.imagePath 获取 UIImage
         // UIImage *firstTempFileImage = [UIImage imageWithContentsOfFile:firstRusult.imagePath];
         
         // 下面以 UIImage 类型的编辑结果举例，如何将编辑结果持有并进行其他操作。
         // 使用 TuSDKTSAssetInterface 和 NSString 类型。
         // 可在此添加自定义方法，将编辑结果结果传出，例如 ：  [self openEditorWithImage:firstOriginalImage];
         // 并在外部使用方法接收编辑结果，例如 ： -(void)openEditorWithImage:(UIImage *)image;
         // 用户也可以在编辑结果的外部接受的方法中实现页面的跳转操作，用户可根据自身需求使用。
         
         // 用户在获取到 firstOriginalImage 结果并跳转到其他页面进行操作的时候可能会出现无法持有对象的情况
         // 此时用户可以将 UIImage 类型的对象转换成 NSData 类型的对象，然后再进行操作，例如 ：
         // NSData *imageData = UIImageJPEGRepresentation(firstOriginalImage, 1.0);
         // UIViewController *viewController = [[UIViewController alloc]init];
         // [self.controller pushViewController:viewController animated:YES];
         // viewController.currentImage = [UIImage imageWithData:imageData];
         
         // 获取 result 对象的不同属性，需要对 option 选项中的保存到相册和保存到临时文件相关项进行设置。
         // 获取多个编辑结果，请将多个编辑结果一起处理或者添加至数组中，将对应数组传出。
         // 

     }];
    
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2CPPhotoEditMultipleOptions.html
    // _photoEditMultipleComponent.options
    
    //    // 照片美化入口控制器配置选项
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFEditMultipleOptions.html
    // _photoEditMultipleComponent.options.editMultipleOptions
    //    // 禁用功能模块 默认：加载全部模块
    //  [_photoEditMultipleComponent.options.editMultipleOptions disableModule:lsqTuSDKCPEditActionSticker];
    //    // 最大输出图片按照设备屏幕 (默认:true, 如果设置了LimitSideSize, 将忽略LimitForScreen)
    //    _photoEditMultipleComponent.options.editMultipleOptions.limitForScreen = YES;
    //    // 保存到系统相册
    //    _photoEditMultipleComponent.options.editMultipleOptions.saveToAlbum = YES;
    //    // 控制器关闭后是否自动删除临时文件
    //    _photoEditMultipleComponent.options.editMultipleOptions.isAutoRemoveTemp = YES;
    //    // 设置水印选项 (默认为空，如果设置不为空，则输出的图片上将带有水印)
    //    _photoEditMultipleComponent.options.editMultipleOptions.waterMarkOption = [self waterMarkOption];
    //    // 设置可编辑的图片数量 （默认为 3 张，最大可设置 9 张）
    _photoEditMultipleComponent.options.editMultipleOptions.maxSelectionNumber = _maxSelection;
    //    // 是否保存所有图片到相册 （默认：NO 结果只保留编辑过的图片，设置 YES 结果保存所有选中图片到相册）
    //    _photoEditMultipleComponent.options.editMultipleOptions.enableAlwaysSaveEditResult = YES;
    //
    //    // 图片编辑组件配置选项
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFEditTabBarOptions.html
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editTabBarOptions.outputCompress = 0.95f;
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editTabBarOptions.saveToTemp = YES;
    //    // 禁用功能模块 默认：加载全部模块@[@(lsqTuSDKCPEditActionCuter),@(lsqTuSDKCPEditActionTurnAndMirror), @(lsqTuSDKCPEditActionWipeFilter),@(lsqTuSDKCPEditActionAperture)]
    //   [_photoEditMultipleComponent.options.editTabBarOptions disableModule:lsqTuSDKCPEditActionWipeFilter];
    //
    //    // 编辑模块模糊功能控制器配置选项
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFEditWipeAndFilterOptions.html
    // _photoEditMultipleComponent.options.editTabBarOptions.editWipeAndFilterOptions
    //    // 默认的笔刷大小 (默认: lsqBrushMedium，中等粗细)
    //    _photoEditMultipleComponent.options.editTabBarOptions.editWipeAndFilterOptions.defaultBrushSize = lsqMediumBrush;
    //    // 默认撤销的最大次数 (默认: 5)
    //    _photoEditMultipleComponent.options.editTabBarOptions.editWipeAndFilterOptions.maxUndoCount = 5;
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editTabBarOptions.editWipeAndFilterOptions.saveToTemp = YES;
    //    // 显示放大镜 (默认: false)
    //    _photoEditMultipleComponent.options.editTabBarOptions.editWipeAndFilterOptions.displayMagnifier = NO;
    //    // 笔刷效果强度 (默认: 0.2, 范围为0 ~ 1，值为1时强度最高)
    //    _photoEditMultipleComponent.options.editTabBarOptions.editWipeAndFilterOptions.brushStrength = 0.2f;
    //
    //    // 滤镜模块控制器配置选项
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFEditFilterOptions.html
    // _photoEditMultipleComponent.options.editFilterOptions
    //    // 默认: true, 开启滤镜配置选项
    //    _photoEditMultipleComponent.options.editFilterOptions.enableFilterConfig = YES;
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editFilterOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editFilterOptions.outputCompress = 0.95f;
    //    // 滤镜列表行视图宽度
    //    _photoEditMultipleComponent.options.editFilterOptions.filterBarCellWidth = 73;
    //    // 滤镜列表折叠视图宽度
    //    _photoEditMultipleComponent.options.editFilterOptions.filterBarStackViewWidth = 73;
    //    // 滤镜分组列表行视图类 (默认:GeeV2CPFilterSectionView, 需要继承 GeeV2CPFilterSectionView)
    //    _photoEditMultipleComponent.options.editFilterOptions.stackViewClazz = [GeeV2CPFilterSectionView class];
    //    // 滤镜列表行视图类 (默认:GeeV2CPGroupFilterItem, 需要继承 GeeV2CPGroupFilterItem)
    //    _photoEditMultipleComponent.options.editFilterOptions.filterBarTableCellClazz = [GeeV2CPGroupFilterItemCell class];
    //    // 开启用户滤镜历史记录
    //    _photoEditMultipleComponent.options.editFilterOptions.enableFilterHistory = YES;
    //    // 显示滤镜标题视图
    //    _photoEditMultipleComponent.options.editFilterOptions.displayFilterSubtitles = YES;
    //    // 是否渲染滤镜封面 (使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TuSDK.com控制台)
    //    _photoEditMultipleComponent.options.editFilterOptions.isRenderFilterThumb = YES;
    //
    //    // 美颜模块控制器视图配置选项
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFEditSkinOptions.html
    // _photoEditMultipleComponent.options.editSkinOptions
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editSkinOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editSkinOptions.outputCompress = 0.95f;
    //
    //    // 贴纸模块控制器配置选项
    // _photoEditMultipleComponent.options.editStickerOptions
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFEditStickerOptions.html
    //    // 单元格间距 (单位：DP)
    //    _photoEditMultipleComponent.options.editStickerOptions.gridPadding = 2;
    //    // 保存到临时文
    //    _photoEditMultipleComponent.options.editStickerOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editStickerOptions.outputCompress = 0.95f;
    //
    //    // 颜色调整模块控制器配置选项
    // _photoEditMultipleComponent.options.editAdjustOptions
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFEditAdjustOptions.html
    //    // 保存到临时文
    //    _photoEditMultipleComponent.options.editAdjustOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editAdjustOptions.outputCompress = 0.95f;
    //
    //    // 涂抹模块控制器配置选项
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFEditSmudgeOptions.html
    // _photoEditMultipleComponent.options.editSmudgeOptions
    //    // 默认的笔刷大小 (默认: lsqGeeV2MediumBrush，中等粗细)
    //    _photoEditMultipleComponent.options.editSmudgeOptions.defaultBrushSize = lsqGeeV2MediumBrush;
    //    // 是否保存上一次使用的笔刷 (默认: YES)
    //    _photoEditMultipleComponent.options.editSmudgeOptions.saveLastBrush = YES;
    //    // 默认撤销的最大次数 (默认: 5)
    //    _photoEditMultipleComponent.options.editSmudgeOptions.maxUndoCount = 5;
    //    // 保存到临时文件
    //    _photoEditMultipleComponent.options.editSmudgeOptions.saveToTemp = YES;
    //    // 照片输出压缩率 0-100 如果设置为0 将保存为PNG格式
    //    _photoEditMultipleComponent.options.editSmudgeOptions.outputCompress = 0.95f;
    //
    _photoEditMultipleComponent.inputResources = inputResults;
    // 是否在组件执行完成后自动关闭组件 (默认:NO)
    _photoEditMultipleComponent.autoDismissWhenCompelted = YES;
    // 当上一个页面是NavigationController时,是否通过 pushViewController 方式打开编辑器视图 (默认：NO，默认以 presentViewController 方式打开）
    // SDK 内部组件采用了一致的界面设计，会通过 push 方式打开视图。如果用户开启了该选项，在调用时可能会遇到布局不兼容问题，请谨慎处理。
    _photoEditMultipleComponent.autoPushViewController = YES;
    
    
    [_photoEditMultipleComponent showComponent];
}
#pragma mark - showCamera
/**
 *  启动相机
 *
 *  @param controller 启动控制器
 */
- (void)showCamera:(GeeV2PFAlbumMultipleViewController *)controller;
{
    // 组件选项配置
    // @see-https://tusdk.com/docs/ios/api-geev2/Classes/GeeV2PFCameraOptions.html
    GeeV2PFCameraViewController *cameraController = _albumComponent.options.cameraOptions.viewController;
    // 添加委托
    cameraController.delegate = self;
    cameraController.openedByAlbumController = YES;
    [controller pushViewController:cameraController animated:YES];
}
#pragma mark - TuSDKPFCameraDelegate
/**
 *  获取一个拍摄结果
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onGeeV2PFCamera:(GeeV2PFCameraViewController *)controller captureResult:(TuSDKResult *)result;
{
    [self openEditMultipleWithController:controller result:[NSArray arrayWithObject:result]];
}
/**
 *  请求从相机界面跳转至相册
 *
 *  @param controller 默认相机视图控制器
 */
- (void)onGeeV2AlbumDemand:(GeeV2PFCameraViewController *)controller;
{
    if (controller.openedByAlbumController) {
        [controller popViewControllerAnimated:YES];
    }
}
#pragma mark - TuSDKCPComponentErrorDelegate
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
