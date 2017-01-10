//
//  GeeV2ICCircularProgressView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  环状进度条
 */
@interface GeeV2ICCircularProgressView : UIView
/**
 *  自定义进度条初始化方法
 *
 *  @param frame
 *  @param backColor     圆环的默认颜色
 *  @param progressColor 进度颜色
 *  @param lineWidth     环的宽度
 *
 *  
 */
- (id)initWithFrame:(CGRect)frame
          backColor:(UIColor *)backColor
      progressColor:(UIColor *)progressColor
          lineWidth:(CGFloat)lineWidth;
/**
 *  更新进度 注意：必须在主线程更新
 *
 *  @param progress 进度值
 */
- (void)updateProgressCircle:(float)progress;

@end
