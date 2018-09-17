//
//  TuSdkPlasticFaceInfo.h
//  TuSDK
//
//  Created by hecc on 2018/8/16.
//  Copyright © 2018年 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TuSDKFaceAligment.h"

@interface TuSdkPlasticFaceInfo : NSObject

-(instancetype) initWithFaceInfo:(TuSDKFaceAligment *)aligment;

/**
 * 获取点信息
 * 注：顺序严格按照已有次序，保证和 FACE_IDX 一致
 */
-(void) getPoints:(GLfloat*)points start:(int)start count:(int)count isVer:(BOOL)isVer;

/**
 * 获取face索引序列
 */
-(void)fillFace:(GLint *)idxs size:(int *)size start:(int)start count:(int)count;

/**
 * 计算瘦脸
 */
-(void)calcChin:(float)value ;

/**
 * 计算大眼
 */
-(void)calcEyeEnlarge:(float)value;

/**
 * 计算瘦鼻
 */
-(void)calcNose:(float)value;
/**
 * 计算嘴宽
 */
-(void)calcMouthWidth:(float) value ;

/**
 * 计算嘴唇
 */
-(void) calcLips:(float) value ;
/**
 * 计算细眉
 */
-(void) calcArchEyebrow:(float) value ;

/**
 * 计算眼距
 */
-(void) calcEyeDis:(float) value;

/**
 * 计算眼角
 */
-(void) calcEyeAngle:(float) value ;

/**
 * 计算下巴
 */
-(void) calcJaw:(float) value;

@end
