//
//  TuSDKCPGroupFilterBar.h
//  TuSDK
//
//  Created by Clear Hu on 15/2/18.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV1Import.h"
#import "TuSDKCPGroupFilterItemCell.h"

#pragma mark - TuSDKCPGroupFilterBar
/**
 *  滤镜组选择栏
 */
@interface TuSDKCPGroupFilterBar : TuSDKCPGroupFilterBarBase<TuSDKCPGroupFilterTableViewDelegate, TuSDKCPGroupFilterGroupCellDelegate, TuSDKCPFilterOnlineControllerDelegate, TuSDKCPGroupFilterBarInterface>
{
    // 滤镜分组列表
    UIView<TuSDKCPGroupFilterTableViewInterface> *_groupTable;
    // 滤镜列表
    UIView<TuSDKCPGroupFilterTableViewInterface> *_filterTable;
    // 后退按钮
    UIButton *_backButton;
}

/**
 *  后退按钮
 */
@property (nonatomic, readonly) UIButton *backButton;
@end