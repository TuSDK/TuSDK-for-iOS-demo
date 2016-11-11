//
//  GeeV2PFPhotoPreviewBarViewWrap.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/14.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  多选相册预览视图工具栏包装类
 */
@interface GeeV2PFPhotoPreviewBarViewWrap : NSObject

// 顶部工具栏
@property(nonatomic, strong) UIView *topBar;
// 返回按钮
@property(nonatomic, strong) UIButton *backButton;
// 选择按钮
@property(nonatomic, strong) UIButton *selectButton;
// 选择按钮
@property(nonatomic, strong) UIButton *selectView;

// 底部工具栏
@property(nonatomic, strong) UIView *bottomBar;
// 完成按钮
@property(nonatomic, strong) UIButton *completeButton;

// 完成icon按钮
@property(nonatomic, strong) UIButton *completeView;

// 完成按钮文本
@property(nonatomic, strong) UILabel *completeLabel;

/**
 *  初始化视图，重写该方法可以改变视图样式
 */
- (void)lsqInitView;
@end
