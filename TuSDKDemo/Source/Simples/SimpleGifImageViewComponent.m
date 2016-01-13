//
//  SimpleGifImageViewComponent.h
//  TuSDKDemo
//
//  Created by Yanlin on 1/7/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import "SimpleGifImageViewComponent.h"

@interface GifViewController () <TuSDKPFGifViewDelegate>
{
    // 返回按钮
    UIButton *_backButton;
    // TuSDKICGifView对象
    TuSDKICGifView *_gifView;
}

@end

#pragma mark - GifViewController
/**
 *  Gif视图控制器
 */
@implementation GifViewController

// 隐藏状态栏 for IOS7
- (BOOL)prefersStatusBarHidden;
{
    return YES;
}

-(void)loadView
{
    [super loadView];
    // 设置全屏 隐藏状态栏 for IOS6
    self.wantsFullScreenLayout = YES;
    [self setNavigationBarHidden:YES animated:NO];
    [self setStatusBarHidden:YES withAnimation:UIStatusBarAnimationNone];}

- (void)viewDidLoad;
{
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    // 初始化GifImage
    TuSDKCPGifImage *image = [TuSDKCPGifImage imageNamed:@"sample_gif_editor"];
    
    // 这里可以通过 image.size 获取Gif文件显示尺寸
    _gifView = [[TuSDKICGifView alloc] initWithFrame:CGRectMake([self.view getCenterX:image.size.width], [self.view getCenterY:image.size.height], image.size.width, image.size.height)];
    /**
     *  自动播放动画 (默认: true)
     */
    _gifView.autoPlay = YES;
    _gifView.image = image;
    
    // 其他初始化方式
    // _gifView = [[TuSDKICGifView alloc] initWithImage:image];

    _gifView.userInteractionEnabled = YES;
    // 设置代理，侦听播放事件
    _gifView.delegate = self;
    
    // 添加手势侦听
    UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc] init];
    [gesture addTarget:self action:@selector(onTapHandle:)];
    [_gifView addGestureRecognizer:gesture];
    
    [self.view addSubview:_gifView];
    
    // 按钮
    _backButton = [UIButton buttonWithFrame:CGRectMake(0, 0, 70, 70)
                        imageLSQBundleNamed:@"style_default_edit_button_cancel_bg"];
    [_backButton addTouchUpInsideTarget:self action:@selector(onBackButtonClick)];
    [self.view addSubview:_backButton];
}

/**
 *  点击返回按钮
 */
- (void)onBackButtonClick;
{
    [self popViewControllerAnimated:YES];
}

/**
 *  图片Tap手势处理
 *
 *  @param sender
 */
- (void)onTapHandle:(id)sender;
{
    if ([_gifView isAnimating])
    {
        [_gifView stopAnimating];
    }
    else
    {
        [_gifView startAnimating];
    }
}

#pragma mark - TuSDKPFGifViewDelegate

/**
 *  每次Gif动画结束时调用
 *
 *  @param gifView   TuSDKICGifView对象
 *  @param currCount 当前已播放次数
 *  @param loopCount Gif文件指定的动画循环次数，0表示无限循环
 */
- (void)onGifAnimationComplete:(TuSDKICGifView *)gifView currentLoopCount:(NSUInteger)currCount totalLoopCount:(NSUInteger)loopCount;
{
    NSLog(@"Gif 已播放次数: %lu，设置的总播放次数: %lu", (unsigned long)currCount, (unsigned long)loopCount);
}

@end

#pragma mark - SimpleGifImageViewComponent

/**
 *  Gif组件范例
 */
@implementation SimpleGifImageViewComponent

- (instancetype)init;
{
    self = [super initWithGroupId:1 title:NSLocalizedString(@"simple_GifComponent", @"Gif组件")];
    return self;
}

/**
 *  显示范例
 *
 *  @param controller 启动控制器
 */
- (void)showSimpleWithController:(UIViewController *)controller;
{
    GifViewController *gifController = [[GifViewController alloc] init];
    
    [controller.navigationController pushViewController:gifController animated:YES];
}

@end
