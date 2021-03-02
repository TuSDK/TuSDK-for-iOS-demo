//
//  TuCAEAGLView.h
//  TuSDK
//
//  Created by Clear Hu on 2020/4/26.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - TuCAEAGLViewListener
// OPENGL ES视图监听
@protocol TuCAEAGLViewListener<NSObject>
- (void) onTuCAEAGLViewLayoutSubviews:(CGRect)frame;    // 视图布局改变
@optional
- (void)onTuCAEAGLViewTouchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)onTuCAEAGLViewTouchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)onTuCAEAGLViewTouchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)onTuCAEAGLViewTouchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
@end

#pragma mark - TuCAEAGLViewInterface
// OPENGL ES视图接口
@protocol TuCAEAGLViewInterface<NSObject>
@property (nonatomic, weak)     id<TuCAEAGLViewListener>    viewListener;   // OPENGL ES视图监听
@property (nonatomic, readonly) CGRect                      viewRect;       // OPENGL ES视图范围
@property (nonatomic, readonly) CAEAGLLayer*                eaglLayer;      // OPENGL ES视图图层
@end

#pragma mark - TuCAEAGLView
// OPENGL ES视图
@interface TuCAEAGLView : UIView<TuCAEAGLViewInterface>

@end

NS_ASSUME_NONNULL_END
