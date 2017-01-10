//
//  GeeV2PFPhotoPreview.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/11/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFPhotosGridPreview.h"

@interface GeeV2PFPhotoPreview : UIView
/**
 *  相册照片列表视图类 (默认:GeeV2PFPhotosGridPreview, 需要继承 GeeV2PFPhotosGridPreview)
 */
@property (nonatomic, strong) Class photosViewClazz;
/**
 *  相册照片列表视图
 */
@property (nonatomic, strong) GeeV2PFPhotosGridPreview *photosView;

// 返回按钮
@property(nonatomic, strong) UIButton *backButton;

// 选择按钮
@property(nonatomic, strong) UIButton *selectButton;

// 完成按钮
@property(nonatomic, strong) UIButton *completeButton;

// 完成icon按钮
@property(nonatomic, strong) UIButton *completeView;

// 完成按钮文本
@property(nonatomic, strong) UILabel *completeLabel;
/**
 *  刷新选择按钮
 *
 *  @param isSelected 是否选择相片资源
 */
- (void)reloadSelectButtonSelected:(BOOL)isSelected;
/**
 *  刷新视图状态
 */
- (void)reloadViewDownloading:(BOOL)downloading;
@end
