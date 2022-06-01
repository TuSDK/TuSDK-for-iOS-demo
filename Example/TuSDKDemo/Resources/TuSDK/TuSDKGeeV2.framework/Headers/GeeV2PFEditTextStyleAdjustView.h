//
//  GeeV2PFEditTextStyleAdjustView.h
//  TuSDKGeeV2
//
//  Created by 刘鹏程 on 2022/5/30.
//  Copyright © 2022 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"
NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    GeeV2PFEditTextStyleType_LeftToRight = 101,
    GeeV2PFEditTextStyleType_RightToLeft,
    GeeV2PFEditTextStyleType_Underline,
    GeeV2PFEditTextStyleType_AlignmentLeft,
    GeeV2PFEditTextStyleType_AlignmentRight,
    GeeV2PFEditTextStyleType_AlignmentCenter,
} GeeV2PFEditTextStyleType;

#pragma mark - GeeV2PFEditTextStyleAdjustDelegate
/**
 样式选择View代理
 */
@protocol GeeV2PFEditTextStyleAdjustDelegate <NSObject>

@optional
/**
 选中某样式
 
 @param styleIndex 选中的样式下标
 */
- (void)onSelectStyle:(GeeV2PFEditTextStyleType)styleType;

@end

#pragma mark - GeeV2PFEditTextStyleAdjustView

@interface GeeV2PFEditTextStyleAdjustView : UIView

// 代理对象
@property (nonatomic, weak) id<GeeV2PFEditTextStyleAdjustDelegate> styleDelegate;

// 样式图标数组
@property (nonatomic, strong) NSArray<NSNumber *> *styleImageNames;

// 整体内边距设置 默认 (10,20,10,20)
@property (nonatomic, assign) UIEdgeInsets edgeInsets;

@end

NS_ASSUME_NONNULL_END
