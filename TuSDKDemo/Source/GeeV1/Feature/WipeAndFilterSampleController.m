//
//  WipeAndFilterSampleController.m
//  TuSDKDemo
//
//  Created by Yanlin on 1/28/16.
//  Copyright © 2016 tusdk.com. All rights reserved.
//

#import "WipeAndFilterSampleController.h"

/**
 *  模糊涂抹功能示例, 模糊功能需要权限验证，使用前请确认已获取相应权限。
 *
 *  更多服务细节请参考: http://tusdk.com/services
 */
@implementation WipeAndFilterSampleController

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
    
    // 显示放大镜
    self.displayMagnifier = YES;
    
    // 笔刷效果强度 (默认: 0.2, 范围为0 ~ 1，值为1时强度最高)
    self.brushStrength = 0.5;
    
    // 保存到系统相册 (默认不保存, 当设置为YES时, TuSDKResult.asset, 处理完成后将自动清理原始图片)
    self.saveToAlbum = YES;
}

/**
 *  通知处理结果
 *
 *  @param result SDK处理结果
 */
- (void)notifyProcessingWithResult:(TuSDKResult *)result;
{
    // 将编辑结果发送给外部代理, 具体见 TuSDKPFEditWipeAndFilterControllerDelegate
    [super notifyProcessingWithResult:result];
    
    // 本例中没有设置外部代码，所以处理完结果后，直接返回上一个视图
    [self backActionHadAnimated];
}

@end
