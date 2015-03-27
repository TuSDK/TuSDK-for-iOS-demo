//
//  TuSDKTSString+Extend.h
//  TuSDK
//
//  Created by Clear Hu on 14/12/15.
//  Copyright (c) 2014年 Lasque. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  字符串帮助类
 */
@interface NSString (TuSDKTSStringExtend)

/**
 *  获取本地化字符串
 *
 *  @param key 键名
 *
 *  @return 本地化字符串
 */
+ (NSString*)localizedString:(NSString*)key;

/**
 *  base64编码
 *
 *  @param str 输入字符串
 *
 *  @return base64编码
 */
+ (NSString*)base64encode:(NSString*)str;

/**
 *  base64编码
 *
 *  @return base64编码
 */
- (NSString*)base64encode;

/**
 *  判断字符串是否为空
 *
 *  @param str 输入字符串
 *
 *  @return 判断字符串是否为空
 */
+(Boolean) isEmptyOrNull:(NSString *) str;

/**
 *  UUID
 *
 *  @return UUID
 */
+ (NSString*)UUID;

/**
 *  返回对应容量单位数
 *
 *  @param byte 字节总数
 *
 *  @return 对应容量单位数
 */
+ (NSString *)stringForByte:(unsigned long long)byte;

/**
 *  编码URL
 *
 *  @return 编码URL
 */
- (NSString*)encodeAsURIComponent;

/**
 *  编码HTML
 *
 *  @return 编码HTML
 */
- (NSString*)escapeHTML;

/**
 *  解码HTML
 *
 *  @return 解码HTML
 */
- (NSString*)unescapeHTML;

/**
 *  MD5编码
 *
 *  @return MD5编码
 */
- (NSString *) md5;

/**
 *  添加字符串省略号
 *
 *  @param length 输出的字符串长度
 *
 *  @return 添加字符串省略号
 */
- (NSString*)substringLinefeed:(NSUInteger)length;

/**
 *  删除字符串头尾空格
 *
 *  @return 删除字符串头尾空格
 */
- (NSString *)trim;

/**
 *  使用正则匹配子字符串
 *
 *  @param regular 正则表达式
 *
 *  @return 子字符串集合
 */
- (NSMutableArray *)substringByRegular:(NSString *)regular;

/**
 *  反转字符串
 *
 *  @return 反转字符串
 */
- (NSString *)reverse;

/**
 *  获取字符串的hex
 *
 *  @return 字符串的hex
 */
- (NSString *)hexString;

/**
 *  Hex转10进制数字
 *
 *  @return 10进制数字
 */
- (NSUInteger)hexToDecimal;

/**
 *  转换为Json对象
 *
 *  @return Json对象
 */
- (id)toJson;

/**
 *  转换为 unsigned long long
 *
 *  @return unsigned long long
 */
- (unsigned long long)unsignedLongLongValue;

/**
 *  转换为 NSUInteger
 *
 *  @return NSUInteger
 */
- (NSUInteger)unsignedIntegerValue;
@end
