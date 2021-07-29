//
//  TUPThread.h
//  Demo
//
//  Created by 言有理 on 2021/4/7.
//  Copyright © 2021 言有理. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^tup_thread_block_t)(void);
@interface TUPThread : NSObject
- (instancetype)initWithName:(NSString *)threadName;
- (void)async:(tup_thread_block_t)block;
- (void)sync:(tup_thread_block_t)block;
/// dealloc 一定要调用
- (void)clear;
@end

NS_ASSUME_NONNULL_END
