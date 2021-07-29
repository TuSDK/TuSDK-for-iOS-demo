//
//  TUCProtocol.h
//  TuSDKPulseCore
//
//  Created by 言有理 on 2021/4/16.
//

#import <Photos/Photos.h>
#import <TuSDKPulseCore/TUCEnum.h>
/// 媒体资源对象接口
@protocol TuTSAssetInterface <NSObject>

/**
 *  媒体资源PHAsset对象  注：相册中用来获取asset对象，判断是否为GIF类型
 */
@property (nonatomic, readonly) PHAsset *asset;

/**
 *  本地标识
 */
@property (nonatomic, readonly) NSString *localIdentifier;

/**
 *  创建时间
 */
@property (nonatomic, readonly) NSDate *creationDate;

/**
 *  获取相片方向
 */
@property (nonatomic, readonly) UIImageOrientation imageOrientation;

/**
 *  获取缩略图 图片
 */
@property (nonatomic, readonly) UIImage *thumbnailImage;

/**
 异步获取缩略图
 */
- (void)requestThumbnailImageWithCompletion:(void (^)(UIImage *thumbnailImage))completion;

/**
 *  获取屏幕大小图片对象
 */
@property (nonatomic, readonly) UIImage *fullScreenImage;

/**
 *  获取原始图片对象
 */
@property (nonatomic, readonly) UIImage *fullResolutionImage;

/**
 *  照片原始宽高
 */
@property (nonatomic, readonly) CGSize fullResolutionImageSize;

/**
 *  获取图片原信息
 */
@property (nonatomic, readonly) NSDictionary *metadata;

/**
 *  异步获取原始图片对象
 *
 *  @param block 回调
 *
 */
- (void)asyncFullResolutionImage:(void (^)(UIImage *image, double progress, NSError *error))block;

/**
 *  取消加载相册图片
 */
- (void)cancelLoadFullResolutionImage;

/**
 *  加载相册图片
 *
 *  @param size      希望输出地相片长宽
 *  @param completed 图片加载完成
 */
- (void)loadImageWithPixelSize:(CGSize)size completed:(void (^)(UIImage * result))completed;

/**
 *  取消加载相册图片
 *
 *  @param size      希望输出地相片长宽
 */
- (void)cancelLoadImageWithPixelSize:(CGSize)size;

@end

/// 媒体资源组对象接口
@protocol TuTSAssetsGroupInterface <NSObject>
/**
 *  是否为相机胶卷(all photos)
 */
@property (nonatomic, readonly) BOOL userLibrary;

/**
 *  相册标题
 */
@property (nonatomic, readonly) NSString *title;

///**
// *  获取该组所有相片信息
// */
//@property (nonatomic, readonly) NSArray<TuTSAssetInterface> *allPhotos;

/**
 *  包含相片总数
 */
@property (nonatomic, readonly) NSUInteger count;

/**
 *  相册封面图片
 */
@property (nonatomic, readonly) UIImage *posterImage;

/**
 * 根据指定的排序字段 获取该组所有相片信息
 *
 *  @param sortKeyType 排序类型
 *  @param ascending 排序方式（升序/降序）
 *  @return 该组所有相片信息
 */
-(NSArray<TuTSAssetInterface> *) allPhotosWithSortKeyType:(TuAssetSortKeyType) sortKeyType ascending:(BOOL) ascending;

/**
 *  获取该组所有相片信息 （默认根据创建时间排序）
 *
 *  @return 该组所有相片信息
 */
-(NSArray<TuTSAssetInterface> *) allPhotos;

@end

