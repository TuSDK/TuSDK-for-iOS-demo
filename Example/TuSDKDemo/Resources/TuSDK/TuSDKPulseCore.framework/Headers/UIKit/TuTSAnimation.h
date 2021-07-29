//
//  TuTSAnimation.h
//  TuSDK
//
//  Created by Clear Hu on 14/12/17.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - TuSDKTween
/**
 *  动画速度基类
 */
@interface TuTween : NSObject
/**
 *  动画执行时间
 */
@property (nonatomic) NSTimeInterval duration;

/**
 *  动画速度基类
 *
 *  @return 动画速度基类
 */
+ (instancetype) tween;

/**
 *  计算当前速度值
 *
 *  @param time 当前时间 (0 <= time <= duration)
 *
 *  @return 当前速度值
 */
- (NSTimeInterval)computerWithTime:(NSTimeInterval)time;
@end

#pragma mark - TuTweenQuad
/**
 *  Quadratic：二次方的缓动（t^2）
 */
@interface TuTweenQuadEaseIn : TuTween
@end

/**
 *  Quadratic：二次方的缓动（t^2）
 */
@interface TuTweenQuadEaseOut : TuTween
@end

/**
 *  Quadratic：二次方的缓动（t^2）
 */
@interface TuTweenQuadEaseInOut : TuTween
@end

#pragma mark - TuSDKTweenCubic
/**
 *  Cubic：三次方的缓动（t^3）
 */
@interface TuTweenCubicEaseIn : TuTween
@end

/**
 *  Cubic：三次方的缓动（t^3）
 */
@interface TuTweenCubicEaseOut : TuTween
@end

/**
 *  Cubic：三次方的缓动（t^3）
 */
@interface TuTweenCubicEaseInOut : TuTween
@end

#pragma mark - TuSDKTweenQuart
/**
 *  Quartic：四次方的缓动（t^4）
 */
@interface TuTweenQuartEaseIn : TuTween
@end

/**
 *  Quartic：四次方的缓动（t^4）
 */
@interface TuTweenQuartEaseOut : TuTween
@end

/**
 *  Quartic：四次方的缓动（t^4）
 */
@interface TuTweenQuartEaseInOut : TuTween
@end

#pragma mark - TuSDKTweenQuint
/**
 *  Quintic：五次方的缓动（t^5）
 */
@interface TuTweenQuintEaseIn : TuTween
@end

/**
 *  Quintic：五次方的缓动（t^5）
 */
@interface TuTweenQuintEaseOut : TuTween
@end

/**
 *  Quintic：五次方的缓动（t^5）
 */
@interface TuTweenQuintEaseInOut : TuTween
@end

#pragma mark - TuSDKTweenSine
/**
 *  Sinusoidal：正弦曲线的缓动（sin(t)）
 */
@interface TuTweenSineEaseIn : TuTween
@end

/**
 *  Sinusoidal：正弦曲线的缓动（sin(t)）
 */
@interface TuTweenSineEaseOut : TuTween
@end

/**
 *  Sinusoidal：正弦曲线的缓动（sin(t)）
 */
@interface TuTweenSineEaseInOut : TuTween
@end

#pragma mark - TuSDKTweenExpo
/**
 *  Exponential：指数曲线的缓动（2^t）
 */
@interface TuTweenExpoEaseIn : TuTween
@end

/**
 *  Exponential：指数曲线的缓动（2^t）
 */
@interface TuTweenExpoEaseOut : TuTween
@end

/**
 *  Exponential：指数曲线的缓动（2^t）
 */
@interface TuTweenExpoEaseInOut : TuTween
@end

#pragma mark - TuSDKTweenCirc
/**
 *  Circular：圆形曲线的缓动（sqrt(1-t^2)）
 */
@interface TuTweenCircEaseIn : TuTween
@end

/**
 *  Circular：圆形曲线的缓动（sqrt(1-t^2)）
 */
@interface TuTweenCircEaseOut : TuTween
@end

/**
 *  Circular：圆形曲线的缓动（sqrt(1-t^2)）
 */
@interface TuTweenCircEaseInOut : TuTween
@end

#pragma mark - TuSDKTweenElastic
/**
 *  Elastic：指数衰减的正弦曲线缓动
 */
@interface TuTweenElastic : TuTween{
    // 周期，可选参数
    float _period;
}
/**
 *  振幅，可选参数
 */
@property (nonatomic) float amplitude;
/**
 *  周期，可选参数
 */
@property (nonatomic) float period;
@end

/**
 *  Elastic：指数衰减的正弦曲线缓动
 */
@interface TuTweenElasticEaseIn : TuTweenElastic
@end

/**
 *  Elastic：指数衰减的正弦曲线缓动
 */
@interface TuTweenElasticEaseOut : TuTweenElastic
@end

/**
 *  Elastic：指数衰减的正弦曲线缓动
 */
@interface TuTweenElasticEaseInOut : TuTweenElastic
@end

#pragma mark - TuSDKTweenBack
/**
 *  超过范围的三次方缓动（(s+1)*t^3 - s*t^2）
 */
@interface TuTweenBack : TuTween
/**
 *  速度 (默认：1.70158)
 */
@property (nonatomic) float speed;
@end

/**
 *  超过范围的三次方缓动（(s+1)*t^3 - s*t^2）
 */
@interface TuTweenBackEaseIn : TuTweenBack
@end

/**
 *  超过范围的三次方缓动（(s+1)*t^3 - s*t^2）
 */
@interface TuTweenBackEaseOut : TuTweenBack
@end

/**
 *  超过范围的三次方缓动（(s+1)*t^3 - s*t^2）
 */
@interface TuTweenBackEaseInOut : TuTweenBack
@end

#pragma mark - TuSDKTweenBounce
/**
 *  Bounce：指数衰减的反弹缓动
 */
@interface TuTweenBounceEaseIn : TuTween
@end

/**
 *  Bounce：指数衰减的反弹缓动
 */
@interface TuTweenBounceEaseOut : TuTween
@end

/**
 *  Bounce：指数衰减的反弹缓动
 */
@interface TuTweenBounceEaseInOut : TuTween
@end

#pragma mark - TuTSAnimation
@class TuTSAnimation;
/**
 *  动画执行回调
 *
 *  @param anim 自定义动画对象
 *  @param step 步进结果 0-1
 */
typedef void (^TuTSAnimationBlock)(TuTSAnimation *anim, NSTimeInterval step);

/**
 *  自定义动画
 */
@interface TuTSAnimation : NSObject

/**
 *  动画执行帧间隔时间 (默认: 0.01)
 */
@property (nonatomic) NSTimeInterval interval;

/**
 *  动画执行时间
 */
@property (nonatomic) NSTimeInterval duration;

/**
 *  动画速度基类
 */
@property (nonatomic, retain) TuTween *tween;

/**
 *  动画执行回调
 */
@property (nonatomic, strong) TuTSAnimationBlock block;

/**
 *  创建自定义动画
 *
 *  @param duration 动画执行时间 (单位:秒)
 *  @param block    动画回调
 *
 *  @return 自定义动画
 */
+ (TuTSAnimation *)animWithDuration:(NSTimeInterval)duration
                                 block:(TuTSAnimationBlock)block;

/**
 *  创建自定义动画
 *
 *  @param duration 动画执行时间 (单位:秒)
 *  @param tween    动画加速度
 *  @param block    动画回调
 *
 *  @return 自定义动画
 */
+ (TuTSAnimation *)animWithDuration:(NSTimeInterval)duration
                                 tween:(TuTween *)tween
                                 block:(TuTSAnimationBlock)block;

/**
 *  动画开始
 */
- (void)start;

/**
 *  动画开始
 */
- (void)startWithBlock:(TuTSAnimationBlock)block;

/**
 *  动画停止
 */
- (void)stop;

/**
 *  销毁
 */
- (void)destory;
@end
