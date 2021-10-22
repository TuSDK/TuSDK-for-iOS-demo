//
//  TUPFPSimultaneouslyFilter.h
//  TuSDKPulseFilter
//
//  Created by 言有理 on 2021/6/15.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulse/TUPProperty.h>
#import <CoreGraphics/CoreGraphics.h>
NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_TYPE_NAME;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_PROP_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_PROP_RECT_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_PROP_SEEK_PARAM;
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_INDEX_CAMERA; // 相机流优先渲染
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_INDEX_FILE; //  视频流优先渲染
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_PATH; // 合拍视频路径
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_WIDTH; // 合拍区域宽度
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_HEIGHT; // 合拍区域高度
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_FIRST_LAYER; // 优先渲染类型
FOUNDATION_EXPORT NSString *const TUPFPSimultaneouslyFilter_CONFIG_STRETCH; // 视频速度

@interface TUPFPSimultaneouslyFilter_PropertyBuilder : NSObject
@property (nonatomic, assign) BOOL enable_play; // 是否播放
@property (nonatomic, assign) CGRect cameraDstRect; // 相机流渲染位置 normalization
@property (nonatomic, assign) CGRect cameraSrcRect; // 相机流裁剪区域 normalization
@property (nonatomic, assign) CGRect videoDstRect; // 文件流渲染位置 normalization
@property (nonatomic, assign) CGRect videoSrcRect; // 文件流裁剪区域 normalization
@property (nonatomic, copy) NSString *firstLayer; // 优先渲染
@property (nonatomic, assign) NSInteger currentPos; // 视频开始位置

- (instancetype) init;
/// 控制播放状态
- (TUPProperty*) makeProperty;
/// 控制seek
- (TUPProperty*) makeSeekProperty;
/// 控制渲染区域
- (TUPProperty*) makeRectProperty;

@end
@interface TUPFPSimultaneouslyFilter : NSObject

@end

NS_ASSUME_NONNULL_END
