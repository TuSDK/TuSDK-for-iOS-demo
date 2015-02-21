//
//  TuSDKPFEditTurnAndCutFilterView.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/20.
//  Copyright (c) 2015年 Lasque. All rights reserved.
//

#import "TuSDKCPGroupFilterBaseView.h"

@class TuSDKPFEditTurnAndCutFilterView;

/**
 *  裁剪与缩放控制器滤镜视图委托
 */
@protocol TuSDKPFEditTurnAndCutFilterDelegate <NSObject>
/**
 *  选中一个滤镜
 *
 *  @param view 裁剪与缩放控制器滤镜视图
 *  @param item 滤镜分组元素
 *
 *  @return 是否允许继续执行
 */
- (BOOL)onTuSDKPFEditTurnAndCutFilter:(TuSDKPFEditTurnAndCutFilterView *)view
                         selectedItem:(TuSDKCPGroupFilterItem *)item;
@end
/**
 *  裁剪与缩放控制器滤镜视图
 */
@interface TuSDKPFEditTurnAndCutFilterView : TuSDKCPGroupFilterBaseView
/**
 *  裁剪与缩放控制器滤镜视图委托
 */
@property (nonatomic, assign) id<TuSDKPFEditTurnAndCutFilterDelegate> delegate;

/**
 *  开关视图
 */
- (void)toggleBarShowState;
@end
