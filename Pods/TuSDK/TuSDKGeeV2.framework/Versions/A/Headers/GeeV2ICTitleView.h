//
//  GeeV2ICTitleView.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/13.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * 带图标的文本
 */
@interface GeeV2ICTitleView : UIView {
    
@protected
    
    /**
     *  标题
     */
    UILabel *_titleLabel;
    
    /**
     *  图标
     */
    UIImageView *_iconView;
}

@property (nonatomic, copy) NSString *title;

@property (nonatomic, strong) UIImage *icon;

@property (nonatomic, readonly) UILabel *titleLabel;

@end
