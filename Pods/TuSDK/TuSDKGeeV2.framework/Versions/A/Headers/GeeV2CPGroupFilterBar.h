//
//  GeeV2CPGroupFilterBar.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuSDKGeeV2Import.h"
#import "GeeV2CPGroupFilterItemCell.h"

#pragma mark - GeeV2CPGroupFilterBar
/**
 *  滤镜组选择栏
 */
@interface GeeV2CPGroupFilterBar : TuSDKCPStackFilterBarBase<TuSDKCPStackFilterTableViewDelegate, TuSDKCPGroupFilterGroupCellDelegate, TuSDKCPFilterOnlineControllerDelegate, TuSDKCPStackFilterBarInterface>
{
    // 滤镜列表
    UIView<TuSDKCPStackFilterTableViewInterface> *_filterTable;
}

@end
