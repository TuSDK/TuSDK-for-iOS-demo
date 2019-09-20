//
//  TuSDKPFNormalFilterGroupView.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/20.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import "TuSDKCPGroupFilterBar.h"

@class TuSDKPFNormalFilterGroupView;

/**
 *  裁剪与缩放控制器滤镜视图委托
 */
@protocol TuSDKPFNormalFilterGroupDelegate <NSObject>
/**
 *  选中一个滤镜
 *
 *  @param view 裁剪与缩放控制器滤镜视图
 *  @param item 滤镜分组元素
 *
 *  @return BOOL 是否允许继续执行
 */
- (BOOL)onTuSDKPFNormalFilterGroup:(TuSDKPFNormalFilterGroupView *)view
                         selectedItem:(TuSDKCPGroupFilterItem *)item;
@end
/**
 *  裁剪与缩放控制器滤镜视图
 */
@interface TuSDKPFNormalFilterGroupView : TuSDKCPGroupFilterBaseView
{
    @protected
    // 滤镜组选择栏
    UIView<TuSDKCPGroupFilterBarInterface> *_filterBar;
    // 滤镜标题视图
    UIView<TuSDKCPSubtitlesViewInterface> *_titleView;
}
/**
 *  裁剪与缩放控制器滤镜视图委托
 */
@property (nonatomic, weak) id<TuSDKPFNormalFilterGroupDelegate> delegate;

/**
 *  开关视图
 */
- (void)toggleBarShowState;
@end
