//
//  TuSDKFaceAligment.h
//  TuSDK
//
//  Created by Yanlin Qiu on 21/08/2017.
//  Copyright © 2017 tusdk.com. All rights reserved.
//
#import <UIKit/UIKit.h>


/** 人脸对齐信息 (归一百分比) */
@interface TuSDKFaceAligment:NSObject
@property (nonatomic, assign) CGFloat screenRatio;

@property (nonatomic, assign) CGRect rect;

@property (nonatomic, readonly, strong) NSArray<NSValue *> *marks;
@property (nonatomic, strong) NSArray<NSValue *> *orginMarks;

@property (nonatomic, assign) CGFloat roll;
@property (nonatomic, assign) CGFloat yaw;
@property (nonatomic, assign) CGFloat pitch;

@end
