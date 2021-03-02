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
@interface TuSDKCPGroupFilterBar : TuGroupFilterBarBase<TuGroupFilterTableViewDelegate, TuGroupFilterGroupCellDelegate, TuFilterOnlineControllerDelegate, TuGroupFilterBarInterface>
{
    // 滤镜分组列表
    UIView<TuGroupFilterTableViewInterface> *_groupTable;
    // 滤镜列表
    UIView<TuGroupFilterTableViewInterface> *_filterTable;
    // 后退按钮
    UIButton *_backButton;
}

/**
 *  后退按钮
 */
@property (nonatomic, readonly) UIButton *backButton;
@end
