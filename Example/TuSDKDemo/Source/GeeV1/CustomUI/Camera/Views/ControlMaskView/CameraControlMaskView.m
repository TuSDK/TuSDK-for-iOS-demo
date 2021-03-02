//
//  CameraControlMaskView.m
//  TuSDKDemo
//
//  Created by 刘鹏程 on 2020/6/10.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import "CameraControlMaskView.h"
#import "TuSDKFramework.h"
#import "RecordButton.h"

// 动画时长
static const NSTimeInterval kAnimationDuration = 0.25;

@interface CameraControlMaskView()
<
    CameraMoreMenuViewDelegate,
    UIGestureRecognizerDelegate,
    CameraFilterPanelDelegate,
    CameraFilterPanelDataSource
>

/**
 相机顶部配置栏目
 */
@property (nonatomic, strong) UIStackView *cameraTopPanelView;

/**
 阻止 tap 手势响应的视图
 */
@property (nonatomic, strong) NSArray *blockTapViews;

/**
 底部视图
 */
@property (nonatomic, strong) NSArray *bottomViews;

/**
 弱引用记录添加的代理
 */
@property (nonatomic, strong) NSHashTable *delegates;

/**
 当前的顶部面板
 */
@property (nonatomic, weak) UIView<OverlayViewProtocol> *currentTopPanelView;

//拍照按钮
@property (nonatomic, strong) RecordButton *captureButton;

//滤镜
@property (nonatomic, strong) UIButton *filterButton;
//贴纸
@property (nonatomic, strong) UIButton *stickerButton;

//相机底部配置视图
@property (nonatomic, strong) UIView *cameraBottomPanelView;


@end

@implementation CameraControlMaskView

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        [self initWithSubViews];
    }
    return self;
}

- (void)initWithSubViews
{
    CGFloat top = 0;
    if ([UIDevice lsqIsDeviceiPhoneX]) { // iPhone X
        top = lsq_STATES_BAR_HEIGHT;
    }
    
    static CGFloat kTopBarHeight = 64.0;
    CGFloat kBottomBarHeight = 80.f;
    
    //相机顶部配置栏目
    _cameraTopPanelView = [[UIStackView alloc]initWithFrame:CGRectMake(0, top, lsqScreenWidth, kTopBarHeight)];
    _cameraTopPanelView.axis = UILayoutConstraintAxisHorizontal;
    _cameraTopPanelView.distribution = UIStackViewDistributionFillEqually;
    _cameraTopPanelView.spacing = 10;
    _cameraTopPanelView.alignment = UIStackViewAlignmentFill;
    [self addSubview:_cameraTopPanelView];
    
    //返回按钮
    UIButton *backButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [backButton setImage:[UIImage imageNamed:@"video_nav_ic_close"] forState:0];
    [backButton addTouchUpInsideTarget:self action:@selector(onWindowExit:)];
    [_cameraTopPanelView addArrangedSubview:backButton];
    
    //切换摄像头
    UIButton *switchCameraButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [switchCameraButton setImage:[UIImage imageNamed:@"video_nav_ic_turn"] forState:0];
    [switchCameraButton addTouchUpInsideTarget:self action:@selector(onSwitchCamera:)];
    [_cameraTopPanelView addArrangedSubview:switchCameraButton];
    
    //美肤按钮
    UIButton *beautyButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [beautyButton setImage:[UIImage imageNamed:@"video_nav_ic_beauty"] forState:0];
    [_cameraTopPanelView addArrangedSubview:beautyButton];
    
    //更多按钮
    UIButton *moreButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [moreButton setImage:[UIImage imageNamed:@"video_nav_ic_more"] forState:0];
    [moreButton addTouchUpInsideTarget:self action:@selector(moreButtonAction:)];
    [_cameraTopPanelView addArrangedSubview:moreButton];
    self.moreButton = moreButton;
    
    _delegates = [NSHashTable hashTableWithOptions:NSPointerFunctionsWeakMemory];
    
    
    //相机底部配置栏目
    self.cameraBottomPanelView = [UIView initWithFrame:CGRectMake(0, lsqScreenHeight - kBottomBarHeight - top, lsqScreenWidth, kBottomBarHeight)];
    self.cameraBottomPanelView.userInteractionEnabled = YES;
    [self addSubview:self.cameraBottomPanelView];
    
    self.captureButton = [RecordButton initWithFrame:CGRectMake((lsqScreenWidth - 72) * 0.5, (kBottomBarHeight - 72) * 0.5, 72, 72)];
    [self.captureButton switchStyle:RecordButtonStylePhoto];
    [self.captureButton addTouchUpInsideTarget:self action:@selector(onCapturePhoto:)];
    [_cameraBottomPanelView addSubview:self.captureButton];
    
    //滤镜视图
    self.filterButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.filterButton setImage:[UIImage imageNamed:@"video_ic_filter"] forState:0];
    [self.filterButton sizeToFit];
    self.filterButton.center = CGPointMake(lsqScreenWidth * 0.75 + 72 * 0.25, self.captureButton.center.y);
    [self.filterButton addTouchUpInsideTarget:self action:@selector(filterButtonAction:)];
    [_cameraBottomPanelView addSubview:self.filterButton];
    
    //贴纸视图
    self.stickerButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.stickerButton setImage:[UIImage imageNamed:@"video_ic_sticker"] forState:0];
    [self.stickerButton sizeToFit];
    self.stickerButton.center = CGPointMake((lsqScreenWidth - 72) * 0.25, self.captureButton.center.y);
    [_cameraBottomPanelView addSubview:self.stickerButton];
    
    
    [self configEffectsView];
}

- (void)configEffectsView
{
    //更多视图
    _moreMenuView = [[CameraMoreMenuView alloc]initWithFrame:CGRectZero];
    _moreMenuView.sender = self.moreButton;
    _moreMenuView.alpha = 0;
    _moreMenuView.delegate = self;
     [self addSubview:_moreMenuView];
    
    //滤镜视图
    _filterPanelView = [[CameraFilterPanelView alloc] initWithFrame:CGRectZero];
    _filterPanelView.alpha = 0;
    _filterPanelView.sender = _filterButton;
    _filterPanelView.delegate = self;
    _filterPanelView.dataSource = self;
    [self addSubview:_filterPanelView];
    
    _blockTapViews = @[_moreMenuView, _filterPanelView];
}


- (void)layoutSubviews
{
    [super layoutSubviews];
    
    CGSize size = self.bounds.size;
    CGRect safeBounds = self.bounds;
    UIEdgeInsets safeAreaInsets = UIEdgeInsetsZero;
    if (@available(iOS 11.0, *)) {
        safeAreaInsets = self.safeAreaInsets;
        safeBounds = UIEdgeInsetsInsetRect(safeBounds, safeAreaInsets);
    }
    
    // 初始化折叠功能菜单视图
    const CGFloat moreMenuX = 10;
    _moreMenuView.frame = CGRectMake(CGRectGetMinX(safeBounds) + moreMenuX, CGRectGetMinY(safeBounds) + 54, CGRectGetWidth(safeBounds) - moreMenuX * 2, _moreMenuView.intrinsicContentSize.height);
    
    // 初始化滤镜视图
    const CGFloat filterPanelHeight = 276 + safeAreaInsets.bottom;
    _filterPanelView.frame = CGRectMake(0, size.height - filterPanelHeight, size.width, filterPanelHeight);
}

#pragma mark - buttonAction
/**
 返回按钮响应
 */
- (void)onWindowExit:(UIButton *)sender
{
    for (id<CameraControlMaskViewDelegate> delegate in _delegates) {
        if ([delegate respondsToSelector:@selector(onClickButtonCompletion:)]) {
            [delegate onClickButtonCompletion:lsqCameraHandleTypeBack];
        }
    }
}
/**
 切换摄像头响应
 */
- (void)onSwitchCamera:(UIButton *)sender
{
    for (id<CameraControlMaskViewDelegate> delegate in _delegates) {
        if ([delegate respondsToSelector:@selector(onClickButtonCompletion:)]) {
            [delegate onClickButtonCompletion:lsqCameraHandleTypeSwitchCamera];
        }
    }
}
/**
 更多按钮响应
 */
- (void)moreButtonAction:(UIButton *)sender
{
    self.currentTopPanelView = _moreMenuView.alpha == 1 ? nil : _moreMenuView;
}

/**
 拍照按钮响应
 */
- (void)onCapturePhoto:(UIButton *)sender
{
    for (id<CameraControlMaskViewDelegate> delegate in _delegates) {
        if ([delegate respondsToSelector:@selector(onClickButtonCompletion:)]) {
            [delegate onClickButtonCompletion:lsqCameraHandleTypeTakePhoto];
        }
    }
}

/**
 滤镜按钮响应
 */
- (void)filterButtonAction:(UIButton *)sender
{
    self.filterPanelView.alpha = 1;
}

#pragma mark - public

- (void)addDelegate:(id<CameraControlMaskViewDelegate>)delegate {
    if ([_delegates containsObject:delegate]) return;
    [_delegates addObject:delegate];
}

#pragma mark- property
- (void)setCurrentTopPanelView:(UIView<OverlayViewProtocol> *)currentTopPanelView
{
    [self setTopPanel:_currentTopPanelView hidden:YES];
    _currentTopPanelView = currentTopPanelView;
    if (!_currentTopPanelView) return;
    
    [self setTopPanel:currentTopPanelView hidden:NO];
}


#pragma mark - UIGestureRecognizerDelegate

- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldReceiveTouch:(UITouch *)touch {
    for (UIView *view in _blockTapViews) {
        if ([touch.view isDescendantOfView:view]) {
            return NO;
        }
    }
    return YES;
}

#pragma mark - touches

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    if (self.userInteractionEnabled == NO || self.hidden == YES || self.alpha <= 0.01 || ![self pointInside:point withEvent:event]) return nil;
    UIView *hitView = [super hitTest:point withEvent:event];
    // 响应子视图
    if (hitView != self) {
        return hitView;
    }
    // 若有叠层，则由自身（tap 手势）响应
    if (_currentTopPanelView || _filterPanelView) {
        return self;
    }
    return nil;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    if (_currentTopPanelView) {
        [UIView animateWithDuration:kAnimationDuration animations:^{
            _currentTopPanelView.alpha = 0;
            _currentTopPanelView = nil;
        }];
    }
    if (_filterPanelView) {
        [UIView animateWithDuration:kAnimationDuration animations:^{
            _filterPanelView.alpha = 0;
        }];
    }
}

/**
 在页面上方出现/隐藏给定面板

 @param panel 显示视图
 @param hidden 视图显隐状态
 */
- (void)setTopPanel:(UIView *)panel hidden:(BOOL)hidden {
    [self setPanel:panel hidden:hidden fromTop:YES];
}

/**
 设置视图显示位置和状态

 @param panel 显示视图
 @param hidden 视图显隐状态
 @param fromTop 距离
 */
- (void)setPanel:(UIView *)panel hidden:(BOOL)hidden fromTop:(BOOL)fromTop {
    if ((panel.alpha == 0.0) == hidden) return;
    
    CGFloat multiplier = fromTop ? 1.0 : -1.0;
    CGPoint panelCenter = panel.center;
    
    if (hidden) {
        [UIView setAnimationCurve:UIViewAnimationCurveEaseInOut];
        [UIView animateWithDuration:kAnimationDuration animations:^{
            panel.alpha = 0;
            panel.center = CGPointMake(panelCenter.x, panelCenter.y + 44);
        } completion:^(BOOL finished) {
            panel.center = panelCenter;
            [panel removeFromSuperview];
        }];
    } else {
        [self addSubview:panel];
        panel.center = CGPointMake(panelCenter.x, panelCenter.y - 44 * multiplier);
        [UIView setAnimationCurve:UIViewAnimationCurveEaseInOut];
        [UIView animateWithDuration:kAnimationDuration animations:^{
            panel.alpha = 1;
            panel.center = panelCenter;
        }];
    }
}

@end
