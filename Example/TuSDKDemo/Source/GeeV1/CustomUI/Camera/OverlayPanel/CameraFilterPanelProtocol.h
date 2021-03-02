//
//  CameraFilterPanelProtocol.h
//  TuSDKVideoDemo
//
//  Created by bqlin on 2018/7/27.
//  Copyright © 2018年 TuSDK. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CameraFilterPanelProtocol;

/**
 滤镜面板回调代理
 */
@protocol CameraFilterPanelDelegate <NSObject>
@optional

/**
 滤镜面板切换标签回调

 @param filterPanel 滤镜面板
 @param tabIndex 标签索引
 */
- (void)filterPanel:(id<CameraFilterPanelProtocol>)filterPanel didSwitchTabIndex:(NSInteger)tabIndex;

/**
 滤镜面板选中回调
 
 @param filterPanel 滤镜面板
 @param code 滤镜码
 */
- (void)filterPanel:(id<CameraFilterPanelProtocol>)filterPanel didSelectedFilterCode:(NSString *)code;

/**
 滤镜面板值变更回调
 
 @param filterPanel 滤镜面板
 @param percent 滤镜参数变更数值
 @param index 滤镜参数索引
 */
- (void)filterPanel:(id<CameraFilterPanelProtocol>)filterPanel didChangeValue:(double)percent paramterIndex:(NSUInteger)index;

/**
 重置滤镜参数回调
 
 @param filterPanel 滤镜面板
 @param paramterKeys 滤镜参数
 */
- (void)filterPanel:(id<CameraFilterPanelProtocol>)filterPanel resetParamterKeys:(NSArray *)paramterKeys;

@end


/**
 滤镜面板数据源
 */
@protocol CameraFilterPanelDataSource <NSObject>

/**
 滤镜参数个数

 @return 参数数量
 */
- (NSInteger)numberOfParamter:(id<CameraFilterPanelProtocol>)filterPanel;

/**
 对应索引的参数名称

 @param index 滤镜参数的索引
 @return 滤镜参数的名称
 */
- (NSString *)filterPanel:(id<CameraFilterPanelProtocol>)filterPanel  paramterNameAtIndex:(NSUInteger)index;

/**
 滤镜参数对应索引的参数值

 @param index 滤镜参数的索引
 @return 对应参数的数值
 */
- (double)filterPanel:(id<CameraFilterPanelProtocol>)filterPanel  percentValueAtIndex:(NSUInteger)index;

@end


/**
 滤镜面板通用接口
 */
@protocol CameraFilterPanelProtocol <NSObject>

@property (nonatomic, weak) id<CameraFilterPanelDelegate> delegate;
@property (nonatomic, weak) id<CameraFilterPanelDataSource> dataSource;

/**
 是否展示
 */
@property (nonatomic, assign, readonly) BOOL display;

/**
 重载参数列表，会触发数据源代理方法
 */
- (void)reloadFilterParamters;

@end
