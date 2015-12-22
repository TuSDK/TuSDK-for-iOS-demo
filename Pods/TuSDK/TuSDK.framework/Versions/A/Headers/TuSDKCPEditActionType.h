//
//  TuSDKCPEditActionType.h
//  TuSDK
//
//  Created by Clear Hu on 15/4/25.
//  Copyright (c) 2015年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  图片编辑动作类型
 */
typedef NS_ENUM(NSInteger, lsqTuSDKCPEditActionType)
{
    /**
     * 未知动作
     */
    lsqTuSDKCPEditActionUnknow,
    /**
     * 裁剪动作
     */
    lsqTuSDKCPEditActionCuter,
    /**
     * 滤镜动作
     */
    lsqTuSDKCPEditActionFilter,
    /**
     * 贴纸动作
     */
    lsqTuSDKCPEditActionSticker,
    /**
     * 美颜动作
     */
    lsqTuSDKCPEditActionSkin,
    /**
     * 涂抹动作
     */
    lsqTuSDKCPEditActionSmudge,
    /**
     * 调整动作
     */
    lsqTuSDKCPEditActionAdjust,
    /**
     * 模糊涂抹
     */
    lsqTuSDKCPEditActionWipeFilter,
    /**
     * 锐化动作
     */
    lsqTuSDKCPEditActionSharpness,
    /**
     * 晕角动作
     */
    lsqTuSDKCPEditActionVignette,
    /**
     * 景深动作
     */
    lsqTuSDKCPEditActionAperture,
    /**
     * 圣光动作
     */
    lsqTuSDKCPEditActionHolyLight,
};

/**
 *  图片编辑动作类型
 */
@interface TuSDKCPEditActionType : NSObject
/**
 *  高级编辑功能模块列表
 *
 *  @return 高级编辑功能模块列表
 */
+ (NSArray *)entryActionTypes;

/**
 *  多功能编辑功能模块列表
 *
 *  @return 多功能编辑功能模块列表
 */
+ (NSArray *)multipleActionTypes;
@end
