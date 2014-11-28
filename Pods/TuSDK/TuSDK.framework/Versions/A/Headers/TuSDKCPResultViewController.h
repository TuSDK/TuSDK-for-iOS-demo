//
//  TuSDKCPResultViewController.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/11.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import "TuSDKICViewController.h"
#import "TuSDKResult.h"

/**
 *  处理结果视图控制器
 */
@interface TuSDKCPResultViewController : TuSDKICViewController
/**
 *  保存到临时文件 (默认不保存, 当设置为YES时, TuSDKCaputorResult.tmpFile, 处理完成后将自动清理原始图片)
 */
@property (nonatomic) BOOL saveToTemp;

/**
 *  保存到系统相册 (默认不保存, 当设置为YES时, TuSDKCaputorResult.asset, 处理完成后将自动清理原始图片)
 */
@property (nonatomic) BOOL saveToAlbum;

/**
 *  保存到系统相册的相册名称
 */
@property (nonatomic, copy) NSString *saveToAlbumName;

/**
 *  通知处理结果
 *
 *  @param result SDK处理结果
 */
- (void)notifyProcessingWithResult:(TuSDKResult *)result;

/**
 *  异步通知处理结果
 *
 *  @param result SDK处理结果
 */
- (void)asyncNotifyProcessingWithResult:(TuSDKResult *)result;

/**
 *  异步处理如果需要保存文件 (默认完成后执行:@selector(notifyProcessingWithResult:))
 *
 *  @param result SDK处理结果
 */
- (void)asyncProcessingIfNeedSave:(TuSDKResult *)result;

/**
 *  异步处理如果需要保存文件
 *
 *  @param result   SDK处理结果
 *  @param selector 结束后执行方法
 */
- (void)asyncProcessingIfNeedSave:(TuSDKResult *)result completedSelector:(SEL)selector;

/**
 *  保存图片到临时文件
 *
 *  @param result 相机拍摄结果
 *  @param selector 结束后执行方法
 */
- (void)saveToTempWithResult:(TuSDKResult *)result completedSelector:(SEL)selector;

/**
 *  保存图片到系统相册
 *
 *  @param result 相机拍摄结果
 *  @param selector 结束后执行方法
 */
- (void)saveToAlbumWithResult:(TuSDKResult *)result completedSelector:(SEL)selector;
@end
