//
//  JMBubbleFilter.h
//  TuSDKDemo
//
//  Created by 言有理 on 2021/3/31.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TuSDKPulseFilter/TuSDKPulseFilter.h>
NS_ASSUME_NONNULL_BEGIN
@interface JMBubbleFilter : NSObject
@property(nonatomic, strong, readonly) TUPFPFilter *filter;
@property(nonatomic, assign, readonly) NSInteger index;
@property(nonatomic, strong) TUPFPBubbleTextFilter_PropertyBuilder *builder;
/// initialize
- (instancetype)initWithCtx:(TUPFilterCtx *)ctx index:(NSInteger)idx;
/// 配置气泡样式
- (void)configWithBubbleStyle:(NSInteger)style;
/// 更新气泡
- (void)fetch;
/// 气泡信息
- (TUPFPBubbleTextFilter_InteractionInfo *)info;
@end

NS_ASSUME_NONNULL_END
