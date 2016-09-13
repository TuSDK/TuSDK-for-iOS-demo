//
//  TuSDKPFPhotoPreviewOptions.h
//  TuSDKGeeV1
//
//  Created by Jimmy Zhao on 16/8/26.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  多选相册预览视图工具栏包装类
 */
@interface TuSDKPFPhotoPreviewBarViewWrap : NSObject

// 顶部工具栏
@property(nonatomic, strong) UIView *topBar;
// 返回按钮
@property(nonatomic, strong) UIButton *backButton;
// 完成按钮
@property(nonatomic, strong) UIButton *completeButton;
// 底部工具栏
@property(nonatomic, strong) UIView *bottomBar;
// 选择按钮
@property(nonatomic, strong) UIButton *selectButton;

/**
 *  初始化视图，重写该方法可以改变视图样式
 */
- (void)lsqInitView;
@end
