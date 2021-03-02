//
//  TuFilterStickerView.h
//  TuSDK
//
//  Created by Clear Hu on 15/9/8.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuCAEAGLView.h"
#import "TuMaskRegionView.h"
#import "TuStickerView.h"

// 滤镜贴纸合并视图接口
@protocol TuFilterStickerViewInterface <NSObject>
// 区域视图
@property (nonatomic, readonly) TuMaskRegionView *cutRegionView;
// 贴纸视图
@property (nonatomic, readonly) TuStickerView *stickerView;
// 滤镜视图
@property (nonatomic, readonly) UIView<TuCAEAGLViewInterface> *filterView;
// 更新布局
- (void)needUpdateLayout;

/**
 *  获取贴纸处理结果
 *  @return stickerResults 贴纸处理结果
 */
- (NSArray *)stickerResults;
/**
 *  设置图片
 *  @param image 图片
 */
- (void)setImage:(UIImage *)image;
@end

// 滤镜贴纸合并视图
@interface TuFilterStickerView : UIView<TuFilterStickerViewInterface>
{
    // 裁剪区域视图
    TuMaskRegionView *_cutRegionView;
    // 贴纸视图
    TuStickerView *_stickerView;
    // 滤镜视图
    UIView<TuCAEAGLViewInterface> *_filterView;
}

// 区域视图
@property (nonatomic, readonly) TuMaskRegionView *cutRegionView;
// 贴纸视图
@property (nonatomic, readonly) TuStickerView *stickerView;
// 滤镜视图
@property (nonatomic, readonly) UIView<TuCAEAGLViewInterface> *filterView;
@end
