//
//  EditFilterSampleController.m
//  TuSDKDemo
//
//  Created by Yanlin on 1/28/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import "EditFilterSampleController.h"

@implementation EditFilterSampleController

/**
 *  初始化视图
 */
- (void)loadView;
{
    [super loadView];
    
    [self initParams];
}

/**
 *  设置参数
 */
- (void)initParams;
{
    // 输入的图片对象 (处理优先级: inputImage > inputTempFilePath > inputAsset)
    self.inputImage = [UIImage imageNamed:@"sample_photo.jpg"];
    
    // 开启滤镜配置选项 (默认: 开启)
    self.enableFilterConfig = NO;
    
    // 滤镜历史记录
    self.enableFilterHistory = NO;
    
    // 开启在线滤镜
    self.enableOnlineFilter = YES;
}

/**
 *  通知处理结果
 *
 *  @param result SDK处理结果
 */
- (void)notifyProcessingWithResult:(TuResult *)result;
{
    // 将编辑结果发送给外部代理, 具体见 TuSDKPFEditFilterControllerDelegate
    [super notifyProcessingWithResult:result];
    
    // 本例中没有设置外部代码，所以处理完结果后，直接返回上一个视图
    [self lsqBackActionHadAnimated];
}

@end
