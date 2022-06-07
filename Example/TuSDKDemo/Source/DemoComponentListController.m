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
#import "GeeV2Sample.h"

#import "CameraComponentSample.h"
#import "EditMultipleComponentSample.h"
#import "EditAdvancedComponentSample.h"
#import "EditAndCutComponentSample.h"
#import "EditAvatarComponentSample.h"

#import "AlbumComponentSample.h"
#import "AlbumMultipleComponentSample.h"

#import "CustomizedEditAndCutComponent.h"
#import "CustomizedCameraComponent.h"

#import "CameraAndEditorSample.h"
#import "SelfishCameraSample.h"
#import "EditFilterSampleController.h"
#import "StickerSampleController.h"
#import "WipeAndFilterSampleController.h"
#import "EditPaintDrawComponentSample.h"
#import "BubbleSampleController.h"
#import "CustomizedNewCameraComponent.h"
#import "JigsawSampleController.h"

#pragma mark - DemoComponentListController
@interface DemoComponentListController ()<DemoRootViewDelegate>
/**
 *  覆盖控制器视图
 */
@property (nonatomic, retain) DemoRootView *listView;
/**
 *  添加屏幕边缘轻扫手势返回主界面
 */
@property (nonatomic, retain) UIScreenEdgePanGestureRecognizer *screenEdgePanGesture;
@property (nonatomic, retain) UISwipeGestureRecognizer *swipeGesture;
@end

@implementation DemoComponentListController
@dynamic view;

- (void)viewWillAppear:(BOOL)animated;
{
    [super viewWillAppear:animated];
    //不管是否是iOS13的暗黑模式都保持该页面风格一致
    self.navigationController.navigationBar.barTintColor = [UIColor whiteColor];
    [self.navigationController.navigationBar setTitleTextAttributes:@{NSForegroundColorAttributeName : [UIColor blackColor]}];
    [self setNavigationBarHidden:NO animated:NO];
}

- (void)loadView;
{
    [super loadView];

    CGFloat autoHeightForComponentList = ([UIDevice lsqSystemFloatVersion] < 7.f) ? [UIScreen height] - lsq_NAV_BAR_HEIGHT : [UIScreen height];
    CGFloat topY = 0;
    if ([UIDevice lsqIsDeviceiPhoneX]) { // iPhone X
        autoHeightForComponentList = self.view.bounds.size.height - 122;
        topY = 88;
    }
    
    self.listView = [DemoRootView initWithFrame:CGRectMake(0, topY, lsqScreenWidth, autoHeightForComponentList)];
    self.view.backgroundColor = lsqRGB(255, 255, 255);
    self.listView.backgroundColor = lsqRGB(255, 255, 255);
    self.listView.delegate = self;
    [self.view addSubview:self.listView];
    
    // 判断设备版本，添加屏幕边缘滑动手势返回主界面
    if ([UIDevice lsqSystemFloatVersion] < 7.0f) {
        _swipeGesture = [[UISwipeGestureRecognizer alloc]initWithTarget:self action:@selector(onSwipeGesture:)];
        _swipeGesture.direction = UISwipeGestureRecognizerDirectionRight;
        [self.listView addGestureRecognizer:_swipeGesture];
    }else if ([UIDevice lsqSystemFloatVersion] > 7.0f) {
        _screenEdgePanGesture = [[UIScreenEdgePanGestureRecognizer alloc]initWithTarget:self action:@selector(onScreenEdgePanGesture:)];
        _screenEdgePanGesture.edges = UIRectEdgeLeft;
        [self.listView addGestureRecognizer:_screenEdgePanGesture];
    }
}

// 屏幕边缘轻扫动作返回主界面
-(void)onSwipeGesture:(UISwipeGestureRecognizer *)recognizer;
{
    [self lsqPopViewControllerAnimated:YES];

    [self.view removeGestureRecognizer:_swipeGesture];
}

-(void)onScreenEdgePanGesture:(UIScreenEdgePanGestureRecognizer *)recognizer;
{
    [self lsqPopViewControllerAnimated:YES];

    [self.view removeGestureRecognizer:_screenEdgePanGesture];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // sdk统计代码，请不要加入您的应用
    [TuStatistics appendWithComponentIdt:tu_sdkComponent];
    
    self.title = [NSString stringWithFormat:@"%@ %@", NSLocalizedString(@"app_name", @"TuSDK 涂图"), lsqPulseSDKVersion ];

    [self lsqNavLeftButtonWithTitle:NSLocalizedString(@"back", @"返回") action:@selector(lsqBackActionHadAnimated)];
    
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
    [group appenWithSample:[GeeV2Sample sample]];
    
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
    
    // 涂鸦组件
    [group appenWithSample:[EditPaintDrawComponentSample sample]];
    // 常用组件
    // 相册组件范例
    [group appenWithSample:[AlbumComponentSample sample]];
    // 多选相册组件范例
    [group appenWithSample:[AlbumMultipleComponentSample sample]];
    
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
    // 气泡文字组件示例
    [group appenWithTitle:NSLocalizedString(@"sample_comp_BubbleComponent", @"气泡文字组件示例")
                    group:FeatureSample
                    clazz:[BubbleSampleController class]];
    // 拼图组件示例
    [group appenWithTitle:NSLocalizedString(@"sample_comp_JigsawComponent", @"拼图组件示例")
                    group:FeatureSample
                    clazz:[JigsawSampleController class]];
    
    // 模糊组件示例
    [group appenWithTitle:NSLocalizedString(@"sample_comp_BlurComponent", @"模糊组件示例")
                    group:FeatureSample
                    clazz:[WipeAndFilterSampleController class]];
    
    // 自定义界面示例
    // 图片编辑组件范例 (对现有组件进行扩展 - 修改界面)
    [group appenWithSample:[CustomizedEditAndCutComponent sample]];
    // 基础相机组件范例 (对现有组件进行扩展 - 修改界面)
    [group appenWithSample:[CustomizedCameraComponent sample]];
    //自定义相机组件（From短视频）
//    [group appenWithSample:[CustomizedNewCameraComponent sample]];
    
    // 设置范例分组数据
    self.listView.group = group;
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
                [self lsqPushViewController:controller animated:YES];
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
