//
//  TuNKDownloadItem.h
//  TuSDK
//
//  Created by Clear Hu on 15/3/23.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <TuSDKPulseCore/TuDataJson.h>
#import <TuSDKPulseCore/TUCEnum.h>

/**
 *  在线命令动作
 */
typedef NS_ENUM(NSInteger, TuOnlineCommandAction)
{
    /**
     * 未知动作
     */
    TuOnlineCommandActionUnknown,
    /**
     * 默认动作
     */
    TuOnlineCommandActionDefault,
    /**
     * 取消动作
     */
    TuOnlineCommandActionCancel,
    /**
     * 选中动作
     */
    TuOnlineCommandActionSelect,
    /**
     * 查看详细
     */
    TuOnlineCommandActionDetail
};


/**
 *  下载对象
 */
@interface TuNKDownloadItem : TuDataJson<NSCoding>
/**
 * 资源ID
 */
@property (nonatomic) uint64_t idt;

/**
 * 资源key
 */
@property (nonatomic, copy) NSString *key;

/**
 * 下载状态
 */
@property (nonatomic) TuDownloadTaskStatus status;

/**
 * 下载进度
 */
@property (nonatomic) CGFloat progress;

/**
 * 用户ID
 */
@property (nonatomic, copy) NSString *userId;

/**
 * 下载类型
 */
@property (nonatomic) TuDownloadTaskType type;

/**
 * 文件名称
 */
@property (nonatomic, copy) NSString *fileName;

/**
 *  下载类型动作标识
 */
@property (nonatomic, readonly) NSString *typeAct;

/**
 *  文件ID
 */
@property (nonatomic, copy) NSString *fileId;

/**
 *  本地下载文件路径
 *
 *  @return 本地下载文件路径
 */
- (NSString *)localDownloadPath;

/**
 *  本地下载文件临时目录
 *
 *  @return 本地下载文件临时目录
 */
- (NSString *)localTempPath;

/**
 *  转为JSON数据
 *
 *  @return JSON数据
 */
- (NSDictionary *)jsonData;

/**
 *  状态改变数据
 *
 *  @return jsonStatusChangeData 状态改变数据
 */
- (NSString *)jsonStatusChangeData;

/**
 *  下载类型动作标识
 *
 *  @param type 下载类型动作
 *
 *  @return type 下载类型动作标识
 */
+ (NSString *)typeActWithType:(TuDownloadTaskType)type;
@end
