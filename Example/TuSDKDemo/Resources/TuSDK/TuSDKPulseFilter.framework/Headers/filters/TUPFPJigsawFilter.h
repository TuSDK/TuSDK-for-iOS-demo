//
//  TUPFPJigsawFilter.h
//  TuSDKPulseFilter
//
//  Created by 言有理 on 2021/7/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <TuSDKPulse/TUPProperty.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_MODEL_TYPE; // 模板类型
FOUNDATION_EXPORT int const TUPFPJigsawFilter_MODEL_TYPE_FILE; // 文件类型
FOUNDATION_EXPORT int const TUPFPJigsawFilter_MODEL_TYPE_JSON; // JSON类型
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_WIDTH; // 拼图输出宽度
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_HEIGHT; // 拼图输出高度
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_MODEL_PATH; // 模板路径
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_CONFIG_MODEL_JSON; // 模板JSON
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_PROP_INTERACTION_INFO;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_PROP_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPJigsawFilter_PROP_PARAM_COLOR;
@interface TUPFPJigsawFilter_InteractionInfo_LayerInfo : NSObject
@property (nonatomic, assign) int index; // 坑位索引
@property (nonatomic, assign) int layerType; // 坑位类型 1为图片
@property (nonatomic, assign) int rotation; // 坑位默认高度
@property (nonatomic, assign) CGRect dsc_rect; // 坑位渲染位置 左上右下
@property (nonatomic, copy) NSString *path; // 默认图片路径
@property (nonatomic, copy) NSString *text;
@end

@interface TUPFPJigsawFilter_InteractionInfo : NSObject
@property (nonatomic, strong) NSMutableArray<TUPFPJigsawFilter_InteractionInfo_LayerInfo *> *layerInfos;
@property (nonatomic, assign) int modelWidth; // 模板宽度
@property (nonatomic, assign) int modelHeight; // 模板高度
@property (nonatomic, assign) int pitsCount; // 坑位数量
- (instancetype)init:(TUPProperty*)prop;
@end

@interface TUPFPJigsawFilter_ImageLayerInfo : NSObject
@property (nonatomic, assign) int index; // 坑位索引
@property (nonatomic, copy) NSString *path; // 路径
@property (nonatomic, assign) double scale; // 缩放
@property (nonatomic, assign) int rotation; // 角度
@property (nonatomic, assign) BOOL isHorizontalFlip; // 是否镜像
@property (nonatomic, assign) BOOL isVerticallyFlip; // 是否翻转
@property (nonatomic, assign) UIEdgeInsets padding; // 边框
@property (nonatomic, assign) CGRect dsc_rect;// // 坑位位置 左上右下
@property (nonatomic, assign) CGPoint offset; // 左上角偏移量
@end

@interface TUPFPJigsawFilter_PropertyHolder : NSObject
@property (nonatomic, strong) NSMutableArray<TUPFPJigsawFilter_ImageLayerInfo *> *layerInfos;
@property (nonatomic, strong) UIColor *backgroundColor;
@end

@interface TUPFPJigsawFilter_PropertyBuilder : NSObject
@property (nonatomic, strong) TUPFPJigsawFilter_PropertyHolder *holder;
- (instancetype)initWithHolder:(TUPFPJigsawFilter_PropertyHolder *)holder;
/// 调整拼图坑位
- (TUPProperty*) makeProperty;
/// 调整坑位背景填充颜色
- (TUPProperty*) makeBackgroundColorProperty;
@end

@interface TUPFPJigsawFilter : NSObject

@end

NS_ASSUME_NONNULL_END
