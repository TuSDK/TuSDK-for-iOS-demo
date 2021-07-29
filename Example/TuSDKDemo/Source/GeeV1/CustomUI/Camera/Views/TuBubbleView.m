//
//  TuBubbleView.m
//  TuSDKDemo
//
//  Created by 刘鹏程 on 2021/2/25.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import "TuBubbleView.h"
#import <TuSDKGeeV1/TuSDKGeeV1Import.h>
#import <TuSDKPulseCore/TuSDKPulseCore.h>
#import <TuViews/TuViews.h>
#define btnW 36
#define margin 10
@interface TuBubbleItemView()<UIGestureRecognizerDelegate, UITextFieldDelegate>
{
    // 图片视图边缘距离
    UIEdgeInsets _mImageEdge;
    // 内容视图长宽
    CGSize _mCSize;
    // 内容视图边缘距离
    CGSize _mCMargin;
    // 最大缩放比例
    CGFloat _mMaxScale;
    // 默认视图长宽
    CGSize _mDefaultViewSize;
    // 内容对角线长度
    CGFloat _mCHypotenuse;
    
    // 缩放比例
    CGFloat _mScale;
    // 旋转度数
    CGFloat _mDegree;
    // 文字视图列表
    NSMutableArray *_textViews;
    // 是否为旋转缩放动作
    BOOL _isRotatScaleAction;
    // 拖动手势
    UIPanGestureRecognizer *_panGesture;
    // 旋转手势
    UIRotationGestureRecognizer *_rotationGesture;
    // 缩放手势
    UIPinchGestureRecognizer *_pinchGesture;
    // 最后的触摸点
    CGPoint _lastPotion;
    // 是否正在操作
    BOOL _hasTouched;
    // 是否为手势动作
    BOOL _isInGesture;
    
}
@end

@implementation TuBubbleItemView

- (instancetype)initWithFrame:(CGRect)frame;
{
    self = [super initWithFrame:frame];
    if (self) {
        [self lsqInitView];
    }
    return self;
}

// 初始化视图
- (void)lsqInitView;
{
    // 默认缩放比例
    _mScale = 1.f;
    _textViews = [NSMutableArray array];
    // 图片视图
    _imageView = [UIImageView initWithFrame:self.bounds];
    _imageView.contentMode = UIViewContentModeScaleAspectFit;
    _imageView.userInteractionEnabled = YES;
    // IOS7 边缘抗锯齿
    _imageView.layer.allowsEdgeAntialiasing = YES;
    [self addSubview:_imageView];
    
    // 取消按钮
    _cancelButton = [UIButton buttonWithFrame:CGRectMake(0, 0, btnW, btnW)
                          imageLSQBundleNamed:@"style_default_edit_drag_cancel"];
    [_cancelButton addTouchUpInsideTarget:self action:@selector(handleCancelButton)];
    [self addSubview:_cancelButton];
    
    // 旋转缩放按钮
    _turnButton = [UIButton buttonWithFrame:CGRectMake(self.lsqGetSizeWidth - btnW, self.lsqGetSizeHeight - btnW, btnW, btnW)
                         imageLSQBundleNamed:@"style_default_edit_drag_rotate_scale"];
    [self addSubview:_turnButton];
    
    [self resetImageEdge];
    // 添加手势
    [self appendGestureRecognizer];
}

// 添加手势
- (void)appendGestureRecognizer;
{
    // 拖动手势
    _panGesture = [[UIPanGestureRecognizer alloc]initWithTarget:self action:@selector(handlePanGesture:)];
    _panGesture.maximumNumberOfTouches = 1;
    [self addGestureRecognizer:_panGesture];
    // 旋转手势
    _rotationGesture = [[UIRotationGestureRecognizer alloc]initWithTarget:self action:@selector(handleRotationGesture:)];
    _rotationGesture.delegate = self;
    [self addGestureRecognizer:_rotationGesture];

    // 缩放手势
    _pinchGesture = [[UIPinchGestureRecognizer alloc]initWithTarget:self action:@selector(handlePinchGesture:)];
    _pinchGesture.delegate = self;
    [self addGestureRecognizer:_pinchGesture];
}

// 同时执行旋转缩放手势
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer;
{
    return YES;
}

// 删除手势
- (void)removeGestureRecognizer;
{
    [self removeGestureRecognizer:_panGesture];
    [self removeGestureRecognizer:_rotationGesture];
    [self removeGestureRecognizer:_pinchGesture];
}

- (void)viewWillDestory;
{
    [super viewWillDestory];
    [self removeGestureRecognizer];
}

- (void)dealloc
{
    [self viewWillDestory];
}

// 关闭贴纸
- (void)handleCancelButton;
{
    if ([self.delegate respondsToSelector:@selector(onClosedBubbleItemView:)])
    {
        [self.delegate onClosedBubbleItemView:self];
    }
}

/**
 *  重置图片视图边缘距离
 */
- (void)resetImageEdge;
{
    // 图片视图边缘距离
    _mImageEdge.left = ceilf(_cancelButton.lsqGetSizeWidth * 0.5f);
    _mImageEdge.right = ceilf(_turnButton.lsqGetSizeWidth * 0.5f);
    _mImageEdge.top = ceilf(_cancelButton.lsqGetSizeHeight * 0.5f);
    _mImageEdge.bottom = ceilf(_turnButton.lsqGetSizeHeight * 0.5f);
    
    // 内容视图边缘距离
    _mCMargin.width = _mImageEdge.left + _mImageEdge.right;
    _mCMargin.height = _mImageEdge.top + _mImageEdge.bottom;
    [_imageView lsqSetOrigin:CGPointMake(_mImageEdge.left, _mImageEdge.top)];
    [self lsqSetSize:self.lsqGetSize];
    // 重置视图大小
    [self resetViewsBounds];
}

/**
 *  重置视图大小
 */
- (void)resetViewsBounds;
{
    CGSize size = self.bounds.size;
    [_imageView lsqSetSize:CGSizeMake(size.width - _mCMargin.width,
                                   size.height - _mCMargin.height)];
    
    [_turnButton lsqSetOrigin:CGPointMake(size.width - _turnButton.lsqGetSizeWidth, size.height - _turnButton.lsqGetSizeHeight)];
    
    if (_textViews.count != 0) {
        NSArray *rects = _posInfo.rects;
        for (int i = 0; i < rects.count; i++) {
            CGRect rect = [rects[i] CGRectValue];
            
            CGFloat minX = rect.origin.x * (CGRectGetWidth(self.bounds) - btnW - 5);
            CGFloat minY = rect.origin.y * (CGRectGetHeight(self.bounds) - btnW);
            CGFloat width = rect.size.width * (CGRectGetWidth(self.bounds) - btnW - 5);
            CGFloat height = rect.size.height * (CGRectGetHeight(self.bounds) - btnW);
            
            UILabel *textLabel = _textViews[i];
            textLabel.frame = CGRectMake(minX, minY, width, height);
            [self drawBorderWithLabel:textLabel isUpdate:YES];
            
        }
    }
}

//  最小缩小比例(默认: 0.5f <= mMinScale <= 1)
- (CGFloat)minScale;
{
    if (_minScale < 0.5f) {
        _minScale = 0.5f;
    }
    return _minScale;
}

// 选中状态
- (void)setSelected:(BOOL)selected;
{
    if (!selected && _hasTouched) return;
    _selected = selected;
    [_imageView lsqSetBorderWidth:self.strokeWidth color:_selected ? self.strokeColor : [UIColor clearColor]];
    
    _cancelButton.hidden = _turnButton.hidden = !selected;
    
    for (UILabel *textLabel in _textViews) {
        [self drawBorderWithLabel:textLabel isUpdate:NO];
    }
}

- (void)setPosInfo:(TUPFPBubbleTextFilter_Info *)posInfo
{
    _posInfo = posInfo;
    _mScale = posInfo.scale;
}

- (void)initStickerPostion;
{
    if (CGSizeEqualToSize(CGSizeZero, _mCSize) || !self.superview) return;
    // 内容对角线长度
    _mCHypotenuse = [TuTSMath distanceOfPointX1:0 y1:0 pointX2:_mCSize.width y2:_mCSize.height];
    // 默认视图长宽
    _mDefaultViewSize = CGSizeMake(_mCSize.width, _mCSize.height + _mCMargin.width / 2);
    // 最大缩放比例
    _mMaxScale = MIN((self.superview.lsqGetSizeWidth - _mCMargin.width) / _mCSize.width,
                     (self.superview.lsqGetSizeHeight - _mCMargin.height) / _mCSize.height);
    
    if (_mMaxScale < self.minScale) _mMaxScale = self.minScale;
    
    [self lsqSetSize:_mDefaultViewSize];
//     重置视图大小
    [self resetViewsBounds];
    
//     初始位置
    CGPoint origin = self.lsqGetOrigin;
    origin.x = (self.superview.lsqGetSizeWidth - _mDefaultViewSize.width) * _posInfo.posX;
    origin.y = (self.superview.lsqGetSizeHeight - _mDefaultViewSize.height) * _posInfo.posY;
    
    // 设置居中
    [self lsqSetOrigin:origin];
    
}

- (void)reloadData
{
    // 内容视图长宽
    _mCSize = CGSizeMake(CGRectGetWidth(self.bounds), CGRectGetHeight(self.bounds));
    
    [self initStickerPostion];
    [self creatInputTextView];
}

#pragma mark - StickerTexts

- (void)creatInputTextView
{
    NSArray *rects = _posInfo.rects;
    for (int i = 0; i < rects.count; i++) {
        CGRect rect = [rects[i] CGRectValue];
        
        CGFloat minX = rect.origin.x * (CGRectGetWidth(self.bounds) - btnW - 5);
        CGFloat minY = rect.origin.y * (CGRectGetHeight(self.bounds) - btnW);
        CGFloat width = rect.size.width * (CGRectGetWidth(self.bounds) - btnW - 5);
        CGFloat height = rect.size.height * (CGRectGetHeight(self.bounds) - btnW);
        
        
        UILabel *textLabel = [[UILabel alloc] init];
        textLabel.tag = i;
        textLabel.userInteractionEnabled = YES;
        [_imageView addSubview:textLabel];
        textLabel.frame = CGRectMake(minX, minY, width, height);
        [_textViews addObject:textLabel];
        
        UITapGestureRecognizer *textLabelTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapAction:)];
        textLabelTap.numberOfTapsRequired = 2;
        [textLabel addGestureRecognizer:textLabelTap];
        
    }
}

- (void)drawBorderWithTextView:(UITextField *)textField isUpdate:(BOOL)isUpdate
{
    if (isUpdate) {
        textField.layer.sublayers = nil;
    }
    CAShapeLayer *border = [CAShapeLayer layer];
    border.strokeColor = [UIColor whiteColor].CGColor;
    //填充的颜色
    border.fillColor = [UIColor clearColor].CGColor;
    //设置路径
    border.path = [UIBezierPath bezierPathWithRect:textField.bounds].CGPath;
    border.frame = textField.bounds;
    //虚线的宽度
    border.lineWidth = _selected ? 1.f : 0;
    //虚线的间隔
    border.lineDashPattern = @[@4, @2];
    [textField.layer addSublayer:border];
    textField.layer.hidden = !_selected;
}

- (void)drawBorderWithLabel:(UILabel *)label isUpdate:(BOOL)isUpdate
{
    if (isUpdate) {
        label.layer.sublayers = nil;
    }
    CAShapeLayer *border = [CAShapeLayer layer];
    border.strokeColor = [UIColor whiteColor].CGColor;
    //填充的颜色
    border.fillColor = [UIColor clearColor].CGColor;
    //设置路径
    border.path = [UIBezierPath bezierPathWithRect:label.bounds].CGPath;
    border.frame = label.bounds;
    //虚线的宽度
    border.lineWidth = _selected ? 1.f : 0;
    //虚线的间隔
    border.lineDashPattern = @[@4, @2];
    [label.layer addSublayer:border];
    label.layer.hidden = !_selected;
}


#pragma mark - PanGesture
// 拖动手势
- (void)handlePanGesture:(UIPanGestureRecognizer *)recognizer;
{
    _isInGesture = YES;
    CGPoint point = [recognizer locationInView:self.superview];
    if (recognizer.state == UIGestureRecognizerStateBegan)
    {
        if (!_turnButton.hidden) {
            CGPoint selfPoint = [recognizer locationInView:self];
            // 是否为旋转缩放动作
            _isRotatScaleAction = CGRectContainsPoint(_turnButton.frame, selfPoint);
        }
    }
    else if (recognizer.state == UIGestureRecognizerStateChanged)
    {
        if (_isRotatScaleAction) {
            [self handlePanGestureRotatScaleAction:point];
        }
        else{
            [self handlePanGestureTransAction:point];
        }
    }
    else {
        _hasTouched = NO;
    }
    _lastPotion = point;
    
    [self updateBubbleTextSticker];
}

// 旋转手势
- (void)handleRotationGesture:(UIRotationGestureRecognizer *)recognizer;
{
    _isInGesture = YES;
    if (recognizer.state == UIGestureRecognizerStateChanged)
    {
        // 旋转度数
        _mDegree = [TuTSMath numberFloat:_mDegree + 360 + [TuTSMath degreesFromRadian:recognizer.rotation] modulus:360];
        
        [self rotationWithDegrees:_mDegree];
    }
    else{
        _hasTouched = (recognizer.state == UIGestureRecognizerStateBegan);
    }
    recognizer.rotation = 0;
    
    _posInfo.rotate = _mDegree;
    [self updateBubbleTextSticker];
}

// 缩放手势
- (void)handlePinchGesture:(UIPinchGestureRecognizer *)recognizer;
{
    _isInGesture = YES;
    if (recognizer.state == UIGestureRecognizerStateChanged)
    {
        [self computerScaleWithScale:recognizer.scale - 1 center:self.center];
    }
    else{
        _hasTouched = (recognizer.state == UIGestureRecognizerStateBegan);
    }
    recognizer.scale = 1;
}

- (void)tapAction:(UITapGestureRecognizer *)sender
{
    NSNumber *selectIndex = [NSNumber numberWithInteger:sender.view.tag];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"TuBubbleViewTextChange" object:@[_posInfo, selectIndex]];
}

/**更新气泡文字数据*/
- (void)updateBubbleTextSticker
{
    _posInfo.rotate = _mDegree;
    _posInfo.scale = _mScale;
    
    if (self.delegate && [self.delegate respondsToSelector:@selector(tuBubbleItemView:moveBubbleSticker:)]) {
        [self.delegate tuBubbleItemView:self moveBubbleSticker:_posInfo];
    }
}

#pragma mark - touches
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
{
    _isInGesture = NO;
    _hasTouched = YES;
    if (self.delegate) {
        [self.delegate onSelectedBubbleItemView:self];
    }
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;
{
    [self touchesEnded:touches withEvent:event];
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
{
    _hasTouched = _isInGesture;
}

#pragma mart - handleTransAction
// 处理移动位置
- (void)handlePanGestureTransAction:(CGPoint)nowPoint;
{
    CGPoint center = self.center;
    NSLog(@"tutu pan x:%f y:%f", nowPoint.x - _lastPotion.x, nowPoint.y - _lastPotion.y);
    if (fabs(nowPoint.x - _lastPotion.x) < 0.2 || fabs(nowPoint.y - _lastPotion.y) < 0.2) {
       //return;
    }
    center.x += nowPoint.x - _lastPotion.x;
    center.y += nowPoint.y - _lastPotion.y;
    
    // 修复移动范围
    center = [self fixedCenterPoint:center];
    self.center = center;
    
    
    double posX = center.x / CGRectGetWidth(_posInfo.bubbleImageFrame);
    double posY = center.y / CGRectGetHeight(_posInfo.bubbleImageFrame);
    _posInfo.posX = posX;
    _posInfo.posY = posY;
    
    [self updateBubbleTextSticker];
}

#pragma mart - handleRotatScaleAction
// 处理旋转和缩放
- (void)handlePanGestureRotatScaleAction:(CGPoint)nowPoint;
{
    // 中心点
    CGPoint cPoint = self.center;
    
    // 计算旋转角度
    [self computerAngleWithPoint:nowPoint lastPoint:_lastPotion center:cPoint];
    
    // 计算缩放
    [self computerScaleWithPoint:nowPoint lastPoint:_lastPotion center:cPoint];
}

/**
 * 计算旋转角度
 *
 * @param point
 *            当前坐标点
 * @param lastPoint
 *            最后坐标点
 * @param cPoint
 *            中心点坐标
 */
- (void)computerAngleWithPoint:(CGPoint)point
                     lastPoint:(CGPoint)lastPoint
                        center:(CGPoint)cPoint;
{
    // 开始角度
    CGFloat sAngle = [TuTSMath degreesWithPoint:lastPoint center:cPoint];
    // 结束角度
    CGFloat eAngle = [TuTSMath degreesWithPoint:point center:cPoint];

    // 旋转度数
    _mDegree = [TuTSMath numberFloat:_mDegree + 360 + (eAngle - sAngle) modulus:360];
    
    [self rotationWithDegrees:_mDegree];
}

/**
 * 计算缩放
 *
 * @param point
 *            当前坐标点
 * @param lastPoint
 *            最后坐标点
 * @param cPoint
 *            中心点坐标
 */
- (void)computerScaleWithPoint:(CGPoint)point
                     lastPoint:(CGPoint)lastPoint
                        center:(CGPoint)cPoint;
{
    // 开始距离中心点距离
    CGFloat sDistance = [TuTSMath distanceOfEndPoint:cPoint startPoint:lastPoint];
    
    // 当前距离中心点距离
    CGFloat cDistance = [TuTSMath distanceOfEndPoint:cPoint startPoint:point];
    // 缩放距离
    CGFloat distance = cDistance - sDistance;
    if (distance == 0) return;
    
    // 计算缩放偏移
    [self computerScaleWithScale:distance / _mCHypotenuse center:cPoint];
}

/**
 *  计算缩放
 *
 *  @param scale  缩放倍数
 *  @param cPoint 中心点坐标
 */
- (void)computerScaleWithScale:(CGFloat)scale center:(CGPoint)cPoint;
{
    // 计算缩放偏移
    CGFloat offsetScale = scale * 2;
    // 缩放比例
    _mScale += offsetScale;
    _mScale = MAX(self.minScale, MIN(_mScale, _mMaxScale));
    
    CGSize size = CGSizeMake(floorf(_mCSize.width * _mScale + _mCMargin.width),
                             floorf(_mCSize.height * _mScale + _mCMargin.height));
    
    // 修复移动范围
    CGPoint center = [self fixedCenterPoint:cPoint];
    
    self.bounds = CGRectMake(0, 0, size.width + 112 * _mScale, size.height);
    self.center = center;
    [self resetViewsBounds];
    
    _posInfo.scale = _mScale;
    double posX = center.x / CGRectGetWidth(_posInfo.bubbleImageFrame);
    double posY = center.y / CGRectGetHeight(_posInfo.bubbleImageFrame);
    _posInfo.posX = posX;
    _posInfo.posY = posY;
    
    
    [self updateBubbleTextSticker];
}

#pragma mark - rect
/**
 *  修复移动范围
 *
 *  @param center 当前中心点
 *
 *  @return 移动的中心坐标
 */
- (CGPoint)fixedCenterPoint:(CGPoint)center;
{
    if (!self.superview) return center;
    
    if (center.x < 0) {
        center.x = 0;
    }else if (center.x > self.superview.lsqGetSizeWidth){
        center.x = self.superview.lsqGetSizeWidth;
    }
    
    if (center.y < 0) {
        center.y = 0;
    }else if (center.y > self.superview.lsqGetSizeHeight){
        center.y = self.superview.lsqGetSizeHeight;
    }
    return center;
}


/**
 *  获取相对于父亲视图选区中心百分比信息
 *
 *  @param regionRect 选区范围
 *
 *  @return 相对于父亲视图选区中心百分比信息
 */
- (CGRect)centerOfParentRegin:(CGRect)regionRect;
{
    if (!self.superview) return regionRect;
    
    // 中心点坐标
    CGPoint cPoint = self.center;
    
    if (CGRectIsEmpty(regionRect)) {
        regionRect = self.superview.bounds;
    }
    
    CGRect center = CGRectMake(cPoint.x, cPoint.y, _mCSize.width * _mScale, _mCSize.height * _mScale);
    
    // 减去选区外距离
    center = CGRectOffset(center, -regionRect.origin.x, -regionRect.origin.y);
    
    center.origin.x /= regionRect.size.width;
    center.origin.y /= regionRect.size.height;
    
    center.size.width /= regionRect.size.width;
    center.size.height /= regionRect.size.height;
    
    return center;
}

@end

@interface TuBubbleView()<UITextViewDelegate>
{
    // 贴纸列表
    NSMutableArray *_stickers;
    //输入图片
    UIImage *_inputImage;
    
    UIImageView *_bubbleImageView;
    
    TUPFPBubbleTextFilter_Info *_currentFilterInfo;
}
/**
 *  贴纸元件视图资源ID (需要实现 TuStickerItemViewInterface 接口)
 */
@property (nonatomic) Class stickerItemViewClazz;

@end

@implementation TuBubbleView

- (instancetype)initWithFrame:(CGRect)frame;
{
    self = [super initWithFrame:frame];
    if (self) {
        [self lsqInitView];
    }
    return self;
}

// 初始化视图
- (void)lsqInitView;
{
    _stickers = [NSMutableArray array];
    self.clipsToBounds = YES;
    
    _bubbleImageView = [[UIImageView alloc] init];
    _bubbleImageView.userInteractionEnabled = YES;
    [self addSubview:_bubbleImageView];
    
    _currentFilterInfo = [[TUPFPBubbleTextFilter_Info alloc] init];
}


/**
 *  当前已使用贴纸总数
 *
 *  @return 当前已使用贴纸总数
 */
- (NSUInteger)stickerCount;
{
    return _stickers.count;
}

/**
 *  贴纸元件视图资源ID (需要实现 TuStickerItemViewInterface 接口)
 */
- (Class)stickerItemViewClazz;
{
    if (!_stickerItemViewClazz || ![_stickerItemViewClazz conformsToProtocol: @protocol(TuBubbleItemViewInterface)]) {
        _stickerItemViewClazz = [TuBubbleItemView class];
    }
    return _stickerItemViewClazz;
}


// 取消所有贴纸选中状态
- (void)cancelAllSelected;
{
    for (UIView<TuBubbleItemViewInterface> *item in _stickers) {
        item.selected = NO;
    }
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
{
    UITouch *touch = [touches anyObject];
    if (touch.tapCount > 1) return;
    [self cancelAllSelected];
    if (self.delegate && [self.delegate respondsToSelector:@selector(onCancelAllSelectedView:)]) {
        [self.delegate onCancelAllSelectedView:self];
    }
}

#pragma mark - property
- (void)setPosInfo:(TUPFPBubbleTextFilter_Info *)posInfo
{
    _posInfo = posInfo;
    NSMutableArray *texts = [NSMutableArray array];
    for (int i = 0; i < _posInfo.rects.count; i++) {
        [texts addObject:@"请输入文字"];
    }
    _posInfo.texts = [texts copy];
}

/**添加气泡文字*/
- (void)appendBubbleSticker:(UIImage *)inputImage
{
    _inputImage = inputImage;
    if (!_posInfo) return;
    [self drawBubbleViewRect];
}

- (void)drawBubbleViewRect
{
    CGFloat safeBottom = 0;
    if ([UIDevice lsqIsDeviceiPhoneX]) {
        safeBottom = 20;
    }
    
    CGRect bubbleFrame = CGRectZero;
    
    
    CGFloat imageWidth = CGImageGetWidth(_inputImage.CGImage);
    CGFloat imageHeight = CGImageGetHeight(_inputImage.CGImage);
    CGFloat imageHeightWidthRatio = imageHeight / imageWidth;
        
    CGFloat bubbleWidth = _posInfo.width;
    CGFloat bubbleHeight = _posInfo.height;
    CGFloat bubbleHeightWidthRatio = bubbleHeight / bubbleWidth;
    
    CGFloat viewWidth = self.bounds.size.width;
    CGFloat viewHeight = self.bounds.size.height;
    CGFloat maxHeightWidthRatio = viewHeight / viewWidth;
    
    
    if (bubbleHeightWidthRatio < 1) {
        if (bubbleWidth > viewWidth) {
            bubbleWidth = bubbleWidth / maxHeightWidthRatio;
            bubbleHeight = bubbleHeight / maxHeightWidthRatio;
        }
    } else {
        if (bubbleHeight > viewHeight) {
            bubbleWidth = bubbleWidth * maxHeightWidthRatio;
            bubbleHeight = bubbleHeight * maxHeightWidthRatio;
        }
    }
    
    
    if (imageHeightWidthRatio > maxHeightWidthRatio) {
        if (imageHeight > viewHeight) {
            imageHeight = viewHeight;
            imageHeight = viewWidth / imageHeightWidthRatio;
        }
    } else {
        if (imageWidth > viewWidth) {
            imageWidth = viewWidth;
            imageHeight = viewWidth * imageHeightWidthRatio;
        }
    }
    
    _bubbleImageView.frame = CGRectMake((viewWidth - imageWidth) / 2, (viewHeight - imageHeight) / 2, imageWidth, imageHeight);
    
    bubbleFrame = CGRectMake(imageWidth * _posInfo.posX - bubbleWidth / 2, imageHeight * _posInfo.posY - bubbleHeight / 2, bubbleWidth, bubbleHeight);
    
    _posInfo.bubbleImageFrame = _bubbleImageView.frame;
    UIView *view = [self buildBubbleItemView:bubbleFrame];
    [self onSelectedStickerItemView:view];
}

// 创建贴纸视图
- (UIView<TuBubbleItemViewInterface> *)buildBubbleItemView:(CGRect)frame;
{
    UIView<TuBubbleItemViewInterface> *view = [self.stickerItemViewClazz initWithFrame:frame];
    view.delegate = self;

    
    [_bubbleImageView addSubview:view];
    [_stickers addObject:view];
    
    view.tag = _posInfo.bubbleIndex;
    view.strokeColor = [UIColor whiteColor];
    view.strokeWidth = 2.0f;
    view.posInfo = _posInfo;
    [view reloadData];
    return view;
}

/**
 *  选中贴纸元件
 *
 *  @param view 贴纸元件视图
 */
- (void)onSelectedStickerItemView:(UIView *)view
{
    if (!view) return;
    for (TuBubbleItemView *item in _stickers) {
        item.selected = [item isEqual:view];
    }
}

#pragma mark - TuStickerItemViewDelegate
/**
 *  贴纸元件关闭
 *
 *  @param view 贴纸元件视图
 */
- (void)onClosedBubbleItemView:(UIView<TuBubbleItemViewInterface> *)view;
{
    if (!view) return;
    
    [_stickers removeObject:view];
    [view removeFromSuperview];
    
    if (self.delegate && [self.delegate respondsToSelector:@selector(onClosedBubbleTextItemView:)]) {
        [self.delegate onClosedBubbleTextItemView:(int)view.tag];
    }
}

/**
 *  选中贴纸元件
 *
 *  @param view 贴纸元件视图
 */
- (void)onSelectedBubbleItemView:(UIView<TuBubbleItemViewInterface> *)view;
{
    if (!view) return;
    [self onSelectedStickerItemView:view];
    if (self.delegate && [self.delegate respondsToSelector:@selector(onCancelAllSelectedView:)]) {
        [self.delegate onCancelAllSelectedView:self];
    }
}

/**气泡文字移动*/
- (void)tuBubbleItemView:(UIView<TuBubbleItemViewInterface> *)view moveBubbleSticker:(TUPFPBubbleTextFilter_Info *)filterInfo
{
    if (!view) return;
    
    _currentFilterInfo = filterInfo;
    
    
    if (self.delegate && [self.delegate respondsToSelector:@selector(tuBubbleView:onMoveBubbleSticker:)]) {
        [self.delegate tuBubbleView:self onMoveBubbleSticker:_currentFilterInfo];
    }
}


@end

