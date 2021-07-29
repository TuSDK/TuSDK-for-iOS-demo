//
//  TuBrushManager.h
//  Mosaic
//
//  Created by Yanlin on 10/26/15.
//  Copyright © 2015 TuSDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TuBrush.h"

#pragma mark - TuBrushManager
/**笔刷管理器*/
@interface TuBrushManager : NSObject

/**笔刷管理器*/
+ (instancetype) manager;

/**
 *  笔刷代号列表
 */
@property (nonatomic, readonly) NSArray *brushCodes;

/**
 *  获取笔刷对象
 *
 *  @param code 笔刷代号
 *
 *  @return 笔刷对象
 */
- (TuBrush *)brushWithCode:(NSString *)code;

@end
