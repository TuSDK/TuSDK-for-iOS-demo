//
//  TuSDKPFPhotoPreview.h
//  TuSDKGeeV1
//
//  Created by Jimmy Zhao on 16/11/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKPFPhotosGridPreview.h"

@interface TuSDKPFPhotoPreview : UIView
{
    UIButton *_backButton;
    UIButton *_selectButton;
    UIButton *_completeButton;
}
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

/**
 *  设置返回按钮文本
 */
-(void) setBackButtonTitle:(NSString *) title;

/**
 *  设置完成按钮文本
 */
-(void) setCompleteButtonTitle:(NSString *)title;

/**
 *  设置选择按钮文本
 */
-(void) setSelectButtonTitle:(NSString *) title;

@end
