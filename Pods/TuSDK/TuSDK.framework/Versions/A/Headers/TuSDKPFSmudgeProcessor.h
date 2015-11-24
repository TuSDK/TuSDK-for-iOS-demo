//
//  TuSDKPFSmudgeProcessor.h
//  TuSDK
//
//  Created by Yanlin on 11/3/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKPFBrush.h"
#import "TuSDKPFSmudgeImageSnap.h"

#define MAX_HISTORY_NUM 5
/**
 *  涂抹画布和笔刷信息
 */
#pragma mark - TuSDKPFSmudgeProcessor

// 模版缩放和旋转
typedef struct {
    float M11;
    float M12;
    float M21;
    float M22;
} TransformMatrix;

/**
 *  涂抹功能处理
 */
@interface TuSDKPFSmudgeProcessor : NSObject

/**
 *  原始图片快照数据，当使用橡皮擦时，即使用原始数据覆盖绘制路径上
 */
@property (nonatomic, retain) TuSDKPFSmudgeImageSnap *originalSnap;

/**
 *  绘制画布，包含底图
 */
@property (nonatomic, retain) TuSDKPFSmudgeImageSnap *canvasSnap;

/**
 *  当前绘制快照，在绘制时同步更新，不包含底图数据
 */
@property (nonatomic, retain) TuSDKPFSmudgeImageSnap *currentSnap;

/**
 *  当前笔刷
 */
@property (nonatomic, retain) TuSDKPFBrush *currentBrush;

/**
 *  笔刷粗细
 */
@property (nonatomic) CGFloat brushSize;

/**
 *  默认撤销的最大次数 (默认: 5)
 */
@property (nonatomic, assign) NSUInteger maxUndoCount;

/**
 *  保存当前画面进入绘制历史
 */
- (void)saveCurrentAsHistory;

/**
 *  重做上一条操作，并返回预览图像
 *  @return 重做操作后的画布图像
 */
- (UIImage *)getRedoData;

/**
 *  撤销上一步操作，并返回预览图像
 *
 *  @return 撤销操作后的画布图像
 */
- (UIImage *)getUndoData;

/**
 * 允许重做的次数
 */
- (NSUInteger)getRedoCount;

/**
 * 允许撤销的次数
 */
- (NSUInteger)getUndoCount;

#pragma mark - image function

/**
 *  获取图片的快照数据，包括长、宽、像素数据等
 */
- (TuSDKPFSmudgeImageSnap *)generateImageSnapForImage: (UIImage*)image;

#pragma mark - draw at touch position

/**
 *  在触摸点绘制
 *
 *  @param currentTouchPoint  当前触点
 *  @param previousTouchPoint 上一个触点
 *
 *  @return 预览图
 */

- (void)touchesBegan;

- (UIImage *)drawAtCurrentPoint: (CGPoint)currentTouchPoint
                           from: (CGPoint)previousTouchPoint;


/**
 *  获取绘制图层的图片
 */
- (UIImage *)getSmudgeImage;

/**
 *  获取预览图
 *
 *  @param includeSmudge 是否包含涂抹效果
 *
 *  @return 图片
 */
- (UIImage *)getPreviewImage:(BOOL)includeSmudge;

/**
 *  销毁数据
 */
- (void)destroy;

@end
