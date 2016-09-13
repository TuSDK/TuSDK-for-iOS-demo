//
//  TuSDKPFEditSkinView.h
//  TuSDKGeeV1
//
//  Created by Jimmy Zhao on 16/8/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditAdjustView.h"
/**
 *  美颜模块视图
 */
@interface TuSDKPFEditSkinView : TuSDKPFEditAdjustView

/**
 *  人脸检测结果, 检测不到人脸信息禁用大眼、瘦脸按钮
 *
 *  @param found 是否监测到人脸
 */
- (void)onFaceDetectionResult:(BOOL)found;

@end
