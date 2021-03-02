//
//  TuSDKPFEditTextViewOptions.h
//  TuSDKGeeV1
//
//  Created by wen on 03/08/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"

@interface TuSDKPFEditTextViewOptions : NSObject
/**
 *  初始化字体颜色
 */
@property (nonatomic, strong) UIColor *textColor;
/**
 *  初始化字体
 */
@property (nonatomic, strong) UIFont *textFont;
/**
 *  初始化提示内容
 */
@property (nonatomic, strong) NSString *textString;
/**
 *  初始化文字样式信息设置
 */
@property (nonatomic, strong) NSMutableParagraphStyle *textParaStyle;
/**
 *  初始化时 是否显示下划线
 */
@property (nonatomic, assign) BOOL enableUnderline;
/**
 *  书写方向 参考 NSWritingDirectionAttributeName
 */
@property (nonatomic, strong) NSArray<NSNumber *> *writingDirection;
/**
 *  初始化时 文字对齐方式
 */
@property (nonatomic, assign) NSTextAlignment textAlignment;
/**
 *  初始化时 文字背景色
 */
@property (nonatomic, strong) UIColor *textBackgroudColor;
/**
 *  初始化时 线条颜色
 */
@property (nonatomic, strong) UIColor *textStrokeColor;
/**
 *  初始化时 边框宽度
 */
@property (nonatomic, assign) CGFloat textBorderWidth;
/**
 *  初始化时 边框颜色
 */
@property (nonatomic, retain) UIColor *textBorderColor;
/**
 *  文字边距 默认 （0，0，0，0）
 */
@property (nonatomic, assign) UIEdgeInsets textEdgeInsets;
/**
 *  文字最大放大倍数 (相对于父视图) 默认 1.0
 */
@property (nonatomic, assign) CGFloat textMaxScale;

// 初始化默认option
+ (instancetype)defaultOptions;

@end
