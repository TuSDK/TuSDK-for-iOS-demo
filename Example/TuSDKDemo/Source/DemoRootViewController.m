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
#import "GeeV2Sample.h"
#import "EditMultipleComponentSample.h"
#import "DemoComponentListController.h"

#pragma mark - DemoRootViewController
@interface DemoRootViewController ()
{
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
    //[[TuLocation shared] requireAuthorWithController:self];
    
    /**
     * ！！！！！！！！！！！！！！！！！！！！！！！！！特别提示信息要长！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
     * 关于TuSDK体积（SDK编译后仅为1.9MB）：
     * 1,如果您不需要使用本地贴纸功能，或仅需要使用在线贴纸功能，请删除/app/TuSDK.bundle/stickers文件夹
     * 2,如果您仅需要几款滤镜，您可以删除/app/TuSDK.bundle/textures下的*.gsce文件
     * 3,如果您不需要使用滤镜功能，请删除/app/TuSDK.bundle/textures文件夹
     * 4,TuSDK在线管理功能请访问：https://tutucloud.com/
     *
     * IOS编译Framework知识：
     * Framework包含armv7,arm64等不同CPU的编译结果的集合；
     * 其中每种CPU编译结果还包含Debug以及Realse两种子结果；
     * 当集成某个Framework（假如TuSDK.Framework物理文件大小为30MB），编译成APP发布后，实际大小约为不到2MB
     *
     * 开发文档:https://tutucloud.com/docs/ios/api-docs
     */
    
    // 异步方式初始化滤镜管理器 (注意：如果需要一开启应用马上执行SDK组件，需要做该检测，否则可以忽略检测)
    // 需要等待滤镜管理器初始化完成，才能使用所有功能
    [self showHubWithStatus:LSQString(@"lsq_initing", @"正在初始化")];
      
    NSLog(@"TuSDK.framework 的版本号 : %@",lsqPulseSDKVersion);
    NSLog(@"TuSDKGeeV1.framework 的版本号 : %@",lsqGeeVersion);
    NSLog(@"TuSDKGeeV2.framework 的版本号 : %@",lsqGeeV2Version);
    
    [TuThread initWithStart:^id{
        while (![TUCCore checkResourceLoaded]){}
        return nil;
    } completed:^(id result) {
        [self showHubSuccessWithStatus:LSQString(@"lsq_inited", @"初始化完成")];
        // 发布时注释下面代码
//         [TUCCore logAuthors];
    }];
}

- (void)lsqInitView
{
    CGRect rect = self.view.bounds;
    
    // 背景图
    UIImageView *backgroundImage = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, rect.size.width,rect.size.height)];
    backgroundImage.center = self.view.center;
    if ([UIDevice lsqIsDeviceiPhoneX])
    { // iPhone X
        backgroundImage.image = [UIImage imageNamed:@"iphonex_homepage_bg"];
    }else{
        backgroundImage.image = [UIImage imageNamed:@"homepage_bg"];
    }
    backgroundImage.contentMode = UIViewContentModeScaleAspectFill;
    backgroundImage.clipsToBounds = YES;
    backgroundImage.userInteractionEnabled = YES;
    [self.view addSubview:backgroundImage];
    
    CGFloat btnInterval = 8;
    CGFloat btnHeight = 68;
    CGFloat btnWidth = backgroundImage.lsqGetSizeWidth - 32;
    CGFloat centerY = self.view.lsqGetSizeHeight - 82 - 2.5*btnHeight - 2*btnInterval;
    
    // 相机
    UIButton *cameraButton = [[UIButton alloc]initWithFrame:CGRectMake(0, 0, btnWidth, btnHeight)];
    cameraButton.center = CGPointMake(self.view.lsqGetSizeWidth/2 , centerY);
    [cameraButton setImage:[UIImage imageNamed:@"homepage_button_normal"] forState:UIControlStateNormal];
    [cameraButton addTouchUpInsideTarget:self action:@selector(openEffectCamera)];
    cameraButton.adjustsImageWhenHighlighted = NO;
    [self.view addSubview:cameraButton];
    
    UIImageView *cameraButtonIcon = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 22, 22)];
    cameraButtonIcon.center = CGPointMake(36, btnHeight/2);
    cameraButtonIcon.image = [UIImage imageNamed:@"homepage_icon_camera"];
    cameraButtonIcon.contentMode = UIViewContentModeScaleAspectFit;
    [cameraButton addSubview:cameraButtonIcon];
    
    UIImageView *cameraButtonLabel = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 20, 20)];
    cameraButtonLabel.center = CGPointMake(btnWidth - 24, btnHeight/2);
    cameraButtonLabel.image = [UIImage imageNamed:@"homepage_icon_next"];
    [cameraButton addSubview:cameraButtonLabel];
    
    UILabel *cameraButtonText = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, 150, 30)];
    cameraButtonText.center = CGPointMake(68+75, btnHeight/2);
    cameraButtonText.text = NSLocalizedString(@"demo_component_camera", @"特效相机");
    cameraButtonText.textColor = [UIColor lsqClorWithHex:@"#553213"];
    cameraButtonText.font = [UIFont systemFontOfSize:19];
    [cameraButton addSubview:cameraButtonText];
    
    centerY = centerY + btnHeight + btnInterval;
    
    // 图片编辑
    UIButton *editorButton = [[UIButton alloc]initWithFrame:CGRectMake(0, 0, btnWidth, btnHeight)];
    editorButton.center = CGPointMake(self.view.lsqGetSizeWidth/2, centerY);
    [editorButton setImage:[UIImage imageNamed:@"homepage_button_normal"] forState:UIControlStateNormal];
    editorButton.adjustsImageWhenHighlighted = NO;
    [editorButton addTouchUpInsideTarget:self action:@selector(openImageEditor)];
    editorButton.contentMode = UIViewContentModeScaleAspectFit;
    [self.view addSubview:editorButton];
    
    UIImageView *editorButtonIcon = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 22, 22)];
    editorButtonIcon.center = CGPointMake(36, btnHeight/2);
    editorButtonIcon.image = [UIImage imageNamed:@"homepage_icon_beauty"];
    [editorButton addSubview:editorButtonIcon];
    
    UIImageView *editorButtonLabel = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 20, 20)];
    editorButtonLabel.center = CGPointMake(btnWidth - 24, btnHeight/2);
    editorButtonLabel.image = [UIImage imageNamed:@"homepage_icon_next"];
    [editorButton addSubview:editorButtonLabel];
    
    UILabel *editorButtonText = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, 150, 30)];
    editorButtonText.center = CGPointMake(68+75, btnHeight/2);
    editorButtonText.text = NSLocalizedString(@"demo_component_editor" , @"图片编辑");
    editorButtonText.textColor = [UIColor lsqClorWithHex:@"#553213"];
    editorButtonText.font = [UIFont systemFontOfSize:19];
    [editorButton addSubview:editorButtonText];
    
    centerY = centerY + btnHeight + btnInterval;
    
    // 功能列表
    UIButton *componentListButton = [[UIButton alloc]initWithFrame:CGRectMake(0, 0, btnWidth, btnHeight)];
    componentListButton.center = CGPointMake(self.view.lsqGetSizeWidth/2, centerY);
    [componentListButton setImage:[UIImage imageNamed:@"homepage_button_normal"] forState:UIControlStateNormal];
    componentListButton.adjustsImageWhenHighlighted = NO;
    [componentListButton addTouchUpInsideTarget: self action:@selector(openComponentList)];
    componentListButton.contentMode = UIViewContentModeScaleAspectFit;
    [self.view addSubview:componentListButton];
    
    UIImageView *ComponentListButtonIcon = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 22, 22)];
    ComponentListButtonIcon.center = CGPointMake(36, btnHeight/2);
    ComponentListButtonIcon.image = [UIImage imageNamed:@"homepage_icon_tools"];
    [componentListButton addSubview:ComponentListButtonIcon];
    
    UIImageView *ComponentListButtonLabel = [[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 20, 20)];
    ComponentListButtonLabel.center = CGPointMake(btnWidth - 24, btnHeight/2);
    ComponentListButtonLabel.image = [UIImage imageNamed:@"homepage_icon_next"];
    [componentListButton addSubview:ComponentListButtonLabel];
    
    UILabel *ComponentListButtonText = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, 150, 30)];
    ComponentListButtonText.center = CGPointMake(68+75, btnHeight/2);
    ComponentListButtonText.text = NSLocalizedString(@"demo_component_list" , @"功能列表");
    ComponentListButtonText.textColor = [UIColor lsqClorWithHex:@"#553213"];
    ComponentListButtonText.font = [UIFont systemFontOfSize:19];
    [componentListButton addSubview:ComponentListButtonText];
    
    centerY = centerY + btnHeight + btnInterval;
    UILabel *icpInfoText = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, self.view.lsqGetSizeWidth, btnHeight)];
    icpInfoText.text = @"浙ICP备14040447号-2A";
    icpInfoText.textAlignment = NSTextAlignmentCenter;
    icpInfoText.center = CGPointMake(self.view.lsqGetSizeWidth/2, centerY);
    icpInfoText.font = [UIFont systemFontOfSize:13];
    icpInfoText.textColor = [UIColor lsqClorWithHex:@"#553213"];
    [self.view addSubview:icpInfoText];
}

#pragma mark - 点击事件
-(void)openEffectCamera;
{
    if (cameraComponentSample == nil)
    {
        cameraComponentSample = [CameraComponentSample sample];
    }
    [cameraComponentSample showSampleWithController:self];
}

-(void)openImageEditor;
{
    if (editMultipleComponentSample == nil)
    {
        editMultipleComponentSample = [EditMultipleComponentSample sample];
    }
    [editMultipleComponentSample showSampleWithController:self];
}

-(void)openComponentList;
{
    DemoComponentListController *controller = [[DemoComponentListController alloc] init];
    
    [self.navigationController pushViewController:controller animated:YES];
}
@end
