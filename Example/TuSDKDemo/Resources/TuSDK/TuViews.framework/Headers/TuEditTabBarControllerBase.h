//
//  TuEditTabBarControllerBase.h
//  TuSDK
//
//  Created by Jimmy Zhao on 16/10/11.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPulseCore/tools/TuTSAsset.h"
#import "TuSDKPulseCore/tools/TuTSCATransition+Extend.h"
/**
 *  图片编辑控制器基础类
 */
@interface TuEditTabBarControllerBase : UITabBarController
/**
 *  保存到临时文件 (默认不保存, 当设置为YES时, TuResult.tmpFile, 处理完成后将自动清理原始图片)
 */
@property (nonatomic) BOOL saveToTemp;

/**
 *  保存到系统相册 (默认不保存, 当设置为YES时, TuResult.asset, 处理完成后将自动清理原始图片)
 */
@property (nonatomic) BOOL saveToAlbum;

/**
 *  保存到系统相册的相册名称
 */
@property (nonatomic, copy) NSString *saveToAlbumName;

/**
 *  照片输出压缩率 0-1 如果设置为0 将保存为PNG格式  (默认: 0.95)
 */
@property (nonatomic) CGFloat outputCompress;

/**
 *  输入的临时文件目录 (处理优先级: inputImage > inputTempFilePath > inputAsset)
 */
@property (nonatomic, copy) NSString *inputTempFilePath;

/**
 *  输入的相册图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
 */
@property (nonatomic, retain) id<TuTSAssetInterface> inputAsset;

/**
 *  输入的图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
 */
@property (nonatomic, retain) UIImage *inputImage;

/**
 *  功能模块列表 lsqTuSDKCPEditActionType (默认全部加载, [TuEditActionType multipleActionTypes])
 */
@property (nonatomic, retain) NSArray *modules;

/**
 *  转场动画
 */
@property (nonatomic,retain) TuSDKTSCControllerTrans *transAnim;
/**
 *  关闭进度提示
 */
- (void)dismissHub;
//返回前一页 使用动画
-(void)lsqBackActionHadAnimated;

@end
