//
//  TuSDKTSDate+Extend.h
//  TuSDK
//
//  Created by Clear Hu on 14/11/1.
//  Copyright (c) 2014年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  时间扩展
 */
@interface NSDate(TuSDKTSDateExtend)
#pragma mark - Calendar
/**
 *  获取当天的包括“年”，“月”，“日”，“周”，“时”，“分”，“秒”的NSDateComponents
 *
 *  @return 当天的包括“年”，“月”，“日”，“周”，“时”，“分”，“秒”的NSDateComponents
 */
- (NSDateComponents *)componentsOfDay;

/**
 *  获取NSDate对应的月份第几周
 *
 *  @return NSDate对应的月份第几周
 */
- (NSInteger)weekdayOrdinal;

/**
 *  获得NSDate对应的年份
 *
 *  @return NSDate对应的年份
 */
- (NSUInteger)year;

/**
 *  获得NSDate对应的月份
 *
 *  @return NSDate对应的月份
 */
- (NSUInteger)month;

/**
 *  获得NSDate对应的日期
 *
 *  @return NSDate对应的日期
 */
- (NSUInteger)day;

/**
 *  获得NSDate对应的小时数
 *
 *  @return NSDate对应的小时数
 */
- (NSUInteger)hour;

/**
 *  获得NSDate对应的分钟数
 *
 *  @return NSDate对应的分钟数
 */
- (NSUInteger)minute;

/**
 *  获得NSDate对应的秒数
 *
 *  @return NSDate对应的秒数
 */
- (NSUInteger)second;

/**
 *  获得NSDate对应的星期
 *
 *  @return NSDate对应的星期 (Sunday:1, Monday:2, Tuesday:3, Wednesday:4, Thursday:5, Friday:6, Saturday:7)
 */
- (NSUInteger)weekday;

/**
 *  获得NSDate对应的周数
 *
 *  @return NSDate对应的周数
 */
- (NSUInteger)week;

/**
 *  获取当天的起始时间（00:00:00）
 *
 *  @return 当天的起始时间
 */
- (NSDate *)beginingOfDay;

/**
 *  获取当天的结束时间（23:59:59）
 *
 *  @return 当天的结束时间
 */
- (NSDate *)endOfDay;

/**
 *  获取当月的第一天
 *
 *  @return 当月的第一天
 */
- (NSDate *)firstDayOfTheMonth;

/**
 *  获取当月的最后一天
 *
 *  @return 当月的最后一天
 */
- (NSDate *)lastDayOfTheMonth;

/**
 *  获取前一个月的第一天
 *
 *  @return 前一个月的第一天
 */
- (NSDate *)firstDayOfThePreviousMonth;

/**
 *  获取后一个月的第一天
 *
 *  @return 后一个月的第一天
 */
- (NSDate *)firstDayOfTheFollowingMonth;

/**
 *  获取前一个月中与当天对应的日期
 *
 *  @return 前一个月中与当天对应的日期
 */
- (NSDate *)associateDayOfThePreviousMonth;

/**
 *  获取后一个月中与当天对应的日期
 *
 *  @return 后一个月中与当天对应的日期
 */
- (NSDate *)associateDayOfTheFollowingMonth;

/**
 *  获取当月的天数
 *
 *  @return 当月的天数
 */
- (NSUInteger)numberOfDaysInMonth;

/**
 *  获取当月的周数
 *
 *  @return 当月的周数
 */
- (NSUInteger)numberOfWeeksInMonth;

/**
 *  获取这一周的第一天
 *
 *  @return 这一周的第一天
 */
- (NSDate *)firstDayOfTheWeek;

/**
 *  获取当月中，前一周的第一天
 *
 *  @return 当月中，前一周的第一天
 */
- (NSDate *)firstDayOfThePreviousWeekInTheMonth;

/**
 *  获取前一个月中，最后一周的第一天
 *
 *  @return 前一个月中，最后一周的第一天
 */
- (NSDate *)firstDayOfTheLastWeekInPreviousMonth;

/**
 *  获取当月中，后一周的第一天
 *
 *  @return 当月中，后一周的第一天
 */
- (NSDate *)firstDayOfTheFollowingWeekInTheMonth;

/**
 *  获取下一个月中，最前一周的第一天
 *
 *  @return 下一个月中，最前一周的第一天
 */
- (NSDate *)firstDayOfTheFirstWeekInFollowingMonth;

/**
 *  获取当月中，这一周的第一天
 *
 *  @return 当月中，这一周的第一天
 */
- (NSDate *)firstDayOfTheWeekInTheMonth;

/**
 *  获取当月中，这一周的天数
 *
 *  @return 当月中，这一周的天数
 */
- (NSUInteger)numberOfDaysInTheWeekInMonth;

/**
 *  获取当天是当月的第几周
 *
 *  @return 当天是当月的第几周
 */
- (NSUInteger)weekOfDayInMonth;

/**
 *  获取当天是当年的第几周
 *
 *  @return 当天是当年的第几周
 */
- (NSUInteger)weekOfDayInYear;

/**
 *  获取前一周中与当天对应的日期
 *
 *  @return 前一周中与当天对应的日期
 */
- (NSDate *)associateDayOfThePreviousWeek;

/**
 *  获取后一周中与当天对应的日期
 *
 *  @return 后一周中与当天对应的日期
 */
- (NSDate *)associateDayOfTheFollowingWeek;

/**
 *  前一天
 *
 *  @return 前一天
 */
- (NSDate *)previousDay;

/**
 *  后一天
 *
 *  @return 后一天
 */
- (NSDate *)followingDay;

/**
 *  判断与某一天是否为同一天
 *
 *  @param otherDate 某一天
 *
 *  @return 与某一天是否为同一天
 */
- (BOOL)sameDayWithDate:(NSDate *)otherDate;

/**
 *  判断与某一天是否为同一周
 *
 *  @param otherDate 某一天
 *
 *  @return 与某一天是否为同一周
 */
- (BOOL)sameWeekWithDate:(NSDate *)otherDate;

/**
 *  判断与某一天是否为同一月
 *
 *  @param otherDate 某一天
 *
 *  @return 与某一天是否为同一月
 */
- (BOOL)sameMonthWithDate:(NSDate *)otherDate;

#pragma mark - Timestamp
/**
 *  格式化时间
 *
 *  @param format 格式化字符串
 *
 *  @return 返回格式化后的时间
 */
- (NSString *)dateFormat:(NSString*)format;

/**
 *  获取周名称
 *
 *  @return 周名称 TuSDK.strings=>"las_week_Sun" = "周日";
 */
- (NSString *)weekdayName;

#pragma mark - RFC1123
/**
 Convert a RFC1123 'Full-Date' string
 (http://www.w3.org/Protocols/rfc2616/rfc2616-sec3.html#sec3.3.1)
 into NSDate.
 */
+ (NSDate *)dateFromRFC1123:(NSString *)value;

/**
 Convert NSDate into a RFC1123 'Full-Date' string
 (http://www.w3.org/Protocols/rfc2616/rfc2616-sec3.html#sec3.3.1).
 */
- (NSString *)rfc1123String;
@end
