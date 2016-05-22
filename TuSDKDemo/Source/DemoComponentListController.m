//
//  DemoComponentListController.m
//  TuSDKDemo
//
//  Created by Yanlin on 12/17/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "DemoComponentListController.h"
#import "DemoRootView.h"

//Samples
#import "CameraComponentSample.h"
#import "EditMultipleComponentSample.h"
#import "EditAdvancedComponentSample.h"
#import "EditAndCutComponentSample.h"
#import "EditAvatarComponentSample.h"

#import "AlbumComponentSample.h"
#import "AlbumMultipleComponentSample.h"
#import "GifImageViewController.h"

#import "CustomizedEditAndCutComponent.h"
#import "CustomizedCameraComponent.h"

#import "CameraAndEditorSample.h"
#import "SelfishCameraSample.h"
#import "EditFilterSampleController.h"
#import "StickerSampleController.h"
#import "WipeAndFilterSampleController.h"

#import "DefineCameraBaseComponent.h"

#pragma mark - DemoComponentListController
@interface DemoComponentListController ()<DemoRootViewDelegate>
/**
 *  覆盖控制器视图
 */
@property (nonatomic, retain) DemoRootView *view;
/**
 *  添加屏幕边缘轻扫手势返回主界面
 */
@property (nonatomic, retain) UIScreenEdgePanGestureRecognizer *screenEdgePanGesture;
@property (nonatomic, retain) UISwipeGestureRecognizer *swipeGesture;
@end

@implementation DemoComponentListController
@dynamic view;

- (void)loadView;
{
    [super loadView];
    
    // 设置全屏 隐藏状态栏 for IOS6
    self.wantsFullScreenLayout = YES;
    [self setNavigationBarHidden:NO animated:NO];
    [self setStatusBarHidden:YES withAnimation:UIStatusBarAnimationFade];

    CGFloat autoHeightForComponentList = ([UIDevice systemFloatVersion] < 7.f) ? [UIScreen height] - lsq_NAV_BAR_HEIGHT : [UIScreen height];
    self.view = [DemoRootView initWithFrame:CGRectMake(0, 0, lsqScreenWidth, autoHeightForComponentList)];
    self.view.backgroundColor = lsqRGB(255, 255, 255);
    self.view.delegate = self;
    
    // 判断设备版本，添加屏幕边缘滑动手势返回主界面
    if ([UIDevice systemFloatVersion] < 7.0f) {
        _swipeGesture = [[UISwipeGestureRecognizer alloc]initWithTarget:self action:@selector(onSwipeGesture:)];
        _swipeGesture.direction = UISwipeGestureRecognizerDirectionRight;
        [self.view addGestureRecognizer:_swipeGesture];
    }else if ([UIDevice systemFloatVersion] > 7.0f) {
        _screenEdgePanGesture = [[UIScreenEdgePanGestureRecognizer alloc]initWithTarget:self action:@selector(onScreenEdgePanGesture:)];
        _screenEdgePanGesture.edges = UIRectEdgeLeft;
        [self.view addGestureRecognizer:_screenEdgePanGesture];
    }
}

// 屏幕边缘轻扫动作返回主界面
-(void)onSwipeGesture:(UISwipeGestureRecognizer *)recognizer;
{
    [self popViewControllerAnimated:YES];

    [self.view removeGestureRecognizer:_swipeGesture];
}

-(void)onScreenEdgePanGesture:(UIScreenEdgePanGestureRecognizer *)recognizer;
{
    [self popViewControllerAnimated:YES];

    [self.view removeGestureRecognizer:_screenEdgePanGesture];
}

// 隐藏状态栏 for IOS7
- (BOOL)prefersStatusBarHidden;
{
    return YES;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // sdk统计代码，请不要加入您的应用
    [TuSDKTKStatistics appendWithComponentIdt:tkc_sdkComponent];
    
    self.title = [NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"app_name", @"TuSDK 涂图"), lsqSDKVersion ];
    
    [self navLeftButtonWithTitle:NSLocalizedString(@"back", @"返回") action:@selector(backActionHadAnimated)];
    
    /**
     * ！！！！！！！！！！！！！！！！！！！！！！！！！特别提示信息要长！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
     * 您可以通过查看 [group appenWithSimple:] 的具体类
     * - (void)showSampleWithController:(UIViewController *)controller;
     * 方法，学习使用范例。
     */
    // 范例分组
    SampleGroup *group = [SampleGroup group];
    
    // 功能套件
    // 相机组件范例
    [group appenWithSample:[CameraComponentSample sample]];
    // 照片美化组件范例
    [group appenWithSample:[EditMultipleComponentSample sample]];
    // 裁切+滤镜组件范例
    [group appenWithSample:[EditAndCutComponentSample sample]];
    // 头像设置组件(编辑)范例
    [group appenWithSample:[EditAvatarComponentSample sample]];
    // 裁切 + 滤镜 + 贴纸编辑组件范例
    [group appenWithSample:[EditAdvancedComponentSample sample]];
    
    // 常用组件
    // 相册组件范例
    [group appenWithSample:[AlbumComponentSample sample]];
    // 多选相册组件范例
    [group appenWithSample:[AlbumMultipleComponentSample sample]];
    // Gif组件范例
    [group appenWithTitle:NSLocalizedString(@"sample_GifComponent", @"Gif组件")
                    group:ComponentSample
                    clazz:[GifImageViewController class]
     ];
    
    // 组件用法范例
    // 拍照+编辑示例组件范例
    [group appenWithSample:[CameraAndEditorSample sample]];
    // 美颜相机组件示例
    [group appenWithSample:[SelfishCameraSample sample]];
    // 滤镜组件示例
    [group appenWithTitle:NSLocalizedString(@"sample_comp_FilterComponent", @"滤镜组件示例")
                    group:FeatureSample
                    clazz:[EditFilterSampleController class]];
    // 贴纸组件示例
    [group appenWithTitle:NSLocalizedString(@"sample_comp_StickerComponent", @"贴纸组件示例")
                    group:FeatureSample
                    clazz:[StickerSampleController class]];
    // 模糊组件示例
    [group appenWithTitle:NSLocalizedString(@"sample_comp_BlurComponent", @"模糊组件示例")
                    group:FeatureSample
                    clazz:[WipeAndFilterSampleController class]];
    
    // 自定义界面示例
    // 图片编辑组件范例 (对现有组件进行扩展 - 修改界面)
    [group appenWithSample:[CustomizedEditAndCutComponent sample]];
    // 基础相机组件范例 (对现有组件进行扩展 - 修改界面)
    [group appenWithSample:[CustomizedCameraComponent sample]];
    
    // API 使用示例（仅供参考）
    // 基础相机自定义 - 底层API
    [group appenWithSample:[DefineCameraBaseComponent sample]];
        
    // 设置范例分组数据
    self.view.group = group;    
}

#pragma mark - DemoRootViewDelegate
/**
 *  选中范例
 *
 *  @param view   入口控制器视图
 *  @param sample 范例
 *  @param action 范例列表行点击动作
 */
- (void)demoRootView:(DemoRootView *)view
      selectedSample:(SampleBase *)sample
          withAction:(demoListItemAction)action;
{
    if (!sample) return;
    switch (action) {
        case demoListItemActionSelected:
            
            if (sample.controllerClazz)
            {
                UIViewController *controller = [[sample.controllerClazz alloc] init];
                [self pushViewController:controller animated:YES];
            }
            else
            {
                [sample showSampleWithController:self];
            }
            break;
        default:
            break;
    }
}
@end
