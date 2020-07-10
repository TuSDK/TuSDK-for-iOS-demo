//
//  TuEditFaceDetectionImageController.h
//  TuSDKDemo
//
//  Created by Clear Hu on 16/3/10.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKCPImageResultController.h"
#pragma mark - TuEditFaceDetectionImageView
/**
 *  图片头像检测 视图
 */
@interface TuEditFaceDetectionImageView : UIView{
    // 图片视图
    UIImageView *_imageView;
    
}
/**
 *  图片视图
 */
@property (nonatomic, readonly) UIImageView *imageView;
@end

#pragma mark - TuEditFaceDetectionImageController
/**
 *  图片头像检测 控制器
 */
@interface TuEditFaceDetectionImageController : TuSDKCPImageResultController{
@protected
    // 默认样式视图
    TuEditFaceDetectionImageView *_defaultStyleView;
}
/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) TuEditFaceDetectionImageView *defaultStyleView;
@end
