//
//  TuSDKStickerDownloader.h
//  TuSDK
//
//  Created by gh.li on 2017/7/26.
//  Copyright © 2017年 tusdk.com. All rights reserved.
//

#import <TuSDKPulseCore/TUCEnum.h>

@class TuStickerGroup;
// 贴纸下载委托
@protocol TuOnlineStickerDownloaderDelegate <NSObject>

/**
 *  贴纸组下载状态事件
 *
 *  @param stickerGroupId 贴纸组id
 *  @param progress 下载进度
 *  @param status 下载状态
 */
- (void)onDownloadProgressChanged:(uint64_t)stickerGroupId
                         progress:(CGFloat)progress
                    changedStatus:(TuDownloadTaskStatus)status;

@end


@interface TuOnlineStickerDownloader : NSObject

/*
 * 贴纸下载委托对象
 */
@property (nonatomic,weak) id<TuOnlineStickerDownloaderDelegate> delegate;


/**
 *  贴纸组是否已下载
 *
 *  @param groupId 包ID
 *
 *  @return true：已下载到本地
 */
- (BOOL)isDownloadedWithGroupId:(uint64_t)groupId;

/**
 * 判断贴纸是否正在下载中
 *
 * @param groupId 贴纸组ID
 *
 * @return  true：下载中
 */
- (BOOL)isDownloadingWithGroupId:(uint64_t)groupId;

/**
 *  下载贴纸组数据
 *
 *  @param stickerGroup 贴纸分组
 */
- (void)downloadStickerGroup:(TuStickerGroup *)stickerGroup;

/**
 *  下载贴纸组数据
 *
 *  @param groupId 贴纸组ID
 */
- (void)downloadWithGroupId:(uint64_t)groupId;

/**
 *  取消下载贴纸
 *
 *  @param groupId 贴纸组ID
 */
- (void)cancelDownloadWithGroupId:(uint64_t)groupId;


@end
