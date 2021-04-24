//
//  SelesParameters.h
//  TuSDK
//
//  Created by Clear Hu on 2020/4/27.
//  Copyright © 2020 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - TuFilterModel
// 滤镜类型
typedef NS_ENUM(NSInteger, TuFilterModel)
{
    TuFilterModel_None,
    TuFilterModel_Audio,    // 音乐
    TuFilterModel_Comic,    // 漫画
    TuFilterModel_Filter,    // 滤镜
    TuFilterModel_MonsterFace,    // 哈哈镜 v3.2.1
    TuFilterModel_Particle,    // 粒子
    TuFilterModel_PlasticFace,    // 微整形 v3.2.0
    TuFilterModel_Scene,    // 场景
    TuFilterModel_SkinFace,    // 美肤 v3.2.0
    TuFilterModel_Sticker,    // 贴纸
    TuFilterModel_StickerAudio,   // MV特效
    TuFilterModel_StickerFace,   // 人脸贴纸
    TuFilterModel_Text,   // 文字
    TuFilterModel_Transition,   // 转场特效 v3.4.1
    TuFilterModel_ImageEdit,   // 图片编辑滤镜
    TuFilterModel_CosmeticFace,   // 美妆
    TuFilterModel_ReshapeFace,
    TuFilterModel_Ratio,

};

#pragma mark - SelesParametersListener
@class SelesParameterArg;

/** 滤镜参数选项监听接口 */
@protocol SelesParametersListener<NSObject>
/** 更新参数 */
- (void)onSelesParametersUpdate:(TuFilterModel)model code:(NSString *)code arg:(SelesParameterArg *)arg;
@end

#pragma mark - SelesParameterArg
/** 滤镜参数*/
@interface SelesParameterArg : NSObject
@property (nonatomic)       CGFloat     defaultValue;   // 参数默认值
@property (nonatomic)       CGFloat     minFloatValue;  // 参数最小值
@property (nonatomic)       CGFloat     maxFloatValue;  // 参数最大值
@property (nonatomic) CGFloat precent;                              // 设置百分比 0 - 1
@property (nonatomic) CGFloat value;                                // 获取值
@property (nonatomic, readonly) NSString *key;                      // 参数键名
@property (nonatomic, readonly) NSString *code;                     // 滤镜代号
@property (nonatomic, readonly) TuFilterModel model;                // 滤镜类型
@property (nonatomic, weak) id<SelesParametersListener> listener;   // 滤镜参数选项监听接口
- (void)reset;                                                      // 重置默认值
- (BOOL)equalsKey:(NSString *)key;                                  // 是否匹配参数键名
@end

#pragma mark - SelesParameters
// 滤镜参数选项
@interface SelesParameters : NSObject
@property (nonatomic, weak)     id<SelesParametersListener>         listener;   // 滤镜参数选项监听接口
@property (nonatomic, readonly) NSArray<SelesParameterArg *>*       args;       // 参数列表
@property (nonatomic, readonly) NSArray*                            argKeys;    // 参数键名列表
@property (nonatomic, readonly) NSUInteger                          count;      // 配置参数总数
@property (nonatomic, readonly) TuFilterModel                       model;      // 滤镜类型
@property (nonatomic, readonly) NSString*                           code;       // 滤镜代号
@property (nonatomic, readonly) BOOL                                isInited;   // 是否已初始化
+ (instancetype)parameterWithCode:(NSString *)code model:(TuFilterModel)model;  // 滤镜配置选项
- (NSArray *)changedArgs;                                                       // 获取已改变数值的参数列表
- (void)reset;                                                                  // 重置参数
- (void)resetWithKey:(NSString *)key;                                           // 重置参数
- (SelesParameterArg *)argWithKey:(NSString *)key;                         // 获取滤镜参数
- (void)setArgWithKey:(NSString *)key precent:(CGFloat)precent;                 // 设置滤镜参数百分比
- (void)stepArgWithKey:(NSString *)key precent:(CGFloat)precent;                // 步进滤镜参数百分比
- (void)merge:(SelesParameters *)other;                                         // 合并滤镜参数
- (void)syncArgs:(SelesParameters *)other;                                      // 同步滤镜参数
- (void)appendFloatArgWithKey:(NSString *)key value:(CGFloat)value;             // 添加一个浮点参数
- (void)appendFloatArgWithKey:(NSString *)key value:(CGFloat)value index:(NSInteger)index; // 添加一个浮点参数
- (void)appendFloatArgWithKey:(NSString *)key value:(CGFloat)value minValue:(CGFloat)minValue maxValue:(CGFloat)maxValue;
/**
 * 添加一个浮点参数
 * @param key 参数键名
 * @param value 当前值
 * @param minValue 最小值
 * @param maxValue 最大值
 * @param index 索引
 */
- (void)appendFloatArgWithKey:(NSString *)key
                        value:(CGFloat)value
                     minValue:(CGFloat)minValue
                     maxValue:(CGFloat)maxValue
                        index:(NSInteger)index;
@end

NS_ASSUME_NONNULL_END
