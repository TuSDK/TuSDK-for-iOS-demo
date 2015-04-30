//
//  SimpleEditComponent.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/4/24.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "SimpleEditComponent.h"
#import "SimpleEditTurnAndCutView.h"

/**
 *  图片编辑组件范例
 */
@interface SimpleEditComponent()<TuSDKPFEditTurnAndCutDelegate>

@end

@implementation SimpleEditComponent
- (instancetype)init;
{
    self = [super initWithGroupId:2 title:NSLocalizedString(@"simple_EditComponent", @"图片编辑组件")];
    return self;
}

/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSimpleWithController:(UIViewController *)controller;
{
    if (!controller) return;
    self.controller = controller;
    
    // 组件选项配置
    // @see-http://tusdk.com/docs/ios/api/Classes/TuSDKPFEditTurnAndCutOptions.html
    TuSDKPFEditTurnAndCutOptions *opt = [TuSDKPFEditTurnAndCutOptions build];
    
    // 视图类 (默认:TuSDKPFEditTurnAndCutView, 需要继承 TuSDKPFEditTurnAndCutView)
    // 自定义视图
    opt.viewClazz = [SimpleEditTurnAndCutView class];
    
    // 旋转和裁剪视图控制栏类 (默认:TuSDKPFEditTurnAndCutBottomView, 需要继承 TuSDKPFEditTurnAndCutBottomView)
    // opt.bottomBarViewClazz = [TuSDKPFEditTurnAndCutBottomView class];
    
    // 图片编辑视图 (旋转，缩放)类 (默认:TuSDKPFEditImageView, 需要继承 TuSDKPFEditImageView)
    // opt.editImageViewClazz = [TuSDKPFEditImageView class];
    
    // 滤镜列表视图类 (默认:TuSDKPFEditTurnAndCutFilterView, 需要继承 TuSDKPFEditTurnAndCutFilterView)
    // opt.filterViewClazz = [TuSDKPFEditTurnAndCutFilterView class];
    
    // 是否开启滤镜支持 (默认: 关闭)
    opt.enableFilters = YES;
    
    // 滤镜列表行视图宽度
    // opt.filterBarCellWidth = 75;
    
    // 滤镜列表选择栏高度
    // opt.filterBarHeight = 100;
    
    // 滤镜分组列表行视图类 (默认:TuSDKCPGroupFilterGroupCell, 需要继承 TuSDKCPGroupFilterGroupCell)
    // opt.filterBarGroupCellClazz = [TuSDKCPGroupFilterGroupCell class];
    
    // 滤镜列表行视图类 (默认:TuSDKCPGroupFilterItem, 需要继承 TuSDKCPGroupFilterItem)
    // opt.filterBarTableCellClazz = [TuSDKCPGroupFilterItem class];
    
    // 需要裁剪的长宽
    // opt.cutSize = CGSizeMake(640, 640);
    
    // 是否显示处理结果预览图 (默认：关闭，调试时可以开启)
    // opt.showResultPreview = NO;
    
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuSDKResult.asset)
    // opt.saveToAlbum = NO;
    
    // 保存到临时文件 (默认不保存, 当设置为YES时, TuSDKResult.tmpFile)
    // opt.saveToTemp = NO;
    
    // 保存到系统相册的相册名称
    // opt.saveToAlbumName = @"TuSdk";
    
    // 照片输出压缩率 0-1 如果设置为0 将保存为PNG格式 (默认: 0.95)
    // opt.outputCompress = 0.95f;
    
    // 控制器关闭后是否自动删除临时文件
    // opt.isAutoRemoveTemp = YES;
    
    TuSDKPFEditTurnAndCutViewController *tcController = opt.viewController;
    // 添加委托
    tcController.delegate = self;
    
    // 输入临时文件 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    // controller.inputTempFilePath = @"/app/temp.file";
    
    // 处理相册图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    // controller.inputAsset = [ALAsset];
    
    // 处理图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    tcController.inputImage = [UIImage imageNamed:@"sample_photo.jpg"];
    
    [self.controller presentModalNavigationController:tcController animated:YES];
}

/**
 *  图片编辑完成
 *
 *  @param controller 旋转和裁剪视图控制器
 *  @param result 旋转和裁剪视图控制器处理结果
 */
- (void)onTuSDKPFEditTurnAndCut:(TuSDKPFEditTurnAndCutViewController *)controller result:(TuSDKResult *)result;
{
    // 清除所有控件
    [controller dismissModalViewControllerAnimated];
    lsqLDebug(@"onTuSDKPFEditTurnAndCut: %@", result);
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
