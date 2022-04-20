//
//  TuResultViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/11.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <TuViews/TuComponentsViewController.h>
#import <TuSDKPulseCore/TuSDKPulseCore.h>
#import <TuSDKPulse/TuSDKPulse.h>

/**
 *  处理结果视图控制器
 */
@interface TuResultViewController : TuComponentsViewController
{
    @protected
    //  是否显示Hub信息 (默认：开启)
    BOOL _enableShowHub;
}

/**
 *  保存到临时文件 (默认不保存, 当设置为YES时, TuResult.tmpFile, 处理完成后将自动清理原始图片)
 */
@property (nonatomic) BOOL saveToTemp;

/**
 *  保存到系统相册 (默认不保存, 当设置为YES时, TuResult.asset, 处理完成后将自动清理原始图片)
 */
@property (nonatomic) BOOL saveToAlbum;
/**
 *  是否移除处理完成后图片。默认为YES
 */
@property (nonatomic) BOOL removeResultImage;

/**
 *  保存到系统相册的相册名称
 */
@property (nonatomic, copy) NSString *saveToAlbumName;

/**
 *  照片输出压缩率 0-1 如果设置为0 将保存为PNG格式  (默认: 0.95)
 */
@property (nonatomic) CGFloat outputCompress;

/**
 *  设置水印选项 (默认为空，如果设置不为空，则输出的图片上将带有水印)
 */
@property (nonatomic) TuWaterMarkOption *waterMarkOption;

/**
 *  是否有访问系统相册权限
 */
@property (nonatomic, readonly) BOOL hasAlbumAccess;

/**
 *  通知处理结果
 *
 *  @param result SDK处理结果
 */
- (void)notifyProcessingWithResult:(TuResult *)result;

/**
 *  异步通知处理结果
 *
 *  @param result SDK处理结果
 *
 *  @return BOOL 是否截断默认处理逻辑 (默认: false, 设置为True时使用自定义处理逻辑)
 */
- (BOOL)asyncNotifyProcessingWithResult:(TuResult *)result;

/**
 *  异步处理如果需要保存文件 (默认完成后执行:@selector(notifyProcessingWithResult:))
 *
 *  @param result SDK处理结果
 */
- (void)asyncProcessingIfNeedSave:(TuResult *)result;

/**
 *  返回主线程通知结果
 *
 *  @param result SDK处理结果
 */
- (void)backUIThreadNotifyProcessingWithResult:(TuResult *)result;

/**
 *  保存图片到临时文件
 *
 *  @param result 相机拍摄结果
 *  @param result 结束后执行方法
 */
- (void)saveToTempWithResult:(TuResult *)result;

/**
 *  保存图片到系统相册
 *
 *  @param result 相机拍摄结果
 *  @param result 结束后执行方法
 */
- (void)saveToAlbumWithResult:(TuResult *)result;

/**
 *  添加水印
 *
 *  @param image 目标图片
 *
 *  @return result
 */
- (UIImage *)addWaterMarkToImage:(UIImage *)result;
@end
