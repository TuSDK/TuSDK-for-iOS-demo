//
//  TuSDKCPFocusTouchView.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/29.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TuSDKGeeV1Import.h"

/**
 *  相机聚焦触摸视图
 */
@interface TuSDKCPFocusTouchView : TuFocusTouchViewBase
// 创建脸部定位视图
- (UIView *)buildFaceDetectionView;
@end
