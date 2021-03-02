//
//  CameraMoreMenuView.m
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/18.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import "CameraMoreMenuView.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunguarded-availability"

@interface UIStackView (Select)

@property (nonatomic, assign) NSInteger selectedIndex;

@end

@implementation UIStackView (Select)

- (NSInteger)selectedIndex {
    NSInteger selectedIndex = -1;
    for (int i = 0; i < self.arrangedSubviews.count; i++) {
        UIControl *control = self.arrangedSubviews[i];
        if (control.selected) {
            selectedIndex = i;
            break;
        }
    }
    return selectedIndex;
}
- (void)setSelectedIndex:(NSInteger)selectedIndex {
    NSInteger count = self.arrangedSubviews.count;
    if (selectedIndex < 0 || selectedIndex >= count) return;
    for (int i = 0; i < count; i++) {
        UIControl *control = self.arrangedSubviews[i];
        if (control.selected) control.selected = NO;
        if (selectedIndex == i) {
            control.selected = YES;
        }
    }
}

@end

// 变声功能组索引
static const NSInteger kPitchRow = 4;

@interface CameraMoreMenuView ()

@property (nonatomic, weak) UIStackView *ratioStackView;
@property (nonatomic, weak) UIStackView *autoFocusStackView;
@property (nonatomic, weak) UIStackView *flashStackView;
@property (nonatomic, weak) UIStackView *pitchStackView;

@end

@implementation CameraMoreMenuView

- (void)commonInit {
    [super commonInit];
    self.title = NSLocalizedStringFromTable(@"lsq_camera_more", @"TuSDK", @"更多");
    CGFloat textOptionsSpacing = 27;
    if (CGRectGetWidth([UIScreen mainScreen].bounds) < 375) {
        textOptionsSpacing = 10;
    }
    
    __weak typeof(self) weakSelf = self;
    [self addCellWithTitle:NSLocalizedStringFromTable(@"lsq_camera_ratio", @"TuSDK", @"比例") optionsConfig:^(UIStackView *optionsStackView) {
        UIButton *ratioFullButton = [UIButton buttonWithType:UIButtonTypeCustom];
        [ratioFullButton setImage:[UIImage imageNamed:@"video_popup_ic_scale_full"] forState:UIControlStateNormal];
        [ratioFullButton setImage:[UIImage imageNamed:@"video_popup_ic_scale_full_selected"] forState:UIControlStateSelected];
        [optionsStackView addArrangedSubview:ratioFullButton];
        [ratioFullButton addTarget:weakSelf action:@selector(ratioButtonAction:) forControlEvents:UIControlEventTouchUpInside];
        ratioFullButton.selected = YES;
        
        UIButton *ratio3To4Button = [UIButton buttonWithType:UIButtonTypeCustom];
        [ratio3To4Button setImage:[UIImage imageNamed:@"video_popup_ic_scale_3-4"] forState:UIControlStateNormal];
        [ratio3To4Button setImage:[UIImage imageNamed:@"video_popup_ic_scale_3-4_selected"] forState:UIControlStateSelected];
        [optionsStackView addArrangedSubview:ratio3To4Button];
        [ratio3To4Button addTarget:weakSelf action:@selector(ratioButtonAction:) forControlEvents:UIControlEventTouchUpInside];
        
        UIButton *ratio1To1Button = [UIButton buttonWithType:UIButtonTypeCustom];
        [ratio1To1Button setImage:[UIImage imageNamed:@"video_popup_ic_scale_square"] forState:UIControlStateNormal];
        [ratio1To1Button setImage:[UIImage imageNamed:@"video_popup_ic_scale_square_selected"] forState:UIControlStateSelected];
        [optionsStackView addArrangedSubview:ratio1To1Button];
        [ratio1To1Button addTarget:weakSelf action:@selector(ratioButtonAction:) forControlEvents:UIControlEventTouchUpInside];
        
        optionsStackView.spacing = 8;
        weakSelf.ratioStackView = optionsStackView;
    }];
    [self addCellWithTitle:NSLocalizedStringFromTable(@"lsq_camera_autoFocus", @"TuSDK", @"自动对焦") optionsConfig:^(UIStackView *optionsStackView) {
        UIButton *onButton = [CameraMoreMenuView switchButtonWithTitle:NSLocalizedStringFromTable(@"lsq_camera_flash_on", @"TuSDK", @"开启")];
        [optionsStackView addArrangedSubview:onButton];
        onButton.selected = YES;
        [onButton addTarget:weakSelf action:@selector(autoFocusButtonAction:) forControlEvents:UIControlEventTouchUpInside];
        
        UIButton *offButton = [CameraMoreMenuView switchButtonWithTitle:NSLocalizedStringFromTable(@"lsq_camera_flash_off", @"TuSDK", @"关闭")];
        [optionsStackView addArrangedSubview:offButton];
        [offButton addTarget:weakSelf action:@selector(autoFocusButtonAction:) forControlEvents:UIControlEventTouchUpInside];
        
        optionsStackView.spacing = textOptionsSpacing;
        weakSelf.autoFocusStackView = optionsStackView;
    }];
    [self addCellWithTitle:NSLocalizedStringFromTable(@"lsq_camera_flash", @"TuSDK", @"闪光灯") optionsConfig:^(UIStackView *optionsStackView) {
        UIButton *onButton = [CameraMoreMenuView switchButtonWithTitle:NSLocalizedStringFromTable(@"lsq_camera_flash_on", @"TuSDK", @"开启")];
        [optionsStackView addArrangedSubview:onButton];
        [onButton addTarget:weakSelf action:@selector(flashButtonAction:) forControlEvents:UIControlEventTouchUpInside];
        
        UIButton *offButton = [CameraMoreMenuView switchButtonWithTitle:NSLocalizedStringFromTable(@"lsq_camera_flash_off", @"TuSDK", @"关闭")];
        offButton.selected = YES;
        [optionsStackView addArrangedSubview:offButton];
        [offButton addTarget:weakSelf action:@selector(flashButtonAction:) forControlEvents:UIControlEventTouchUpInside];
        
        optionsStackView.spacing = textOptionsSpacing;
        weakSelf.flashStackView = optionsStackView;
    }];
//    [self addCellWithTitle:NSLocalizedStringFromTable(@"tu_变声", @"VideoDemo", @"变声") optionsConfig:^(UIStackView *optionsStackView) {
//        for (int i = TuSDKSoundPitchNormal; i < 5; i++) {
//            UIButton *pitchButton = [CameraMoreMenuView switchButtonWithTitle:[CameraMoreMenuView descriptionWithTuSDKSoundPitchType:i]];
//            [optionsStackView addArrangedSubview:pitchButton];
//            [pitchButton addTarget:weakSelf action:@selector(pitchButtonAction:) forControlEvents:UIControlEventTouchUpInside];
//            if (i == TuSDKSoundPitchNormal) {
//                pitchButton.selected = YES;
//            }
//        }
//        optionsStackView.spacing = textOptionsSpacing;
//        weakSelf.pitchStackView = optionsStackView;
//    }];
    
    self.layer.masksToBounds = YES;
    self.layer.cornerRadius = 7.f;
}

/**
 配置界面文案显示

 @param pitchType 变声类型
 @return 对应变声类型的名称
 */
//+ (NSString *)descriptionWithTuSDKSoundPitchType:(lsqSoundPitch)pitchType {
//    switch (pitchType) {
//        case lsqSoundPitchNormal:{
//            return NSLocalizedStringFromTable(@"tu_正常", @"VideoDemo", @"正常");
//        } break;
//        case lsqSoundPitchMonster:{
//            return NSLocalizedStringFromTable(@"tu_怪兽", @"VideoDemo", @"怪兽");
//        } break;
//        case lsqSoundPitchUncle:{
//            return NSLocalizedStringFromTable(@"tu_大叔", @"VideoDemo", @"大叔");
//        } break;
//        case lsqSoundPitchGirl:{
//            return NSLocalizedStringFromTable(@"tu_女生", @"VideoDemo", @"女生");
//        } break;
//        case lsqSoundPitchLolita:{
//            return NSLocalizedStringFromTable(@"tu_萝莉", @"VideoDemo", @"萝莉");
//        } break;
//    }
//    return nil;
//}

/**
 设置按钮文字

 @param title 按钮文字
 @return 按钮
 */
+ (UIButton *)switchButtonWithTitle:(NSString *)title {
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.titleLabel.font = [UIFont systemFontOfSize:12];
    [button setTitle:title forState:UIControlStateNormal];
    [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [button setTitleColor:[UIColor colorWithRed:255.0f/255.0f green:204.0f/255.0f blue:0.0f/255.0f alpha:1.0f] forState:UIControlStateSelected];
    return button;
}

#pragma mark - property

- (BOOL)autoFocus {
    return _autoFocusStackView.selectedIndex == 0;
}
- (void)setAutoFocus:(BOOL)autoFocus {
    NSInteger selectIndex = autoFocus ? 0 : 1;
    _autoFocusStackView.selectedIndex = selectIndex;
    [self autoFocusButtonAction:_autoFocusStackView.arrangedSubviews[selectIndex]];
}

- (BOOL)enableFlash {
    return _flashStackView.selectedIndex == 0;
}
- (void)setEnableFlash:(BOOL)enableFlash {
    NSInteger selectIndex = enableFlash ? 0 : 1;
    _flashStackView.selectedIndex = selectIndex;
    [self flashButtonAction:_flashStackView.arrangedSubviews[selectIndex]];
}

- (BOOL)disableFlashSwitching {
    return !_flashStackView.userInteractionEnabled;
}
- (void)setDisableFlashSwitching:(BOOL)disableFlashSwitching {
    _flashStackView.userInteractionEnabled = !disableFlashSwitching;
}

- (BOOL)disableRatioSwitching {
    return !_ratioStackView.userInteractionEnabled;
}
- (void)setDisableRatioSwitching:(BOOL)disableRatioSwitching {
    _ratioStackView.userInteractionEnabled = !disableRatioSwitching;
}

- (BOOL)pitchHidden {
    return [self isRowHidden:kPitchRow];
}
- (void)setPitchHidden:(BOOL)pitchHidden {
    if (pitchHidden) {
        [self addHiddenRow:kPitchRow];
    } else {
        [self removeHiddenRow:kPitchRow];
    }
}

#pragma mark - action

/**
 比例切换

 @param sender 比例切换按钮
 */
- (void)ratioButtonAction:(UIButton *)sender {
    for (UIButton *button in _ratioStackView.arrangedSubviews) {
        if (button.selected) button.selected = NO;
    }
    sender.selected = YES;
    CGFloat ratio = 0;
    NSInteger index = [_ratioStackView.arrangedSubviews indexOfObject:sender];
    switch (index) {
        case 0:{
            ratio = .0;
        } break;
        case 1:{
            ratio = 3 / 4.0;
        } break;
        case 2:{
            ratio = 1.0;
        } break;
    }
    if ([self.delegate respondsToSelector:@selector(moreMenu:didSelectedRatio:)]) {
        [self.delegate moreMenu:self didSelectedRatio:ratio];
    }
}

/**
 自动聚焦

 @param sender 自动聚焦按钮
 */
- (void)autoFocusButtonAction:(UIButton *)sender {
    for (UIButton *button in _autoFocusStackView.arrangedSubviews) {
        if (button.selected) button.selected = NO;
    }
    sender.selected = YES;
    
    NSInteger index = [_autoFocusStackView.arrangedSubviews indexOfObject:sender];
    BOOL autoFocus = index == 0;
    if ([self.delegate respondsToSelector:@selector(moreMenu:didSwitchAutoFocus:)]) {
        [self.delegate moreMenu:self didSwitchAutoFocus:autoFocus];
    }
}

/**
 闪光灯

 @param sender 闪光灯按钮
 */
- (void)flashButtonAction:(UIButton *)sender {
    for (UIButton *button in _flashStackView.arrangedSubviews) {
        if (button.selected) button.selected = NO;
    }
    sender.selected = YES;
    
    NSInteger index = [_flashStackView.arrangedSubviews indexOfObject:sender];
    BOOL enableFlash = index == 0;
    if ([self.delegate respondsToSelector:@selector(moreMenu:didSwitchFlashMode:)]) {
        [self.delegate moreMenu:self didSwitchFlashMode:enableFlash];
    }
}

/**
 变声功能

 @param sender 变声功能按钮
 */
//- (void)pitchButtonAction:(UIButton *)sender {
//    for (UIButton *button in _pitchStackView.arrangedSubviews) {
//        if (button.selected) button.selected = NO;
//    }
//    sender.selected = YES;
//
//    NSInteger index = [_pitchStackView.arrangedSubviews indexOfObject:sender];
//    if ([self.delegate respondsToSelector:@selector(moreMenu:didSwitchPitchType:)]) {
//        [self.delegate moreMenu:self didSwitchPitchType:index];
//    }
//}

@end

#pragma clang diagnostic pop
