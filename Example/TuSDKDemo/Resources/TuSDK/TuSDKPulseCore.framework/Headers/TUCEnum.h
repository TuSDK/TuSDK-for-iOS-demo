//
//  TUCEnum.h
//  TuSDKPulseCore
//
//  Created by 言有理 on 2021/4/16.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
/// 方向定义
typedef NS_ENUM(NSUInteger, TuRotationMode) {
    TuRotationMode_Up            = 0,   // 向上       (false, 0,    NoRotation,                false, 0),
    TuRotationMode_Down          = 1,   // 向下       (false, 180,  Rotate180,                 false, 1),
    TuRotationMode_Right         = 2,   // 右边       (false, 90,   RotateRight,               true,  2),
    TuRotationMode_Left          = 3,   // 左边       (false, 270,  RotateLeft,                true,  3),
    TuRotationMode_UpMirrored    = 4,   // 向上镜像    (true,  0,    FlipHorizonal,             false, 4),
    TuRotationMode_DownMirrored  = 5,   // 向下镜像    (true,  180,  FlipVertical,              false, 5),
    TuRotationMode_RightMirrored = 6,   // 向右镜像    (true,  90,   RotateRightFlipVertical,   true,  6),
    TuRotationMode_LeftMirrored  = 7,   // 向左镜像    (true,  270,  RotateRightFlipHorizontal, true,  7);
};

/// 裁剪比例
typedef NS_ENUM(NSInteger, TTRatioType)
{
    // 原始比例
    TTRatioOrgin = 1,
    // 1:1比例
    TTRatio_1_1 = 1 << 1,
    // 2:3比例
    TTRatio_2_3 = 1 << 2,
    // 3:4比例
    TTRatio_3_4 = 1 << 3,
    // 9:16比例
    TTRatio_9_16 = 1 << 4,
    // 3:2比例
    TTRatio_3_2 = 1 << 5,
    // 4:3比例
    TTRatio_4_3 = 1 << 6,
    // 16:9比例
    TTRatio_16_9 = 1 << 7,
    // 所有比例
    TTRatioAll = TTRatioOrgin | TTRatio_1_1 | TTRatio_2_3 | TTRatio_3_4 | TTRatio_9_16 | TTRatio_3_2 | TTRatio_4_3 | TTRatio_16_9,
    // 默认比例
    TTRatioDefault = TTRatioOrgin | TTRatio_1_1 | TTRatio_2_3 | TTRatio_3_4 | TTRatio_9_16,
};

/// 排序字段
typedef NS_ENUM(NSInteger, TuAssetSortKeyType)
{
    /**
     * 根据创建时间排序
     */
    TuAssetSortKeyCreateDate = 0,
    /**
     * 根据修改时间排序（iOS8.0及以上可用）
     */
    TuAssetSortKeyModificationDate = 1,
    /**
     * 默认顺序，与系统相册所有照片排序一致
     */
    TuAssetSortKeyDefault,
};
/// 下载状态
typedef NS_ENUM(NSInteger, TuDownloadTaskStatus)
{
    /**
     * 初始化状态
     */
    TuDownloadTaskStatusInit,
    /**
     * 正在下载
     */
    TuDownloadTaskStatusDowning = 10,
    /**
     * 正在下载完成
     */
    TuDownloadTaskStatusDowned = 20,
    /**
     * 下载失败
     */
    TuDownloadTaskStatusDownFailed = 30,
    /**
     * 取消处理
     */
    TuDownloadTaskStatusCancel = 40,
    /**
     * 删除处理
     */
    TuDownloadTaskStatusRemoved = 100,
};

/// 下载类型
typedef NS_ENUM(NSInteger, TuDownloadTaskType)
{
    /**
     * 滤镜
     */
    TuDownloadTaskTypeFilter,
    /**
     * 贴纸
     */
    TuDownloadTaskTypeSticker,
    /**
     * 笔刷
     */
    TuDownloadTaskTypeBrush,
};
typedef NS_ENUM(NSInteger, TuNetworkStatus)
{
    // Apple NetworkStatus Compatible Names.
    TuNotReachable     = 0,
    TuReachableViaWiFi = 2,
    TuReachableViaWWAN = 1
};
/**
 *  Image Analysis processed type
 */
typedef NS_ENUM(NSInteger, TuImageAnalysisType)
{
    /**
     * Unknow
     */
    TuImageAnalysisTypeUnknow,
    /**
     * Succeed
     */
    TuImageAnalysisTypeSucceed,
    /**
     * Not Input Image Object
     */
    TuImageAnalysisTypeNotInputImage,
    /**
     * Service Failed
     */
    TuImageAnalysisTypeServiceFailed,
};
/**
 *  笔刷旋转类型
 */
typedef NS_ENUM(NSInteger, TuSDKBrushSize)
{
    /**
     * 小
     */
    TuSDKSmallBrush = 1,
    /**
     * 中
     */
    TuSDKMediumBrush,
    /**
     * 大
     */
    TuSDKLargeBrush,
};

typedef NS_ENUM(NSInteger, TuNetworkImageCacheType) {
    /**
     * The image wasn't available the SDWebImage caches, but was downloaded from the web.
     */
    TuNetworkImageCacheTypeNone,
    /**
     * The image was obtained from the disk cache.
     */
    TuNetworkImageCacheTypeDisk,
    /**
     * The image was obtained from the memory cache.
     */
    TuNetworkImageCacheTypeMemory
};
NS_ASSUME_NONNULL_END

