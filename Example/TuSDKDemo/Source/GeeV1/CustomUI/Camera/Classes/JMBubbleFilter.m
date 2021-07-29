//
//  JMBubbleFilter.m
//  TuSDKDemo
//
//  Created by 言有理 on 2021/3/31.
//  Copyright © 2021 tusdk.com. All rights reserved.
//

#import "JMBubbleFilter.h"

#import "FCFileManager.h"

@interface JMBubbleFilter()
@property(nonatomic, strong) TUPFPFilter *filter;
@property(nonatomic, assign) NSInteger index;
@property(nonatomic, strong) TUPConfig *config;
@end

@implementation JMBubbleFilter

- (instancetype)initWithCtx:(TUPFilterCtx *)ctx index:(NSInteger)idx {
    self = [super init];
    if (self) {
        _filter = [[TUPFPFilter alloc] init:ctx withName:TUPFPBubbleTextFilter_TYPE_NAME];
        _config = [[TUPConfig alloc] init];
        _index = idx;
        
        _builder = [[TUPFPBubbleTextFilter_PropertyBuilder alloc] init];
        _builder.scale = 0.7;
        _builder.posX = 0.5;
        _builder.posY = 0.5;
    }
    return self;
}

- (void)configWithBubbleStyle:(NSInteger)style {
    NSString *pulseBundle = [[NSBundle mainBundle] pathForResource:@"TuSDKPulse" ofType:@"bundle"];
    NSString *fontPath = [pulseBundle stringByAppendingPathComponent:@"bubbleFont"];
    NSString *bubblePath = [NSString stringWithFormat:@"bt/lsq_bubble_%ld.bt", (long)style];
    NSString *sandboxPath = [FCFileManager pathForDocumentsDirectoryWithPath:bubblePath];
    [FCFileManager copyItemAtPath:[pulseBundle stringByAppendingPathComponent:bubblePath] toPath:sandboxPath];
    
    [_config setString:sandboxPath forKey:TUPFPBubbleTextFilter_CONFIG_MODEL];
    [_config setString:fontPath forKey:TUPFPBubbleTextFilter_CONFIG_FONT_DIR];
    [_filter setConfig:_config];
}

- (void)fetch {
    [_filter setProperty:_builder.makeProperty forKey:TUPFPBubbleTextFilter_PROP_PARAM];
}

- (TUPFPBubbleTextFilter_InteractionInfo *)info {
    return [[TUPFPBubbleTextFilter_InteractionInfo alloc] init:[_filter getProperty:TUPFPBubbleTextFilter_PROP_INTERACTION_INFO]];
}
@end
