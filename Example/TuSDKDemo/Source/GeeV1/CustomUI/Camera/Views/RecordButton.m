//
//  RecordButton.m
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/2.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import "RecordButton.h"

@interface RecordButton ()

/**
 背景圆点图层
 */
@property (nonatomic, strong) CAShapeLayer *backgroundDotLayer;

/**
 前景圆点图层
 */
@property (nonatomic, strong) CAShapeLayer *dotLayer;

/**
 滑动手势
 */
@property (nonatomic, assign) BOOL panning;

/**
 滑动开始中点，用于滑动结束后还原
 */
@property (nonatomic, assign) CGPoint panBeganCenter;

/**
 弱引用记录添加的代理
 */
@property (nonatomic, strong) NSHashTable *delegates;

@end

@implementation RecordButton

- (instancetype)initWithCoder:(NSCoder *)decoder {
    if (self = [super initWithCoder:decoder]) {
        [self commonInit];
    }
    return self;
}
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self commonInit];
    }
    return self;
}

- (void)commonInit {
    self.backgroundColor = [UIColor clearColor];
    self.tintColor = [UIColor whiteColor];
    self.adjustsImageWhenHighlighted = NO;
    _backgroundDotColor = [UIColor colorWithWhite:1 alpha:0.6];
    _dotColor = [UIColor colorWithRed:254.0f/255.0f green:58.0f/255.0f blue:58.0f/255.0f alpha:1.0f];
    _backgroundDotRatio = 7/9.0;
    
    _dotLayer = [CAShapeLayer layer];
    [self.layer insertSublayer:_dotLayer atIndex:0];
    _dotLayer.fillColor = _dotColor.CGColor;
    
    _backgroundDotLayer = [CAShapeLayer layer];
    [self.layer insertSublayer:_backgroundDotLayer atIndex:0];
    _backgroundDotLayer.fillColor = _backgroundDotColor.CGColor;
    
    [self addTarget:self action:@selector(touchDownAction:) forControlEvents:UIControlEventTouchDown];
    [self addTarget:self action:@selector(touchEndAction:) forControlEvents:
     UIControlEventTouchUpInside
     | UIControlEventTouchUpOutside
     | UIControlEventTouchCancel
     ];
    
    UIPanGestureRecognizer *pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panAction:)];
    [self addGestureRecognizer:pan];
    
    _delegates = [NSHashTable hashTableWithOptions:NSPointerFunctionsWeakMemory];
}

- (void)layoutSubviews {
    [super layoutSubviews];
    
    _backgroundDotLayer.frame = _dotLayer.frame = self.bounds;
    _backgroundDotLayer.path = [self circleWithRadiusInset:0].CGPath;
    _dotLayer.path = [self circleWithRadiusScale:_backgroundDotRatio].CGPath;
    [self bringSubviewToFront:self.imageView];
}

/**
 创建圆形路径

 @param radiusInset 半径缩进
 @return 圆形路径
 */
- (UIBezierPath *)circleWithRadiusInset:(CGFloat)radiusInset {
    CGPoint center = CGPointMake(CGRectGetMidX(self.bounds), CGRectGetMidY(self.bounds));
    CGFloat radius = center.x + radiusInset;
    UIBezierPath *path = [UIBezierPath bezierPathWithArcCenter:center radius:radius startAngle:0 endAngle:M_PI * 2 clockwise:YES];
    return path;
}

/**
 创建圆形路径

 @param radiusScale 半径缩放
 @return 圆形路径
 */
- (UIBezierPath *)circleWithRadiusScale:(CGFloat)radiusScale {
    CGPoint center = CGPointMake(CGRectGetMidX(self.bounds), CGRectGetMidY(self.bounds));
    CGFloat radius = center.x * radiusScale;
    UIBezierPath *path = [UIBezierPath bezierPathWithArcCenter:center radius:radius startAngle:0 endAngle:M_PI * 2 clockwise:YES];
    return path;
}

- (void)touchDownCallback {
    for (id<RecordButtonDelegate> delegate in _delegates) {
        if ([delegate respondsToSelector:@selector(recordButtonDidTouchDown:)]) {
            [delegate recordButtonDidTouchDown:self];
        }
    }
}
- (void)touchEndCallback {
    for (id<RecordButtonDelegate> delegate in _delegates) {
        if ([delegate respondsToSelector:@selector(recordButtonDidTouchEnd:)]) {
            [delegate recordButtonDidTouchEnd:self];
        }
    }
}
- (void)panningCallback:(UIPanGestureRecognizer *)sender {
    for (id<RecordButtonDelegate> delegate in _delegates) {
        if ([delegate respondsToSelector:@selector(recordButton:panningWithSender:)]) {
            [delegate recordButton:self panningWithSender:sender];
        }
    }
}

#pragma mark - property

- (void)setContentSize:(CGSize)contentSize {
    _contentSize = contentSize;
    [self invalidateIntrinsicContentSize];
}

- (CGSize)intrinsicContentSize {
    return _contentSize;
}

- (void)setBackgroundDotColor:(UIColor *)backgroundDotColor {
    _backgroundDotColor = backgroundDotColor;
    _backgroundDotLayer.fillColor = backgroundDotColor.CGColor;
}

- (void)setDotColor:(UIColor *)dotColor {
    _dotColor = dotColor;
    _dotLayer.fillColor = _dotColor.CGColor;
}

- (void)setBackgroundDotRatio:(double)backgroundDotRatio {
    _backgroundDotRatio = backgroundDotRatio;
    [self setNeedsLayout];
}

- (void)setSelected:(BOOL)selected {
    [super setSelected:selected];
    [self updateUIWithTouchDwon:selected];
}

#pragma mark - action

/**
 按下事件
 */
- (void)touchDownAction:(UIButton *)sender {
    [self touchDownCallback];
}

/**
 抬起事件
 */
- (void)touchEndAction:(UIButton *)sender {
    // 当时滑动，在滑动事件回调 touch end 事件
    if (_panning) return;
    
    [self touchEndCallback];
}

/**
 更新按下时 UI
 */
- (void)updateUIWithTouchDwon:(BOOL)touchDwon {
    if (touchDwon) {
        NSString *transformKey = @"transform.scale";
        [_backgroundDotLayer setValue:@(7/6.0) forKeyPath:transformKey];
        [_dotLayer setValue:@(6/7.0) forKeyPath:transformKey];
    } else {
        _backgroundDotLayer.affineTransform = CGAffineTransformIdentity;
        _dotLayer.affineTransform = CGAffineTransformIdentity;
    }
}

/**
 滑动手势
 */
- (void)panAction:(UIPanGestureRecognizer *)sender {
    if (!_panEnable) return;
    CGPoint translation = [sender translationInView:self];
    //NSLog(@"translation: %@", NSStringFromCGPoint(translation));
    switch (sender.state) {
        case UIGestureRecognizerStateBegan:{
            _panBeganCenter = self.center;
            _panning = YES;
        } break;
        case UIGestureRecognizerStateChanged:{
            self.center = CGPointMake(_panBeganCenter.x + translation.x, _panBeganCenter.y + translation.y);
            _panning = YES;
        } break;
        default:{
            _panning = NO;
            [UIView animateWithDuration:0.15 animations:^{
                self.center = self.panBeganCenter;
            } completion:^(BOOL finished) {}];
            [self touchEndCallback];
        } break;
    }
    [self panningCallback:sender];
}

#pragma mark - public

- (void)addDelegate:(id<RecordButtonDelegate>)delegate {
    if ([_delegates containsObject:delegate]) return;
    [_delegates addObject:delegate];
}

- (void)switchStyle:(RecordButtonStyle)style {
    self.backgroundDotColor = [UIColor colorWithWhite:1 alpha:0.6];
    self.dotColor = [UIColor colorWithRed:254.0f/255.0f green:58.0f/255.0f blue:58.0f/255.0f alpha:1.0f];
    self.contentSize = CGSizeMake(72, 72);
    [self setImage:nil forState:UIControlStateNormal];
    [self setImage:nil forState:UIControlStateSelected];
    
    switch (style) {
        case RecordButtonStylePhoto:{
            self.dotColor = [UIColor whiteColor];
        } break;
        case RecordButtonStyleVideo1:{
            
        } break;
        case RecordButtonStyleVideo2:{
            UIImage *image = [UIImage imageNamed:@"video_ic_recording"];
            [self setImage:image forState:UIControlStateNormal];
            [self setImage:image forState:UIControlStateSelected];
        } break;
    }
}

@end
