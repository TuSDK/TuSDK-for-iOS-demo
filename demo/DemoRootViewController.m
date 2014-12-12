//
//  DemoRootViewController.m
//  TuSDKDemo
//
//  Created by Clear Hu on 14/10/28.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "DemoRootViewController.h"
#import "SimpleCameraViewController.h"

#pragma mark - DemoRootView
/**
 *  演示选择
 */
@protocol DemoChooseDelegate <NSObject>
/**
 *  选中一个演示
 *
 *  @param index 演示索引
 */
- (void)onDemoChoosedWithIndex:(NSInteger)index;
@end

/**
 *  入口视图
 */
@interface DemoRootView : UIView<UITableViewDelegate, UITableViewDataSource>{
    // 表格视图
    TuSDKICTableView *_tableView;
    // 缓存标记
    NSString *_cellIdentifier;
    // 演示列表
    NSArray *_demos;
}

/**
 * 演示选择
 */
@property (nonatomic, assign) id<DemoChooseDelegate> delegate;
@end

@implementation DemoRootView
- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self initView];
    }
    return self;
}

- (void)initView;
{
    // 缓存标记
    _cellIdentifier = @"DemoRootViewCellIdentify";
    
    // 演示列表
    _demos = @[@"1-1 快速自定义相机",
               @"2-1 相册组件", @"2-2 相机组件",
               @"2-3 图片编辑组件", @"2-4 图片编辑组件 (裁剪)",
               @"3-1 头像设置组件"];
    
    // 表格视图
    _tableView = [TuSDKICTableView table];
    _tableView.delegate = self;
    _tableView.dataSource = self;
    _tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
    _tableView.backgroundColor = [UIColor whiteColor];
    _tableView.allowsMultipleSelection = YES;
    [self addSubview:_tableView];
}

#pragma mark - UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;
{
    return 50;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
{
    if (self.delegate) {
        [self.delegate onDemoChoosedWithIndex:indexPath.row];
    }
}
#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
{
    return _demos.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
{
    TuSDKICTableViewCell * cell = [tableView dequeueReusableCellWithIdentifier:_cellIdentifier];
    if (!cell) {
        cell = [TuSDKICTableViewCell initWithReuseIdentifier:_cellIdentifier];
        //cell.selectionStyle = UITableViewCellSelectionStyleGray;
    }
    
    cell.textLabel.font = FONT(15);
    cell.textLabel.text = _demos[indexPath.row];
    return cell;
}
@end


#pragma mark - DemoRootViewController

@interface DemoRootViewController ()<DemoChooseDelegate, TuSDKPFAlbumDelegate, TuSDKPFPhotosDelegate, TuSDKPFCameraDelegate, TuSDKPFEditTurnAndCutDelegate>
{
    // 头像设置组件
    TuSDKCPAvatarComponent *_avatarComponent;
}
/**
 *  覆盖控制器视图
 */
@property (nonatomic, retain) DemoRootView *view;
@end

@implementation DemoRootViewController

- (void)loadView;
{
    [super loadView];
    
    self.view = [DemoRootView initWithFrame:CGRectMake(0, 0, lsqScreenWidth, lsqScreenHeight)];
    self.view.backgroundColor = RGB(255, 255, 255);
    self.view.delegate = self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = @"涂图-TuSDK";
}

#pragma mark - DemoChooseDelegate
/**
 *  选中一个演示
 *
 *  @param index 演示索引
 */
- (void)onDemoChoosedWithIndex:(NSInteger)index;
{
    switch (index) {
        case 0:
            // 1-1 快速自定义相机
            [self simpleCustomHandler];
            break;
        case 1:
            // 2-1 相册组件
            [self albumComponentHandler];
            break;
        case 2:
            // 2-2 相机组件
            [self cameraComponentHandler];
            break;
        case 3:
            // 2-3 图片编辑组件
            [self editComponentHandler];
            break;
        case 4:
            // 2-4 图片编辑组件 (裁剪)
            [self editAndCutComponentHandler];
            break;
        case 5:
            // 3-1 头像设置组件
            [self avatarComponentHandler];
            break;
            
        default:
            break;
    }
}

#pragma mark - simpleCustomHandler
/**
 *  1-1 快速自定义相机
 */
- (void)simpleCustomHandler;
{
    [self presentViewController:[[SimpleCameraViewController alloc] init] animated:YES completion:nil];
}

#pragma mark - albumComponentHandler
/**
 *  2-1 相册组件
 */
- (void) albumComponentHandler;
{
    // 需要检测是否拥有相册读取权限
    [[ALAssetsLibrary defaultLibrary] getGroupsWithBlock:^(NSArray *groups, NSError *error) {
        if (error) {
            [ALAssetsLibrary showAlertWithLoadFailure:error];
            return;
        }
        lsqLDebug(@"albumComponentHandler: %ld", (long)groups.count);
        [self showAlbumWithGroups:groups];
    }];
}

/**
 *  显示系统相册列表
 *
 *  @param groups 系统相册组列表
 */
- (void)showAlbumWithGroups:(NSArray *)groups;
{
    TuSDKPFAlbumOptions *opt = [TuSDKPFAlbumOptions build];
    
    // 视图类 (默认:TuSDKPFAlbumView, 需要继承 TuSDKPFAlbumView)
    // opt.viewClazz = [TuSDKPFAlbumView class];
    
    // 表格行视图类 (默认:TuSDKPFAlbumCell, 需要继承 TuSDKPFAlbumCell)
    // opt.cellViewClazz = [TuSDKPFAlbumCell class];
    
    // 空数据视图类 (默认:TuSDKPFEmptyView, 需要继承 TuSDKPFEmptyView)
    // opt.emptyViewClazz = [TuSDKPFEmptyView class];
    
    // 是否自动选择相册组 (默认: YES, 如果没有设定相册组名称，自动跳转到系统相册组)
    // opt.autoSelectedAblumGroup = YES;
    
    // 需要自动跳转到相册组名称 (需要设定 autoSkipToPhotoList = YES)
    // opt.skipAlbumName = @"相机胶卷";
    
    TuSDKPFAlbumViewController *controller = opt.viewController;
    controller.delegate = self;
    controller.groups = groups;
    // 开启相册列表
    [self presentModalNavigationController:controller animated:YES];;
}

#pragma mark - albumComponentHandler TuSDKPFAlbumDelegate
/**
 *  选中相册组
 *
 *  @param controller 系统相册控制器
 *  @param group 相册组
 */
- (void)onTuSDKPFAlbum:(TuSDKPFAlbumViewController *)controller selectedGroup:(ALAssetsGroup *)group;
{
    TuSDKPFPhotosOptions *opt = [TuSDKPFPhotosOptions build];
    // 视图类 (默认:TuSDKPFPhotosView, 需要继承 TuSDKPFPhotosView)
    // opt.viewClazz = [TuSDKPFPhotosView class];
    
    // 表格行视图类 (默认:TuSDKPFPhotosCell, 需要继承 TuSDKPFPhotosCell)
    // opt.cellViewClazz = [TuSDKPFPhotosCell class];
    
    // 表格单元格视图类 (默认:TuSDKPFPhotosGrid, 需要继承 TuSDKPFPhotosGrid)
    // opt.gridViewClazz = [TuSDKPFPhotosGrid class];
    
    // 表格行头部视图类 (默认:TuSDKPFPhotosCellSectionHeader, 需要继承 TuSDKPFPhotosCellSectionHeader)
    // opt.cellHeaderViewClazz = [TuSDKPFPhotosCellSectionHeader class];
    
    // 空数据视图类 (默认:TuSDKPFEmptyView, 需要继承 TuSDKPFEmptyView)
    // opt.emptyViewClazz = [TuSDKPFEmptyView class];
    
    TuSDKPFPhotosViewController *photosController = opt.viewController;
    photosController.delegate = self;
    photosController.group = group;
    // 开启相片列表
    [controller pushViewController:photosController animated:YES];
}

#pragma mark - TuSDKPFPhotosDelegate
/**
 *  选中相片
 *
 *  @param controller 相册照片列表控制器
 *  @param asset      相片
 */
- (void)onTuSDKPFPhotos:(TuSDKPFPhotosViewController *)controller selectedAsset:(ALAsset *)asset;
{
    [controller dismissModalViewControllerAnimated:YES];
    lsqLDebug(@"onTuSDKPFPhotos: %@", asset);
}

#pragma mark - cameraComponentHandler
/**
 *  2-2 相机组件
 */
- (void) cameraComponentHandler;
{
    // 如果不支持摄像头显示警告信息
    if ([AVCaptureDevice showAlertIfNotSupportCamera]){
        return;
    }
    
    TuSDKPFCameraOptions *opt = [TuSDKPFCameraOptions build];
    
    // 视图类 (默认:TuSDKPFCameraView, 需要继承 TuSDKPFCameraView)
    // opt.viewClazz = [TuSDKPFCameraView class];
    
    // 默认相机控制栏视图类 (默认:TuSDKPFCameraConfigView, 需要继承 TuSDKPFCameraConfigView)
    // opt.configBarViewClazz = [TuSDKPFCameraConfigView class];
    
    // 默认相机底部栏视图类 (默认:TuSDKPFCameraBottomView, 需要继承 TuSDKPFCameraBottomView)
    // opt.bottomBarViewClazz = [TuSDKPFCameraBottomView class];
    
    // 闪光灯视图类 (默认:TuSDKPFCameraFlashView, 需要继承 TuSDKPFCameraFlashView)
    // opt.flashViewClazz = [TuSDKPFCameraFlashView class];
    
    // 滤镜视图类 (默认:TuSDKPFCameraFilterView, 需要继承 TuSDKPFCameraFilterView)
    // opt.filterViewClazz = [TuSDKPFCameraFilterView class];
    
    // 聚焦触摸视图类 (默认:TuSDKICFocusTouchView, 需要继承 TuSDKICFocusTouchView)
    // opt.focusTouchViewClazz = [TuSDKICFocusTouchView class];
    
    // 摄像头前后方向 (默认为后置优先)
    // opt.avPostion = [AVCaptureDevice firstBackCameraPosition];
    
    // 设置分辨率模式
    // opt.sessionPreset = AVCaptureSessionPresetHigh;
    
    // 闪光灯模式 (默认:AVCaptureFlashModeOff)
    // opt.defaultFlashMode = AVCaptureFlashModeOff;
    
    // 是否开启滤镜支持 (默认: 关闭)
    opt.enableFilters = YES;
    
    // 视频视图显示比例 (默认:0.75f, 0 < cameraViewRatio <= 1)
    // opt.cameraViewRatio = 0.75f;
    
    // 是否开启长按拍摄 (默认: NO)
    opt.enableLongTouchCapture = YES;
    
    // 开启持续自动对焦 (默认: NO)
    opt.enableContinueFoucs = YES;
    
    // 自动聚焦延时 (默认: 5秒)
    // opt.autoFoucsDelay = 5;
    
    // 长按延时 (默认: 1.2秒)
    // opt.longTouchDelay = 1.2;
    
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuSDKResult.asset)
    // opt.saveToAlbum = NO;
    
    // 保存到临时文件 (默认不保存, 当设置为YES时, TuSDKResult.tmpFile)
    // opt.saveToTemp = NO;
    
    // 保存到系统相册的相册名称
    // opt.saveToAlbumName = @"TuSdk";
    
    // 照片输出压缩率 0-1 如果设置为0 将保存为PNG格式 (默认: 0.95)
    // opt.outputCompress = 0.95f;
    
    TuSDKPFCameraViewController *controller = opt.viewController;
    // 添加委托
    controller.delegate = self;
    [self presentModalNavigationController:controller animated:YES];
}

#pragma mark - cameraComponentHandler TuSDKPFCameraDelegate
/**
 *  获取一个拍摄结果
 *
 *  @param controller 默认相机视图控制器
 *  @param result     拍摄结果
 */
- (void)onTuSDKPFCamera:(TuSDKPFCameraViewController *)controller captureResult:(TuSDKResult *)result;
{
    [controller dismissModalViewControllerAnimated:YES];
    lsqLDebug(@"onTuSDKPFCamera: %@", result);
}

#pragma mark - editComponentHandler
/**
 *  2-3 图片编辑组件
 */
- (void) editComponentHandler;
{
    TuSDKPFEditTurnAndCutOptions *opt = [TuSDKPFEditTurnAndCutOptions build];
    
    // 视图类 (默认:TuSDKPFEditTurnAndCutView, 需要继承 TuSDKPFEditTurnAndCutView)
    // opt.viewClazz = [TuSDKPFEditTurnAndCutView class];
    
    // 旋转和裁剪视图控制栏类 (默认:TuSDKPFEditTurnAndCutBottomView, 需要继承 TuSDKPFEditTurnAndCutBottomView)
    // opt.bottomBarViewClazz = [TuSDKPFEditTurnAndCutBottomView class];
    
    // 旋转和裁剪 裁剪区域视图类 (默认:TuSDKPFEditTurnAndCutRegion, 需要继承 TuSDKPFEditTurnAndCutRegion)
    // opt.cutRegionViewClazz = [TuSDKPFEditTurnAndCutRegion class];
    
    // 滤镜列表视图类 (默认:TuSDKPFCameraFilterView, 需要继承 TuSDKPFCameraFilterView)
    // opt.filterViewClazz = [TuSDKPFCameraFilterView class];
    
    // 是否开启滤镜支持 (默认: 关闭)
    opt.enableFilters = YES;
    
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
    
    TuSDKPFEditTurnAndCutViewController *controller = opt.viewController;
    // 添加委托
    controller.delegate = self;
    
    // 输入临时文件 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    // controller.inputTempFilePath = @"/app/temp.file";
    
    // 处理相册图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    // controller.inputAsset = [ALAsset];
    
    // 处理图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    controller.inputImage = [UIImage imageNamed:@"sample_photo.jpg"];
    
    [self presentModalNavigationController:controller animated:YES];
}

#pragma mark - editAndCutComponentHandler
/**
 *  2-4 图片编辑组件 (裁剪)
 */
- (void) editAndCutComponentHandler;
{
    TuSDKPFEditTurnAndCutOptions *opt = [TuSDKPFEditTurnAndCutOptions build];
    
    // 是否开启滤镜支持 (默认: 关闭)
    opt.enableFilters = YES;
    
    // 需要裁剪的长宽
    opt.cutSize = CGSizeMake(640, 640);
    
    // 是否显示处理结果预览图 (默认：关闭，调试时可以开启)
    opt.showResultPreview = YES;
    
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuSDKResult.asset)
    // opt.saveToAlbum = YES;
    
    // 保存到系统相册的相册名称
    // opt.saveToAlbumName = @"TuSdk";
    
    TuSDKPFEditTurnAndCutViewController *controller = opt.viewController;
    // 添加委托
    controller.delegate = self;
    
    // 处理图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    controller.inputImage = [UIImage imageNamed:@"sample_photo.jpg"];
    
    [self presentModalNavigationController:controller animated:YES];
}
#pragma mark - editComponentHandler TuSDKPFEditTurnAndCutDelegate
/**
 *  图片编辑完成
 *
 *  @param controller 旋转和裁剪视图控制器
 *  @param result 旋转和裁剪视图控制器处理结果
 */
- (void)onTuSDKPFEditTurnAndCut:(TuSDKPFEditTurnAndCutViewController *)controller result:(TuSDKResult *)result;
{
    if (!controller.showResultPreview) {
        [controller dismissModalViewControllerAnimated];
    }
    lsqLDebug(@"onTuSDKPFEditTurnAndCut: %@", result);
}
#pragma mark - avatarComponentHandler
/**
 *  3-1 头像设置组件
 */
- (void) avatarComponentHandler;
{
    lsqLDebug(@"avatarComponentHandler");
    _avatarComponent = [TuSDK avatarCommponentWithController:self callbackBlock:^(TuSDKResult *result, NSError *error) {
        // 获取头像图片
        if (error) {
            [self throwWithReason:@"avatar reader error" userInfo:error.userInfo];
            return;
        }
        [result logInfo];
    }];
    [_avatarComponent showComponent];
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
