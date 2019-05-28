//
//  TuSDKPaintMode.h
//  TuSDK
//
//  Created by tutu on 2018/12/7.
//  Copyright © 2018 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


/**
 笔刷类
 @since v3.1.0
 */
@interface TuSDKPaintMode : NSObject


/**
 笔刷颜色
 @since v3.1.0
 */
@property (nonatomic, copy) NSString *colorCode;


/**
 笔刷选中颜色
 @since v3.1.0
 */
@property (nonatomic, copy) NSString *selectedColor;

@end

NS_ASSUME_NONNULL_END
