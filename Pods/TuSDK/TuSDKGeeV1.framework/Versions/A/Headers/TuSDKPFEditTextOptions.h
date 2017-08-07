//
//  TuSDKPFEditTextOptions.h
//  TuSDKGeeV1
//
//  Created by wen on 25/07/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditTextController.h"
#import "TuSDKPFEditTextViewOptions.h"

/**
 *  图片编辑文字控制器配置选项
 */
@interface TuSDKPFEditTextOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditTextView, 需要继承 TuSDKPFEditTextView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  文字初始化创建样式
 */
@property (nonatomic, strong) TuSDKPFEditTextViewOptions *textOptions;

/**
 *  创建图片编辑滤镜控制器对象
 *
 *  @return controller 图片编辑滤镜控制器对象
 */
- (TuSDKPFEditTextController *)viewController;

@end
