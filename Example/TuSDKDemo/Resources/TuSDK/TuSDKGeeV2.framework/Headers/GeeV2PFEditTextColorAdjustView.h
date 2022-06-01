//
//  GeeV2PFEditTextColorAdjustView.h
//  TuSDKGeeV2
//
//  Created by 刘鹏程 on 2022/5/30.
//  Copyright © 2022 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"
NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    GeeV2PFEditTextColorType_TextColor = 101,
    GeeV2PFEditTextColorType_BackgroudColor,
    GeeV2PFEditTextColorType_StrokeColor,
} GeeV2PFEditTextColorType;

#pragma mark - GeeV2PFEditTextColorAdjustDelegate

/**
 颜色选择View代理
 */
@protocol GeeV2PFEditTextColorAdjustDelegate <NSObject>

@optional
/**
 选中某一颜色

 @param color 选中的颜色对象
 */
- (void)onSelectColorWith:(UIColor *)color styleType:(GeeV2PFEditTextColorType)styleType;

@end

#pragma mark - GeeV2PFEditTextColorAdjustView
@interface GeeV2PFEditTextColorAdjustView : UIView
// 代理对象
@property (nonatomic, weak) id<GeeV2PFEditTextColorAdjustDelegate> colorDelegate;
// 颜色数组
@property (nonatomic, strong) NSArray<NSString *> *hexColors;

// 边距设置 默认 (10,20,10,20)
@property (nonatomic, assign) UIEdgeInsets edgeInsets;

// 是否默认第一个为 clearColor
@property (nonatomic, assign) BOOL defaultClearColor;

// 颜色类别
@property (nonatomic, strong) NSArray<NSNumber *> *styleArr;

// 类别选中时的显示颜色
@property (nonatomic, strong) UIColor *styleSelectedColor;

// 类别非选中时的显示颜色
@property (nonatomic, strong) UIColor *styleNormalColor;

@end

NS_ASSUME_NONNULL_END
