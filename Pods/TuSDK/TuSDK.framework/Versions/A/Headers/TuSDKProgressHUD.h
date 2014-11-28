//
//  TuSDKProgressHUD.h
//  TuSDK
//
//  Created by Sam Vermette on 27.03.11.
//  Copyright 2011 Sam Vermette. All rights reserved.
//
//  https://github.com/samvermette/SVProgressHUD
//

#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>

extern NSString * const TuSDKProgressHUDDidReceiveTouchEventNotification;
extern NSString * const TuSDKProgressHUDWillDisappearNotification;
extern NSString * const TuSDKProgressHUDDidDisappearNotification;
extern NSString * const TuSDKProgressHUDWillAppearNotification;
extern NSString * const TuSDKProgressHUDDidAppearNotification;

extern NSString * const TuSDKProgressHUDStatusUserInfoKey;

typedef NS_ENUM(NSUInteger, TuSDKProgressHUDMaskType) {
    TuSDKProgressHUDMaskTypeNone = 1, // allow user interactions while HUD is displayed
    TuSDKProgressHUDMaskTypeClear, // don't allow
    TuSDKProgressHUDMaskTypeBlack, // don't allow and dim the UI in the back of the HUD
    TuSDKProgressHUDMaskTypeGradient // don't allow and dim the UI with a a-la-alert-view bg gradient
};

@interface TuSDKProgressHUD : UIView
#pragma mark - Customization

+ (void)setBackgroundColor:(UIColor*)color; // default is [UIColor whiteColor]
+ (void)setForegroundColor:(UIColor*)color; // default is [UIColor blackColor]
+ (void)setRingThickness:(CGFloat)width; // default is 4 pt
+ (void)setFont:(UIFont*)font; // default is [UIFont preferredFontForTextStyle:UIFontTextStyleSubheadline]
+ (void)setSuccessImage:(UIImage*)image; // default is bundled success image from Glyphish
+ (void)setErrorImage:(UIImage*)image; // default is bundled error image from Glyphish

#pragma mark - Show Methods

+ (void)show;
+ (void)showWithMaskType:(TuSDKProgressHUDMaskType)maskType;
+ (void)showWithStatus:(NSString*)status;
+ (void)showWithStatus:(NSString*)status maskType:(TuSDKProgressHUDMaskType)maskType;

+ (void)showProgress:(float)progress;
+ (void)showProgress:(float)progress status:(NSString*)status;
+ (void)showProgress:(float)progress status:(NSString*)status maskType:(TuSDKProgressHUDMaskType)maskType;

+ (void)setStatus:(NSString*)string; // change the HUD loading status while it's showing

// stops the activity indicator, shows a glyph + status, and dismisses HUD 1s later
+ (void)showSuccessWithStatus:(NSString*)string;
+ (void)showErrorWithStatus:(NSString *)string;
+ (void)showImage:(UIImage*)image status:(NSString*)status; // use 28x28 white pngs

+ (void)setOffsetFromCenter:(UIOffset)offset;
+ (void)resetOffsetFromCenter;

+ (void)popActivity;
+ (void)dismiss;

+ (BOOL)isVisible;
@end

@interface SVIndefiniteAnimatedView : UIView

@property (nonatomic, assign) CGFloat strokeThickness;
@property (nonatomic, assign) CGFloat radius;
@property (nonatomic, strong) UIColor *strokeColor;

@end

/**
 *  TuSDK 扩展
 */
@interface TuSDKProgressHUD(TuSDKExtend)
/**
 *  在主线程中显示信息
 *
 *  @param status 信息
 */
+ (void)showMainThreadWithStatus:(NSString*)status;

/**
 *  在主线程中显示成功信息
 *
 *  @param string 信息
 */
+ (void)showMainThreadSuccessWithStatus:(NSString*)string;

/**
 *  在主线程中显示错误信息
 *
 *  @param string 信息
 */
+ (void)showMainThreadErrorWithStatus:(NSString *)string;
@end
