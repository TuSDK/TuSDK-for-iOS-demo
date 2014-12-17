//
//  TuSDKAOValid.h
//  TuSDK
//
//  Created by Clear Hu on 14/12/15.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  SDK用户验证
 */
@interface TuSDKAOValid : NSObject

/**
 *  SDK用户验证
 *
 *  @return SDK用户验证
 */
+ (instancetype) shared;

/**
 *  是否通过开发者账号验证
 */
@property (nonatomic, readonly) BOOL isValid;

/**
 *  开发者级别
 */
@property (nonatomic, readonly) NSInteger level;

/**
 *  验证开发者ID
 *
 *  @param key 开发者ID
 *
 *  @return 是否通过验证
 */
- (BOOL)sdkValidWithKey:(NSString *)key;

/**
 *  验证开发者ID
 *
 *  @return 是否通过验证
 */
- (BOOL)sdkValid;
@end
