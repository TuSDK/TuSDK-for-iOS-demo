//
//  TuSDKTSImage+Extend.h
//  TuSDK
//
//  Created by Clear Hu on 14/10/28.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - ImageExtend
/**
 *  图片帮助类
 */
@interface UIImage(ImageExtend)
/**
 *  材质资源库图片名称
 *
 *  @param name 图片名称
 *
 *  @return 材质资源库图片名称
 */
+ (NSString *)lsqBundleName:(NSString *)name;

/**
 *  从材质资源库初始化
 *
 *  @param name 图片名称
 *
 *  @return 返回图片对象
 */
+ (UIImage *) imageLSQBundleNamed:(NSString *)name;

/**
 *  使用颜色获取Image对象
 *
 *  @param color 颜色对象
 *
 *  @return Image对象
 */
+ (UIImage *) imageFromColor:(UIColor *)color;

/**
 *  缩放图片
 *
 *  @param newSize 新的长宽
 *
 *  @return 缩放过的图片
 */
- (UIImage *) scaleImage:(CGSize)newSize;

/**
 *  等比旋转缩放 (不得小于 newSize)
 *
 *  @param newSize 新的长宽
 *
 *  @return 等比旋转缩放
 */
- (UIImage *) scaleGeometricAndRotate:(CGSize)newSize;

/**
 *  旋转图像到UP角度
 *
 *  @return 旋转图像到UP角度
 */
- (UIImage *) imageRotatedToUp;

/**
 *  按比例裁剪图片
 *
 *  @param ratio 裁剪比例
 *
 *  @return 裁剪后的图片
 */
- (UIImage *) imageCorpWithRatio:(CGFloat)ratio;

/**
 *  获取全屏大小图片
 *
 *  @return 全屏大小图片
 */
- (UIImage *) fullScreenImage;

/**
 *  获取全屏大小图片 (保持图片原始方向)
 *
 *  @return 全屏大小图片
 */
- (UIImage *) fullScreenImageKeepOrientation;

/**
 *  改变图片方向属性
 *
 *  @return 图片对象
 */
- (UIImage *) changeOrientation: (UIImageOrientation)orientation;

/**
 *  将输入图片拼合到自身上层
 *
 *  @param inputImage 输入图片
 *
 *  @return 拼合的图片
 */
- (UIImage *) mergeAboveImage:(UIImage *)inputImage;
/**
 *  转换为JPEG数据
 *
 *  @param compress 压缩率 0-1
 *  @param meta     图片信息
 *
 *  @return JPEG数据
 */
- (NSData *) jpegDataWithCompress:(CGFloat)compress meta:(NSDictionary *)meta;

/**
 *  是否需要长宽换位
 *
 *  @return 是否换位
 */
- (BOOL) sizeTransposed;
@end

#pragma mark - ResizeAndRotate
/**
 *  旋转并缩放图片
 */
@interface UIImage(ResizeAndRotate)

/**
 *  等比缩放并旋转图片
 *
 *  @param resize      目标长宽
 *  @param baseLongSide    是否按最大边比例作为缩放标准
 *
 *  @return 处理后的图片
 */
- (UIImage *)imageResize:(CGSize)resize baseLongSide:(BOOL)baseLongSide;

/**
 *  等比缩放并旋转图片
 *
 *  @param resize      目标长宽
 *  @param orientation 图片方向
 *  @param baseLongSide    是否按最大边比例作为缩放标准
 *
 *  @return 处理后的图片
 */
- (UIImage *)imageResize:(CGSize)resize
             orientation:(UIImageOrientation)orientation
            baseLongSide:(BOOL)baseLongSide;

/**
 *  等比缩放并旋转图片
 *
 *  @param resize      目标长宽
 *  @param baseLongSide    是否按最大边比例作为缩放标准
 *  @param quality     缩放质量
 *
 *  @return 处理后的图片
 */
- (UIImage *)imageResize:(CGSize)resize
            baseLongSide:(BOOL)baseLongSide
    interpolationQuality:(CGInterpolationQuality)quality;
/**
 *  等比缩放并旋转图片
 *
 *  @param resize      目标长宽
 *  @param baseLongSide    是否按最大边比例作为缩放标准
 *  @param ratio    输出图片的长宽比例 (默认为：0或小于0时按原图比例，当原图为正方形时不计算比例)
 *
 *  @return 处理后的图片
 */
- (UIImage *)imageResize:(CGSize)resize baseLongSide:(BOOL)baseLongSide ratio:(CGFloat)ratio;

/**
 *  等比缩放并旋转图片
 *
 *  @param resize      目标长宽
 *  @param orientation 图片方向
 *  @param baseLongSide    是否按最大边比例作为缩放标准
 *  @param ratio    输出图片的长宽比例 (默认为：0或小于0时按原图比例，当原图为正方形时不计算比例)
 *
 *  @return 处理后的图片
 */
- (UIImage *)imageResize:(CGSize)resize
             orientation:(UIImageOrientation)orientation
            baseLongSide:(BOOL)baseLongSide
                   ratio:(CGFloat)ratio;

/**
 *  等比缩放并旋转图片
 *
 *  @param resize      目标长宽
 *  @param orientation 图片方向
 *  @param baseLongSide    是否按最大边比例作为缩放标准
 *  @param quality     缩放质量
 *  @param ratio    输出图片的长宽比例 (默认为：0或小于0时按原图比例)
 *
 *  @return 处理后的图片
 */
- (UIImage *)imageResize:(CGSize)resize
             orientation:(UIImageOrientation)orientation
            baseLongSide:(BOOL)baseLongSide
    interpolationQuality:(CGInterpolationQuality)quality
                   ratio:(CGFloat)ratio;
@end

#pragma mark - OrientationChange
/**
 *  修改图片对象方向属性 （不修改图像）
 */
@interface UIImage(OrientationChange)
/**
 *  设置图片属性向左旋转图片90度
 *
 *  @return 重设属性后的图片对象
 */
- (UIImage *)changeTurnLeft;

/**
 *  设置图片属性向右旋转图片90度
 *
 *  @return 重设属性后的图片对象
 */
- (UIImage *)changeTurnRight;

/**
 *  设置图片属性水平镜像
 *
 *  @return 重设属性后的图片对象
 */
- (UIImage *)changeMirrorHorizontal;

/**
 *  设置图片属性垂直镜像
 *
 *  @return 重设属性后的图片对象
 */
- (UIImage *)changeMirrorVertical;
@end

#pragma mark - ImageCorp
/**
 *  图片裁剪扩展
 */
@interface UIImage(ImageCorp)
/**
 *  裁剪图片
 *
 *  @param rect 百分比裁剪区域
 *  @param outputSize 输出图片长宽
 *
 *  @return 裁剪后的图片
 */
- (UIImage *)imageCorpWithPrecentRect:(CGRect)rect outputSize:(CGSize)outputSize;

/**
 *  裁剪图片
 *
 *  @param size        源图片长宽
 *  @param rect        百分比裁剪区域
 *  @param outputSize  输出图片长宽
 *  @param orientation 图片宽度
 *  @param quality     图片质量
 *
 *  @return 裁剪后的图片
 */
- (UIImage *)imageCorpWithSize:(CGSize)size
                          rect:(CGRect)rect
                    outputSize:(CGSize)outputSize
                   orientation:(UIImageOrientation)orientation
          interpolationQuality:(CGInterpolationQuality)quality;
@end
