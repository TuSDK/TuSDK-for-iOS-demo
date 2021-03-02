//
//  DefineCAEAGLView.m
//  TuSDKDemo
//
//  Created by Clear Hu on 2020/6/8.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import "DefineCAEAGLView.h"

// 自定义 OPENGL ES视图
@implementation DefineCAEAGLView
@synthesize viewListener    = _viewListener;    // OPENGL ES视图监听
@synthesize viewRect        = _viewRect;        // OPENGL ES视图范围
// 设置GL视图
+ (Class)layerClass;
{
    return [CAEAGLLayer class];
}

// OPENGL ES视图图层
- (CAEAGLLayer *)eaglLayer;
{
    return (CAEAGLLayer *)self.layer;
}

- (void)setFrame:(CGRect)frame;
{
    [super setFrame:frame];
    _viewRect = self.bounds;
}

- (void)layoutSubviews;
{
    [super layoutSubviews];
    if (self.viewListener) [self.viewListener onTuCAEAGLViewLayoutSubviews:_viewRect];
}
@end
