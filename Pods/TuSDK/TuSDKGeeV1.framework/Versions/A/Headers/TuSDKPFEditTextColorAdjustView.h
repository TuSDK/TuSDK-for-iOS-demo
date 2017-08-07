//
//  TuSDKPFEditTextColorAdjustView.h
//  TuSDKGeeV1
//
//  Created by wen on 27/07/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"

#pragma mark - enum ColorType

typedef enum : NSUInteger {
    TuSDKPFEditTextColorType_TextColor = 101,
    TuSDKPFEditTextColorType_BackgroudColor,
    TuSDKPFEditTextColorType_StrokeColor,
} TuSDKPFEditTextColorType;

#pragma mark - TuSDKPFEditTextColorAdjustDelegate

/**
 颜色选择View代理
 */
@protocol TuSDKPFEditTextColorAdjustDelegate <NSObject>

@optional
/**
 选中某一颜色

 @param color 选中的颜色对象
 */
- (void)onSelectColorWith:(UIColor *)color styleType:(TuSDKPFEditTextColorType)styleType;

@end


#pragma mark - TuSDKPFEditTextColorAdjustView

/**
 颜色选择器视图
 */
@interface TuSDKPFEditTextColorAdjustView : UIView

// 代理对象
@property (nonatomic, weak) id<TuSDKPFEditTextColorAdjustDelegate> colorDelegate;

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
