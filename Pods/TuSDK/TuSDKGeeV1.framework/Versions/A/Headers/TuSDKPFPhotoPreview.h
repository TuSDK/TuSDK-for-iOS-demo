//
//  TuSDKPFPhotoPreview.h
//  TuSDKGeeV1
//
//  Created by Jimmy Zhao on 16/11/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKPFPhotosGridPreview.h"

@interface TuSDKPFPhotoPreview : UIView
/**
 *  相册照片列表视图类 (默认:TuSDKPFPhotosGridPreview, 需要继承 TuSDKPFPhotosGridPreview)
 */
@property (nonatomic, strong) Class photosViewClazz;
/**
 *  相册照片列表视图
 */
@property (nonatomic, strong) TuSDKPFPhotosGridPreview *photosView;

// 返回按钮
@property(nonatomic, strong) UIButton *backButton;

// 选择按钮
@property(nonatomic, strong) UIButton *selectButton;

// 完成按钮
@property(nonatomic, strong) UIButton *completeButton;

/**
 *  刷新视图状态
 */
- (void)reloadViewDownloading:(BOOL)downloading;

@end
