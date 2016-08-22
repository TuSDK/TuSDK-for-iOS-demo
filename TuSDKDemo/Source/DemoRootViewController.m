//
//  DemoRootViewController.m
//  TuSDKDemo
//
//  Created by Clear Hu on 14/10/28.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import "DemoRootViewController.h"

//Samples
#import "CameraComponentSample.h"
#import "EditMultipleComponentSample.h"
#import "DemoComponentListController.h"

#pragma mark - DemoRootViewController
@interface DemoRootViewController ()<TuSDKFilterManagerDelegate>
{
    // 顶部Logo
    UIButton *mTopLogo;
    
    // 相机组件按钮
    UIButton *mCameraButton;
    // 编辑器组件按钮
    UIButton *mEditorButton;
    // 组件列表按钮
    UIButton *mComponentListButton;
    
    // 相机组件
    CameraComponentSample *cameraComponentSample;
    
    // 照片美化组件
    EditMultipleComponentSample *editMultipleComponentSample;
    
}
@end

@implementation DemoRootViewController

- (void)loadView;
{
    [super loadView];
    
    // 设置全屏 隐藏状态栏 for IOS6
    self.wantsFullScreenLayout = YES;
    [self setNavigationBarHidden:YES animated:NO];
    [self setStatusBarHidden:YES withAnimation:UIStatusBarAnimationFade];
}

// 隐藏状态栏 for IOS7
- (BOOL)prefersStatusBarHidden;
{
    return YES;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self lsqInitView];
    // 启动GPS
    [[TuSDKTKLocation shared] requireAuthorWithController:self];
    
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

- (void)lsqInitView
{
    CGFloat navButtonHeight = 64;
    
    CGRect rect = self.view.bounds;
    
    mTopLogo = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, rect.size.width, rect.size.height - navButtonHeight * 3)];
    mTopLogo.enabled = NO;
    mTopLogo.adjustsImageWhenDisabled = NO;
    mTopLogo.contentMode = UIViewContentModeCenter;
    [mTopLogo setBackgroundImage:[UIImage imageNamed:@"top_background.jpg"] forState:UIControlStateNormal];
    [mTopLogo setImage:[UIImage imageNamed:@"top_logo"] forState:UIControlStateNormal];
    [self.view addSubview:mTopLogo];
    
    // 导航按钮
    mCameraButton = [self buildEntryButton:@"component_camera"
                                      icon:@"icon_camera"
                                     frame:CGRectMake(0, [mTopLogo getBottomY], rect.size.width, navButtonHeight)];
    
    [mCameraButton setBackgroundImageColor:lsqRGB(255, 85, 52) forState:UIControlStateNormal];
    [mCameraButton setBackgroundImageColor:lsqRGBA(255, 85, 52, 0.8) forState:UIControlStateHighlighted];
    [self.view addSubview:mCameraButton];
    
    mEditorButton = [self buildEntryButton:@"component_editor"
                                      icon:@"icon_editor"
                                     frame:CGRectMake(0, [mCameraButton getBottomY], rect.size.width, navButtonHeight)];
    
    [mEditorButton setBackgroundImageColor:lsqRGB(230, 76, 46) forState:UIControlStateNormal];
    [mEditorButton setBackgroundImageColor:lsqRGBA(230, 76, 46, 0.8) forState:UIControlStateHighlighted];
    [self.view addSubview:mEditorButton];
    
    mComponentListButton = [self buildEntryButton:@"component_list"
                                             icon:@"icon_component_list"
                                            frame:CGRectMake(0, [mEditorButton getBottomY], rect.size.width, navButtonHeight)];
    [mComponentListButton setBackgroundImageColor:lsqRGB(204, 68, 41) forState:UIControlStateNormal];
    [mComponentListButton setBackgroundImageColor:lsqRGBA(204, 68, 41, 0.8) forState:UIControlStateHighlighted];
    [self.view addSubview:mComponentListButton];
}

- (UIButton *)buildEntryButton:(NSString *)localeKey icon:(NSString *)iconName frame:(CGRect)frame
{
    UIButton *btn = [[UIButton alloc] initWithFrame:frame];
    [btn setImage:[UIImage imageNamed:iconName] forState:UIControlStateNormal];
    [btn setTitle:NSLocalizedString(localeKey, @"") forState:UIControlStateNormal];
    [btn setTitleEdgeInsets:UIEdgeInsetsMake(0, 16, 0, 0)];
    [btn setAdjustsImageWhenHighlighted:NO];
    [btn setBackgroundColor:[UIColor blackColor]];
    [btn addTouchUpInsideTarget:self action:@selector(onEntryButtonClicked:)];
    return btn;
}

#pragma mark - click handler
- (void)onEntryButtonClicked:(UIButton *)btn
{
    if (btn == mCameraButton)
    {
        if (cameraComponentSample == nil)
        {
            cameraComponentSample = [CameraComponentSample sample];
        }
        [cameraComponentSample showSampleWithController:self];
    }
    else if(btn == mEditorButton)
    {
        if (editMultipleComponentSample == nil)
        {
            editMultipleComponentSample = [EditMultipleComponentSample sample];
        }
                                     
        [editMultipleComponentSample showSampleWithController:self];
    }
    else if(btn == mComponentListButton)
    {
        DemoComponentListController *controller = [[DemoComponentListController alloc] init];
        
        [self.navigationController pushViewController:controller animated:YES];
    }
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
@end