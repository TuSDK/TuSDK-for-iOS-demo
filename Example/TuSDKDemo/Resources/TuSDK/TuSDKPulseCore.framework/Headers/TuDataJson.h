//
//  TuDataJson.h
//  TuSDK
//
//  Created by Clear Hu on 15/1/31.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Json数据
 */
@interface TuDataJson : NSObject
/**
 *  初始化
 *
 *  @param sJson json字符串
 *
 *  @return Json 数据
 */
+ (id)initWithString:(NSString *)sJson;

/**
 *  反序列化数据
 *
 *  @param json Json字典
 */
- (void)deserializationWithJson:(NSDictionary*)json;
@end
