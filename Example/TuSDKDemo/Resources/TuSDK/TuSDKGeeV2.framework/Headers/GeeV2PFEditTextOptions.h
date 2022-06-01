//
//  GeeV2PFEditTextOptions.h
//  TuSDKGeeV2
//
//  Created by 刘鹏程 on 2022/5/30.
//  Copyright © 2022 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditTextController.h"
#import "GeeV2PFEditTextViewOptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface GeeV2PFEditTextOptions : TuImageResultOptions

/**
 *  视图类 (默认:GeeV2PFEditTextView, 需要继承 GeeV2PFEditTextView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  文字初始化创建样式
 */
@property (nonatomic, strong) GeeV2PFEditTextViewOptions *textOptions;

/**
 *  创建图片编辑滤镜控制器对象
 *
 *  @return controller 图片编辑滤镜控制器对象
 */
- (GeeV2PFEditTextController *)viewController;

@end

NS_ASSUME_NONNULL_END
