//
//  DemoRootViewController.m
//  TuSDKDemo
//
//  Created by Clear Hu on 14/10/28.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "DemoRootViewController.h"
#import "DemoRootView.h"

//Simples
#import "SimpleAlbumComponent.h"
#import "SimpleCameraComponent.h"
#import "SimpleDefineCamera.h"
#import "SimpleEditAdvancedComponent.h"
#import "SimpleEditAndCutComponent.h"
#import "SimpleEditAvatarComponent.h"
#import "SimpleEditComponent.h"
#import "SimpleEditMultipleComponent.h"

#pragma mark - DemoRootViewController
@interface DemoRootViewController ()<DemoRootViewDelegate, TuSDKFilterManagerDelegate>
/**
 *  覆盖控制器视图
 */
@property (nonatomic, retain) DemoRootView *view;
@end

@implementation DemoRootViewController
@dynamic view;

- (void)loadView;
{
    [super loadView];
    
    self.view = [DemoRootView initWithFrame:CGRectMake(0, 0, lsqScreenWidth, lsqScreenHeight)];
    self.view.backgroundColor = RGB(255, 255, 255);
    self.view.delegate = self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // sdk统计代码，请不要加入您的应用
    [TuSDKTKStatistics appendWithComponentIdt:tkc_sdkComponent];
    
    self.title = NSLocalizedString(@"app_name", @"TuSDK 涂图");
    // 启动GPS
    [TuSDKTKLocation shared].requireAuthor = YES;
    
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
    // 相机组件范例
    [group appenWithSimple:[SimpleCameraComponent simple]];
    // 图片编辑组件范例
    [group appenWithSimple:[SimpleEditComponent simple]];
    // 图片编辑组件 (裁剪)范例
    [group appenWithSimple:[SimpleEditAndCutComponent simple]];
    // 头像设置组件(编辑)范例
    [group appenWithSimple:[SimpleEditAvatarComponent simple]];
    // 高级图片编辑组件范例
    [group appenWithSimple:[SimpleEditAdvancedComponent simple]];
    // 多功能图片编辑组件范例
    [group appenWithSimple:[SimpleEditMultipleComponent simple]];
    // 自定义相机范例
    [group appenWithSimple:[SimpleDefineCamera simple]];
    
    // 设置范例分组数据
    self.view.group = group;
    
    /**
     * ！！！！！！！！！！！！！！！！！！！！！！！！！特别提示信息要长！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
     * 关于TuSDK体积（SDK编译后仅为1.9MB）：
     * 1,如果您不需要使用本地贴纸功能，或仅需要使用在线贴纸功能，请删除/app/TuSDK.bundle/stickers文件夹
     * 2,如果您仅需要几款滤镜，您可以删除/app/TuSDK.bundle/textures下的*.gsce文件
     * 3,如果您不需要使用滤镜功能，请删除/app/TuSDK.bundle/textures文件夹
     * 4,TuSDK在线管理功能请访问：http://tusdk.com/
     *
     * IOS编译Framework知识：
     * Framework包含armv7,arm64等不同CPU的编译结果的集合；
     * 其中每种CPU编译结果还包含Debug以及Realse两种子结果；
     * 当集成某个Framework（假如TuSDK.Framework物理文件大小为30MB），编译成APP发布后，实际大小约为不到2MB
     *
     * 开发文档:http://tusdk.com/docs/ios/api/
     */
    
    // 异步方式初始化滤镜管理器 (注意：如果需要一开启应用马上执行SDK组件，需要做该检测，否则可以忽略检测)
    // 需要等待滤镜管理器初始化完成，才能使用所有功能
    [self showHubWithStatus:LSQString(@"lsq_initing", @"正在初始化")];
    [TuSDK checkManagerWithDelegate:self];
}

#pragma mark - TuSDKFilterManagerDelegate
/**
 * 滤镜管理器初始化完成
 *
 * @param manager
 *            滤镜管理器
 */
- (void)onTuSDKFilterManagerInited:(TuSDKFilterManager *)manager;
{
    [self showHubSuccessWithStatus:LSQString(@"lsq_inited", @"初始化完成")];
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