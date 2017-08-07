//
//  TuSDKStickerDownloader.h
//  TuSDK
//
//  Created by gh.li on 2017/7/26.
//  Copyright © 2017年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKNKDownloadItem.h"

#import "TuSDKPFStickerGroup.h"

/*
 * 贴纸下载委托
 */
@protocol TuSDKOnlineStickerDownloaderDelegate <NSObject>

/**
 *  贴纸组下载状态事件
 *
 *  @param stickerGroupId 贴纸组id
 *  @param progress 下载进度
 *  @param changedStatus 下载状态
 */
- (void)onDownloadProgressChanged:(uint64_t) stickerGroupId
                         progress:(CGFloat )progress
                    changedStatus:(lsqDownloadTaskStatus)status;


@end


@interface TuSDKOnlineStickerDownloader : NSObject

/*
 * 贴纸下载委托对象
 */
@property (nonatomic,assign) id<TuSDKOnlineStickerDownloaderDelegate> delegate;


/**
 *  贴纸组是否已下载
 *
 *  @param groupId 包ID
 *
 *  @return true：已下载到本地
 */
- (BOOL)containsWithGroupId:(uint64_t)groupId;

/**
 *  下载贴纸组数据
 *
 *  @param stickerGroup 贴纸分组
 */
- (void)downloadStickerGroup:(TuSDKPFStickerGroup *)stickerGroup;

/**
 *  取消下载贴纸
 *
 *  @param idt 贴纸组ID
 */
- (void)cancelDownloadWithStickerGroupId:(uint64_t)groupId;


@end
