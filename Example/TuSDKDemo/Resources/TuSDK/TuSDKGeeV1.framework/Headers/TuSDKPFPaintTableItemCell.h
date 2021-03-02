//
//  TuSDKPFPaintTableItemCell.h
//  TuSDKGeeV1
//
//  Created by tutu on 2018/11/30.
//  Copyright © 2018 tusdk.com. All rights reserved.
//

#import "TuSDKGeeV1Import.h"
#import "TuSDKPaintMode.h"

#pragma mark - TuSDKPFBrushTableItemCell

/**
 *  笔刷列表行视图
 *  @since v3.1.0
 */
@interface TuSDKPFPaintTableItemCell : TuTableViewCell
{
@protected
    // 包装视图
    UIView *_wrapView;
    // 颜色视图
    UIView *_thumbView;
}

/**
 *  包装视图
 */
@property (nonatomic, readonly) UIView *wrapView;


/**
 *  笔刷数据
 *  @since v3.1.0
 */
@property (nonatomic, strong) TuSDKPaintMode *mode;

@end
