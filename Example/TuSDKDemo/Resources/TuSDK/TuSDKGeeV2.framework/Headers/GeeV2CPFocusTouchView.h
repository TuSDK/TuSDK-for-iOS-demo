//
//  GeeV2CPFocusTouchView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKGeeV2Import.h"

/**
 *  相机聚焦触摸视图
 */
@interface GeeV2CPFocusTouchView : TuFocusTouchViewBase
// 创建脸部定位视图
- (UIView *)buildFaceDetectionView;
@end
