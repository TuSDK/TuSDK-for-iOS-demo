//
//  DemoComponentListController.m
//  TuSDKDemo
//
//  Created by Yanlin on 12/17/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "DemoComponentListController.h"
#import "DemoRootView.h"

//Simples
#import "SimpleAlbumComponent.h"
#import "SimpleAlbumMultipleComponent.h"
#import "SimpleCameraComponent.h"
#import "SimpleEditAdvancedComponent.h"
#import "SimpleEditAndCutComponent.h"
#import "SimpleEditAvatarComponent.h"
#import "SimpleEditMultipleComponent.h"

#import "ExtendEditAndCutComponent.h"
#import "ExtendCameraBaseComponent.h"

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
    
    self.view = [DemoRootView initWithFrame:CGRectMake(0, 0, lsqScreenWidth, [UIScreen midViewAutoHeight])];
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
     * - (void)showSimpleWithController:(UIViewController *)controller;
     * 方法，学习使用范例。
     */
    // 范例分组
    DemoSimpleGroup *group = [DemoSimpleGroup group];
    // 相册组件范例
    [group appenWithSimple:[SimpleAlbumComponent simple]];
    // 多功能相册组件范例
    [group appenWithSimple:[SimpleAlbumMultipleComponent simple]];
    // 相机组件范例
    [group appenWithSimple:[SimpleCameraComponent simple]];
    // 图片编辑组件 (裁剪)范例
    [group appenWithSimple:[SimpleEditAndCutComponent simple]];
    // 头像设置组件(编辑)范例
    [group appenWithSimple:[SimpleEditAvatarComponent simple]];
    // 高级图片编辑组件范例
    [group appenWithSimple:[SimpleEditAdvancedComponent simple]];
    // 多功能图片编辑组件范例
    [group appenWithSimple:[SimpleEditMultipleComponent simple]];
    // 图片编辑组件范例 (对现有组件进行扩展 - 修改界面)
    [group appenWithSimple:[ExtendEditAndCutComponent simple]];
    // 基础相机组件范例 (对现有组件进行扩展 - 修改界面)
    [group appenWithSimple:[ExtendCameraBaseComponent simple]];
    // 基础相机自定义 - 底层API
    [group appenWithSimple:[DefineCameraBaseComponent simple]];
    
    // 设置范例分组数据
    self.view.group = group;    
}

#pragma mark - DemoRootViewDelegate
/**
 *  选中范例
 *
 *  @param view   入口控制器视图
 *  @param simple 范例
 *  @param action 范例列表行点击动作
 */
- (void)demoRootView:(DemoRootView *)view
      selectedSimple:(DemoSimpleBase *)simple
          withAction:(demoListItemAction)action;
{
    if (!simple) return;
    switch (action) {
        case demoListItemActionSelected:
            [simple showSimpleWithController:self];
            break;
        default:
            break;
    }
}
@end
