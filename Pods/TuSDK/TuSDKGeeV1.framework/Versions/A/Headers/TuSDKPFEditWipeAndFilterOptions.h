//
//  TuSDKPFEditWipeAndFilterOptions.h
//  TuSDKGeeV1
//
//  Created by Yanlin on 12/3/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import "TuSDKPFEditWipeAndFilterController.h"

@interface TuSDKPFEditWipeAndFilterOptions : TuSDKCPImageResultOptions
/**
 *  视图类 (默认:TuSDKPFEditSmudgeView, 需要继承 TuSDKPFEditSmudgeView)
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
 *  @return 滤镜涂抹控制器对象
 */
- (TuSDKPFEditWipeAndFilterController *)viewController;
@end
