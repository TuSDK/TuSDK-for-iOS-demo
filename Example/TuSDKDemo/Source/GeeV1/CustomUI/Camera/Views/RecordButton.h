//
//  RecordButton.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/2.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RecordButton;

/**
 录制按钮样式
 */
typedef NS_ENUM(NSInteger, RecordButtonStyle) {
    // 拍照模式样式
    RecordButtonStylePhoto,
    // 长按录制模式样式（默认）
    RecordButtonStyleVideo1,
    // 单击录制模式样式
    RecordButtonStyleVideo2,
};

@protocol RecordButtonDelegate <NSObject>
@optional

/**
 录制按钮按下回调

 @param reocrdButton 录制按钮
 */
- (void)recordButtonDidTouchDown:(RecordButton *)reocrdButton;

/**
 录制按钮抬起或结束触摸回调

 @param reocrdButton 录制按钮
 */
- (void)recordButtonDidTouchEnd:(RecordButton *)reocrdButton;

/**
 录制按钮滑动事件回调

 @param recordButton 录制按钮
 @param sender 滑动手势
 */
- (void)recordButton:(RecordButton *)recordButton panningWithSender:(UIPanGestureRecognizer *)sender;

@end

/**
 录制按钮
 */
@interface RecordButton : UIButton

/**
 内容适配大小
 */
@property (nonatomic, assign) CGSize contentSize;

/**
 背景圆点颜色
 */
@property (nonatomic, strong) UIColor *backgroundDotColor;

/**
 前景圆点颜色
 */
@property (nonatomic, strong) UIColor *dotColor;

/**
 背景圆点与前景圆点直径比率
 */
@property (nonatomic, assign) double backgroundDotRatio;

/**
 是否启用滑动
 */
@property (nonatomic, assign) BOOL panEnable;

/**
 添加代理，此处使用 NSHashTable 存储添加的代理对象，以消除强引用
 */
- (void)addDelegate:(id<RecordButtonDelegate>)delegate;

/**
 切换按钮样式
 */
- (void)switchStyle:(RecordButtonStyle)style;

@end
