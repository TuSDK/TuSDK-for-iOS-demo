//
//  UIImage+Demo.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/6/28.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Demo)

/**
 绘制生成圆形图片

 @param size 指定大小
 @param color 颜色
 @return UIImage 对象
 */
+ (UIImage *)circleImageWithSize:(CGSize)size color:(UIColor *)color;

@end
