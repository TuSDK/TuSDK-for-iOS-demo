//
//  GeeV2PFEditMultipleController.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditMultipleView.h"

#pragma mark - GeeV2PFEditMultipleControllerDelegate
@class GeeV2PFEditMultipleController;

/**
 *  多功能图像编辑控制器委托
 */
@protocol GeeV2PFEditMultipleControllerDelegate <TuSDKCPComponentErrorDelegate>

/**
 *  图片编辑完成 
 *
 *  @param controller 图片编辑入口控制器
 *  @param result 图片编辑入口控制器处理结果
 */
- (void)onGeeV2PFEditMultiple:(GeeV2PFEditMultipleController *)controller result:(NSArray<TuSDKResult *> *)resultArray;

/**
 *  图片编辑完成
 *
 *  @param controller 图片编辑入口
 制器
 *  @param action 图片编辑动作类型
 */
- (void)onGeeV2PFEditMultiple:(GeeV2PFEditMultipleController *)controller action:(lsqTuSDKCPEditActionType)action;
@optional

/**
 *  是否自己实现打开多选相册
 *
 *  @return BOOL（默认为：false， 设置为True时使用自定义处理逻辑）
 */
- (BOOL)onGeeV2PFEditMultipleOpenAlumMutipleSourceController:(GeeV2PFEditMultipleController *)sourceController;

@end


#pragma mark - GeeV2PFEditMultipleController
/**
 *  多功能图像编辑控制器
 */
@interface GeeV2PFEditMultipleController : TuSDKPFEditMultipleControllerBase{
    @protected
    // 默认样式视图
    GeeV2PFEditMultipleView *_defaultStyleView;
}

/**
 *  默认样式视图 (如果覆盖 buildDefaultStyleView 方法，实现了自己的视图，defaultStyleView == nil)
 */
@property (nonatomic, readonly) GeeV2PFEditMultipleView *defaultStyleView;

/**
 *  多功能图像编辑控制器委托
 */
@property (nonatomic, weak) id<GeeV2PFEditMultipleControllerDelegate> delegate;

/**
 *  一次编辑的最大照片数量 (默认: 9, 0 < n <= 9)
 */
@property (nonatomic, assign) NSUInteger maxSelectionNumber;

/**
 *  是否保存全部图片（默认：NO 结果只保留编辑过的图片）
 *
 *  当设置为Yes,结果保留所有图片（无论图片是否编辑过）
 */
@property (nonatomic) BOOL enableAlwaysSaveEditResult;

/**
 *  是否禁用滑动切换显示图片 (默认:不禁用)
 */
@property (nonatomic) BOOL disableSlideSwitch;

/**
 *  输入资源对象列表
 */
@property (nonatomic, retain) NSArray<TuSDKResult *> *inputResources;

#pragma mark - config
/**
 *  视图类 (默认:GeeV2PFEditMultipleView, 需要继承 GeeV2PFEditMultipleView)
 */
@property (nonatomic, strong) Class viewClazz;
@end
