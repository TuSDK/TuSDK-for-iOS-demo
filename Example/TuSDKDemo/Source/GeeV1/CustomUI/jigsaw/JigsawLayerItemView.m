//
//  JigsawLayerItemView.m
//  TuSDKDemo
//
//  Created by 言有理 on 2021/7/21.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import "JigsawLayerItemView.h"

@interface JigsawLayerItemView()<UIGestureRecognizerDelegate>
/// 偏移
@property(nonatomic, assign) CGPoint transformCenter;
/// 缩放比例 - 相对于开始
@property(nonatomic, assign) CGFloat transformScale;
/// 旋转角度 default is 0
@property(nonatomic, assign) CGFloat transformRotation;
@property(nonatomic, assign) CGPoint lastCenter;
@end

@implementation JigsawLayerItemView
- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        _transformScale = 1;
        _transformRotation = 0;
        _transformCenter = self.center;
        _rotation = 0;
        _lastCenter = CGPointZero;
        [self setupGesture];
    }
    return self;
}

- (void)setupGesture {
    // 拖动手势
    UIPanGestureRecognizer *panGesture = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panGestureAction:)];
    panGesture.maximumNumberOfTouches = 1;
    panGesture.delegate = self;
    [self addGestureRecognizer:panGesture];
    // 旋转手势
//    UIRotationGestureRecognizer *rotationGesture = [[UIRotationGestureRecognizer alloc] initWithTarget:self action:@selector(rotationGestureAction:)];
//    rotationGesture.delegate = self;
//    [self addGestureRecognizer:rotationGesture];
    // 缩放手势
    UIPinchGestureRecognizer *pinchGesture = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(pinchGestureAction:)];
    pinchGesture.delegate = self;
    [self addGestureRecognizer:pinchGesture];
}
// 两种或多种手势可以一起响应
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer {
    return YES;
}
// MARK: - 移动
- (void)panGestureAction:(UIPanGestureRecognizer *)gesture {
    //gesture.state == UIGestureRecognizerStateBegan ||
    if (gesture.state == UIGestureRecognizerStateChanged) {
        // 偏移量
        CGPoint translation = [gesture translationInView:gesture.view];
        // 移动后 中心点
        self.transformCenter =  CGPointMake(translation.x + self.lastCenter.x, translation.y + self.lastCenter.y);
        [self fetchOffset];
    } else if (gesture.state == UIGestureRecognizerStateEnded) {
        self.lastCenter = self.transformCenter;
        [gesture setTranslation:CGPointZero inView:gesture.view];
    }
}
// MARK: - 缩放
- (void)pinchGestureAction:(UIPinchGestureRecognizer *)gesture {
    if (gesture.state == UIGestureRecognizerStateBegan || gesture.state == UIGestureRecognizerStateChanged) {
        CGFloat scale = gesture.scale;
        self.transformScale *= scale;
        if (self.transformScale > 1) {
            [self fetch];
        }
        gesture.scale = 1;
    }
}
// MARK: - 旋转
- (void)rotationGestureAction:(UIRotationGestureRecognizer *)gesture {
    if (gesture.state == UIGestureRecognizerStateBegan || gesture.state == UIGestureRecognizerStateChanged) {
        CGFloat rotation = gesture.rotation;
        self.transformRotation += rotation;
        gesture.rotation = 0;
        [self fetch];
    }
}
- (void)fetch {
    //NSLog(@"%@ %f %f",NSStringFromCGPoint(self.transformCenter), self.transformScale, self.transformRotation);
    if ([self.delegate respondsToSelector:@selector(itemView:scale:angle:)]) {
        CGFloat angle = [self angleFromRadian:self.transformRotation] + self.rotation;
        [self.delegate itemView:self scale:self.transformScale angle:angle];
    }
}
- (void)fetchOffset {
    if ([self.delegate respondsToSelector:@selector(itemView:center:)]) {
        [self.delegate itemView:self center:self.transformCenter];
    }
}
/// 弧度转换为角度
- (CGFloat)angleFromRadian:(CGFloat)radian {
    return radian * 180 / M_PI;
}
- (void)setRotation:(int)rotation {
    _rotation = rotation;
    self.transformRotation = 0;
}
- (void)setIsSelected:(BOOL)isSelected {
    _isSelected = isSelected;
    self.layer.borderWidth = isSelected ? 1 : 0;
}
@end
