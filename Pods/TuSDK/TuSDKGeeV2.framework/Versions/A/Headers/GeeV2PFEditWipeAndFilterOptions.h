//
//  GeeV2PFEditWipeAndFilterOptions.h
//  TuSDKGeeV2
//
//  Created by Jimmy Zhao on 16/9/18.
//  Copyright © 2016年 tusdk.com. All rights reserved.
//

#import "GeeV2PFEditWipeAndFilterController.h"

@interface GeeV2PFEditWipeAndFilterOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:GeeV2PFEditSmudgeView, 需要继承 GeeV2PFEditSmudgeView)
 */
@property (nonatomic, strong) Class viewClazz;

/**
 *  默认的笔刷大小 (默认: lsqMediumBrush，中等粗细)
 */
@property (nonatomic, assign) lsqBrushSize defaultBrushSize;

/**
 *  撤销的最大次数 (默认: 5)
 */
@property (nonatomic, assign) NSUInteger maxUndoCount;

/**
 *  显示放大镜 (默认: true)
 */
@property (nonatomic, assign) BOOL displayMagnifier;

/**
 *  笔刷效果强度 (默认: 0.2, 范围为0 ~ 1，值为1时强度最高)
 */
@property (nonatomic, assign) CGFloat brushStrength;

/**
 *  创建滤镜涂抹控制器对象
 *
 *  @return controller 滤镜涂抹控制器对象
 */
- (GeeV2PFEditWipeAndFilterController *)viewController;
@end
