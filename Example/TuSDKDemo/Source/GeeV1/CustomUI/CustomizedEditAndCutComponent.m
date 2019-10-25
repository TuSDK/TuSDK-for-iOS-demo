//
//  CustomizedEditAndCutComponent.m
//  TuSDKDemo
//
//  Created by Clear Hu on 15/5/11.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "CustomizedEditAndCutComponent.h"

#pragma mark - CustomizedEditTurnAndCutView
/**
 *  自定义旋转和裁剪视图
 */
@interface CustomizedEditTurnAndCutView : TuSDKPFEditTurnAndCutView
/**
 *  向右旋转按钮
 */
@property (nonatomic, readonly) UIButton *trunRightButton;
@end

@implementation CustomizedEditTurnAndCutView
/**
 *  每个视图都会执行lsqInitView，自定义视图在这里开始
 */
-(void)lsqInitView;
{
    [super lsqInitView];
    
    // 修改底部工具栏背景
    self.bottomBar.backgroundColor = lsqRGB(255,123,44);
    // 改变底部镜像按钮为向右旋转按钮
    // 隐藏镜像按钮
    self.bottomBar.mirrorButton.hidden = YES;
    // 创建向右旋转按钮
    _trunRightButton = [UIButton buttonWithFrame:self.bottomBar.mirrorButton.frame
                             imageLSQBundleNamed:@"style_default_edit_button_trun_right"];
    // 绑定动作
    [_trunRightButton addTouchUpInsideTarget:self action:@selector(onImageTurnRightAction)];
    // 添加到视图
    [self.bottomBar addSubview:_trunRightButton];
}

/**
 *  向右旋转图片
 */
- (void)onImageTurnRightAction;
{
    [self.editImageView changeImage:lsqImageChangeTurnRight];
}
@end


#pragma mark - CustomizedEditAndCutComponent
/**
 *  图片编辑组件范例 (对现有组件进行扩展 - 修改界面)
 */
@interface CustomizedEditAndCutComponent()<TuSDKPFEditTurnAndCutDelegate>

@end

@implementation CustomizedEditAndCutComponent
- (instancetype)init;
{
    self = [super initWithGroupId:UISample title:NSLocalizedString(@"sample_ui_EditComponent", @"裁切+滤镜组件组件自定义界面")];
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
    
    // 组件选项配置
    // @see-https://tutucloud.com/docs/ios/image/image/api-geev1/Classes/TuSDKPFEditTurnAndCutOptions.html
    TuSDKPFEditTurnAndCutOptions *opt = [TuSDKPFEditTurnAndCutOptions build];
    
    // 视图类 (默认:TuSDKPFEditTurnAndCutView, 需要继承 TuSDKPFEditTurnAndCutView)
    // 自定义视图
    opt.viewClazz = [CustomizedEditTurnAndCutView class];
    
    // 旋转和裁剪视图控制栏类 (默认:TuSDKPFEditTurnAndCutBottomView, 需要继承 TuSDKPFEditTurnAndCutBottomView)
    // opt.bottomBarViewClazz = [TuSDKPFEditTurnAndCutBottomView class];
    
    // 图片编辑视图 (旋转，缩放)类 (默认:TuSDKICTouchImageView, 需要继承 TuSDKICTouchImageView)
    // opt.editImageViewClazz = [TuSDKICTouchImageView class];
    
    // 滤镜列表视图类 (默认:TuSDKPFEditTurnAndCutFilterView, 需要继承 TuSDKPFEditTurnAndCutFilterView)
    // opt.filterViewClazz = [TuSDKPFEditTurnAndCutFilterView class];
    
    // 是否开启滤镜支持 (默认: 关闭)
    opt.enableFilters = YES;
    
    // 开启滤镜历史记录
    opt.enableFilterHistory = YES;
    
    // 开启在线滤镜
    opt.enableOnlineFilter = YES;
    
    // 显示滤镜标题视图
    opt.displayFilterSubtitles = YES;
    
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
    
    // 是否渲染滤镜封面 (使用设置的滤镜直接渲染，需要拥有滤镜列表封面设置权限，请访问TUTUCLOUD.com控制台)
    // opt.isRenderFilterThumb = YES;
    
    TuSDKPFEditTurnAndCutViewController *tcController = opt.viewController;
    // 添加委托
    tcController.delegate = self;
    
    // 输入临时文件 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    // controller.inputTempFilePath = @"/app/temp.file";
    
    // 处理相册图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    // controller.inputAsset = [ALAsset];
    
    // 处理图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    tcController.inputImage = [UIImage imageNamed:@"sample_photo.jpg"];
    
    [self.controller lsqPresentModalNavigationController:tcController animated:YES];
    
    [tcController.navigationController.navigationBar setBarStyle:UIBarStyleBlack];
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
- (void)onComponent:(TuSDKCPViewController *)controller result:(TuSDKResult *)result error:(NSError *)error;
{
    lsqLDebug(@"onComponent: controller - %@, result - %@, error - %@", controller, result, error);
}
@end
