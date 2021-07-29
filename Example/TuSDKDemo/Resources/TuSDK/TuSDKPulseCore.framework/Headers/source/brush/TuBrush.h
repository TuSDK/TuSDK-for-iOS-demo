//
//  TuBrush.h
//  TuSDK
//
//  Created by Yanlin on 10/28/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TuSDKPulseCore/TuDataJson.h>
#import <TuSDKPulseCore/TUCEnum.h>

/**笔刷类型*/
typedef NS_ENUM(NSInteger, TuBrushType)
{
    TuBrushEmpty = 0,
    /**橡皮擦类*/
    TuBrushEraser = 1,
    /**马赛克类*/
    TuBrushMosaic = 2,
    /**印记类*/
    TuBrushStamp = 3,
    /**在线商场*/
    TuBrushOnline = 4,
};

/**笔刷旋转类型*/
typedef NS_ENUM(NSInteger, TuBrushRotateType)
{
    TuBrushRotateEmpty = 0,
    /**不旋转*/
    TuBrushRotateNone = 1,
    /**自动跟随轨迹*/
    TuBrushRotateAuto = 2,
    /**随机角度*/
    TuBrushRotateRandom = 3,
    /**限定范围随机角度*/
    TuBrushRotateLimitRandom = 4,
};

/**笔刷位置分布类型*/
typedef NS_ENUM(NSInteger, TuBrushPositionType)
{
    TuBrushPositionEmpty = 0,
    /**自动跟随轨迹*/
    TuBrushPositionAuto = 1,
    /**轨迹四周随机分级*/
    TuBrushPositionRandom = 2,
};

/**笔刷尺寸类型*/
typedef NS_ENUM(NSInteger, TuBrushSizeType)
{
    TuBrushSizeEmpty = 0,
    /**外部设置*/
    TuBrushSizeAuto = 1,
    /**随机大小*/
    TuBrushSizeRandom = 2,
};

/**
 *  笔刷对象
 */
@interface TuBrush : TuDataJson

/**
 * 笔刷ID
 */
@property (nonatomic)uint64_t brushId;

/**
 * 笔刷包ID
 */
@property (nonatomic) uint64_t groupId;

/**
 * 笔刷代号
 */
@property (nonatomic, retain) NSString *code;

/**
 * 笔刷名称
 */
@property (nonatomic, retain) NSString *name;

/**
 * 外部预览图
 */
@property (nonatomic, retain) NSString *thumb;

/**
 * 预览图文件名
 */
@property (nonatomic, copy) NSString *thumbKey;

/**
 * 笔刷文件名
 */
@property (nonatomic, copy) NSString *brushImageKey;

/**
 * 笔刷类型
 */
@property (nonatomic) TuBrushType brushType;

/**
 * 涂抹时旋转方式
 */
@property (nonatomic) TuBrushRotateType rotateType;

/**
 * 涂抹时位置分布方式
 */
@property (nonatomic) TuBrushPositionType positionType;

/**
 * 涂抹时笔触粗细
 */
@property (nonatomic) TuBrushSizeType sizeType;

/**
 * 笔刷配置参数
 */
@property (nonatomic, retain) NSDictionary *args;

/**
 * 是否为内置笔刷
 */
@property (nonatomic) BOOL isInternal;

/**
 *  笔刷图片
 */
@property (nonatomic, retain) UIImage *image;

/**
 *  笔刷对象
 *
 *  @return 笔刷对象
 */
+ (TuBrush *)brushWithType:(TuBrushType)type;

/**
 *  获取语言资源名称
 *
 *  @return 获取语言资源名称
 */
- (NSString *)nameKey;

/**
 * 复制笔刷配置选项
 *
 * @return 笔刷对象
 */
- (TuBrush *)copy;

@end
