//
//  TuTSAsset.h
//  TuSDK
//
//  Created by Clear Hu on 15/10/10.
//  Copyright © 2015年 tusdk.com. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulseCore/TUCProtocol.h>

/**
 *  远程图片下载进度回调
 *
 *  @param image    UIImage
 *  @param progress double
 *  @param error    NSError
 */
typedef void (^TuTSAssetProgressBlock)(UIImage *image, double progress, NSError *error);

#pragma mark - TuTSAssetsManager
/**
 *  系统相册授权错误
 */
typedef NS_ENUM(NSInteger, TuAssetsAuthorizationError){
    /**
     *  未定义
     */
    TuAssetsAuthorizationErrorNotDetermined = 0,
    /**
     *  限制访问
     */
    TuAssetsAuthorizationErrorRestricted,
    /**
     *  拒绝访问
     */
    TuAssetsAuthorizationErrorDenied
};
/**
 *  系统相册授权回调
 *
 *  @param error 是否返回错误信息
 */
typedef void (^TuTSAssetsManagerAuthorBlock)(NSError *error);

/**
 *  获取系统相册列表回调
 *
 *  @param groups 系统相册列表
 *  @param error  是否返回错误信息
 */
typedef void (^TuTSAssetsManagerGroupsBlock)(NSArray<TuTSAssetsGroupInterface> *groups, NSError *error);

/**
 *  保存相片到系统相册回掉
 *
 *  @param asset 相片对象
 *  @param error 错误对象
 */
typedef void (^TuTSAssetsManagerSaveImageCompletion)(id<TuTSAssetInterface> asset, NSError* error);

/**
 *  保存相片到指定相册
 *
 *  @param group 相册对象
 *  @param asset 相片对象
 *  @param error 错误对象
 */
typedef void (^TuTSAssetsManagerSaveImageAblumCompletion)(id<TuTSAssetsGroupInterface> group, id<TuTSAssetInterface> asset, NSError* error);

/**
 *  媒体资源管理对象
 */
@interface TuTSAssetsManager : NSObject
/**
 *  媒体资源管理对象
 *
 *  @return 媒体资源管理对象
 */
+ (TuTSAssetsManager *)sharedAssetsManager;

/**
 *  是否用户已授权访问系统相册
 *
 *  @return 是否用户已授权访问系统相册
 */
+ (BOOL)hasAuthor;

/**
 *  是否未决定授权
 *
 *  @return 是否未决定授权
 */
+ (BOOL)notDetermined;

/**
 *  获取系统相册加载错误信息
 *
 *  @param error 错误信息
 *
 *  @return 返回详细信息
 */
+ (NSString *)assetsGroupsLoadFailure:(NSError *)error;

/**
 *  显示系统相册加载错误信息警告
 *
 *  @param controller 控制器
 *  @param error      错误信息
 */
+ (void)showAlertWithController:(UIViewController *)controller loadFailure:(NSError *)error;

/**
 *  获取相册访问失败信息
 *
 *  @return 相册访问失败信息
 */
+ (NSString *)accessFailedInfo;

/**
 *  测试系统相册授权状态
 *
 *  @param authorBlock 系统相册授权回调
 */
+ (void)testLibraryAuthor:(TuTSAssetsManagerAuthorBlock)authorBlock;

/**
 *  获取系统相册分组
 *
 *  @param groupsBlock 获取系统相册列表回调
 */
+ (void)imageAlbumsWithBlock:(TuTSAssetsManagerGroupsBlock)groupsBlock;

/**
 *  保存图片数据到系统相册
 *
 *  @param image                图片数据
 *  @param compress             图片压缩比
 *  @param metadata             照片meta信息
 *  @param albumName            相册名称
 *  @param completionBlock      相册名称
 *  @param ablumCompletionBlock 保存相片到指定相册
 *
 *  @return 是否允许操作系统相册
 */
+ (BOOL) saveWithImage:(UIImage *)image
              compress:(CGFloat)compress
              metadata:(NSDictionary *)metadata
               toAblum:(NSString *)albumName
       completionBlock:(TuTSAssetsManagerSaveImageCompletion)completionBlock
  ablumCompletionBlock:(TuTSAssetsManagerSaveImageAblumCompletion)ablumCompletionBlock;

/**
 *  保存视频到系统相册
 *
 *  @param videoURL             视频文件
 *  @param albumName            相册名称
 *  @param completionBlock      相册名称
 *  @param ablumCompletionBlock 保存相片到指定相册
 *
 *  @return 是否允许操作系统相册
 */
+ (BOOL) saveWithVideo:(NSURL *)videoURL
               toAblum:(NSString *)albumName
       completionBlock:(TuTSAssetsManagerSaveImageCompletion)completionBlock
  ablumCompletionBlock:(TuTSAssetsManagerSaveImageAblumCompletion)ablumCompletionBlock;
@end
