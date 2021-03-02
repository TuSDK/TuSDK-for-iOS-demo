//
//  TuSDKICTitleView.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 8/26/15.
//  Copyright (c) 2015 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * 带图标的文本
 */
@interface TuSDKICTitleView : UIView {
    
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
