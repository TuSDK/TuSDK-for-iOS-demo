//
//  TuSDKICFilterImageViewWrap.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/7.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKFilterWrap.h"

/**
 *  Filter Image View Interface
 */
@protocol TuSDKICFilterImageViewInterface <NSObject>
/**
 *  开启触摸时显示原图效果
 */
@property (nonatomic) BOOL enableTouchCleanFilter;

/**
 *  显示的图片
 */
- (void)setImage:(UIImage *)image;

/**
 *  滤镜包装
 */
- (void)setFilterWrap:(TuSDKFilterWrap *)filterWrap;

/**
 *  请求渲染图片
 */
- (void)requestRender;

/**
 *  更新布局
 */
- (void)needUpdateLayout;
@end

/**
 *  滤镜显示视图包装
 */
@interface TuSDKICFilterImageViewWrap : UIView<TuSDKICFilterImageViewInterface>

@end
