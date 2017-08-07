//
//  TuSDKPFEditTextStyleAdjustView.h
//  TuSDKGeeV1
//
//  Created by wen on 28/07/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"

typedef enum : NSUInteger {
    TuSDKPFEditTextStyleType_LeftToRight = 101,
    TuSDKPFEditTextStyleType_RightToLeft,
    TuSDKPFEditTextStyleType_Underline,
    TuSDKPFEditTextStyleType_AlignmentLeft,
    TuSDKPFEditTextStyleType_AlignmentRight,
    TuSDKPFEditTextStyleType_AlignmentCenter,
} TuSDKPFEditTextStyleType;

#pragma mark - TuSDKPFEditTextStyleAdjustDelegate

/**
 样式选择View代理
 */
@protocol TuSDKPFEditTextStyleAdjustDelegate <NSObject>

@optional
/**
 选中某样式
 
 @param styleIndex 选中的样式下标
 */
- (void)onSelectStyle:(TuSDKPFEditTextStyleType)styleType;

@end

#pragma mark - TuSDKPFEditTextStyleAdjustView

@interface TuSDKPFEditTextStyleAdjustView : UIView

// 代理对象
@property (nonatomic, weak) id<TuSDKPFEditTextStyleAdjustDelegate> styleDelegate;

// 样式图标数组
@property (nonatomic, strong) NSArray<NSNumber *> *styleImageNames;

// 整体内边距设置 默认 (10,20,10,20)
@property (nonatomic, assign) UIEdgeInsets edgeInsets;

@end
