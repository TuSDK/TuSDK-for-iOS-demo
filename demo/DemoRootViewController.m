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
    _demos = @[@"快速自定义相机", @"头像设置组件", @"头像设置自定义"];

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

@interface DemoRootViewController ()<DemoChooseDelegate>
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

    self.title = @"TuSDK Demo";
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
            // 快速自定义相机
            [self simpleCustomHandler];
            break;
            case 1:
            // 头像设置组件
            [self avatarComponentHandler];
            break;
            case 2:
            // 头像设置自定义
            [self avatarCustomHandler];
            break;
        default:
            break;
    }
}

#pragma mark - simpleCustomHandler
/**
 *  快速自定义相机
 */
- (void)simpleCustomHandler;
{
    [self presentViewController:[[SimpleCameraViewController alloc] init] animated:YES completion:nil];
}

#pragma mark - avatarComponentHandler
/**
 *  头像设置组件
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

#pragma mark - avatarCustomHandler
/**
 *  头像设置自定义
 */
- (void) avatarCustomHandler;
{

}
@end
