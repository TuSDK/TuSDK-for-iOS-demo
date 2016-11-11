//
//  StickerSampleController.m
//  TuSDKDemo
//
//  Created by Yanlin on 1/28/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import "StickerSampleController.h"

@implementation StickerSampleController

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
    
    // 单元格高度
    self.gridHeight = 80;
    
    // 单元格间距
    self.gridPadding = 5;
}

/**
 *  通知处理结果
 *
 *  @param result SDK处理结果
 */
- (void)notifyProcessingWithResult:(TuSDKResult *)result;
{
    // 将编辑结果发送给视图外部, 具体见 TuSDKPFEditStickerControllerDelegate
    [super notifyProcessingWithResult:result];
    
    // 本例中没有设置外部代码，所以处理完结果后，直接返回上一个视图
    [self backActionHadAnimated];
}

@end
