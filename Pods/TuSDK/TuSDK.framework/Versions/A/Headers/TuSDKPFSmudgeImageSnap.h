//
//  TuSDKPFSmudgeImageSnap.h
//  TuSDK
//
//  Created by Yanlin on 11/3/15.
//  Copyright © 2015 tusdk.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - TuSDKPFSmudgeImageSnap

/**
 *  图片快照对象
 */
@interface TuSDKPFSmudgeImageSnap : NSObject

/** 宽 */
@property (nonatomic) int width;

/** 宽 */
@property (nonatomic) int height;

/** 行字节数 */
@property (nonatomic) int bytesPerRow;

/** 数据长度 */
@property (nonatomic) int dataSize;

/** 像素数据 */
@property (nonatomic) unsigned char *data;

/**
 *  销毁数据
 */
- (void)destroy;

/**
 *  从源更新像素数据
 *
 *  @param snap 源快照对象
 */
- (void)updateDataFrom:(TuSDKPFSmudgeImageSnap *)snap;

/**
 *  复制，不包含原始的图像数据
 */
- (TuSDKPFSmudgeImageSnap *)copy;

/**
 *  复制
 *
 *  @param includeImageData 是否复制图像原始数据
 *
 *  @return 新的快照对象
 */
- (TuSDKPFSmudgeImageSnap *)copy:(BOOL)includeImageData;
@end
